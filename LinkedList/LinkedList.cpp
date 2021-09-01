#include <iostream>
#include <sstream>
#include <string>
#include "./includes/LinkedList.hpp"
#include "./includes/LinkedListNode.hpp"

using namespace std;
using namespace LinkedListCustomImplementation;

void runTests();
void echo(string, int = 1);
string intToString(int);


int main(){
    runTests();
    return 0;
}

void runTests(){
    LinkedList *myLinkedList = new LinkedList;
    LinkedListNode *temporary;


    echo("Nodes Count: ", 0);
    echo(intToString(myLinkedList->getCount()));


    echo("\nFill the List With 5 Nodes.", 2);
    myLinkedList->cursorBegin();
    for(int i = 0; i<5; i++){
        LinkedListNode *n = new LinkedListNode;
        n->setData("Data of Node " + intToString(i+1));
        myLinkedList->insert(n);
    }


    echo("Nodes Count: ", 0);
    echo(intToString(myLinkedList->getCount()), 2);


    echo("Nodes List: ");
    if(!myLinkedList->isEmpty()){
        myLinkedList->cursorBegin();
        do {
            myLinkedList->cursor->print();
        } while (myLinkedList->next());
    }


    echo("\nRemove Node 3 ", 2);
    myLinkedList->cursorBegin();
    myLinkedList->next(); // Move to Node 2
    myLinkedList->next(); // Move to Node 3
    myLinkedList->remove(); // Remove Node 3
    myLinkedList->prev(); // Move To Node 2


    echo("Insert new Node: Middle Node", 2);
    // Insert New Node at current Cursor Position which is 3
    LinkedListNode *middleNode = new LinkedListNode;
    middleNode->setData("Data of Middle Node ");
    myLinkedList->insert(middleNode);


    // ############################### Push New Nodes ##################################

    echo("Push new Node to Top: Node 0", 2);
    LinkedListNode *topNode = new LinkedListNode;
    topNode->setData("Data of Node 0");
    myLinkedList->pushTop(topNode);


    echo("Push new Node to Top: Node -1", 2);
    LinkedListNode *topNode2 = new LinkedListNode;
    topNode2->setData("Data of Node -1");
    myLinkedList->pushTop(topNode2);


    echo("Push new Node to End: Node 6", 2);
    LinkedListNode *endNode = new LinkedListNode;
    endNode->setData("Data of Node 6");
    myLinkedList->pushEnd(endNode);


    echo("Push new Node to End: Node 7", 2);
    LinkedListNode *endNode2 = new LinkedListNode;
    endNode2->setData("Data of Node 7");
    myLinkedList->pushEnd(endNode2);


    echo("Nodes List: ");
    if(!myLinkedList->isEmpty()){
        myLinkedList->cursorBegin();
        do {
            myLinkedList->cursor->print();
        } while (myLinkedList->next());
    }


    // ############################### Pop Nodes ##################################

    echo("\nPop Node from Top: Node -1", 2);
    LinkedListNode *nodeToPop = new LinkedListNode;
    myLinkedList->popTop(nodeToPop);
    echo("Poped Node:");
    nodeToPop->print();


    echo("\nPop Node from End: Node 7", 2);
    LinkedListNode *nodeToPop2 = new LinkedListNode;
    myLinkedList->popEnd(nodeToPop2);
    echo("Poped Node:");
    nodeToPop2->print();


    // ############################### Print Whole List Nodes ##################################

    echo("\nNodes Count: ", 0);
    echo(intToString(myLinkedList->getCount()),2);

    echo("Nodes List: ");
    if(!myLinkedList->isEmpty()){
        myLinkedList->cursorBegin();
        do {
            myLinkedList->cursor->print();
        } while (myLinkedList->next());
    }

    // ############################### Empty the List ##################################

    echo("\nNodes Count before calling myLinkedList->empty: ", 0);
    echo(intToString(myLinkedList->getCount()),2);

    myLinkedList->empty();

    echo("Nodes Count after calling myLinkedList->empty: ", 0);
    echo(intToString(myLinkedList->getCount()),2);

    echo("Nodes List after calling myLinkedList->empty: ");
    if(!myLinkedList->isEmpty()){
        myLinkedList->cursorBegin();
        do {
            myLinkedList->cursor->print();
        } while (myLinkedList->next());
    }

}

void echo(string text, int numberOfNewLines){
    cout << text;
    for(int i=0;i<numberOfNewLines; i++){
        cout << endl;
    }
}

string intToString(int intToConvert){
    std::ostringstream convertedString;
    convertedString << intToConvert;
    return convertedString.str();
}