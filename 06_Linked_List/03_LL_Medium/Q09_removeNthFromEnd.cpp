// Remove N-th node from the end of a Linked List

// Problem Statement: Given a linked list and an integer N, the task is to delete the
// Nth node from the end of the linked list and print the updated linked list.

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

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
ListNode *removeNthFromEndBruteForce(ListNode *head, int n)
{
    int length = 0;
    ListNode *temp = head;

    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }
    if (n == length)
    {
        ListNode *deleteNode = head;
        head = head->next;
        delete deleteNode;
        return head;
    }
    int deleteIndex = length - n;

    temp = head;
    while (temp != nullptr)
    {
        deleteIndex--;
        if (deleteIndex == 0)
        {
            break;
        }
        temp = temp->next;
    }
    ListNode *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    return head;
}

// Optimal Approach (Slow & Fast Pointers)
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *temp = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (fast == nullptr)
    {
        ListNode *deleteNode = head;
        head = head->next;
        delete deleteNode;
        return head;
    }
    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *linkedList = convertArray2LL(arr);
    display(linkedList);
    display(removeNthFromEndBruteForce(linkedList, 2));

    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    ListNode *linkedList2 = convertArray2LL(arr2);
    display(linkedList2);
    display(removeNthFromEnd(linkedList2, 6));

    return 0;
}

// TIME AND SPACE COMPLEXITY`

// 1. BRUTE FORCE

//    Time Complexity  : O(n)+O(n-k); n = Length of List, k = node from end
//                       O(n) for list traversal and finding length
//                       O(n-k) for deleting kth node from end
//
//    Space Complexity : O(1);
//                       No extra space used.

// 2. OPTIMAL APPROACH

//    Time Complexity  : O(n); n = Lenght of List
//                       O(n) fast pointer will traverse the whole list once

//    Space Complexity : O(1);
//                       No extra space used.
