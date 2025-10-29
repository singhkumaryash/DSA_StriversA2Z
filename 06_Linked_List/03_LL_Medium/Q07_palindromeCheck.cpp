// Check if the given Linked List is Palindrome

// Problem Statement : Given the head of a singly linked list, return true if it
// is a palindrome or false otherwise.

// Input: head = [1,2,2,1]
// Output: true

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

// Brute Force
bool isPalindromeBruteForce(ListNode *head)
{
    stack<int> data;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        data.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (temp->val != data.top())
        {
            return false;
        }
        data.pop();
        temp = temp->next;
    }
    return true;
}

// Optimal Approach

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

bool isPalindrome(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *newHead = reverseList(slow->next);
    ListNode *first = head;
    ListNode *second = newHead;
    while (second != nullptr)
    {
        if (first->val != second->val)
        {
            reverseList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseList(newHead);
    return true;
}

int main()
{

    vector<int> arr = {1, 2, 2, 1};
    ListNode *linkedList = convertArray2LL(arr);
    display(linkedList);
    cout << (isPalindromeBruteForce(linkedList) ? "True" : "False") << endl;
    ;

    vector<int> arr2 = {1, 2, 3, 4, 3, 2, 1};
    ListNode *linkedList2 = convertArray2LL(arr2);
    display(linkedList2);
    cout << (isPalindrome(linkedList2)) << endl;

    return 0;
}

// TIME AND SPACE COMPLEXITY`

// 1. BRUTE FORCE
//    Time Complexity  : O(2n); n = Length of List
//                       O(n) for list traversal and data storage
//                       O(n) for comparison

//    Space Complexity : O(n); n = Length of List
//                       Stack used to store node data.
// 2. OPTIMAL APPROACH
//    Time Complexity  : O(2n); n = Lenght of List
//                       O(n/2) list traversal till half
//                       O(n/2) reversing the second half
//                       O(n/2) list traversal first half
//                       O(n/2) list traversal second half

//    Space Complexity : O(1);
//                       No extra space used.
