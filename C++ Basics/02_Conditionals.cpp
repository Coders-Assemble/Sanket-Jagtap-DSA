#include <iostream>
using namespace std;

int main() {
  // int age;
  // cout << "Enter Your Age : ";
  // cin >> age;

  // if
  // if (age > 17) {
  //   cout << "You are eligible for vote." << endl;
  // }
  // cout << "You are not eligible for vote." << endl;

  // if-else
  // if (age > 17) {
  //   cout << "You are eligible for vote." << endl;
  // } else {
  //   cout << "You are not eligible for vote." << endl;
  // }

  // int marks;
  // cout << "Enter Your Marks : ";
  // cin >> marks;

  // Nested if-else
  // if (marks >= 90) {
  //   cout << "A Grade" << endl;
  // } else {
  //   if (marks >= 80) {
  //     cout << "B Grade" << endl;
  //   } else {
  //     if (marks >= 60) {
  //       cout << "C Grade" << endl;
  //     } else {
  //       if (marks >= 40) {
  //         cout << "D Garde" << endl;
  //       } else {
  //         cout << "F Grade" << endl;
  //       }
  //     }
  //   }
  // }

  // ifelse-ifelse
  // if (marks >= 90) {
  //   cout << "A Grade" << endl;
  // } else if (marks >= 80) {
  //   cout << "B Grade" << endl;
  // } else if (marks >= 60) {
  //   cout << "C Grade" << endl;
  // } else if (marks >= 40) {
  //   cout << "D Grade" << endl;
  // } else {
  //   cout << "F Grade" << endl;
  // }

  // Example of if-else
  // int broNum;
  // cin>>broNum;

  // if(broNum == 0){
  //   cout<<"BAAT BANJAYEGI"<<endl;
  // }
  // else{
  //   cout<<"BAAT NHI BANEGI"<<endl;
  // }

  // Switch statement

  int val;
  cout << "Enter value of val: ";
  cin >> val;

  switch (val) {
  case 1:
    cout << "Sanket" << endl;
    break;
  case 2:
    cout << "Suraj" << endl;
    break;
  case 3:
    cout << "Sunny" << endl;
    break;
  case 4:
    cout << "Pranjal" << endl;
    break;
  case 5:
    cout << "Payal" << endl;
    break;
  case 6:
    cout << "Shreyas" << endl;
    break;
  case 7:
    cout << "Pragati" << endl;
    break;
  default:
    cout << "Riya" << endl;
  }

  return 0;
}