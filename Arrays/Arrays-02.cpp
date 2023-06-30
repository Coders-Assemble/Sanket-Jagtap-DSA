#include <iostream>
#include <limits.h>
using namespace std;

bool findElement(int arr[], int size, int key) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      return true;
    }
  }
  return false;
}

int main() {

  // Linear Search
  // int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // int size = 9;

  // int key;
  // cout << "Enter Key: ";
  // cin >> key;

  // if (findElement(arr, size, key)) {
  //   cout << "Element Found" << endl;
  // } else {
  //   cout << "Element Not Found" << endl;
  // }

  // Counting Zero's and one's
  // int arr[] = {0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0};
  // int size = 13;

  // int countZero = 0;
  // int countOne = 0;

  // for (int i = 0; i < 13; i++) {
  //   if (arr[i] == 0) {
  //     countZero++;
  //   }

  //   if (arr[i] == 1) {
  //     countOne++;
  //   }
  // }

  // cout << "Count of Zero's : " << countZero << endl;
  // cout << "Count of One's : " << countOne << endl;

  // Maximum number in an array
  // int arr[] = {4, 8, 12, 5, 7, 3, 45, 14};
  // int size = 8;

  // int maxi = INT_MIN;
  // for (int i = 0; i < size; i++) {
  //   if (arr[i] > maxi) {
  //     maxi = arr[i];
  //   }
  // }

  // cout << "Maximum number is : " << maxi << endl;

  // Minimum number in an array
  // int arr[] = {4, 8, 12, 5, 7, 3, 45, 14};
  // int size = 8;

  // int mini = INT_MAX;
  // for (int i = 0; i < size; i++) {
  //   if (arr[i] < mini) {
  //     mini = arr[i];
  //   }
  // }

  // cout << "Minimum number is : " << mini << endl;

  // Extreme Values
  // int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  // int size = 9;

  // int start = 0;
  // int end = size - 1;

  // while (start <= end) {
  //   if (start == end) {
  //     cout << arr[start] << " ";
  //   } else {
  //     cout << arr[start] << " ";
  //     cout << arr[end] << " ";
  //   }

  //   start++;
  //   end--;
  // }

  // Reversing array
  int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
  int size = 8;

  int start = 0;
  int end = size - 1;

  while (start <= end) {

    swap(arr[start], arr[end]);
    start++;
    end--;
  }
  // Printing array
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}