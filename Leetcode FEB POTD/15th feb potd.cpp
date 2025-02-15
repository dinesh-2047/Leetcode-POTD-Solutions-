// 2698. Find the Punishment Number of an Integer

//Approach-1 : (Recursion + Memoization)
//T.C : O(n * 2^(log10(n^2)))
//S.C : O(n * log10(n^2))
class Solution {
    public:
        bool check(int i, int currsum, string s, int num, vector<vector<int>>& t) {
            if (i == s.length()) {
                return currsum == num;
            }
            if (currsum > num) 
                return false;
    
            if (t[i][currsum] != -1) //we have repeating subproblems. Draw tree diagram of "1296"
                return t[i][currsum];
    
            bool possible = false;
            for (int j = i; j < s.length(); j++) {
                string currentString = s.substr(i, j - i + 1);
                int addend = stoi(currentString);
    
                possible = possible || check(j + 1, currsum + addend, s, num, t);
                if (possible == true) 
                    return true;
            }
    
            return t[i][currsum] = possible;
        }
    
        int punishmentNumber(int n) {
            int punishmentNum = 0;
            for (int num = 1; num <= n; num++) {
                int squareNum = num * num;
                string s = to_string(squareNum);
    
                vector<vector<int>> t(s.size(), vector<int>(num + 1, -1));
    
                if (check(0, 0, s, num, t)) {
                    punishmentNum += squareNum;
                }
            }
            return punishmentNum;
        }
    };
    


    //Approach-2 : (Recursion + Memoization)
//T.C : O(n * 2^(log10(n^2)))
//S.C : O(log10(n^2))
class Solution {
    public:
        bool check(int num, int currnum, int target) {
            if(num == 0) {
                return currnum == target;
            }
            
            return check(num / 10, currnum + num % 10, target) ||
                   check(num / 100, currnum + num % 100, target) ||
                   check(num / 1000, currnum + num % 1000, target) ||
                   check(num / 10000, currnum + num % 10000, target);
        }
    
        int punishmentNumber(int n) {
            int punishmentNum = 0;
            for (int currentNum = 1; currentNum <= n; currentNum++) {
                int squareNum = currentNum * currentNum;
                if (check(squareNum, 0, currentNum)) {
                    punishmentNum += squareNum;
                }
            }
            return punishmentNum;
        }
    };


    // Approach 3 -> good time and space complexity but not good logically 

    class Solution {
        public:
            int punishmentNumber(int n) {
                vector<int> arr = {1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,
                                   657,675,703,756,792,909,918,945,964,990,991,999,1000};
                int sum = 0;
                for(int i = 0; i < arr.size(); i++) {
                    if(arr[i] <= n) sum += arr[i] * arr[i];
                    else break;
                }
                return sum;
            }
        };