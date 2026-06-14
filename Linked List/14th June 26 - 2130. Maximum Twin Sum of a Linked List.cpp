// 2130. Maximum Twin Sum of a Linked List

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
       int n = 0 ; 
       ListNode* temp = head; 
       while(temp) {
          n++;
          temp = temp->next; 
       }

       int count = 0 ; 
       temp = head; 
       while(count < n/2 - 1){
           count++;
           temp = temp->next; 
       }
       ListNode* mid = temp->next ; 
       ListNode* prev = nullptr; 
       ListNode* curr = mid ; 
       while(curr){
           ListNode* next = curr->next; 
          curr->next = prev; 
          prev = curr; 
          curr = next; 
       }
       temp->next =  prev; 
       mid = temp->next; 
        temp = head; 
       int result = 0 ; 
       int cnt = 0 ; 
       while(cnt < n/2){
           int sum = temp->val + mid->val; 
           result = max(result, sum);
           mid = mid->next; 
           temp = temp->next;
           cnt++; 
       }
     return result; 
       
    }
};