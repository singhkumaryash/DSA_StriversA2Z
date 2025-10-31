// Segregate even and odd nodes in LinkedList

// Problem Statement : Segregate even and odd nodes in LinkedList. Given a LinkedList of integers.
// Modify the LinkedList in such a way that in Modified LinkedList all the even numbers appear
// before all the odd numbers in LinkedList.
// Also, note that the order of even and odd numbers should remain the same.

// Input: 1→2→3→4→5→6→Null
// Output: 2→4→6→1→3→5→Null
// Explanation :
// Odd Nodes in LinkedList are 1,3,5 and
// Even Nodes in LinkedList are 2,4,6
// In Modified LinkedList all even Nodes comes before
// all Odd Nodes. So Modified LinkedList looks like
// 2→4→6→1→3→5→Null. Order of even and odd Nodes is
// maintained in modified LinkedList.

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
ListNode *oddEvenListBruteForce(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *temp = head;
    vector<int> segregated;

    temp = head->next;
    while (temp != nullptr && temp->next != nullptr)
    {
        segregated.push_back(temp->val);
        temp = temp->next->next;
    }
    if (temp != nullptr)
    {
        segregated.push_back(temp->val);
    }
    temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        segregated.push_back(temp->val);
        temp = temp->next->next;
    }
    if (temp != nullptr)
    {
        segregated.push_back(temp->val);
    }
    temp = head;
    int i = 0;
    while (temp != nullptr)
    {
        temp->val = segregated[i];
        temp = temp->next;
        i++;
    }
    return head;
}

// Optimal Approach
ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *temp = head;
    ListNode *even = temp->next;
    ListNode *odd = temp;
    ListNode *evenHead = temp->next;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        odd = odd->next;

        even->next = even->next->next;
        even = even->next;
    }

    even->next = temp;

    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *linkedList = convertArray2LL(arr);
    display(linkedList);
    display(oddEvenListBruteForce(linkedList));

    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    ListNode *linkedList2 = convertArray2LL(arr2);
    display(linkedList2);
    display(oddEvenList(linkedList2));

    return 0;
}

// TIME AND SPACE COMPLEXITY`

// 1. BRUTE FORCE
//    Time Complexity  : O(2n); n = Length of List
//                       O(n/2) for odd node traversal and data storage
//                       O(n/2) for even node traversal and data storage
//                       O(n) for segregated data assignment

//    Space Complexity : O(n); n = Length of List
//                       Vector used to store node data.
// 2. OPTIMAL APPROACH
//    Time Complexity  : O(nn); n = Lenght of List
//                       O(n/2) odd node links reassignment
//                       O(n/2) even node links reassignment

//    Space Complexity : O(1);
//                       No extra space used.
