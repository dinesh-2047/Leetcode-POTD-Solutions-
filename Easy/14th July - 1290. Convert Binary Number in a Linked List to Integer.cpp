// 1290. Convert Binary Number in a Linked List to Integer


/*

⁉️ Problem Statement:
 🔸 You are given the head of a singly linked list where each node contains a binary digit (0 or 1), arranged from most significant bit (MSB) to least significant bit (LSB).
 🔸 Convert the binary number represented by this list into its decimal value, and return the result.

🔎 Approaches I Used:
1️⃣ String Building + Reversal + Power Calculation
 🔹 Traverse the list, append binary digits to a string
 🔹 Reverse the string so that index i represents 2ⁱ
 🔹 Calculate result using result += pow(2, i) * binary[i]

2️⃣ Length Counting + Direct Power Mapping
 🔹 First pass to count number of nodes
 🔹 Second pass: multiply each digit by pow(2, len - i - 1)

3️⃣ Bitwise Accumulation (Optimized)
 🔹 Traverse the list while building result:
 result = (result << 1) | node->val
 🔹 Equivalent to base-2 digit shifting (very efficient)

4️⃣ Reverse Linked List + LSB Processing
 🔹 First reverse the linked list
 🔹 Then use powers of 2 from LSB side like traditional binary parsing

5️⃣ Pure Arithmetic (Base Conversion)
 🔹 Multiply result by 2 and add the node’s value at each step
 🔹 Efficient and clean: result = result * 2 + node->val
*/






// Approach 1 
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
    int getDecimalValue(ListNode* head) {
        string binary = "";

        ListNode* temp = head; 

        while(temp){
            binary.push_back(temp->val +'0');
            temp = temp->next; 
        }

       reverse(begin(binary), end(binary));
        
        int result = 0 ; 
       for(int i = 0 ; i < binary.length(); i++){
           result += pow(2, i) * (binary[i]-'0');
       }
       return result ;
    }
};






//Approach 2 -> 

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
    int getDecimalValue(ListNode* head) {
       

       int len = 0 ;  
        ListNode* temp = head; 
        while(temp){
            len++;
            temp = temp->next; 
        }
       
       temp = head;
       int result = 0 ;  
       int i = len-1 ; 
       while(temp){
          result += pow(2, i) * temp->val;
          temp = temp->next; 
          i--;
       }
       return result; 
      
    }
};




//Approach 3 
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
    int getDecimalValue(ListNode* head) {
        ListNode *temp = head; 
        int result = 0 ; 
        while(temp){
            result = (result << 1) | temp->val; 
            temp = temp->next; 

        }
        return result; 
    }
};





//Approach 4   
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
    int getDecimalValue(ListNode* head) {

       
       ListNode* prev = nullptr ; 
       ListNode* curr = head; 

         while(curr!=nullptr){
            ListNode* nextt = curr->next; 
            curr->next = prev ; 
            prev = curr; 
            curr = nextt; 
           
         }

        int result = 0 ; 
        int i = 0 ; 
        ListNode* temp = prev; 
        while(temp){
            result += pow(2, i) * temp->val; 
            i++;
            temp= temp->next; 
        }
        return result; 


    }
};






//Approach 5 
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
    int getDecimalValue(ListNode* head) {
        int result = 0 ; 
        ListNode *temp = head; 
        while(temp){
            result = result * 2 + temp->val; 
            temp = temp->next; 
        }
      return result; 
    }

};