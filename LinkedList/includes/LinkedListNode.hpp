#include <string>

typedef std::string str;

#ifndef __LINKED_LIST_NODE_GUARD_H
#define __LINKED_LIST_NODE_GUARD_H

namespace LinkedListCustomImplementation {

struct LinkedListNode {
    
    public:
        LinkedListNode *next;
        LinkedListNode *prev;
        void setData(str);
        str getData();
        void print();
    
    private:
        str data;
};

}

#endif