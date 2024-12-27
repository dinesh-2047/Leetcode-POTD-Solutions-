// brute force code -> TLE
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        for(int i = 0; i<n; i++ ){
            for(int j = i+1; j<n; j++){
               int possibleAns = values[i] + values[j] + (i - j);
                ans = max(ans , possibleAns);

            }
        }
        return ans;
    }
};



// using a vector to store max elements 
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int>vec(n,0); // stores the maximum value at values[i] index i in values array

      vec[0] = values[0] + 0;
      for(int i = 1; i<n; i++){
        vec[i] = max(values[i]+i, vec[i-1]);

      }
      int result = 0;
      for(int j = 1; j<n; j++){
       int x =  values[j]-j;
       int y = vec[j-1]; //max values of values[i] + i in LHS

        result  = max(result , x+y);
       }
      return result ;
    }
};


//to improve SC we replace vector with variable that track max elememt 
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
      
      int result = 0;
      int maxTillNow = values[0] + 0; // this stores the max value of values[i] + i till now 
      for(int j = 1; j<n; j++){
       int x =  values[j]-j;
       int y = maxTillNow;

        result  = max(result , x+y);
        maxTillNow = max(maxTillNow , values[j] + j);
       }
      return result ;
    }
};



//we can also do this problem by using priority queue

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
      
      int result =0;
      priority_queue<int>pq;
      pq.push( values[0] + 0); // this stores the max value of values[i] + i till now 
      for(int j = 1; j<n; j++){
       int x =  values[j]-j;
       int y = pq.top();

        result  = max(result , x+y);
        pq.push( values[j] + j);
       }
      return result ;
    }
};



