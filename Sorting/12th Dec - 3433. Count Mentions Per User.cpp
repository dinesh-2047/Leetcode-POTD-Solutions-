// 3433. Count Mentions Per User


class Solution {
public:
static bool cmp(const vector<string>& a, const vector<string>& b) {
    int t1 = stoi(a[1]);
    int t2 = stoi(b[1]);

    if (t1 != t2)
        return t1 < t2;

    return a[0] == "OFFLINE" && b[0] == "MESSAGE";
}

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
         vector<int>mentions(numberOfUsers, 0);

         sort(begin(events), end(events), cmp);

         vector<int>onlineTime(numberOfUsers, 0); 

         
         for(auto &event : events){
            int time = stoi(event[1]);
            string type = event[0];

            if(type == "OFFLINE"){
                onlineTime[stoi(event[2])] = time + 60; 
            }

            else {
                string mention_string  = event[2];
                if(mention_string == "ALL"){
                    for(int i = 0 ; i < numberOfUsers ; i++){
                        mentions[i]++;
                    }
                }
                
                else if(mention_string == "HERE"){
                    for(int i  = 0 ; i < numberOfUsers; i++){
                        if(onlineTime[i] <= time){
                            mentions[i]++;
                        }
                    }
                }
                else {
                    stringstream ss(mention_string);
                    string token ; 

                    while(ss >> token){
                        int id = stoi(token.substr(2));
                        mentions[id]++;
                    }
                }
            }
         }
         return mentions; 
    }
};