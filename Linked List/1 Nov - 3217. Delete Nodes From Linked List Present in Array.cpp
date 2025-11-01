// 3217. Delete Nodes From Linked List Present in Array


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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums), end(nums));

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr) {
            if (st.count(curr->val)) {
                if (prev == nullptr) {
                    head = head->next;
                } else {
                    prev->next = curr->next;
                }
            } else
                prev = curr;
            curr = curr->next;
        }
        return head;
    }
};