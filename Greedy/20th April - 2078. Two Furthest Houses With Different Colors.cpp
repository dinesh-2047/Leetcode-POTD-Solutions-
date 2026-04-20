// 2078. Two Furthest Houses With Different Colors


class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int i = 0 ; 
        int j = n-1 ; 
        int result = 0 ; 

        while(i < n ){
            if(colors[i] != colors[n-1]){
                result = max(result, abs(i - n )-1);
                
            }
            if(colors[j] != colors[0]){
                result = max(result, j);
            }
            i++;
            j--;
            
        }
        return result; 
    }
}; 