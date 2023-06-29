#include <iostream>
using namespace std;

int main() {

  // For loop
  // for(int i=0; i<5; i++){
  //   cout<<"Sanket Jagtap"<<endl;
  // }

  // for(int i=0; i<5; i++){
  //   cout<<i<<endl;
  // }

  // for(int i=10; i>0; i--){
  //   cout<<i<<endl;
  // }

  // for(int i=1; i<=10; i++){
  //   cout<<2*i<<endl;
  // }

  // for(int i=0; i<=5; i+=2){
  //   cout<<i<<endl;
  // }

  //  for(int i=1; i<=5; i+=2){
  //   cout<<i<<endl;
  // }

  //  for(int i=1; i<10; i*=2){
  //   cout<<i<<endl;
  // }

  // for (int i = 100; i > 0; i /= 2) {
  //   cout << i << endl;
  // }

  // int i = 0;
  // for (;;) {
  //   if (i < 5) {
  //     cout << i << endl;
  //     i++;
  //   }
  // }

  // Break and Continue Keywords
  // for (int i = 0; i < 5; i++) {
  //   cout << "Sanket ";
  //   break;
  // }
  // cout << "Jagtap" << endl;

  // for (int i = 0; i < 5; i++) {
  //   if (i == 2) {
  //     continue;
  //   }
  //   cout << "Sanket"<<endl;
  // }
  // cout << "Jagtap" << endl;

  // Variable Scoping

  // Variable a declaration
  int a;

  // Variable b initialization
  int b = 5;

  b = 10;

  if (true) {
    int b = 15;

    cout << b << endl;
  }

  cout << b << endl;

  return 0;
}