#include <iostream>
#include <stack>
using namespace std;

// Node Class
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor to initialize a node
    Node(int data) : data(data), next(nullptr), prev(nullptr) {};

    // Constructor to initialize a node with next and prev pointers
    Node(int data, Node *next, Node *prev) : data(data), next(next), prev(prev) {};
};

// Doubly Linked List Class
class DoublyLinkedList
{
private:
    Node *head; // pointer to head node

public:
    // Constructor to initialize head to nullptr
    DoublyLinkedList()
    {
        head = nullptr;
    }

    // Destructor to free memory
    ~DoublyLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = temp->next;
            delete temp;
        }
    }

    // Function to convert array to doubly linked list
    void convertArray2Dll(vector<int> &arr)
    {
        if (arr.empty())
        {
            head = nullptr;
            cout << "Array is Empty to Covert!" << endl;
            return;
        }
        head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < arr.size(); i++)
        {
            temp->next = new Node(arr[i], nullptr, temp);
            temp = temp->next;
        }
    }

    // Functions to reverse a doubly linked list

    void reverseDllBruteForce(); // brute force
    void reverseDll();           // optimal

    // Function to display the doubly linked list
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
            return;
        }
        Node *temp = head;
        cout << "nullptr <-> ";
        while (temp != nullptr)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

// EXTREME BRUTE FORCE
void DoublyLinkedList ::reverseDllBruteForce()
{

    stack<int> nodeData;
    Node *temp = head;
    while (temp != nullptr)
    {
        nodeData.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr)
    {

        temp->data = nodeData.top();
        nodeData.pop();
        temp = temp->next;
    }
}

// OPTIMAL APPROACH
void DoublyLinkedList ::reverseDll()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    Node *current = head;
    Node *prevNode = nullptr;
    Node *newHead = nullptr;
    while (current != nullptr)
    {
        prevNode = current->prev;       // pointer to previous node
        Node *nextNode = current->next; // pointer to next node
        current->prev = current->next;  // swapping prev node with next
        current->next = prevNode;       // swapping next with prev node
        current = nextNode;             // incrementing current with next node
    }
    if (prevNode != nullptr)
    {
        head = prevNode->prev;
    }
};
int main()
{
    DoublyLinkedList dll, dll2;
    vector<int> arr = {1, 2, 3, 4, 5};
    dll.convertArray2Dll(arr);
    dll.display();
    dll.reverseDll();
    dll.display();

    dll.reverseDllBruteForce();
    dll.display();
    return 0;
}

// TIME AND SPACE COMPLEXITY

// BRUTE FORCE
//  Time Complexity : O(2N); N = Lenght of List
//                     As we traverse the list twice once for data storage;
//                     other for data assignment.
//  Space Complexity : O(N); N = Length of List
//                     As we use stack to store the data of every node for late asisgnment.

// OPTIMAL APPROACH
//  Time Complexity : O(N); N = Lenght of List
//                     As we traverse the list only once and swap prev & next pointe
//  Space Complexity : O(1)
//                     No extra space used.
