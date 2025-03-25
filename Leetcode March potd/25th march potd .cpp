// 3394. Check if Grid can be Cut into Sections


class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int>>x_axis;
            vector<vector<int>>y_axis;
    
            vector<vector<int>>x_axis_result;
            vector<vector<int>>y_axis_result; 
    
            for(int i = 0 ; i<rectangles.size(); i++){
                x_axis.push_back({rectangles[i][0], rectangles[i][2]});
                y_axis.push_back({rectangles[i][1], rectangles[i][3]});
            }
             
             sort(x_axis.begin(), x_axis.end());
             sort(y_axis.begin(), y_axis.end());
    
             x_axis_result.push_back(x_axis[0]);
             y_axis_result.push_back(y_axis[0]);
    
             for(int i = 1; i < x_axis.size() ; i++){
                     int start_x = x_axis[i][0];
                     int end_x =  x_axis_result.back()[1];
                     int start_y = y_axis[i][0];
                     int end_y = y_axis_result.back()[1];
     
                     if(start_x < end_x){
                          x_axis_result.back()[0] = min(x_axis_result.back()[0], start_x);
                          x_axis_result.back()[1] = max(x_axis_result.back()[1], x_axis[i][1]);
                     }
                     else x_axis_result.push_back(x_axis[i]);
    
                     if(start_y < end_y){
                        y_axis_result.back()[0] = min(y_axis_result.back()[0], start_y);
                          y_axis_result.back()[1] = max(y_axis_result.back()[1], y_axis[i][1]);
                     }
                     else y_axis_result.push_back(y_axis[i]);
                    
    
             }
    
             if(x_axis_result.size()>=3 || y_axis_result.size()>=3) return true; 
             else return false; 
            
    
        }
    };