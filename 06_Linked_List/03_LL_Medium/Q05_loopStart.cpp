// Starting point of loop in a Linked List

// Problem Statement : Given the head of a linked list that may contain a cycle,
// return the starting point of that cycle. If there is no cycle in the linked
// list return null.

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

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
ListNode *detectCycleBruteForce(ListNode *head)
{
    map<ListNode *, bool> mpp;
    ListNode *temp = head;
    while (temp != nullptr)
    {

        if (mpp.find(temp) != mpp.end())
        {
            return temp;
        }
        mpp[temp] = true;
        temp = temp->next;
    }
    return nullptr;
}

// Optimal Approach (Tortoise & Hare)
ListNode *detectCycle(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
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

    cout << detectCycleBruteForce(head) << endl;
    cout << detectCycle(head) << endl;

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
//                       O(log(n)) for every map operation.

//    Space Complexity : O(n); n = Length of List
//                       HashMap used to store node and visited status.

// 2. OPTIMAL APPROACH
//    Time Complexity  : O(n); n = Lenght of List
//                       List traversal

//    Space Complexity : O(1);
//                       No extra space used.
