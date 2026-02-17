// 401. Binary Watch

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int h = 0; h <= 11; h++) {
            for (int m = 0; m <= 59; m++) {
                int h_set_bits = __builtin_popcount(h);
                int m_set_bits = __builtin_popcount(m);

                if (h_set_bits + m_set_bits == turnedOn) {
                    string time = to_string(h) + ":";
                    time += to_string(m);
                    if (m < 10) {
                        time = to_string(h) +  ":0";
                        time += to_string(m);
                    }
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};