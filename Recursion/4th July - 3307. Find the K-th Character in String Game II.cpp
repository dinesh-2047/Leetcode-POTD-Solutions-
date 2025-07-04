// 3307. Find the K-th Character in String Game II/



class Solution {
public:
int n ; 
char solve(long long k , vector<int> &operations){
    if(k==1) return 'a';

      long long length = 1; 

      long long operation = -1; 

      for(int i = 0 ; i <n; i++){
          length *= 2; 
          if(length >= k) {
             k = k - length/2; 
             operation = operations[i];
             break; 
          }
      }

      char ch = solve(k , operations);

      if(operation == 0 ){
         return ch;
      }

      if(ch == 'z') return 'a';

      return ch + 1; 
}

    char kthCharacter(long long k, vector<int>& operations) {
         n = operations.size();

         return solve(k , operations);
    }
};