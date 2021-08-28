#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Student {
    int id;
    string name;
    string email;
};

void printStudentInfo(Student *studentToPrint, void(*pf)(Student)){
    pf(*studentToPrint);
}

void print_handler(Student s){
    cout << s.id << " : " << s.name << s.email << endl;
}

int main(){

    Student students[20];

    // Fill Students Array
    for(int i=0; i<20; i++){
        Student s;
        std::ostringstream studentId;
        studentId << i;
        s.id = i;
        s.name = "Student " + studentId.str();
        s.email = "Student " + studentId.str() + "@example.com";
        students[i] = s;
    }
    
    // Print Studentws Array
    for(int i=0; i<20; i++){
        printStudentInfo(&students[i], &print_handler);

        // OR:
        // Create a pointer to the print_handler function and pass it to printStudentInfo
        //void (*print_handler_ptr) (Student) = print_handler;
        //printStudentInfo(&students[i], print_handler_ptr);
    }
    
    return 0;
}
