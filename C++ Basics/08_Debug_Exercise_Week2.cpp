#include <iostream>
using namespace std;

int binaryToDecimal(int b) {
  int ans = 0;
  int c = 0;
  while (b) {
    ans = ans + (b % 10) * (1 << c++);
    b /= 10;
  }
  return ans;
}

int main() {

  // 1. Add integers from 1 to N and display the sum on console.
  // int n;
  // cout << "Enter the value of n : ";
  // cin >> n;
  // int sum = 0;
  // for (int i = 0; i < n; i++) {
  //   sum += i;
  // }
  // cout << sum << endl;

  // 2. Print full pyramid like an Equilateral Triangle
  // int n;
  // cout << "Enter the number of rows : ";
  // cin >> n;
  // for (int row = 0; row < n; row++) {

  //   for (int col = 0; col < n - row - 1; col++)
  //     cout << " ";

  //   int start;
  //   for (int col = 0; col < row + 1; col++) {
  //     cout << col + 1;
  //     start = col + 1;
  //     // if (col % 2 == 0) {
  //     //   cout << start;
  //     //   start++;
  //     // } else
  //     //   cout << " ";
  //   }

  //   for (int col = 0; col < row; col++) {
  //     cout << start-1;
  //     start--;
  //   }
  //   cout << endl;
  // }

  // 3. Left Triangle star Pattern
  // size of the triangle
  // int N;
  // cout << "Enter N : ";
  // cin >> N;
  // int size = N;
  // // loop to print the pattern
  // for (int i = 0; i <= size; i++) {
  //   // print column
  //   for (int col = 0; col < i; col++) {
  //     cout << "*";
  //   }
  //   cout << "\n";
  // }

  // 4. Reverse Pyramid star pattern.
  // size of the pyramid
  // int n;
  // cout<<"Enter the n : ";
  // cin >> n;
  // for (int row = 0; row < n; row++) {
  //   // print spaces
  //   for (int col = 0; col < row; col++) {
  //     cout << " ";
  //   }
  //   // print stars
  //   for (int col = 0; col < 2 * (n - row) - 1; col++) {
  //     cout << "*";
  //   }
  //   cout << "\n";
  // }

  // 4. Reverse Pyramid star pattern.
  // e.g., for size=6;
  //  ***   ***
  // ***** *****
  // ***********
  //  *********
  //   *******
  //    *****
  //     ***
  //      *

  // heart star pattern
  // int n;
  // cin >> n;

  // for (int row = n / 2; row < n; row += 2) {
  //   // print first spaces
  //   for (int col = 1; col < n - row; col += 2) {
  //     cout << " ";
  //   }
  //   // print first stars
  //   for (int col = 0; col < row; col++) {
  //     cout << "*";
  //   }
  //   // print second spaces
  //   for (int col = 1; col < n - row + 1; col++) {
  //     cout << " ";
  //   }
  //   // print second stars
  //   for (int col = 1; col < row + 1; col++) {
  //     cout << "*";
  //   }
  //   cout << "\n";
  // }
  // // lower part
  // // inverted pyramid
  // for (int row = 0; row < n; row++) {
  //   // print spaces
  //   for (int col = 0; col < row; col++) {
  //     cout << " ";
  //   }
  //   // print stars
  //   for (int col = 0; col < 2 * (n - row) - 1; col++) {
  //     cout << "*";
  //   }
  //   cout << "\n";
  // }

  // 6. Convert given Binary number to Decimal.
  // int b = 100100111;
  // cout << binaryToDecimal(b) << endl;

  // 7. Simple Calculator
  char oper;
  float num1, num2;
  cout << "Enter an operator (+, -, *, /): ";
  cin >> oper;
  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  switch (oper) {
  case '+':
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    break;
  case '-':
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    break;
  case '*':
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    break;
  case '/':
    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    break;
  default:
    // operator is doesn't match any case constant (+, -, *, /)
    cout << "Error! The operator is not correct";
    break;
  }

  return 0;
}