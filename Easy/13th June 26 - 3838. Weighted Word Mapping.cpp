// 3838. Weighted Word Mapping

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for(auto &word : words){
            int w = 0 ; 
            for(const auto &ch : word){
                w += (weights[ch - 'a']);
            }
             w %= 26; 
             result += ('z' - w); 
        }
        return result; 
    }
};