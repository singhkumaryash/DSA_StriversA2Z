// Sort a Linked List

// Problem Statement : Given a linked list, sort its nodes based on the data value in them.
// Return the head of the sorted linked list.

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

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

// Brute Force
ListNode *sortListBruteForce(ListNode *head)
{
    ListNode *temp = head;
    vector<int> data;
    while (temp != nullptr)
    {
        data.push_back(temp->val);
        temp = temp->next;
    }
    sort(data.begin(), data.end());
    temp = head;
    int i = 0;
    while (temp != nullptr)
    {
        temp->val = data[i];
        i++;
        temp = temp->next;
    }
    return head;
}

// Optimal Approach
ListNode *mergeList(ListNode *list1, ListNode *list2)
{
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (list1 != nullptr)
    {
        temp->next = list1;
    }

    else
    {
        temp->next = list2;
    }

    return dummyNode->next;
}

ListNode *findMid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *mid = findMid(head);

    ListNode *right = mid->next;
    mid->next = nullptr;
    ListNode *left = head;

    left = sortList(left);
    right = sortList(right);
    return mergeList(left, right);
}

int main()
{

    vector<int> arr = {4, 3, 5, 2, 1};
    ListNode *linkedList = convertArray2LL(arr);
    display(linkedList);
    display(sortListBruteForce(linkedList));

    vector<int> arr2 = {6, 8, 10, 12, 1, 5, 3, 2, 7};
    ListNode *linkedList2 = convertArray2LL(arr2);
    display(linkedList2);
    display(sortList(linkedList2));
    return 0;
}

// TIME AND SPACE COMPLEXITY

// 1. BRUTE FORCE APPROACH

//    Time Complexity  : O(n log n + n)
//                       O(n) to traverse the list and store elements in a vector
//                       O(n log n) to sort the vector
//                       O(n) to rewrite sorted values back into the list
//                       Simplifies to → O(n log n)
//
//    Space Complexity : O(n)
//                       Extra space used for storing node values in a vector

// 2. OPTIMAL APPROACH (MERGE SORT)

//    Time Complexity  : O(n log n)
//                       The list is recursively divided into halves → O(log n) levels
//                       Each level requires O(n) time to merge lists
//                       Therefore, total → O(n log n)
//
//    Space Complexity : O(log n)
//                       Only recursive stack space is used due to recursive calls
//                       No extra data structures or arrays are created
