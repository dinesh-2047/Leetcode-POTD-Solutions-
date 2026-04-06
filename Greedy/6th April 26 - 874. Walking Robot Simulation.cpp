// 874. Walking Robot Simulation

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int , int>>st;
        for(auto &obst : obstacles){
            st.insert({obst[0], obst[1]});
        }

        int x = 0 ; 
        int y = 0 ; 

        char dir = 'N';

        int result = 0 ;  

        for(auto &c : commands){
            if(c == -2){
                if(dir == 'N') dir = 'W';
                else if(dir == 'S') dir = 'E';
                else if(dir == 'W') dir = 'S';
                else if(dir == 'E') dir = 'N';
            }
           else if(c == -1){
                if(dir == 'N') dir = 'E';
                else if(dir == 'S') dir = 'W';
                else if(dir == 'W') dir = 'N';
                else if(dir == 'E') dir = 'S';
            }
            else {
                 int k = c; 
                if(dir == 'N'){
                    for(int i = 0; i < k; i++ ){
                         pair<int , int> p = {x, y + 1};
                         if(st.count(p)) break; 
                         y++;
                    }
                }
                else if(dir == 'S'){
                     for(int i = 0; i < k; i++ ){
                         pair<int , int> p = {x, y - 1};
                         if(st.count(p)) break; 
                         y--;
                    }
                }
                else if(dir == 'W' ){
                    for(int i = 0; i < k; i++ ){
                         pair<int , int> p = {x-1, y};
                         if(st.count(p)) break; 
                         x--;
                    }
                }
                else if(dir == 'E'){
                      for(int i = 0; i < k; i++ ){
                         pair<int , int> p = {x+1, y};
                         if(st.count(p)) break; 
                         x++;
                    }
                }
                result = max(result, x * x + y * y ); 
            }
        }
        return result; 
    }
};