#include <iostream>
#include <queue>
using namespace std;

class CircularQueue
{
public:
    int size;
    int *arr;
    int front;
    int rear;

    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        // Queue is Full
        // Inserting First element
        // Circular nature
        // normal flow

        if (front == 0 && rear == size - 1)
        {
            cout << "Queue is Full, Can't insert element";
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pop()
    {
        // Queue is Empty
        // Removing First element
        // Circular nature
        // normal flow

        if (front == -1)
        {
            cout << "Queue is Empty, Can't remove element";
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
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
    // Queue is Full
    // CircularQueue q(5);

    // for (int i = 0; i < 5; i++)
    // {
    //     q.push(i);
    // }

    // // This should fail because the queue is full.
    // q.push(6);

    // Inserting First Element
    // CircularQueue q(5);

    // q.push(1); // This should succeed because the queue is empty.

    // Circular Nature
    // CircularQueue q(5);

    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5); // This should succeed because the queue is circular.

    // Normal Flow
    CircularQueue q(5);

    q.push(1);
    q.push(2);
    q.pop();
    q.push(3);
    q.pop();
    q.pop();
    q.pop(); // This should fail because the queue is empty.

    return 0;
}