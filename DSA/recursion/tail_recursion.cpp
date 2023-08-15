#include <iostream>
using namespace std;

int factorial(int n, int result = 1) {
    if (n == 0) {
        return result;
    }
    return factorial(n - 1, n * result);
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}