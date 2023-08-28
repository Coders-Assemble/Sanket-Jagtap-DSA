#include <iostream>
using namespace std;

class Animal
{
private:
    int weight;

public:
    // State / Properties / Data members
    int age;
    string name;

    // Constructor
    // Default constructor
    Animal()
    {
        this->age = 0;
        this->weight = 0;
        this->name = "";
        cout << "Constructor Called" << endl;
    }

    // Parameterised Constructor
    Animal(int age)
    {
        this->age = age;
        cout << "Parameterised Constructor Called" << endl;
    }

    Animal(int age, int weight)
    {
        this->age = age;
        this->weight = weight;
        cout << "Parameterised Constructor 2 Called" << endl;
    }

    Animal(int age, int weight, string name)
    {
        this->age = age;
        this->weight = weight;
        this->name = name;
        cout << "Parameterised Constructor 3 Called" << endl;
    }

    // Copy Constructor
    Animal(Animal &obj)
    {
        this->age = obj.age;
        this->weight = obj.weight;
        this->name = obj.name;
        cout << "I am inside copy constructor" << endl;
    }

    // Behaviour / Method / Menmber functions
    void eat() { cout << "Eating" << endl; }

    void sleep() { cout << "Sleeping" << endl; }

    int getWeight() { return weight; }

    // void setWeight(int w) { weight = w; }
    void setWeight(int weight) { this->weight = weight; }

    ~Animal() { cout << "Destructor is called" << endl; }
};

int main()
{
    // cout << "Size of empty class: " << sizeof(Animal) << endl;

    // // Static
    // Animal wild;
    // wild.age = 12;
    // wild.name = "Lion";

    // cout << "Age : " << wild.age << endl;
    // cout << "Name : " << wild.name << endl;

    // // To access private members
    // wild.setWeight(101);
    // cout << "Weight : " << wild.getWeight() << endl;

    // wild.eat();
    // wild.sleep();

    // // Dynamic memory allocation

    // Animal *pet = new Animal;

    // (*pet).age = 15;
    // (*pet).name = "Cat";
    // cout << "Age : " << (*pet).age << endl;
    // cout << "Name : " << (*pet).name << endl;

    // // Alternate -> dynamic

    // pet->age = 17;
    // pet->name = "Dog";
    // cout << "Age : " << pet->age << endl;
    // cout << "Name : " << pet->name << endl;

    // delete pet;

    // Animal a;
    // Animal *b = new Animal;

    // Animal a(10);
    // Animal *b = new Animal(20);

    // Animal a(10, 20);
    // Animal *b = new Animal(20, 40);

    // Animal a(10, 20, "Mani");
    // Animal *b = new Animal(20, 40, "Tommy");

    // Animal a(10, 20, "Manni");
    // Animal *b = new Animal(20, 40, "Tommy");
    // Animal c = a;

    // Animal d(*b);

    cout << "a obj creation" << endl;
    Animal a;
    a.age = 12;

    cout << "b obj creation" << endl;
    Animal *b = new Animal();
    b->age = 14;

    // Manually destructor is called in case of dynamic
    delete b;

    return 0;
}