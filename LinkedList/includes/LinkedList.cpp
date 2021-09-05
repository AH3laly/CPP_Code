#include<string>
#include<iostream>
#include "LinkedList.hpp"

using namespace LinkedListCustomImplementation;

template <typename NodeEntryType>
NodeEntryType* LinkedList<NodeEntryType>::LinkedListNode::getData() const{
    return this->data;
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::LinkedListNode::setData(NodeEntryType *data){
        this->data = data;
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::LinkedListNode::print() const{
    std::cout << this->data << std::endl;
}

template <typename NodeEntryType>
NodeEntryType* LinkedList<NodeEntryType>::LinkedListNode::get() const{
    return this->data;
}

template <typename NodeEntryType>
LinkedList<NodeEntryType>::LinkedList(){
    this->count = 0;
    this->head = NULL;
    this->end = NULL;
    this->cursor = NULL;
}

template <typename NodeEntryType>
typename LinkedList<NodeEntryType>::NodePointer LinkedList<NodeEntryType>::createLinkedListNode(NodeEntryType *nodeEntry){
    NodePointer node = new LinkedListNode;
    node->setData(nodeEntry);
    return node;
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::addFirstNode(NodeEntryType *nodeEntry){
    NodePointer node = createLinkedListNode(nodeEntry);
    node->next = NULL;
    node->prev = NULL;
    this->head = this->end = node;
    this->cursor = node;
    this->count++;
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::pushTop(NodeEntryType *nodeEntry){
    if(this->count == 0){
        this->addFirstNode(nodeEntry);
    } else {
        NodePointer node = createLinkedListNode(nodeEntry);
        node->prev = NULL;
        node->next = this->head;
        this->head->prev = node;
        this->head = node;
        this->cursor = node;
        this->count++;
    }
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::pushEnd(NodeEntryType *nodeEntry){
    if(this->count == 0){
        this->addFirstNode(nodeEntry);
    } else {
        NodePointer node = createLinkedListNode(nodeEntry);
        this->end->next = node;
        node->prev = this->end;
        node->next = NULL;
        this->end = node;
        this->cursor = node;
        this->count++;
    }
    
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::popTop(NodeEntryType* &nodeEntry){
    if(this->count == 0){
        nodeEntry = NULL;
        return;
    };
    nodeEntry = this->head->getData();
    NodePointer oldHead = this->head;
    this->head->next->prev = NULL;
    this->head = this->head->next;
    this->cursor = this->head;
    this->count--;
    delete oldHead;
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::popEnd(NodeEntryType* &nodeEntry){
     if(this->count == 0){
        nodeEntry = NULL;
        return;
    };
    nodeEntry = this->head->getData();
    NodePointer oldEnd = this->end;
    this->end->prev->next = NULL;
    this->end = this->end->prev;
    this->cursor = this->end;
    this->count--;
    delete oldEnd;
}

template <typename NodeEntryType>
bool LinkedList<NodeEntryType>::next(){
    if(this->cursor->next != NULL){
        this->current = this->cursor;
        this->cursor = this->cursor->next;
        return true;
    }
    return false;
}

template <typename NodeEntryType>
bool LinkedList<NodeEntryType>::prev(){
    if(this->cursor != NULL){
        this->current = this->cursor;
        this->cursor = this->cursor->prev;
        return true;
    }
    return false;
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::cursorBegin(){
    this->cursor = this->head;
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::cursorEnd(){
    this->cursor = this->end;
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::insert(NodeEntryType *nodeEntry){
    throw "Exception: The insert method is depricated, please use inserBefore or insertAfter";
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::insertBefore(NodeEntryType *nodeEntry){
    if(this->isEmpty()){
        this->addFirstNode(nodeEntry);
    } else if(this->cursor == this->head){
        this->pushTop(nodeEntry);
    } else if(this->cursor == this->end){
        this->pushEnd(nodeEntry);
    } else {
        // Insert new Node before this->cursor
        NodePointer node = createLinkedListNode(nodeEntry);
        node->prev = this->cursor->prev;
        node->next = this->cursor;
        this->cursor->prev->next = node;
        this->cursor->prev = node;
        this->cursor = node;
        this->count++;
    }
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::traverse(void(*pt)(NodeEntryType *nodeEntry)){
    if(!this->isEmpty()){
        this->cursorBegin();
        do {
            pt(this->cursor->get());
        } while (this->next());
    }
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::insertAfter(NodeEntryType *nodeEntry){
    if(this->isEmpty()){
        this->addFirstNode(nodeEntry);
    } else if(this->cursor == this->head){
        this->pushEnd(nodeEntry);
    } else if(this->cursor == this->end){
        this->pushTop(nodeEntry);
    } else {
        // Insert New Node after this->cursor
        NodePointer node = createLinkedListNode(nodeEntry);
        node->next = this->cursor->next;
        node->prev = this->cursor;
        this->cursor->next->prev = node;
        this->cursor->next = node;
        this->count++;
    }
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::remove(){
    
    if(this->count == 0){
        return;

    } else if(this->cursor->next == NULL && this->cursor->prev == NULL){
        // There is only one Node
        delete this->cursor;
        this->reset();

    } else if(this->cursor->next != NULL && this->cursor->prev != NULL){
        // The Node has next and prev Nodes,
        // So, link prev to next, delete and set cursor to next Node
        NodePointer newCursor = this->cursor->next;
        this->cursor->prev->next = this->cursor->next;
        this->cursor->next->prev = this->cursor->prev;
        delete this->cursor;
        this->cursor = newCursor;

    } else if(this->cursor->next == NULL){
        // It's the last Node
        // So, set end to cursor->prev, delete cursor and set cursor to cursor->prev Node
        this->end = cursor->prev;
        delete this->cursor;
        this->cursor = this->end;
        this->cursor->next = NULL;

    } else if(this->cursor->prev == NULL){
        // It's the first Node
        // So, set head to cursor->next, delete cursor and set cursor to cursor->next Node
        this->head = this->cursor->next;
        delete this->cursor;
        this->cursor = this->head;
        this->cursor->prev = NULL;
    }
    this->count--;
}

template <typename NodeEntryType>
int LinkedList<NodeEntryType>::getCount() const{
    return this->count;
}

template <typename NodeEntryType>
int LinkedList<NodeEntryType>::isEmpty() const{
    return this->count <= 0;
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::reset(){
        this->head = this->end = this->cursor = this->current = NULL;
}

template <typename NodeEntryType>
void LinkedList<NodeEntryType>::empty(){
    this->cursorBegin();
    while(this->getCount()>0){
        this->remove();
    }
}

template <typename NodeEntryType>
LinkedList<NodeEntryType>::~LinkedList(){
    this->empty();
}