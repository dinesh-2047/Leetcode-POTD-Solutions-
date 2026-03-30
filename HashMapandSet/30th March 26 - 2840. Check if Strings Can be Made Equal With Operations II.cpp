// 2840. Check if Strings Can be Made Equal With Operations II

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        vector<int>e1(26, 0), e2(26, 0), o1(26, 0), o2(26, 0); 

        for(int i = 0 ; i  < n; i++ ){
            if(i % 2 == 0 ){
                e1[s1[i] - 'a']++;
                e2[s2[i] - 'a']++;
            }
            else {
                o1[s1[i] - 'a']++;
                o2[s2[i] - 'a']++;
            }
        }

        return o1 == o2 && e1 == e2;
    }
};