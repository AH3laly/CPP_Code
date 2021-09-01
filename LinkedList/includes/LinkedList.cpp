#include<string>
#include "LinkedList.hpp"

using namespace LinkedListCustomImplementation;

LinkedList::LinkedList(){
    this->count = 0;
    this->head = NULL;
    this->end = NULL;
    this->cursor = NULL;
}

void LinkedList::addFirstNode(LinkedListNode *node){
    node->next = NULL;
    node->prev = NULL;
    this->head = this->end = node;
    this->cursor = node;
    this->count++;
}

void LinkedList::pushTop(LinkedListNode *node){
    if(this->count == 0){
        this->addFirstNode(node);
    } else {
        node->prev = NULL;
        node->next = this->head;
        this->head->prev = node;
        this->head = node;
        this->cursor = node;
        this->count++;
    }
}

void LinkedList::pushEnd(LinkedListNode *node){
    if(this->count == 0){
        this->addFirstNode(node);
    } else {
        this->end->next = node;
        node->prev = this->end;
        node->next = NULL;
        this->end = node;
        this->cursor = node;
        this->count++;
    }
    
}

void LinkedList::popTop(LinkedListNode* &popped){
    if(this->count == 0){
        popped = NULL;
        return;
    };
    popped = this->head;
    this->head->prev = NULL;
    this->head = this->head->next;
    this->cursor = this->head;
    this->count--;
}

void LinkedList::popEnd(LinkedListNode* &popped){
     if(this->count == 0){
        popped = NULL;
        return;
    };
    popped = this->end;
    this->end->prev->next = NULL;
    this->end = this->end->prev;
    this->cursor = this->end;
    this->count--;
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

void LinkedList::insert(LinkedListNode *node){
    if(this->count == 0){
        this->addFirstNode(node);
    } else if(this->cursor->next != NULL && this->cursor->prev != NULL){
        node->prev = this->cursor;
        node->next = this->cursor->next;
        this->cursor->next->prev = node;
        this->cursor->next = node;
        this->cursor = node;
        this->count++;
    } else if(this->cursor->next == NULL) {
        this->pushEnd(node);
    } else if(this->cursor->prev == NULL){
        this->pushTop(node);
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

int LinkedList::getCount(){
    return this->count;
}

int LinkedList::isEmpty(){
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