// 2211. Count Collisions on a Road


class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

       int result = 0 ; 
       int i = 0 ; 
       int j = n - 1; 

       while(i < n && directions[i] == 'L'){
             i++;
       }
       while( j >= 0 && directions[j] == 'R'){
        j--;
       }

       while(i <= j){
           if(directions[i] == 'S'){
              i++;
            continue;
           }
           else result++;
           i++;
       }
       return result; 
    }
};