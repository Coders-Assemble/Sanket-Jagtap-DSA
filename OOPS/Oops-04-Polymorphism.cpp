#include <iostream>
using namespace std;

// Compile time polymorphism
// Function overloading
class Maths
{
public:
    int sum(int a, int b)
    {
        cout << "I am inside first signature" << endl;
        return a + b;
    }

    int sum(int a, int b, int c)
    {
        cout << "I am inside second signature" << endl;
        return a + b + c;
    }

    int sum(int a, float b)
    {
        cout << "I am inside third signature" << endl;
        return a + b + 10;
    }
};

// Operator overloading
class Param
{
public:
    int val;

    void operator+(Param &obj2)
    {
        int value1 = this->val;
        int value2 = obj2.val;
        cout << (value1 - value2) << endl;
    }
};

// Runtime polymorphism
// Function overriding

class Animal
{
public:
    Animal()
    {
        cout << "I am inside Animal class" << endl;
    }

    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog()
    {
        cout << "I am inside Dog class" << endl;
    }

    // Overriding
    void speak()
    {
        cout << "Barking" << endl;
    }
};

int main()
{
    // Compile time polymorphism
    // Function overloading
    // Maths obj;

    // cout<<obj.sum(5, 3.4f)<<endl;

    // Operator overloading
    // Param object1, object2;

    // object1.val = 7;
    // object2.val = 2;

    // // This should give difference between two objects
    // object1 + object2;

    // Runtime polymorphism
    // Function overriding
    // Dog a;
    // a.speak();

    // Dynamic
    // Animal* a = new Animal();
    // a->speak();

    // Dog* b = new Dog();
    // b->speak();

    // // UpCasting
    // Animal* c = new Dog();
    // c->speak();

    // // DownCasting
    // Dog* d = (Dog*) new Animal();
    // d->speak();

    Animal *a = new Animal();
    Dog *b = new Dog();
    Animal *c = new Dog();
    Dog *d = (Dog *)new Animal();

    return 0;
}