// 2943. Maximize Area of Square Hole in Grid


class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));


        int maxConsHBars = 1; 
        int maxConsVBars = 1; 

        int consHBars = 1;  

        for(int i = 1; i  < hBars.size(); i++){
            if(hBars[i] - hBars[i - 1] == 1){
                consHBars++;
            }
            else consHBars = 1; 

            maxConsHBars = max(maxConsHBars, consHBars);
        }


         int consVBars = 1; 
         for(int i = 1; i  < vBars.size(); i++){
            if(vBars[i] - vBars[i - 1] == 1){
                consVBars++;
            }
            else consVBars = 1; 

            maxConsVBars = max(maxConsVBars, consVBars);
         }

         int side = min(maxConsHBars + 1, maxConsVBars+1);

         return side * side;
    }
};