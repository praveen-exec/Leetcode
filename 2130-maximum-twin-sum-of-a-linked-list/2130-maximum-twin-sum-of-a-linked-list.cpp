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
    int pairSum(ListNode* head) {
        vector<int> arr;
        
        while(head != nullptr){
            arr.push_back(head->val);
            head = head->next;
        }

        int i=0,j=arr.size()-1;
        int max_sum=INT_MIN,sum=0;

        while(i < j){
         sum=arr[i] + arr[j];
         max_sum=max(max_sum,sum);
         i++,j--;
        }
        return max_sum;
    }
};