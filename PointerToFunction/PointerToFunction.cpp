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

void print(Student s){
    cout << "Welcome, The information of the sent object is " << endl;
    cout << s.id << " : " << s.name << endl;
}

int main(){

    Student s;
    s.id = 1;
    s.name = "Abdo";

    printStudentInfo(&s, &print);
    
    // OR:
    // Create a pointer to the print function and pass it to printStudentInfo
    //void (*print1) (Student) = print;
    //printStudentInfo(&s, print1);
    
    return 0;
}
