#include <iostream>
using namespace std;

int main() {

  // BITWISE OPERATORS

  // If both the values are true
  // bool a = true;
  // bool b = true;

  // cout << (a & b) << endl;
  // cout << (a | b) << endl;
  // cout << (!a) << endl;
  // cout << (!b) << endl;
  // cout << (a ^ b) << endl;

  // If one value is true and other is false
  // bool a = true;
  // bool a = false;
  // bool b = false;
  // bool b = true;

  // cout << (a & b) << endl;
  // cout << (a | b) << endl;
  // cout << (!a) << endl;
  // cout << (!b) << endl;
  // cout << (a ^ b) << endl;

  // If both the values are false
  // bool a = false;
  // bool b = false;

  // cout << (a & b) << endl;
  // cout << (a | b) << endl;
  // cout << (!a) << endl;
  // cout << (!b) << endl;
  // cout << (a ^ b) << endl;

  // cout << (2 & 3) << endl;
  // cout << (5 & 10) << endl;

  // Left shift operator
  // int x = 2;
  // x = x << 3;
  // cout << x << endl;

  // Right shift operator
  // int x = 24;
  // x = x >> 3;
  // cout << x << endl

  // PRE/POST INCREMENT/DECREMENT OPERATORS
  // Pre increment
  // int y = 5;
  // cout << ++y << endl;
  // cout << y << endl;

  // int i = 5;
  // int c = ++i + 1;
  // cout << c << endl;

  // Post increment
  // int y = 5;
  // cout << y++ << endl;
  // cout << y << endl;

  // int i = 5;
  // int c = i++ + 1;
  // cout << c << endl;

  // Pre decrement 
  // int a = 5;
  // int b = 4;
  // int c = (--a)*(--b);
  // cout<<c<<endl;

  // Post decrement
  int a = 5;
  int b = 4;
  int c = (a--)*(b--);
  cout<<c<<endl;

  return 0;
}