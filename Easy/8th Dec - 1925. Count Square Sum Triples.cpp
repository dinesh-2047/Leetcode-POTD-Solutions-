// 1925. Count Square Sum Triples

class Solution {
public:
    int countTriples(int n) {
        int result = 0 ; 
        for(int i = 1; i <= n ; i++){
            for(int j = i ; j <= n;  j++){
               int ab = (i * i ) + (j * j );
               int c = sqrt(ab);

               if(c <= n && c * c == ab)  result+=2; 
            }
        }
        return result; 
    }
};