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
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node() { cout << "Node with value " << this->data << " deleted" << endl; }
};

// Here we are inserting a new node right at head of LL
void insertAtHead(Node *&head, Node *&tail, int data)
{

    // If Linked List is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If Linked List is not empty
    // Step 1 - Create new node
    Node *newNode = new Node(data);

    // Step 2 - Connect the next pointer of newNode to head
    newNode->next = head;

    // Step 3 - Make the head to newNode because now newNode is first node
    head = newNode;
}

// Here we are inserting a new node right at end of LL
void insertAtTail(Node *&head, Node *&tail, int data)
{

    // If Linked List is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If Linked List is not empty
    // Step 1 - Create new node
    Node *newNode = new Node(data);

    // Step 2 - Connect the tail next of current tail to newNode
    tail->next = newNode;

    // Step 3 - Make newNode as tail because now newNode is at tail
    tail = newNode;
}

int findLength(Node *&head)
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

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If position is 0 then insert node at head
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // If position is greater than or equal to length of LL then insert node at
    // tail
    int len = findLength(head);
    if (position >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // Step 1 - Find the prev and curr
    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // Step 2 - Create a new Node
    Node *newNode = new Node(data);

    // Step 3 - Connect newNode next to curr
    newNode->next = curr;

    // Step 4 - Connect prev next to newNode
    prev->next = newNode;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "Can't delete because LL is empty";
        return;
    }

    // Deleting first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // Deleting last node
    int len = findLength(head);
    while (position == len)
    {
        // Step 1 - Find prev
        int i = 1;
        Node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }

        // Step 2 - Point prev next to NULL
        prev->next = NULL;

        // Step 3 - Create temp point to head
        Node *temp = tail;

        // Step 4 - Make tail as prev
        tail = prev;

        // Step 5 = Delete temp
        delete temp;
        return;
    }

    // Deleting middle node
    // Step 1 - Find prev and curr
    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // Step 2 - Point prev next to curr next
    prev->next = curr->next;

    // Step 3 - Point curr next to NULL
    curr->next = NULL;

    // Step 4 - Delete curr
    delete curr;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtTail(head, tail, 10);

    print(head);
    cout << endl;
    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;

    // insertAtPosition(head, tail, 0, 101);

    // print(head);
    // cout << endl;
    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;

    deleteNode(head, tail, 5);
    print(head);
    cout << endl;

    return 0;
}