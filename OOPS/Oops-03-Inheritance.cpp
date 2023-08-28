#include <iostream>
using namespace std;

// Inheritance
// Parent class
// class Animal {
//   public:
//   int age;
//   int weight;

//   void eat() {
// 	  cout << "eating" << endl;
//   }
// };

// // Child class
// class Dog : public Animal {
// 	public:
// 	void print(){
// 		cout<<"Dog Class"<<endl;
// 	}
// };

// Single Inheritance
// Parent class
class Car
{
public:
    string name;
    int age;
    int weight;

    void speedUp()
    {
        cout << "Speed Up" << endl;
    }

    void breakMaro()
    {
        cout << "Break Mardia" << endl;
    }
};

// Child class
class Scorpio : public Car
{
public:
    void print()
    {
        cout << "I am Scorpio" << endl;
    }
};

// Multi-level Inheritance
// Parent class
class Fruit
{
public:
    string name;
};

// Child class
class Mango : public Fruit
{
public:
    int weight;
};

// Grand child class
class Alphonso : public Mango
{
public:
    int sugarLevel;
};

// Multiple Inheritance
class A
{
public:
    int physics;
    int chemistry;

    A()
    {
        chemistry = 101;
    }
};

class B
{
public:
    int chemistry;

    B()
    {
        chemistry = 410;
    }
};

class C : public A, public B
{
public:
    int maths;
};

// Hierarchial Inheritance
class Vehicle
{
public:
    int age;
    int weight;
    string name;

    void print()
    {
        cout << "Speeding Up" << endl;
    }
};

class FourWheeler : public Vehicle
{
};

class TwoWheeler : public Vehicle
{
};

int main()
{
    // Inheritance
    // Dog d1;
    // d1.eat();
    // d1.print();

    // Single Inheritance
    // Scorpio s1;
    // cout<< s1.age <<endl;
    // s1.print();

    // Multi-level Inheritance
    // Alphonso a;
    // a.name = "Keshar";
    // a.weight = 50;
    // a.sugarLevel = 20;
    // cout<<a.name<<" "<<a.weight<<" "<<a.sugarLevel<<endl;

    // Multiple Inheritance
    // C obj;
    // cout<<obj.physics<<" "<<obj.A::chemistry<<" "<<obj.B::chemistry<<" "<<obj.maths<<endl;

    // Hierachial Inheritance
    FourWheeler fw11;
    fw11.print();

    TwoWheeler TW11;
    TW11.print();

    return 0;
}