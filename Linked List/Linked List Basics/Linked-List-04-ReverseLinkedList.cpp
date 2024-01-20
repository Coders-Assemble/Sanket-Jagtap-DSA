#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        Node *next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        Node *next = NULL;
    }
};

int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void insertAtPos(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int len = getLength(head);
    if (position >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    Node *newNode = new Node(data);

    prev->next = newNode;
    newNode->next = curr;
}

Node *reverse(Node *&prev, Node *&curr)
{
    if (curr == NULL)
    {
        return prev;
    }

    Node *forward = curr->next;
    curr->next = prev;

    return reverse(curr, forward);
}

Node *reverseUsingLoop(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node *reverseUsingRecursion(Node *&prev, Node *&curr)
{
    if (curr == NULL)
    {
        return prev;
    }

    Node *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;

    return reverseUsingRecursion(prev, curr);
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtPos(head, tail, 40, 4);
    insertAtPos(head, tail, 50, 5);
    insertAtTail(head, tail, 60);

    print(head);
    cout << endl;

    Node *prev = NULL;
    Node *curr = head;
    // head = reverse(prev, curr);
    // head = reverseUsingLoop(head);
    head = reverseUsingRecursion(prev, curr);
    cout << "Printing after reverse list" << endl;
    print(head);

    return 0;
}