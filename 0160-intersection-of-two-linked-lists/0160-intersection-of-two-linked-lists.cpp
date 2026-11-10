/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA,*temp2=headB;
        int c1=0,c2=0;
        
        while(temp1 != nullptr){
            c1++;
            temp1=temp1->next;
        }
        
        while(temp2 != nullptr){
            c2++;
            temp2=temp2->next;
        }
        
        int diff = abs(c1-c2);
        //same level pe laayenge pehle 
        if(c1 >= c2){
            for(int i=1; i<=diff; i++){
                headA=headA->next;
            }
        }
        
        else if(c1 < c2){
            for(int i=1; i<=diff; i++){
                headB=headB->next;
            }
        }
        
        //until they meet, keep moving
        while(headA != headB){
            headA=headA->next;
            headB=headB->next;
        }
        
        if(headA==nullptr || headB==nullptr)
         return nullptr;
         
        return headA;
        
    }
};