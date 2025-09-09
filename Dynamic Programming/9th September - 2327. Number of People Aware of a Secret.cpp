// 2327. Number of People Aware of a Secret




/*

✨ LeetCode POTD: Number of People Aware of a Secret (2327) 🔐



⁉️ Problem Statement:

 🔸 You are given n days, and a secret is shared with one person on day 1.

 🔸 Each person can start sharing the secret with others after delay days.

 🔸 However, each person forgets the secret after forget days.

 🔸 Task → Find the total number of people who still remember the secret at the end of day n.



🔎 My Approaches:

1️⃣Approach 1 : Simulation with Queue

 🔹 Use a queue to keep track of people by the day they first learned the secret.

 🔹 For each new day, remove people who forget the secret (day == prev_day + forget).

 🔹 Count how many people are allowed to share (those with delay ≤ day - prev_day < forget).

 🔹 Push new people (sharers) into the queue with their start day.

 🔹 At the end, sum up all active people still in the queue.



2️⃣Approach 2 : Top-Down DP with Memoization

 🔹 Define solve(day) = number of people who first learn the secret on day.

 🔹 For every day, look back at possible prev_day ranges [day - forget + 1, day - delay].

 🔹 Each valid prev_day contributes new people for day.

 🔹 Use memoization to avoid recalculating solve(prev_day).

 🔹 Finally, sum up contributions from days [n - forget + 1 … n] (those who still remember).



3️⃣Approach 3 : Bottom-Up

 🔹 Build a DP array where dp[day] = number of people who first learn the secret on day.

 🔹 For each day, check all possible prev_day ranges [day - forget + 1, day - delay].

 🔹 Add their contributions to compute dp[day].

 🔹 At the end, sum up values from the last forget days.



4️⃣Approach 4 :  Optimized DP with Prefix Subtraction

 🔹 Maintain a running count of active sharers instead of looping.

 🔹 On each day:

Add dp[day - delay] (new sharers start today).

Subtract dp[day - forget] (old sharers forget today).

 🔹 Set dp[day] = count → people who first learn today.

 🔹 Sum up contributions from the last forget days to get the result.

 🔹 This reduces time complexity from O(n²) → O(n).




*/



// Approach 1 : 
class Solution {
public:
    const int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<pair<int, int>> q;
        q.push({1, 1});

        for (int day = 2; day <= n; day++) {
            while (!q.empty() && q.front().first + forget == day)
                q.pop();

            queue<pair<int, int>> temp = q;
            int today_sharing = 0;
            while (!temp.empty()) {
                auto curr = temp.front();
                temp.pop();

                int prev_day = curr.first;
                int count = curr.second;

                if (day >= prev_day + delay && day < prev_day + forget) {
                    today_sharing = (today_sharing + count) % mod;
                }
            }
            if (today_sharing > 0)
                q.push({day, today_sharing});
        }
        int person = 0;
        while (!q.empty()) {
            int count = q.front().second;
            q.pop();
            person = (person + count) % mod;
        }
        return person;
    }
};









//Approach 2 
class Solution {
public:
const int mod = 1e9 + 7;
  vector<int>dp;
int solve(int day, int delay , int forget){
    if(day == 1) return 1; 
    if(dp[day]!=-1) return dp[day];
    int result = 0 ; 
    for(int prev_day = day - forget + 1; prev_day <= day - delay; prev_day++){
          if(prev_day > 0 ){
            result = (result + solve(prev_day , delay , forget))%mod;
          }
    }
    return dp[day] =  result%mod; 
}

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int result = 0 ; 
      dp.assign(n+1, -1);
         for(int day = n- forget + 1; day <= n ; day++){
            if(day >0){
                result = (result + solve(day , delay,  forget)) %mod;
            }
         }
         return result; 
    }
};










//Approach 3:
class Solution {
public:
const int mod = 1e9 + 7; 

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1, 0) ; 
        // dp[day] = number of people who will knw the secret on day 
        dp[1] = 1;

        for(int day = 2; day <= n ; day++){
            int count = 0 ; 
            for(int prev_day = day-forget + 1; prev_day <= day - delay; prev_day++){
                if(prev_day > 0)
                count =( count + dp[prev_day])%mod;

            }
            dp[day] = count ; 
        }

        int result = 0 ; 
        for(int day = n - forget + 1; day <= n ; day++){
             if(day > 0 ){
                result  = (result + dp[day])%mod; 
             }
        }
        return result;

        
    }
};










//Approach 4:
class Solution {
public:
const int mod = 1e9 + 7; 

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1, 0) ; 
        // dp[day] = number of people who will knw the secret on day 
        dp[1] = 1;
       int count = 0 ; 
        for(int day = 2; day <= n ; day++){
            if(day - delay > 0 ){
            count = (count + dp[day - delay])%mod;
            }
            if(day - forget > 0 ){
               count = (count - dp[day - forget] + mod)%mod; 
            }  
            dp[day] = count;   
        }
        

        int result = 0 ; 
        for(int day = n - forget + 1; day <= n ; day++){
             if(day > 0 ){
                result  = (result + dp[day])%mod; 
             }
        }
        return result;

        
    }
};