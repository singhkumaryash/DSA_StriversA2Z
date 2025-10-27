// Reverse a Linked List

// Problem Statement : Problem Statement: Given the head of a singly linked list, 
// write a program to reverse the linked list, and return the head pointer to the 
// reversed list.

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Solution : 

#include <iostream>
#include <vector>
#include<stack>
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

// Brute Force Approach (Stack Based)
ListNode *reverseListBruteForce(ListNode *head)
{
    ListNode *temp = head;
    stack<int> nodeData;
    while (temp != nullptr)
    {
        nodeData.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        temp->val = nodeData.top();
        nodeData.pop();
        temp = temp->next;
    }
    return head;
}

// Optimal Approach (Iterative)
ListNode *reverseList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *nextNode = nullptr;
    ListNode *prevNode = nullptr;
    while (temp != nullptr)
    {
        nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
    }
    head = prevNode;
    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *linkedList = convertArray2LL(arr);
    display(linkedList);
    display(reverseListBruteForce(linkedList));

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};
    ListNode *linkedList2 = convertArray2LL(arr2);
    display(linkedList2);
    display(reverseListBruteForce(linkedList2));
    return 0;
}

// TIME AND SPACE COMPLEXITY

// 1. BRUTE FORCE
//    Time Complexity  : O(2N); N = Length of List
//                       As We traverse the list twice, once for data storage
//                       and again for data assignment.
//    Space Complexity : O(N); N = Length of List
//                       As we use stack to store the data of every node for later assignment.

// 2. OPTIMAL APPROACH
//    Time Complexity  : O(N); N = Lenght of List
//                       As we traverse the list only once and change the next pointer.
//    Space Complexity : O(1);
//                       No extra space used.
