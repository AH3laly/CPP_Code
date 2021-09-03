#include<string>
#include<iostream>
#include "LinkedList.hpp"

using namespace LinkedListCustomImplementation;

NodeEntry* LinkedList::LinkedListNode::getData() const{
    return this->data;
}

void LinkedList::LinkedListNode::setData(NodeEntry *data){
        this->data = data;
}

void LinkedList::LinkedListNode::print() const{
    std::cout << this->data << std::endl;
}

NodeEntry* LinkedList::LinkedListNode::get() const{
    return this->data;
}

LinkedList::LinkedList(){
    this->count = 0;
    this->head = NULL;
    this->end = NULL;
    this->cursor = NULL;
}

LinkedList::LinkedListNode* LinkedList::createLinkedListNode(NodeEntry *nodeEntry){
    LinkedListNode *node = new LinkedListNode;
    node->setData(nodeEntry);
    return node;
}

void LinkedList::addFirstNode(NodeEntry *nodeEntry){
    LinkedListNode *node = createLinkedListNode(nodeEntry);
    node->next = NULL;
    node->prev = NULL;
    this->head = this->end = node;
    this->cursor = node;
    this->count++;
}

void LinkedList::pushTop(NodeEntry *nodeEntry){
    if(this->count == 0){
        this->addFirstNode(nodeEntry);
    } else {
        LinkedListNode *node = createLinkedListNode(nodeEntry);
        node->prev = NULL;
        node->next = this->head;
        this->head->prev = node;
        this->head = node;
        this->cursor = node;
        this->count++;
    }
}

void LinkedList::pushEnd(NodeEntry *nodeEntry){
    if(this->count == 0){
        this->addFirstNode(nodeEntry);
    } else {
        LinkedListNode *node = createLinkedListNode(nodeEntry);
        this->end->next = node;
        node->prev = this->end;
        node->next = NULL;
        this->end = node;
        this->cursor = node;
        this->count++;
    }
    
}

void LinkedList::popTop(NodeEntry* &nodeEntry){
    if(this->count == 0){
        nodeEntry = NULL;
        return;
    };
    nodeEntry = this->head->getData();
    LinkedListNode *oldHead = this->head;
    this->head->next->prev = NULL;
    this->head = this->head->next;
    this->cursor = this->head;
    this->count--;
    delete oldHead;
}

void LinkedList::popEnd(NodeEntry* &nodeEntry){
     if(this->count == 0){
        nodeEntry = NULL;
        return;
    };
    nodeEntry = this->head->getData();
    LinkedListNode *oldEnd = this->end;
    this->end->prev->next = NULL;
    this->end = this->end->prev;
    this->cursor = this->end;
    this->count--;
    delete oldEnd;
}
    
bool LinkedList::next(){
    if(this->cursor->next != NULL){
        this->current = this->cursor;
        this->cursor = this->cursor->next;
        return true;
    }
    return false;
}

bool LinkedList::prev(){
    if(this->cursor != NULL){
        this->current = this->cursor;
        this->cursor = this->cursor->prev;
        return true;
    }
    return false;
}

void LinkedList::cursorBegin(){
    this->cursor = this->head;
}

void LinkedList::cursorEnd(){
    this->cursor = this->end;
}

void LinkedList::insert(NodeEntry *nodeEntry){
    throw "Exception: The insert method is depricated, please use inserBefore or insertAfter";
}

void LinkedList::insertBefore(NodeEntry *nodeEntry){
    if(this->isEmpty()){
        this->addFirstNode(nodeEntry);
    } else if(this->cursor == this->head){
        this->pushTop(nodeEntry);
    } else if(this->cursor == this->end){
        this->pushEnd(nodeEntry);
    } else {
        // Insert new Node before this->cursor
        LinkedListNode *node = createLinkedListNode(nodeEntry);
        node->prev = this->cursor->prev;
        node->next = this->cursor;
        this->cursor->prev->next = node;
        this->cursor->prev = node;
        this->cursor = node;
        this->count++;
    }
}

void LinkedList::insertAfter(NodeEntry *nodeEntry){
    if(this->isEmpty()){
        this->addFirstNode(nodeEntry);
    } else if(this->cursor == this->head){
        this->pushTop(nodeEntry);
    } else if(this->cursor == this->end){
        this->pushEnd(nodeEntry);
    } else {
        // Insert New Node after this->cursor
        LinkedListNode *node = createLinkedListNode(nodeEntry);
        node->next = this->cursor->next;
        node->prev = this->cursor;
        this->cursor->next->prev = node;
        this->cursor->next = node;
        this->count++;
    }
}

void LinkedList::remove(){
    
    if(this->count == 0){
        return;

    } else if(this->cursor->next == NULL && this->cursor->prev == NULL){
        // There is only one Node
        delete this->cursor;
        this->reset();

    } else if(this->cursor->next != NULL && this->cursor->prev != NULL){
        // The Node has next and prev Nodes,
        // So, link prev to next, delete and set cursor to next Node
        LinkedListNode *newCursor = this->cursor->next;
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

int LinkedList::getCount() const{
    return this->count;
}

int LinkedList::isEmpty() const{
    return this->count <= 0;
}

void LinkedList::reset(){
        this->head = this->end = this->cursor = this->current = NULL;
}

void LinkedList::empty(){
    this->cursorBegin();
    while(this->getCount()>0){
        this->remove();
    }
}

LinkedList::~LinkedList(){
    this->empty();
}