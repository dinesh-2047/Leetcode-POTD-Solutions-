// 1291. Sequential Digits


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result; 

        for(int len = 2;  len < 10; len++){
       
            int i = 1; 
            string num = "" ;  
            while(i < 10){
                num = num + to_string(i);
                if(num.length() == len){
                    int n = stoi(num);
                    if(n >= low && n <= high){
                        result.push_back(n);
                    }
                   num.erase(begin(num));
                }
                i++;
                
            }
        }
        return result; 
    }
};