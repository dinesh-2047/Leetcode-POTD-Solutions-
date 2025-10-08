// 2300. Successful Pairs of Spells and Potions




// approach 1 /
class Solution {
public:
int getCount( vector<int> &potions, int spell, long long success){
       int m = potions.size();

       int idx = -1 ; 
       int l =0 ; 
       int r = m-1; 

       while(l <= r){
          int mid = l + (r -l )/2;
          if((1LL * potions[mid] * spell) >= success){
              idx = mid ; 
             r= mid -1; 
          }
          else l = mid + 1; 
       }
       if(idx  == -1 ) return 0 ; 
       else return m - idx; 
}

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        int n = spells.size();
        int m = potions.size();

        vector<int>result(n);

        sort(potions.begin(), potions.end());

        for(int i = 0 ; i < n; i++){
            result[i] = getCount( potions , spells[i], success);
        }
        return result; 
        
    }
};







//Approach2 
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        int n = spells.size();
        int m = potions.size();

        vector<int>result(n);

        sort(potions.begin(), potions.end());

        for(int i = 0 ; i < n; i++){
           long long minValue = ceil((1.0 * 1LL * success) /spells[i]);
           if(minValue > potions[m-1]){
               result[i] = 0; 
               continue; 
           }

           int idx = lower_bound(begin(potions), end(potions), minValue) -begin(potions);
            result[i] = m - idx ;
        }
        return result; 
        
    }
};