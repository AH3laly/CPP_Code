#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
};

void printStudentInfo(Student *studentToPrint, void(*pf)(Student)){
    pf(*studentToPrint);
}

void print_handler(Student s){
    cout << "Welcome, The information of the sent object is " << endl;
    cout << s.id << " : " << s.name << endl;
}

int main(){

    Student s;
    s.id = 1;
    s.name = "Abdo";

    printStudentInfo(&s, &print_handler);
    
    // OR:
    // Create a pointer to the print_handler function and pass it to printStudentInfo
    //void (*print_handler_ptr) (Student) = print_handler;
    //printStudentInfo(&s, print_handler_ptr);
    
    return 0;
}
