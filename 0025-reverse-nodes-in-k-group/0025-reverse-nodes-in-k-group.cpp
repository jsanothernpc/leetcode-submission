class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode* prev = end;
        ListNode* curr = head;
        while (curr != end) {
            ListNode* node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = node;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* temp = curr;
            for (int i = 0; i < k; i++) {
                if (temp == nullptr)
                    return head;
                temp = temp->next;
            }
            ListNode* Next = temp;
            ListNode* dummy = reverse(curr, Next);
            if (prev != nullptr)
                prev->next = dummy;
            else
                head = dummy;
            prev = curr;
            curr = Next;
        }
        return head;
    }
};