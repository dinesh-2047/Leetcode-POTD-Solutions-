// 3321. Find X-Sum of All K-Long Subarrays II


class Solution {
public:
int k, x ; 

void removeFromSet(pair<int , int>p , set<pair<int , int>> &main , set<pair<int , int>> &sec, long long &sum ){
      
      if(main.count(p)){
        sum -= 1LL * p.first * p.second; 
        main.erase(p);

        if(!sec.empty()){
            auto largest = *sec.rbegin();
            sec.erase(largest);
            main.insert(largest);

            sum += 1LL * largest.first * largest.second; 
        }
      }

      else sec.erase(p);
    

}
void insertInSet(pair<int , int>p , set<pair<int , int>> &main , set<pair<int , int>> &sec, long long &sum ){
     
      if(main.size() < x || p > *main.begin()){
        sum += 1LL * p.first * p.second; 

        main.insert(p);

        if(main.size() > x ){
            auto smallest = *main.begin();
            sum -= 1LL * smallest.first * smallest.second; 
            main.erase(smallest);
            sec.insert(smallest);
        }
        
     }
     else sec.insert(p);

}



    vector<long long> findXSum(vector<int>& nums, int K, int X) {
        int n = nums.size();
         k = K;
         x = X; 
        vector<long long> result;
        set<pair<int, int>> main; // top x {freq, element}
        set<pair<int, int>> sec;   // rem {req, element}
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        long long sum = 0;

        while (j < n) {
            if (mp[nums[j]] > 0) {
                removeFromSet({mp[nums[j]], nums[j]}, main, sec, sum);
            }

            mp[nums[j]]++;
            insertInSet({mp[nums[j]], nums[j]}, main, sec, sum);

            if (j - i + 1 == k) {
                result.push_back(sum);

                removeFromSet({mp[nums[i]], nums[i]}, main, sec, sum);

                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                else insertInSet({mp[nums[i]], nums[i]}, main , sec , sum );
                i++;
            }
            j++;
        }
        return result;
    }
};