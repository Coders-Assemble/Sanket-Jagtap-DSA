#include <iostream>
using namespace std;

// Encapsulation
// When all data members are marked as private -> Perfect Encapsulation

class Animal
{
private:
    int age;
    int weight;

public:
    void eat() { cout << "Eating" << endl; }

    int getAge() { return age; }

    void setAge(int age) { this->age = age; }
};

int main()
{
    // Encapsulation
    Animal Tommy;
    Tommy.setAge(12);
    cout << "Age of Tommy is : " << Tommy.getAge() << endl;

    return 0;
}