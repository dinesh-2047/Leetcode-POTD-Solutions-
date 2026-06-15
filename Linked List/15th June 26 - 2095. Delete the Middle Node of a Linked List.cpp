// 2095. Delete the Middle Node of a Linked List


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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr; 
        ListNode* slow = head; 
        ListNode* fast = head; 

        while(fast && fast->next){
            slow = slow->next; 
            fast = fast->next; 
            if(fast){
                fast = fast->next; 
            }
        }
        
        ListNode* mid = slow; 
        ListNode* nextt = mid->next; 
        ListNode* prev = head; 
        while(prev->next != slow){
            prev = prev->next; 
        }
       
        mid->next = nullptr; 
        prev->next = nextt; 

        return head; 



    }
};