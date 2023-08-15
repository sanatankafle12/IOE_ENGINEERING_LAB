#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 22;
    int index = binarySearch(arr, 0, n - 1, x);
    if (index != -1) {
        cout << "Element " << x << " found at index " << index << endl;
    } else {
        cout << "Element " << x << " not found in the array" << endl;
    }
    return 0;
}