//Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers are" and another should contain " Creatures of logic". Member function join() should concatenate two strings by passing two objects as arguments. Display the concatenated string through a member function. Use constructors to allocate and initialize the data member. Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two strings.

#include <iostream>
#include <cstring>
using namespace std;

class StringConcat {
private:
    char* str;

public:
    StringConcat(const char* s = "") {
        int len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    StringConcat(const StringConcat& s) {
        int len = strlen(s.str);
        str = new char[len + 1];
        strcpy(str, s.str);
    }

    ~StringConcat() {
        delete[] str;
    }

    void join(const StringConcat& s1, const StringConcat& s2) {
        int len1 = strlen(s1.str);
        int len2 = strlen(s2.str);
        str = new char[len1 + len2 + 1];
        strcpy(str, s1.str);
        strcat(str, s2.str);
    }

    void display() {
        cout << str << endl;
    }
};

int main() {
    StringConcat s1("Engineers are");
    StringConcat s2(" Creatures of logic");
    StringConcat s3;
    s3.join(s1, s2);

    s3.display();

    return 0;
}