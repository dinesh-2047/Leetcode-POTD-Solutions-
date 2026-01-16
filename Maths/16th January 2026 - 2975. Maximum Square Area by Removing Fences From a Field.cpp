// 2975. Maximum Square Area by Removing Fences From a Field

class Solution {
public:
int mod = 1e9 + 7 ; 
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        unordered_set<int>widths; 
        unordered_set<int>heights;

        for(int i = 0 ; i < hFences.size() - 1; i++){
            for(int j = i + 1; j < hFences.size(); j++){
                heights.insert(abs(hFences[j] - hFences[i]));
            }
        }
        for(int i = 0 ; i < vFences.size() - 1; i++){
            for(int j = i + 1; j < vFences.size(); j++){
                widths.insert(abs(vFences[j] - vFences[i]));
            }
        }

        int maxSide = 0;
        for(auto &side : widths){
            if(heights.count(side)){
                maxSide = max(maxSide ,  side);
            }
        }
        return maxSide == 0 ? -1 : (1LL  * maxSide * maxSide)%mod;
    }
};