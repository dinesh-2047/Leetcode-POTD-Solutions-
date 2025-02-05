// 1790. Check if One String Swap Can Make Strings Equal

//Approach-1 (using map and counting)
//T.C : O(n)
//S.C : O(26) ~= O(1)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();

        if(s1 == s2) {
            return true;
        }

        int diffs = 0;

        int freq1[26] = {0};
        int freq2[26] = {0};

        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                diffs++;
            }

            if(diffs > 2)
                return false;

            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;

    }
};


//Approach-2 (using counting only. No map required)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();

        if(s1 == s2) {
            return true;
        }

        int diffs = 0;

        int firstIdx = 0;
        int secondIdx = 0;

        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                diffs++;

                if(diffs > 2) {
                    return false;
                } else if(diffs == 1) {
                    firstIdx = i;
                } else {
                    secondIdx = i;
                }

            }
        }

        return s1[firstIdx] == s2[secondIdx] && s1[secondIdx] == s2[firstIdx];

        

    }
};
