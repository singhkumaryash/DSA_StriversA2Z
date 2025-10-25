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
        newNode->next = head;
        head = newNode;
    }

    // Function to insert at tail
    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to insert value at a given psoition K
    void insertAtK(int value, int k)
    {
        if (k < 1)
        {
            cout << "Invalid Index!" << endl;
            return;
        }
        if (k == 1)
        {
            insertAtHead(value);
            return;
        }
        int count = 1;
        Node *temp = head;
        while (count < k - 1 && temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr)
        {
            cout << "Index out of bound!" << endl;
            return;
        }
        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to insert before a given value
    void insertBeforeValue(int value, int key)
    {
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
            return;
        }
        if (head->data == key)
        {
            insertAtHead(value);
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != key)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            cout << "Key not found!" << endl;
            return;
        }
        Node *newNode = new Node(value, temp->next);
        temp->next = newNode;
    }

    // Function to delete the head node
    void removeHead()
    {
        if (head == nullptr)
        {
            cout << "List is Empty~" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete the tail node
    void removeTail()
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

    // Function to delete Kth element from linked list
    void removeKthElement(int k)
    {
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
            return;
        }
        if (k < 1)
        {
            cout << "Invalid Index!" << endl;
        }

        if (k == 1)
        {
            removeHead();
            return;
        }

        int count = 1;
        int index = k - 1;
        Node *temp = head;
        while (count < index && temp->next != nullptr)
        {
            temp = temp->next;
            count++;
        }
        if (temp->next == nullptr || temp == nullptr)
        {
            cout << "Index out of bound!" << endl;
            return;
        }
        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Function to remove element by value
    void removeByValue(int value)
    {
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        if (head->data == value)
        {
            removeHead();
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != value)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            cout << "Value not found!" << endl;
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
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

    // Function to get length of linked list
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
    sll.removeTail();
    sll.display();
    cout << (sll.lengthOfLinkedList()) << endl;
    cout << (sll.search(0)) << endl;
    cout << (sll.search(90)) << endl;
    sll.removeByValue(1);
    sll.display();
    sll.insertAtK(100, 2);
    sll.display();
    sll.insertBeforeValue(500, 90);
    sll.display();
    return 0;
}