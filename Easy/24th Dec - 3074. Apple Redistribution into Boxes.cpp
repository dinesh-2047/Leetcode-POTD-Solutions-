// 3074. Apple Redistribution into Boxes



class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        sort(rbegin(capacity), rend(capacity));

        int apples = accumulate(begin(apple), end(apple), 0);
         
        for(int i = 0 ; i  < m ; i++){
             apples -= capacity[i];
             if(apples <= 0 ) return i+1; 
        }
        return 0; 
    }
};class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        sort(rbegin(capacity), rend(capacity));

        int apples = accumulate(begin(apple), end(apple), 0);
         
        for(int i = 0 ; i  < m ; i++){
             apples -= capacity[i];
             if(apples <= 0 ) return i+1; 
        }
        return 0; 
    }
};