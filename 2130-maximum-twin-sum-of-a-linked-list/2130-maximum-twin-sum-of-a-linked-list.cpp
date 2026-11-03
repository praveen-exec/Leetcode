/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    typedef ListNode* node; //shortcut for ListNode*
    int pairSum(ListNode* head) {
     
     //step 1 : find the middle node

     ListNode* slow=head;
     ListNode* fast=head;

     while(fast != nullptr && fast->next != nullptr){
        slow=slow->next;
        fast=fast->next->next;
     }

     //step 2 : reverse the second half ll
     ListNode* prev = nullptr,
          *curr = slow,
          *nxt  = nullptr;

    while(curr != nullptr){
        nxt = curr->next;

        curr->next=prev;

        prev=curr;
        curr=nxt;
    }
    int max_sum=INT_MIN,sum=0;
    node n1=head;
    node n2=prev;

    while(n2 != nullptr){
        sum = n1->val + n2->val;
        max_sum=max(max_sum,sum);

        n1=n1->next;
        n2=n2->next;
    }
    return max_sum;

    }
};