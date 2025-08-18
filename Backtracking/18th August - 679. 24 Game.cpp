// 679. 24 Game


class Solution {
public:
int n ; 
double epsilon = 1e-6; 
int target = 24;
bool solve(vector<double> &cards){
   if(cards.size() == 1){
       if(abs(cards[0] - target) <= epsilon){
        return true; 
       }
       else return false; 
   }


     for(int i = 0 ; i  < cards.size() ; i++){
        for(int j = 0 ; j < cards.size() ; j++){
            if(i == j ) continue; 

            double x = cards[i];
            double y = cards[j];
              vector<double>temp  ; 
            for(int k = 0 ; k < cards.size(); k++){
                   if(k != i && k != j){
                    temp.push_back(cards[k]);
                   }
            }

            vector<double>possibleResults = {x+y, x*y, x-y,y-x};
            if(y!=0){
              possibleResults.push_back(x/y);
            }
            if(x!=0){
                possibleResults.push_back(y/x);
            }

            for(int l = 0 ; l < possibleResults.size(); l++){
                temp.push_back(possibleResults[l]);
                if(solve(temp)) return true; 
                temp.pop_back();

            }
        }
     }
     return false; 
}

    bool judgePoint24(vector<int>& cards) {
        n = cards.size();
       vector<double>c ;

       for(int i = 0 ;i < n ; i++ ){
          c.push_back(double(cards[i]));
       }

       return solve(c);

    }
};