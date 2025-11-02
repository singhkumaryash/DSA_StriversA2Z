// Delete the Middle Node of the Linked List

// Problem Statement : Given the head of a linked list of integers, delete the middle node
// of the linked list and return the modified head. However, if the linked list has an even
// number of nodes, delete the second middle node.

// Input: head = [1,3,4,7,1,2,6]
// Output: [1,3,4,1,2,6]
// Explanation:
// The above figure represents the given linked list. The indices of the nodes are written below.
// Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
// We return the new list after removing this node.

// Input: head = [1,2,3,4]
// Output: [1,2,4]
// Explanation:
// The above figure represents the given linked list.
// For n = 4, node 2 with value 3 is the middle node, which is marked in red.

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
ListNode *deleteMiddleBruteForce(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        head = nullptr;
        return head;
    }
    int length = 0;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }
    temp = head;
    int mid = length / 2;
    while (mid != 1)
    {
        temp = temp->next;
        mid--;
    }
    ListNode *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    return head;
}

// Optimal Approach (Slow & Fast Pointers)
ListNode *deleteMiddle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        head = nullptr;
        return head;
    }

    ListNode *slow = head;
    ListNode *fast = head->next->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
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
    display(deleteMiddleBruteForce(linkedList));

    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    ListNode *linkedList2 = convertArray2LL(arr2);
    display(linkedList2);
    display(deleteMiddle(linkedList2));

    return 0;
}

// TIME AND SPACE COMPLEXITY`

// 1. BRUTE FORCE

//    Time Complexity  : O(n + n/2); n = Length of List
//                       O(n) for list traversal and finding length
//                       O(n/2) for traversing to middle node to delete
//
//    Space Complexity : O(1);
//                       No extra space used.

// 2. OPTIMAL APPROACH

//    Time Complexity  : O(n); n = Lenght of List
//                       O(n) fast pointer will traverse the whole list once

//    Space Complexity : O(1);
//                       No extra space used.
