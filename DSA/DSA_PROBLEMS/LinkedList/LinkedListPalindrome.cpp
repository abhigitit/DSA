/*
Leetcode 234
AlgoExpert

Intuition : Push all the values of LL into a stack in the first iteration and during the second iteration, compare value from stack and elements of LL.
Without using extra stack, we can smartly use recursive stack.

--Make use of helper function with return type as pair<bool,Node*>. Call the function with two parameters - head, head as left, right.
Inside helper function, recursively call the helper with changing right to right->next. When right becomes null, return {true,left}. Now, top of the recursive stack
is the last value of LL and left(head) is preserved as its not incremented.

--Collect values from return and validate.

TC: O(N)
SC : Recursive Stack

*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return helper(head,head).first;
    }

    pair<bool,ListNode*> helper(ListNode* left, ListNode* right)
    {
        if(!right)
            return {true,left};
        pair<bool,ListNode*> checker = helper(left,right->next);
        bool value_check = checker.first;
        ListNode* left_increment = checker.second;

        bool palindrome = checker.first and right->val == left_increment->val;

        return {palindrome,left_increment->next};


    }
};
