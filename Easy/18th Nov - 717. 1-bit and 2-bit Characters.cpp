// 717. 1-bit and 2-bit Characters


//Approach 1
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
         int n = bits.size();
      
        for(int i = 0 ; i  < n-1; i++){
            if((bits[i] == 1 && bits[i + 1] == 0) || (bits[i] == 1 && bits[i + 1] == 1)) {
                bits[i + 1] = -1; 
                i++;
            }
        }

        if(bits[n - 1] != -1) return true; 
        return false; 
    }
};



/// approach 2 
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
         int n = bits.size();
      
        for(int i = 0 ; i  < n-1; i++){
            if((bits[i] == 1 && bits[i + 1] == 0) || (bits[i] == 1 && bits[i + 1] == 1)) {
               if(i + 1 == n-1) return false; 
               i++;
            }
        }

        return true; 
    }
};




//Approach 3
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int count1 = 0 ; 
        
         int i = n-2 ; 
       while( i >= 0 && bits[i] == 1 ){
            if(bits[i] == 1) {
                count1++;
            }
            i--;
        }
        

        return count1 %2 == 0 ;


    }
};   