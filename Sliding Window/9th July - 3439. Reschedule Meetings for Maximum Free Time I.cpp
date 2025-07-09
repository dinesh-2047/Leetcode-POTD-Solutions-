// 3439. Reschedule Meetings for Maximum Free Time I


// hint : k shifting is equal to k + 1 gaps

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> gaps(n + 1);

        gaps[0] = startTime[0];
        for (int i = 1; i < n; i++) {
            gaps[i] = startTime[i] - endTime[i - 1];
        }

        gaps[n] = eventTime - endTime[n - 1];

        int result = 0;
        int i = 0;
        int j = 0;
        int sum = 0;

        while (j <= n) {
            sum += gaps[j];
            if (j - i + 1 == k + 1) {
                result = max(result, sum);
                sum -= gaps[i];
                i++;
            }
            j++;
        }

        return result;
    }
};