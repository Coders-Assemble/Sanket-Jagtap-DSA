#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() { cout << "Deleting node with value " << this->data << endl; }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node *head)
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

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // If LL is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // If LL is non-empty;
        // Step 1 - Create a new node
        Node *newNode = new Node(data);

        // Step 2 - Connect newNode next to head
        newNode->next = head;

        // Step 3 - Connect head prev to newNode
        head->prev = newNode;

        // Step 4 - Make newNode as head
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Not working properly
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        // LL is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is not-empty
        if (position == 1)
        {
            // i.e insertAtHead
            insertAtHead(head, tail, data);
            return;
        }

        int len = getLength(head);
        if (position > len)
        {
            insertAtTail(head, tail, data);
            return;
        }

        // Step 1 - Find prevNode and currNode
        int i = 1;
        Node *prevNode = head;
        if (i < position - 1)
        {
            prevNode = prevNode->next;
            i++;
        }
        Node *currNode = prevNode->next;

        // Step 2 - Create newNode
        Node *newNode = new Node(data);

        // Step 3 - Connect prevNode next to newNode
        prevNode->next = newNode;

        // Step 4 - Connect newNode prev to prevNode
        newNode->prev = prevNode;

        // Step 5 - Connect newNode next to currNode
        newNode->next = currNode;

        // Step 6 - Connect currNode prev to newNode
        currNode->prev = newNode;
    }
}

void deleteFromPos(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    // LL with only one node
    if (head->next == NULL)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    // Invalid position
    int len = getLength(head);
    if (position > len)
    {
        cout << "Enter valid position" << endl;
    }

    // Delete first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    // Delete last node
    if (position == len)
    {
        Node *temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }

    // Delete middle node
    int i = 1;
    Node *left = head;
    while (i < position - 1)
    {
        left = left->next;
        i++;
    }

    Node *curr = left->next;
    Node *right = curr->next;

    left->next = right;
    right->prev = left;
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);
    cout << endl;
    int len = getLength(first);
    cout << "Length of Linked List is: " << len << endl;

    cout << endl
         << "After inserting at head" << endl;
    insertAtHead(head, tail, 44);

    print(head);
    cout << endl;
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    cout << endl
         << "After inserting at tail" << endl;
    insertAtTail(head, tail, 101);

    print(head);
    cout << endl;
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    cout << endl
         << "After inserting at Middle" << endl;
    insertAtPosition(head, tail, 401, 4);

    print(head);
    cout << endl;
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
    cout << endl;

    print(head);
    cout << endl;

    deleteFromPos(head, tail, 4);

    print(head);

    return 0;
}