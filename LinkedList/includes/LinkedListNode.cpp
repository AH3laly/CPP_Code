#include<iostream>
#include<string>
#include "LinkedListNode.hpp"

using namespace LinkedListCustomImplementation;

str LinkedListNode::getData(){
    return this->data;
}

void LinkedListNode::setData(str data){
        this->data = data;
}

void LinkedListNode::print(){
    std::cout << this->data << std::endl;
}