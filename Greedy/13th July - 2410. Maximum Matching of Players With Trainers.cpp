// 2410. Maximum Matching of Players With Trainers


class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0;
        int j = 0;
        int result = 0;

        while (i < n && j < m) {
            if (players[i] > trainers[j]) {
                j++;
            } else {
                result++;
                i++;
                j++;
            }
        }
        return result;
    }
};