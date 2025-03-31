// 2551. Put Marbles in Bags

// Approach 1///
class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n = weights.size();
    
            vector<int>pairSum(n-1 );
    
            for(int i = 0 ; i<n-1; i++){
                pairSum[i] = weights[i] + weights[i+1];
            }
            sort(pairSum.begin(), pairSum.end());
            
            long long  maxSum = 0 ; 
            long long  minSum = 0 ; 
            for(int i = 0 ; i<k-1; i++){
                minSum += pairSum[i];
                maxSum += pairSum[n-2-i];
            }
            return maxSum - minSum ; 
        }
    };


    // Approach 2 

    class Solution {
        public:
            long long putMarbles(vector<int>& weights, int k) {
                int n = weights.size();
        
               
                priority_queue<int>maxPairSum;
                priority_queue<int, vector<int>, greater<>>minPairSum ; 
        
                for(int i = 0 ; i<n-1; i++){
                    maxPairSum.push(weights[i] + weights[i+1]);
                    minPairSum.push(weights[i] + weights[i+1]);
                }
              
                
                long long  maxSum = 0 ; 
                long long  minSum = 0 ; 
                for(int i = 0 ; i<k-1; i++){
                    minSum += minPairSum.top();
                    maxSum += maxPairSum.top();
                    minPairSum.pop();
                    maxPairSum.pop();
                }
                return maxSum - minSum ; 
            }
        };