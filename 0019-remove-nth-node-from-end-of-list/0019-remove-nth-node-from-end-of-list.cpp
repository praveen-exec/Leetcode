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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        //step 1 : find the length of linked list
        int len=0;
        ListNode* temp = head;

        while( temp != nullptr){
            len++;
            temp = temp->next;
        }

        int d = len - n + 1;
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;

        int i=0;
        // Hume d-1 jump lene hai
        while(i < d-1){
            prev = prev->next;
            curr = curr->next;
            i++;
        }
        prev->next = curr->next;

        return dummy->next;
    }
};
