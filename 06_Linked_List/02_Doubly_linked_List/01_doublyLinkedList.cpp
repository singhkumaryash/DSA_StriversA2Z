#include <iostream>
#include <vector>
using namespace std;

// Node class for Doubly Linked List
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

    // Function to check if the list is empty
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Function to insert at head
    void insertAtHead(int value)
    {

        Node *newNode = new Node(value, head, nullptr);
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Function to insert before tail
    void insertBeforeTail(int value)

    {
        if (head == nullptr || head->next == nullptr)
        {
            insertAtHead(value);
            return;
        }
        Node *newNode = new Node(value);
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        Node *secondLast = temp->prev;

        secondLast->next = newNode;
        newNode->prev = secondLast;
        newNode->next = temp;
        temp->prev = newNode;
    }

    // Function to insert at position K
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

        Node *temp = head;
        int count = 1;
        while (temp != nullptr && count < k)
        {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr)
        {
            // if (count == k)
            // {
            //     insertBeforeTail(value);
            //     // Node *newNode = new Node(value, nullptr, temp->prev);
            //     // temp->prev->next = newNode;
            //     return;
            // }
            cout << "Invalid Index" << endl;
            return;
        }
        Node *prevNode = temp->prev;
        Node *newNode = new Node(value, temp, prevNode);
        temp->prev = newNode;
        prevNode->next = newNode;
    }

    // Function to insert before a given value
    void insertBeforeValue(int value, int key)
    {
        if (isEmpty())
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
        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Key not found!" << endl;
            return;
        }
        Node *prevNode = temp->prev;
        Node *newNode = new Node(value, temp, prevNode);
        temp->prev = newNode;
        prevNode->next = newNode;
    }

    // Function to delete the head node
    void removeHead()
    {
        if (isEmpty())
        {
            cout << "List is Empty!" << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        head = temp->next;
        head->prev = nullptr;
        delete temp;
    }

    // Function to delete the tail node
    void removeTail()
    {
        if (isEmpty())
        {
            cout << "List is Empty!"
                 << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    // Function to delete Kth element from doubly linked list
    void removeKthElement(int k)
    {
        if (isEmpty())
        {
            cout << "List is Empty!" << endl;
            return;
        }
        if (k < 1)
        {
            cout << "Invalid Index!" << endl;
            return;
        }
        if (k == 1)
        {
            removeHead();
            return;
        }

        int count = 1;
        Node *temp = head;
        while (temp != nullptr && count < k)
        {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr)
        {
            cout << "Invalid Index!" << endl;
            return;
        }
        if (temp->next == nullptr)
        {
            temp->prev->next = nullptr;
            delete temp;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // Function to remove element by value
    void removeByValue(int value)
    {

        if (isEmpty())
        {
            cout << "List is Empty!" << endl;
            return;
        }

        // head node
        if (head->data == value)
        {
            removeHead();
            return;
        }

        Node *temp = head;
        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value not Found!" << endl;
            return;
        }

        temp->prev->next = temp->next;

        // if middle node
        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Function to display the doubly linked list
    void display()
    {
        if (isEmpty())
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

int main()
{
    DoublyLinkedList dll;
    vector<int> arr = {1, 2, 3, 4, 5};
    dll.convertArray2Dll(arr);
    dll.display();
    // dll.removeByValue(3);
    dll.insertBeforeValue(0, 3);
    dll.display();
    return 0;
}