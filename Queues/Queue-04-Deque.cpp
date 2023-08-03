#include <iostream>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 1;
        rear = -1;
    }

    void pushRear(int data)
    {
        // Full Check
        // First Element
        // Circular Nature
        // Normal Flow

        if ((rear == size - 1 && front == 0) || (rear + 1 == front))
        {
            cout << "Queue is Full, Cannot insert element" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }

    void pushFront(int data)
    {
        // Full Check
        // First Element
        // Circular Nature
        // Normal Flow

        if ((rear == size - 1 && front == 0) || (rear + 1 == front))
        {
            cout << "Queue is Full, Cannot insert element" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }

    void popRear()
    {
        // Empty Check
        // Single Element
        // Circular Nature
        // Normal Flow

        if (front == -1)
        {
            cout << "Queue is Empty, Cannot delete element" << endl;
            return;
        }
        else if (front == rear)
        {
            // arr[rear] = -1;
            // front = -1;
            // rear = -1;
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }

    void popFront()
    {
        // Empty Check
        // Single Element
        // Circular Nature
        // Normal Flow

        if (front == -1)
        {
            cout << "Queue is Empty, Cannot delete element" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
};

int main()
{

    return 0;
}
