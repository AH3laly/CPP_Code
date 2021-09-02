#include<string>

#ifndef __LINKED_LIST_GUARD_H
#define __LINKED_LIST_GUARD_H

typedef std::string str;

namespace LinkedListCustomImplementation {

class LinkedList {

    private:
        class LinkedListNode {
            
            public:
                LinkedListNode *next;
                LinkedListNode *prev;
                void setData(str);
                str getData();
                void print();
            
            private:
                str data;
        };

        int count;
        /**
         * Initialize the List with the first Node
         */
        void addFirstNode(LinkedListNode *node);

        /**
         * Reset everything for a new Empty List
         */
        void reset();
        
    public:
        LinkedListNode *cursor, *head, *end, *current;
        LinkedList();
        ~LinkedList();

        /**
         * Push LinkedListNode on the Top
         * Note: This operation Resets the cursor
         */
        void pushTop(LinkedListNode *node);

        /**
         * Push LinkedListNode at the End
         * Note: This operation Resets the cursor
         */
        void pushEnd(LinkedListNode *node);
        
        /**
         * POP LinkedListNode from the Top and saves it to popped
         * Note: This operation sets the cursor to Head
         */
        void popTop(LinkedListNode* &popped);

        /**
         * POP LinkedListNode from the End and saves it to popped
         * Note: This operation sets the cursor to End
         */
        void popEnd(LinkedListNode* &popped);

        /**
         * Insert LinkedListNode at the cursor position
         * Note: This operation moves the cursor to inserted Node
         */
        void insert(LinkedListNode *node);

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
        int getCount();

        /**
         * Returns true if the list is empty
         */
        int isEmpty();

        /**
         * Remove all elements from the List
         */
        void empty();
};

}
#endif