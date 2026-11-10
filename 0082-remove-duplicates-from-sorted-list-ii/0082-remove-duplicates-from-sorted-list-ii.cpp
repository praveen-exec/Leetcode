class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr != nullptr) {

            if(curr->next != nullptr && curr->val == curr->next->val) {

                while(curr->next != nullptr && curr->val == curr->next->val) {
                    curr = curr->next;
                }

                if(prev == nullptr)
                    head = curr->next;
                else
                    prev->next = curr->next;

                curr = curr->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};