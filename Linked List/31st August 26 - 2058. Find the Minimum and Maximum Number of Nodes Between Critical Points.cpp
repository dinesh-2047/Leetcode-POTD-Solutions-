// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next || !head->next->next) return {-1, -1};

        vector<int> cp; 

        ListNode* curr = head->next; 
        ListNode* prev = head; 
        ListNode* nextt = head->next->next; 
         int pos = 2; 
        while(nextt){
            if((curr->val > prev->val && curr->val > nextt->val) || (curr->val < prev->val && curr->val < nextt->val)){
                cp.push_back(pos);
            }
            pos++;
            curr = curr->next; 
            prev=prev->next; 
            nextt = nextt->next; 
        }
        cout<<cp.size();
          if(cp.size() < 2) return {-1, -1};
          int mn = 1e9; 
          int mx = 0; 

          for(int i = 1 ; i < cp.size(); i++){
              mn = min(mn, cp[i] - cp[i - 1]);
          }
          return {mn, cp[cp.size()-1] - cp[0]};

    }
};