#include <iostream>
#include <vector>
using namespace std;


int Bin_search_simple(int arr[], int right, int key) {
    int left = 0;
    int mid = 0;
    while (true) {
        mid = (left + right) / 2;
        if (key < arr[mid])
            right = mid - 1;
        else if (key > arr[mid])
            left = mid + 1;
        else
            return mid;
        if (left > right)
            return -1;
    }
}

int Bin_search_recursion(int arr[], int left, int right, int key) {
    int mid = (left + right) / 2;
    if (left > right)
        return -1;
    if (key < arr[mid])
       return Bin_search_recursion(arr, left, mid - 1, key);
    else if (key > arr[mid])
       return Bin_search_recursion(arr, mid + 1, right, key);
    else
        return mid;

}

int main() {
    int SIZE, index, left, right, key;
    cout << "Enter the length of the array: ";
    cin >> SIZE;
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++) {
        arr[i] = (i + 1) * 2;
        cout << arr[i] << " ";
    }
    cout << '\n'<<"Enter the value that you want to find: ";
    cin >> key;
    cout << "This value is located under the index: " << Bin_search_simple(arr, SIZE, key) << '\n';
    cout << "Using recursion function:" << Bin_search_recursion(arr, 0, SIZE, key);

};