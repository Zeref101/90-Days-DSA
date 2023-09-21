## CODE
```cpp
#include <iostream>
using namespace std;
```
* These lines include the necessary header files and define the namespace to be used in the code.
```cpp
int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}
```
## EXPLAINATION
* This function implements the partition step of the quicksort algorithm. It takes an array arr , a starting index start , and an ending index end.It selects the last element of the array as the pivot, and then partitions the array into two parts: elements smaller than the pivot and elements greater than the pivot. It returns the index of the pivot element after partitioning.

```cpp
void quickSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int pivotIndex = partition(arr, start, end);
    quickSort(arr, start, pivotIndex-1);
    quickSort(arr, pivotIndex+1, end);
}
```
* This function implements the quicksort algorithm. It takes an array arr , a starting index start , and an ending index end . It first checks if the array has more than one element, and if not, it returns. Otherwise, it calls the partition function to partition the array around a pivot element, and then recursively calls itself on the left and right subarrays.
```cpp
int main() {
    int arr[] = {0, 1, 5, 2, 88, 45, 1213, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size-1);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```
* This is the main function that creates an array of integers, calls the quickSort  function to sort the array, and then prints the sorted array to the  console. It first calculates the size of the array using the sizeof  operator, and then passes the array and its size to the quickSort  function.Finally, it uses a loop to print each element of the sorted array to the console, followed by a newline character for better formatting.
