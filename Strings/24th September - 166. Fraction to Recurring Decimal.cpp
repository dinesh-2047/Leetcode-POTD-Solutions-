// 166. Fraction to Recurring Decimal


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
       string result = "";
      if(numerator ==0 ) return "0";

      if(((long long)(numerator) * (long long)(denominator) )< 0 ){
        result.push_back('-');
      }

       long long num = labs(numerator);
       long long den = labs(denominator);

       long long div = num/den;
       result += to_string(div);

       long long rem = num%den;
       if(rem == 0 ){
        return result; 
       }

       result.push_back('.');

       unordered_map<int , int>mp ; 

       while(rem != 0 ){
           if(mp.count(rem)){
              result.insert(mp[rem], 1, '(');
              result.push_back(')');
              break; 
           }
          
          mp[rem] = result.length();

          rem *= 10;

          div = rem/den; 
          result += to_string(div);

           rem = rem % den; 
            
       }
       return result; 

       

    }
};