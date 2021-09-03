#include <iostream>
#include <sstream>
#include <string>
#include "./includes/LinkedList.hpp"
#include "./includes/types.hpp"

using namespace std;
using namespace LinkedListCustomImplementation;



void runTests();
void echo(string, int = 1);
string intToString(int);
void printNodes(NodeEntry*);

int main(){
    runTests();
    return 0;
}

void printNodes(NodeEntry *node){
    cout << *node << endl;
}

void runTests(){
    LinkedList *myLinkedList = new LinkedList;

    echo("Try to use Depricated method 'insert' ", 1);
    try{
        NodeEntry *tempNode = new NodeEntry;
        *tempNode = "Hello World";
        myLinkedList->insert(tempNode);
    }catch(const char* error){
        echo(error, 2);
    }


    echo("Nodes Count: ", 0);
    echo(intToString(myLinkedList->getCount()));


    echo("\nFill the List With 5 Nodes.", 2);
    myLinkedList->cursorBegin();
    for(int i = 0; i<5; i++){
        NodeEntry *e = new NodeEntry;
        *e = "Hello World";
        myLinkedList->insertBefore(e);
    }


    echo("Nodes Count: ", 0);
    echo(intToString(myLinkedList->getCount()), 2);


    echo("Nodes List: ");
    myLinkedList->traverse(&printNodes);


    echo("\nRemove Node 3 ", 2);
    myLinkedList->cursorBegin();
    myLinkedList->next(); // Move to Node 2
    myLinkedList->next(); // Move to Node 3
    myLinkedList->remove(); // Remove Node 3
    myLinkedList->prev(); // Move To Node 2


    echo("Insert new Node: Middle Node", 2);
    // Insert New Node at current Cursor Position which is 3
    NodeEntry *middleNode = new NodeEntry;
    *middleNode = "Hello World";
    myLinkedList->insertAfter(middleNode);


    // ############################### Push New Nodes ##################################

    echo("Push new Node to Top: Node 0", 2);
    NodeEntry *topNode = new NodeEntry;
    *topNode = "Hello World";
    myLinkedList->pushTop(topNode);


    echo("Push new Node to Top: Node -1", 2);
    NodeEntry *topNode2 = new NodeEntry;
    *topNode2 = "Data of Node -1";
    myLinkedList->pushTop(topNode2);


    echo("Push new Node to End: Node 6", 2);
    NodeEntry *endNode = new NodeEntry;
    *endNode = "Data of Node 6";
    myLinkedList->pushEnd(endNode);


    echo("Push new Node to End: Node 7", 2);
    NodeEntry *endNode2 = new NodeEntry;
    *endNode2 = "Data of Node 7";
    myLinkedList->pushEnd(endNode2);


    echo("Nodes List: ");
    myLinkedList->traverse(&printNodes);


    // ############################### Pop Nodes ##################################

    echo("\nPop Node from Top: Node -1", 2);
    NodeEntry *nodeToPop = new NodeEntry;
    myLinkedList->popTop(nodeToPop);
    echo("Poped Node:");
    echo(*nodeToPop);


    echo("\nPop Node from End: Node 7", 2);
    NodeEntry *nodeToPop2 = new NodeEntry;
    myLinkedList->popEnd(nodeToPop2);
    echo("Poped Node:");
    echo(*nodeToPop2);


    // ############################### Print Whole List Nodes ##################################

    echo("\nNodes Count: ", 0);
    echo(intToString(myLinkedList->getCount()),2);

    echo("Nodes List: ");
    myLinkedList->traverse(&printNodes);

    // ############################### Empty the List ##################################

    echo("\nNodes Count before calling myLinkedList->empty: ", 0);
    echo(intToString(myLinkedList->getCount()),2);

    myLinkedList->empty();

    echo("Nodes Count after calling myLinkedList->empty: ", 0);
    echo(intToString(myLinkedList->getCount()),2);

    echo("Nodes List after calling myLinkedList->empty: ");
    myLinkedList->traverse(&printNodes);

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