#include<string>
#include "./types.hpp"

#ifndef __LINKED_LIST_GUARD_H
#define __LINKED_LIST_GUARD_H

namespace LinkedListCustomImplementation {

class LinkedList {

    private:
        class LinkedListNode {
            
            public:
                class LinkedListNode *next;
                class LinkedListNode *prev;
                void setData(NodeEntry*);
                NodeEntry* getData() const;
                void print() const;
                NodeEntry* get() const;
            
            private:
                NodeEntry *data;
        };
        
        int count;
        /**
         * Initialize the List with the first Node
         */
        void addFirstNode(NodeEntry *nodeEntry);

        /**
         * Reset everything for a new Empty List
         */
        void reset();

        LinkedListNode* createLinkedListNode(NodeEntry *nodeEntry);

    public:
        LinkedListNode *cursor, *head, *end, *current;
        LinkedList();
        ~LinkedList();

        /**
         * Push LinkedListNode on the Top
         * Note: This operation Resets the cursor
         */
        void pushTop(NodeEntry *nodeEntry);

        /**
         * Push LinkedListNode at the End
         * Note: This operation Resets the cursor
         */
        void pushEnd(NodeEntry *nodeEntry);
        
        /**
         * POP LinkedListNode from the Top and saves it to popped
         * Note: This operation sets the cursor to Head
         */
        void popTop(NodeEntry* &popped);

        /**
         * POP LinkedListNode from the End and saves it to popped
         * Note: This operation sets the cursor to End
         */
        void popEnd(NodeEntry* &popped);

        /**
         * Insert LinkedListNode at the cursor position
         * Note: This operation moves the cursor to inserted Node
         */
        void insert(NodeEntry *nodeEntry);

        /**
         * Insert LinkedListNode after the cursor position
         * Note: The cursor position will NOT change
         */
        void insertAfter(NodeEntry *nodeEntry);

        /**
         * Insert LinkedListNode before the cursor position
         * Note: The cursor position will change to the inserted Node
         */
        void insertBefore(NodeEntry *nodeEntry);

        /**
         * Remove LinkedListNode at the cursor position
         * Note: This operation moves the cursor to next Node
         */
        void remove();

        /**
         * Move cursor to the next Node
         */
        bool next();

        /**
         * Move cursor to the previous Node
         */
        bool prev();
        
        /**
         * Reset the cursor to head
         */
        void cursorBegin();

        /**
         * Reset the cursor to end
         */
        void cursorEnd();

        /**
         * Returns the number of Elements in the list
         */
        int getCount() const;

        /**
         * Returns true if the list is empty
         */
        int isEmpty() const;

        /**
         * Remove all elements from the List
         */
        void empty();
};

}
#endif