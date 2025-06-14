// 2566. Maximum Difference by Remapping a Digit


//Approach-1 (Simple iterating on digits)
//T.C : O(log10(n))
//S.C : O(log10(n))
class Solution {
public:
    int minMaxDifference(int num) {
        string minNum = to_string(num);
        string maxNum = to_string(num);
        int n = minNum.length();

        char ch = ' ';
        for(int i = 0; i < n; i++) {
            if(maxNum[i] != '9') {
                ch = maxNum[i];
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(maxNum[i] == ch) {
                maxNum[i] = '9';
            }
        }
        

        ch = minNum[0];
        for(int i = 0; i < n; i++) {
            if(minNum[i] == ch) {
                minNum[i] = '0';
            }
        }

        return stoi(maxNum) - stoi(minNum);

    }
};


//Approach-2 (Using C++ STLs)
//T.C : O(log10(n))
//S.C : O(log10(n))
class Solution {
public:
    int minMaxDifference(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        char ch = str2[0]; //given input will not have leading zero
        replace(begin(str2), end(str2), ch, '0');

        return stoi(str1) - stoi(str2);
    }
};