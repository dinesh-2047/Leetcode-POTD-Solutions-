// 3625. Count Number of Trapezoids II

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        
        unordered_map<double, vector<double>>slopeIntercept; 
        unordered_map<int , vector<double>>midPointSlope; 

        int result = 0 ; 

        for(int i = 0 ;i < n; i++){
            for(int j = i + 1; j < n ; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2 - x1; 
                int dy = y2 - y1 ; 

                double slope  = 0 ; 
                double intercept = 0  ;

                if(x2 == x1){
                    slope = 1e9 + 7; 
                    intercept  = x2;
                     
                }
                else {
                    slope = (double)(y2-y1)/(x2 - x1); 
                    intercept = (double) (y1*dx - x1 * dy)/dx;
                }
                int mid_point_key = (x1 + x2) * 10000 + (y1 + y2);
                slopeIntercept[slope].push_back(intercept);
                midPointSlope[mid_point_key].push_back(slope);
            }
        }

        for(auto &it : slopeIntercept){
            if(it.second.size() <= 1) continue; 
            map<double , int>mp; 
            for(double intercept : it.second){
                mp[intercept]++;
            }

            int prev_h_lines = 0; 
            for(auto &it : mp){
                int count = it.second; 
                result += count * prev_h_lines;

                prev_h_lines += count; 
            }
        }

        for(auto &it : midPointSlope){
            if(it.second.size() <= 1) continue; 
            map<double, int>mp; 
            for(double slope : it.second){
                mp[slope]++;
            }

             int prev_h_lines = 0; 
            for(auto &it : mp){
                int count = it.second; 
                result -= count * prev_h_lines;

                prev_h_lines += count; 
            }
            
        }
        return result; 
    }
};