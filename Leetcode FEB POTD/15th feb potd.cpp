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
    