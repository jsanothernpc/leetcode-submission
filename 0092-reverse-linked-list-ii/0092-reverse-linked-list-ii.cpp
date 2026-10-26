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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;

        ListNode* beforeL = nullptr;
        ListNode* curr = head;

        for (int i = 1; i < left; i++) {
            beforeL = curr;
            curr = curr->next;
        }

        ListNode* start = curr;

        for (int i = left; i <= right; i++) {
            curr = curr->next;
        }

        ListNode* end = curr;

        ListNode* dummy = reverse(start, end);

        if (beforeL != nullptr)
            beforeL->next = dummy;

        else
            head = dummy;

        return head;
    }
};