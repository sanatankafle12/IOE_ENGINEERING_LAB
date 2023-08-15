/*Write a program that illustrates the following relationship and comment on them. 

i) const_object.non_const_mem_function

ii) const_object.const_mem_function

iii) non_const_object.non_const_mem_function

iv) non_const_object.const_mem_function
*/


#include <iostream>
using namespace std;

class Relation
{
    const int id;

public:
    Relation(int i) : id(i) {}
    int get() { return id; }
    int const_get() const { return id; }
};

int main()
{
    Relation r(1);
    cout << "non const object calling non const mem func = " << r.get() << endl;
    cout << "non const object calling const mem func = " << r.const_get() << endl;
    const Relation c(2);
    cout << "const object calling const mem func = " << c.const_get();
}