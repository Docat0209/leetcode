// Source : https://leetcode.com/problems/add-two-numbers/
// Author : Docat
// Date   : 02-27-2024

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}     
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        bool is_carry = false;

        while(l1||l2||is_carry){
            int result = (l1?l1->val:0) + (l2?l2->val:0) + is_carry;

            cur->next = new ListNode(result%10);
            cur = cur->next;
        
            is_carry = result/10;

            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }

        ListNode* result = head->next;
        delete head;
        return result;
    }
};
