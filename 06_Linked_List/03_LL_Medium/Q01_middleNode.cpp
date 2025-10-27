// Find middle element in a Linked List

// Problem Statement : Given the head of a linked list of integers, determine
// the middle node of the linked list. However, if the linked list has an even
// number of nodes, return the second middle node.

// Input : head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we
// return the second one.

// Solution :

#include <iostream>
#include <vector>
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

// Brute Force Approach
ListNode *middleNodeBruteForce(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    ListNode *temp = head;
    int count = 1;

    while (temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    int mid = 0;
    if (count % 2 == 1)
    {
        mid = ((count / 2) + 1);
    }
    else
    {
        mid = count / 2;
    }

    count = 1;
    temp = head;
    while (count != mid )
    {
        temp = temp->next;
        count++;
    }
    return temp;
}

// Optimal Approach (Tortoise & Hare)
ListNode *middleNode(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    vector<int> arrOdd = {1, 2, 3, 4, 5};
    ListNode *headOdd = convertArray2LL(arrOdd);
    display(headOdd);
    display(middleNode(headOdd));
    vector<int> arrEven = {1, 2, 3, 4, 5, 6};
    ListNode *headEven = convertArray2LL(arrEven);
    display(headEven);
    display(middleNodeBruteForce(headEven));

    return 0;
}

// TIME AND SPACE COMPLEXITY

// 1. BRUTE FORCE
//    Time Complexity  : O(N + N/2); N = Lenght of List
//                       We traverse the list twice, once to find length
//                       and again till mid(N/2) to return.
//    Space Complexity : O(1);
//                       No extra space used.

// 2. OPTIMAL APPROACH
//    Time Complexity  : O(N); N = Lenght of List
//                       As we traverse the list only once using two pointers.
//    Space Complexity : O(1);
//                       No extra space used.
