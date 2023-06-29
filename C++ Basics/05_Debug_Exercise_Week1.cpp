#include <iostream>
using namespace std;

int main()
{

    // 1. The below code snippet has some errors. Let’s debug it and make it
    // compile & run successfully. int i = 0; i = i + 1; cout << i << endl;
    // /* print i */
    // // i=i+1;
    // cout << ++i << endl;

    // 2. Below code should print the sum of ‘i’ and ‘j’.
    // short i = 2300, j = 4322;
    // cout << "i+j = " << (i + j) << endl;

    // 3. Find perimeter of a rectangle.
    // float l, b;
    // float P = 2 * (l + b);
    // cout << "Perimeter = " << P << endl;

    // 4. Print solid square pattern.
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     cout << "* ";
    //   }
    //   cout << endl;
    // }

    // 5. Check given number is Prime or not.
    int n;
    cin >> n;
    bool isPrime = true;
    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      cout << "Prime" << endl;
    } else {
      cout << "Not Prime" << endl;
    }

    // 6. Print Numeric Hollow Inverted Half Pyramid
    //   int n;
    //   cin >> n;
    //   for (int row = 0; row < n; row++) {
    //     if (row == 0) {
    //       for (int col = 0; col<n; col++){
    //          cout<<col+1;
    //       }
    //     } else {
    //       cout<<
    //     }
    //     cout << endl;
    //   }

    return 0;
}