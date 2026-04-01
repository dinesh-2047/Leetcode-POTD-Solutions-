// 2751. Robot Collisions

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {positions[i], i};
        }

        sort(begin(vec), end(vec));

        stack<int> st;

        for (int i = 0; i < n; i++) {
            int idx = vec[i].second;
            char dir = directions[idx];
            int health = healths[idx];

            if (st.empty()) {
                st.push(idx);
                continue;
            }
            if (dir == directions[st.top()] ||(dir == 'R' && directions[st.top()] == 'L')) {
                st.push(idx);
                continue;
            }

            else {
                bool flag = false; 
                while (!st.empty() && dir == 'L' && directions[st.top()] == 'R') {

                    if (health == healths[st.top()]) {
                        st.pop();
                        flag = true; 
                        break;
                    }

                    else if (health < healths[st.top()]) {
                        healths[st.top()]--;
                        flag = true; 
                        break ; 
                    }

                    else if (health > healths[st.top()]) {
                        st.pop();
                        healths[idx]--;
                        health--;
                        
                    }
                }
                if(!flag){
                    st.push(idx);
                }
            }
        }

        vector<int> idxx;

        while (!st.empty()) {
            idxx.push_back(st.top());
            st.pop();
        }

        sort(begin(idxx), end(idxx));
        vector<int> result;
        for (int i = 0; i < idxx.size(); i++) {
            result.push_back(healths[idxx[i]]);
        }
        return result;
    }
};