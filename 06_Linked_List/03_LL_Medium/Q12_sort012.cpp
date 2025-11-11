// Sort a Linked List of 0's 1's and 2's by changing links

// Problem Statement : Given a linked list containing only 0's, 1's, and 2's,
// sort the linked list by rearranging the links (not by changing the data values).

// Input: 1 -> 2 -> 0 -> 1 -> 0 -> 2 -> NULL
// Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL

// Input: 2 -> 1 -> 2 -> 0 -> 0 -> 1 -> NULL
// Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL

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
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *temp = head;
    int count0 = 0, count1 = 0, count2 = 0;
    while (temp)
    {
        if (temp->val == 0)
            count0++;
        else if (temp->val == 1)
            count1++;
        else
            count2++;
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (count0)
        {
            temp->val = 0;
            count0--;
        }
        else if (count1)
        {
            temp->val = 1;
            count1--;
        }
        else
        {
            temp->val = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}

// Optimal Approach
ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *zeroDummy = new ListNode(-1);
    ListNode *zero = zeroDummy;

    ListNode *oneDummy = new ListNode(-1);
    ListNode *one = oneDummy;

    ListNode *twoDummy = new ListNode(-1);
    ListNode *two = twoDummy;

    ListNode *temp = head;

    while (temp != nullptr)
    {
        if (temp->val == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->val == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (oneDummy->next != nullptr) ? oneDummy->next : twoDummy->next;
    one->next = twoDummy->next;
    two->next = nullptr;

    ListNode *result = zeroDummy->next;
    delete zeroDummy;
    delete oneDummy;
    delete twoDummy;

    return result;
};

int main()
{

    vector<int> arr = {2, 0, 1, 2, 0, 1};
    ListNode *linkedList = convertArray2LL(arr);
    display(linkedList);
    display(sortList(linkedList));

    vector<int> arr2 = {2, 1, 0, 2, 2, 1, 2, 0};
    ListNode *linkedList2 = convertArray2LL(arr2);
    display(linkedList2);
    display(sortListBruteForce(linkedList2));
}

// TIME AND SPACE COMPLEXITY

// 1. BRUTE FORCE APPROACH

//    Time Complexity  : O(2n)
//                       O(n) to traverse the list and count 0, 1, & 2.
//                       O(n) to rewrite back into list.

//    Space Complexity : O(1)
//                       No extra space used.

// 2. OPTIMAL APPROACH

//    Time Complexity  : O(n)
//                       The list is traversed once and is partitioned into sorted sublists.
//                       The three sublists are connected to form sorted lists.

//    Space Complexity : O(1)
//                       No extra space used.
