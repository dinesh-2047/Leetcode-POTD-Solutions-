2561. Rearranging Fruits


// Approach 1 
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();

        long long result = 0  ; 

      unordered_map<int, int>mp ; 
      unordered_map<int , int>mp1; 
      unordered_map<int , int>mp2 ; 

      int globalMin = INT_MAX;


      for(int i = 0 ; i < n; i++){
        mp[basket1[i]]++;
        mp[basket2[i]]++;
        mp1[basket1[i]]++;
        mp2[basket2[i]]++;

        globalMin = min({globalMin , basket1[i], basket2[i] });
      }
     
     vector<pair<int , int>>b1Add;
     vector<pair<int , int>>b2Add;


      for(auto &[num , cnt] : mp){
          if(cnt %2 !=0 ) return -1; 

          int r = cnt/2; 

          if(mp1[num] == r) continue; 
          
          if(mp1[num] > r|| !mp2.count(num) ) {
              b2Add.push_back({num, mp1[num]-r});
          }
          if(mp2[num] > r || !mp1.count(num)){
              b1Add.push_back({num, mp2[num] - r});
          }


      }

      sort(all(b1Add));
      sort(rall(b2Add));

      

      int i = 0 ; 
      int j = 0 ; 
    

      while (i < b1Add.size() && j < b2Add.size()) {
            int curr1Num = b1Add[i].first;
            int curr1Freq = b1Add[i].second;

            int curr2Num = b2Add[j].first;
            int curr2Freq = b2Add[j].second;

            int take = min(curr1Freq, curr2Freq);
            result += 1LL * take * min(1LL * min(curr1Num, curr2Num), 2LL *globalMin) ;

            b1Add[i].second -= take;
            b2Add[j].second -= take;

            if (b1Add[i].second == 0) i++;
            if (b2Add[j].second == 0) j++;
        }
       

          return result; 


    }
};











//Approach 2 Clean code 
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        unordered_map<int , int>mp ; 

        int globalMin = INT_MAX;

        for(int i = 0 ; i < n; i++){
            mp[basket1[i]]++;
            mp[basket2[i]]--;
            globalMin = min({globalMin , basket1[i], basket2[i]});
        }

        vector<int>vec; 
        for(auto &[num, cnt] : mp){
            if(cnt%2==1) return -1;

            int r = abs(cnt/2); 
            while(r){
                vec.push_back(num);
                r--;
            }
        }

        sort(begin(vec), end(vec));
       long long result = 0 ; 
        for(int i = 0 ; i < vec.size()/2 ;i++){
             result += 1LL * min(1LL * vec[i], 2LL*globalMin);
        }
        return result; 

        
    }
};