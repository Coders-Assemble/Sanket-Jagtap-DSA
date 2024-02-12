#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_front(10);
    dq.push_front(5);
    dq.push_back(15);
    dq.push_back(20);

    cout << "Size: " << dq.size() << endl;

    dq.pop_front();

    cout << "Size: " << dq.size() << endl;

    dq.pop_back();

    cout << "Size: " << dq.size() << endl;

    cout << "Front: " << dq.front() << endl;

    cout << "Back: " << dq.back() << endl;

    if (dq.empty())
    {
        cout << "Dq is empty" << endl;
    }
    else
    {
        cout << "Dq is not empty" << endl;
    }

    return 0;
}
