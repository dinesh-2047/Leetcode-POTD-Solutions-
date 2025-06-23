// 2081. Sum of k-Mirror Numbers


/*
✨ LeetCode POTD: Sum of k‑Mirror Numbers (2081) 🔄🔢

⁉️ Problem Statement (LeetCode):
🔸 You’re given two integers, k (the base) and n.
🔸 A k‑mirror number is a positive integer that is a palindrome in both base‑10 and base‑k, with no leading zeros.
🔸 Return the sum of the n smallest k‑mirror numbers.

🔎 Approach I Used :

▶️ Generate Decimal Palindromes and Validate in Base-k

🔹 Start with decimal palindromes by building them digit by digit:
 • For each length L, generate the first half and mirror it to form full palindromes.
 • Handles both even and odd length palindromes separately:
  – Even: full = first_half + reverse(first_half)
  – Odd: full = first_half + reverse(first_half.substr(1))

🔹 For every generated decimal palindrome:
 • Convert it to base-k using a custom baseK function
 • Check if the base-k representation is also a palindrome using a simple two-pointer check

🔹 If it qualifies as a k‑mirror number, add it to the running total.
🔹 Repeat the process until n such numbers are found.









*/

//Approach - Using palindrome generation logic
//T.C : ~O((10 ^ D) * D), where D = number of digits in k-mirror number
//S.C : O(D), where D = number of digits in k-mirror number
class Solution {
public:
    
    bool isPalindrome(string baseK) {
        int i = 0;
        int j = baseK.length()-1;

        while(i <= j) {
            if(baseK[i] != baseK[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    string convertToBaseK(long long num, int k) {
        if(num == 0) {
            return "0";
        }

        string res = "";
        while(num > 0) {
            res += to_string(num%k);
            num /= k;
        }

        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1; //create L length palindromes

        while(n > 0) {
            int half_length = (L+1)/2;
            
            long long min_num = pow(10, half_length-1);
            long long max_num = pow(10, half_length) - 1;

            for(int num = min_num; num <= max_num; num++) {
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(begin(second_half), end(second_half));

                string pal = "";
                if(L % 2 == 0) { //even length palindrome
                    pal = first_half + second_half;
                } else { //off length palindrome
                    pal = first_half + second_half.substr(1);
                }

                long long pal_num = stoll(pal);

                string baseK = convertToBaseK(pal_num, k);

                if(isPalindrome(baseK)) {
                    sum += pal_num; //found one k-mirror number
                    n--;
                    if(n == 0) {
                        break;
                    }
                }
            }

            L++;
        }

        return sum;
    }
};