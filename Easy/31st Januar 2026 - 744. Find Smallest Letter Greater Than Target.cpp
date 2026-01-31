// 744. Find Smallest Letter Greater Than Target


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        int idx = upper_bound(begin(letters), end(letters), target)-begin(letters);

        return idx == n ? letters[0] : letters[idx];
    }
};