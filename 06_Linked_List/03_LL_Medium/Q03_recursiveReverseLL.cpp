// Reverse a Linked List

// Problem Statement : Problem Statement: Given the head of a singly linked list,
// write a program to reverse the linked list, and return the head pointer to the
// reversed list.

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Solution :

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// List Node definition
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

// function to create a list from array
ListNode *convertArray2LL(vector<int> arr)
{
    if (arr.empty())
    {
        cout << "Array is Empty to Covert!" << endl;
        return nullptr;
    }
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// function to display the list
void display(ListNode *head)
{
    if (head == nullptr)
    {
        cout << "List is Empty!" << endl;
        return;
    }
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Optimal Approach (Recursive)
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *newHead = reverseList(head->next);
    ListNode *nextNode = head->next;
    nextNode->next = head;
    head->next = nullptr;
    return newHead;
};

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *linkedList = convertArray2LL(arr);
    display(linkedList);
    display(reverseList(linkedList));

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};
    ListNode *linkedList2 = convertArray2LL(arr2);
    display(linkedList2);
    display(reverseList(linkedList2));
    return 0;
}

// TIME AND SPACE COMPLEXITY
// Time Complexity  : O(N)
//                    Each node is visited once.
// Space Complexity : O(N)
//                    Due to recursion call stack (depth = number of nodes).
