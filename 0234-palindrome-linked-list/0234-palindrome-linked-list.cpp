class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> arr;
        ListNode* temp = head;

        while(temp != nullptr) {
            arr.push_back(temp);
            temp = temp->next;
        }

        int i = 0, j = arr.size() - 1;

        while(i < j) {
            if(arr[i]->val != arr[j]->val)
                return false;

            i++;
            j--;
        }

        return true;
    }
};