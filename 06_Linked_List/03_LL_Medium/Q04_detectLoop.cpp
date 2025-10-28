// Detect a Cycle in a Linked List

// Problem Statement : Given a Linked List, determine whether the linked list
// contains a cycle or not.

// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects
// to the 1st node (0-indexed).

// Solution :

#include <iostream>
#include <vector>
#include <map>
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

// Brute Force (Hashing)
bool hasCycleBruteForce(ListNode *head)
{
    map<ListNode *, int> mpp;
    ListNode *temp = head;
    while (temp != nullptr)
    {

        if (mpp.find(temp) != mpp.end())
        {
            return true;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

// Optimal Approach (Tortoise & Hare)
bool hasCycle(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{

    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);
    ListNode *fifth = new ListNode(5);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop for testing
    fifth->next = third;

    cout << (hasCycle(head) ? "True" : "False") << endl;
    cout << (hasCycleBruteForce(head) ? "True" : "False") << endl;

    // Free allocated memory

    fifth->next = nullptr; // cycle break

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}

// TIME AND SPACE COMPLEXITY

// 1. BRUTE FORCE
//    Time Complexity  : O(n*log(n)); n = Length of List
//                       O(n) for list traversal
//                       O(log(n)) for every unordered_map operation.

//    Space Complexity : O(n); n = Length of List
//                       HashMap used to store node and visited status.

// 2. OPTIMAL APPROACH
//    Time Complexity  : O(n); n = Lenght of List
//                       List traversal

//    Space Complexity : O(1);
//                       No extra space used.
