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
    bool isPalindrome(ListNode* head) {

        //step 1 : find the middle node
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next !=nullptr && fast->next->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        //step 2 : reverse the half linkedlist
        ListNode* prev=nullptr;
        ListNode* curr=slow->next;
        ListNode* nxt=nullptr;

        while(curr != nullptr){
            nxt=curr->next; //store the next pointer

            curr->next=prev;
           
            prev=curr;
            curr=nxt;
        }

        //step 3 : compare the two halves
        ListNode* n1=head;
        ListNode* n2=prev;

        while(n2 != nullptr){
            if(n1->val != n2->val){
                return false;
            }
            n1=n1->next;
            n2=n2->next;
        }
      return true;
    }
};