#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 22;
    int index = linearSearch(arr, n, x);
    if (index != -1) {
        cout << "Element " << x << " found at index " << index << endl;
    } else {
        cout << "Element " << x << " not found in the array" << endl;
    }
    return 0;
}