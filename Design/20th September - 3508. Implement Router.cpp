// 3508. Implement Router



class Router {
public:
    int limit;
    set<vector<int>> src_dest_time_st;
    queue<vector<int>> src_dest_time_q;
    unordered_map<int, vector<int>> dest_time;

    Router(int memoryLimit) { 
        limit = memoryLimit; 
    }

    bool addPacket(int source, int destination, int timestamp) {
         if(src_dest_time_st.count({source, destination , timestamp}) ) return false; 

         if(src_dest_time_st.size() >= limit){
              vector<int>vec = src_dest_time_q.front();
              src_dest_time_q.pop();
              src_dest_time_st.erase(vec);
              dest_time[vec[1]].erase(dest_time[vec[1]].begin());
         }

         src_dest_time_st.insert({source, destination , timestamp});
         src_dest_time_q.push({source, destination , timestamp});
         dest_time[destination].push_back(timestamp);
         return true; 
    }

    vector<int> forwardPacket() {
        if (src_dest_time_st.empty()) return {};

        vector<int>vec = src_dest_time_q.front();
        src_dest_time_q.pop();
        src_dest_time_st.erase(vec);

        dest_time[vec[1]].erase(dest_time[vec[1]].begin());

        return vec;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto &vec = dest_time[destination];
        auto l = lower_bound(vec.begin(), vec.end(), startTime);
        auto r = upper_bound(vec.begin(), vec.end(), endTime);
        return r - l;
    }
};
