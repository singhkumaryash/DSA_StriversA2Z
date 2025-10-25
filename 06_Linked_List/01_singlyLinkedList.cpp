#include <iostream>
using namespace std;

// Singly Linked List Node
class Node
{
public:
    int data;   // data
    Node *next; // pointer to next node

    // Constructor to initialize a node with data only
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    // Constructor to initialize a node with next pointer
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// Singly Linked List Class
class SinglyLinkedList
{
    Node *head; // pointer to head node

public:
    // Constructor to initialize head to nullptr
    SinglyLinkedList()
    {
        head = nullptr;
    }

    // Destructor to free memory
    ~SinglyLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = temp->next;
            delete temp;
        }
    }
    // Function to insert at head
    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        head = newNode;
        newNode->next = temp;
    }

    // Function to delete the tail node
    void deleteTail()
    {
        // if list is empty
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
            return;
        }
        // if list has only one node
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        // fi list has more than one node
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Function to display the linked list
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        else
        {

            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
    }

    // Function to get lenght of linked list
    int lengthOfLinkedList()
    {
        int lenght = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            lenght++;
            temp = temp->next;
        }
        return lenght;
    }

    // Function to search a value in linked list
    bool search(int value)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }
};
int main()
{
    SinglyLinkedList sll;
    sll.insertAtHead(10);
    sll.insertAtHead(90);
    sll.insertAtHead(67);
    sll.insertAtHead(78);
    sll.deleteTail();
    sll.display();
    cout << (sll.lengthOfLinkedList()) << endl;
    cout << (sll.search(0)) << endl;
    cout << (sll.search(90)) << endl;
    return 0;
}