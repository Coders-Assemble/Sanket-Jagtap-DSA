#include <iostream>
#include <queue>
using namespace std;

int main()
{

    // Creation
    queue<int> q;

    // Insertion
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    // Size
    cout << "Size of queue: " << q.size() << endl;

    // Removal
    q.pop();
    cout << "Size of queue: " << q.size() << endl;

    // Empty
    if (q.empty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is NOT Empty" << endl;
    }

    // Front
    cout << "Front Element is: " << q.front() << endl;

    return 0;
}