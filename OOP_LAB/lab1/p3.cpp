//Store and retrieve the name of the students and obtained marks in c programming in 1st semester using structure.

#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 50;

struct Student {
    string name;
    int marks[5];
};

int main() {
    Student students[MAX_STUDENTS];
    int num_students;
    
    cout << "Enter the number of students: ";
    cin >> num_students;
    
    // Input student names and marks
    for (int i = 0; i < num_students; i++) {
        cout << "\nEnter the name of student " << i+1 << ": ";
        cin >> students[i].name;
        
        cout << "Enter the marks obtained by " << students[i].name << " in 5 subjects:\n";
        for (int j = 0; j < 5; j++) {
            cout << "Subject " << j+1 << ": ";
            cin >> students[i].marks[j];
        }
    }
    
    // Output student names and marks
    cout << "\nNames and marks of the students:\n";
    for (int i = 0; i < num_students; i++) {
        cout << "\nStudent " << i+1 << ": " << students[i].name << endl;
        cout << "Marks: ";
        for (int j = 0; j < 5; j++) {
            cout << students[i].marks[j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}