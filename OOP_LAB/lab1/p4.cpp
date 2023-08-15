//Write a program to read name, rollno, address, and phone number of each student in your class using structure. 
//Store the information in file so that you can recover the information later. 
//While recovering the information from the file sort the information alphabetically according to the name.

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int rollno;
    string address;
    string phone;
};

bool compareByName(const Student& s1, const Student& s2) {
    return s1.name < s2.name;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name, rollno, address, and phone number of student " << i+1 << ": ";
        cin >> students[i].name >> students[i].rollno >> students[i].address >> students[i].phone;
    }

    ofstream outFile("students.txt");

    for (int i = 0; i < n; i++) {
        outFile << students[i].name << " " << students[i].rollno << " " << students[i].address << " " << students[i].phone << endl;
    }

    outFile.close();

    ifstream inFile("students.txt");

    Student* studentsFromFile = new Student[n];

    for (int i = 0; i < n; i++) {
        inFile>> studentsFromFile[i].name >> studentsFromFile[i].rollno >> studentsFromFile[i].address >> studentsFromFile[i].phone;
    }

    sort(studentsFromFile, studentsFromFile+n, compareByName);

    cout << "Student information sorted by name: " << endl;
    for (int i = 0; i < n; i++) {
        cout << studentsFromFile[i].name << " " << studentsFromFile[i].rollno << " " << studentsFromFile[i].address << " " << studentsFromFile[i].phone << endl;
    }

    inFile.close();

    delete[] students;
    delete[] studentsFromFile;

    return 0;
}