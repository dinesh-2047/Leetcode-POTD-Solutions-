// 3396. Minimum Number of Operations to Make Elements in Array Distinct


// Approach 1 
class Solution {
    public:
    int n ; 
    bool checkDistinct(vector<int> nums, int st ){
        sort(nums.begin()+st, nums.end());
        for(int i = st; i<n-1; i++){
            cout<<nums[i]<<endl; 
            if(nums[i] == nums[i+1]) return false; 
        }
        cout<<"true aaya h "<<endl  ;
        return true; 
    }
        int minimumOperations(vector<int>& nums) {
            n = nums.size();
    
            int minOp = 0 ; 
            for(int i = 0 ; i<n; i++){
                if(checkDistinct(nums, i )) return minOp;
    
                minOp++;
                if(i+1<n) i++;
                if(i+1<n) i++;
            }
            return minOp;
        }
    };



//Approach 2 
class Solution {
    public:
    int n ; 
    bool checkDistinct(vector<int> &nums, int st ){
        set<int>s(nums.begin()+st , nums.end());
      
    
        if(s.size() == ( n-st)) return true; 
        else return false; 
    }
        int minimumOperations(vector<int>& nums) {
            n = nums.size();
    
            int minOp = 0 ; 
            for(int i = 0 ; i<n; i++){
                if(checkDistinct(nums, i )) return minOp;
    
                minOp++;
                if(i+1<n) i++;
                if(i+1<n) i++;
            }
            return minOp;
        }
    };




// Approach 3 
class Solution {
    public:
    int n ; 
        int minimumOperations(vector<int>& nums) {
            n = nums.size();
            set<int>st;
    
            int minOp = 0 ; 
            for(int i =n-1; i >= 0; i--){
                 if(st.count(nums[i])) return (i/3)+1;
                 st.insert(nums[i]);
            }
            return minOp;
        }
    };