// 2780. Minimum Index of a Valid Split

// Approach 1
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            
            unordered_map<int, int>mp1; 
            unordered_map<int , int>mp2; 
    
    
            for(int i = 0 ;i<n; i++){
                mp2[nums[i]]++;
            }
             
             int f1 = 0;
             int f2 = 0; 
            for(int i = 0 ; i<n; i++){
                mp1[nums[i]]++;
                mp2[nums[i]]--;
    
                f1 = mp1[nums[i]];
                f2 = mp2[nums[i]];
    
                if(f1 > (i+1)/2 && f2 >(n-i-1)/2) return i ; 
            }
            return -1; 
        }
    };


//Approach 2 
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
    
            unordered_map<int, int>freq; 
            for(int i = 0 ; i<n; i++){
                freq[nums[i]]++;
            }
    
            int dominant = -1 ; 
            int maxFreq = 0;
            for(auto it = freq.begin(); it!=freq.end(); it++){
                if(it->second > maxFreq){
                    maxFreq = it->second; 
                    dominant = it->first; 
                }
            }
            cout<<"dominant = "<< dominant<<endl; 
            cout<<"maxFreq = "<<maxFreq<<endl; 
    
             
          int f1 =0 ;
          int f2 = maxFreq ;
    
         for(int i = 0 ; i<n-1; i++){
            if(nums[i]==dominant) {
                f1++;
                f2--;
            }
             if((f1 * 2) >(i+1) && (f2 * 2) > (n-i-1) ) return i;
         }
    
    
           
             return -1; 
              
        }
    };


//Approach 3
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
    
            int dominant = -1; 
            int cnt = 0 ; 
            for(int i = 0 ; i<n; i++){
                if(nums[i]==dominant){
                    cnt++;
                   
                }
                else if(cnt ==0 ) {
                     dominant = nums[i];
                }
                else cnt--;
            }
    
            int f = 0 ; 
            for(int i = 0; i<n; i++){
                if(nums[i] == dominant) f++;
            }
    
            int f1 = 0 ;
            for(int i = 0 ; i<n; i++){
                if(nums[i]==dominant){
                    f1++;
                }
                int f2 = f - f1;
    
                if(f1*2 > (i+1) && f2 * 2 > (n-i-1)) return i ;
            }
            return -1; 
        }
    };