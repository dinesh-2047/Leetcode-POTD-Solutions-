// 3013. Divide an Array Into Subarrays With Minimum Cost II

class Solution {
public:
    using ll = long long;
    multiset<int> small, large;
    ll sum = 0;
    int k;

    void add(int x) {
        small.insert(x);
        sum += x;

        if (small.size() > k) {
            auto it = prev(small.end());
            sum -= *it;
            large.insert(*it);
            small.erase(it);
        }
    }

    void remove(int x) {
        auto it = small.find(x);
        if (it != small.end()) {
            sum -= x;
            small.erase(it);

            if (!large.empty()) {
                auto lit = large.begin();
                sum += *lit;
                small.insert(*lit);
                large.erase(lit);
            }
        } else {
            auto itL = large.find(x);
            if (itL != large.end())
                large.erase(itL);
        }
    }

    long long minimumCost(vector<int>& nums, int K, int dist) {
        int n = nums.size();
        k = K - 1;
        sum = 0;

        for (int i = 1; i <= dist + 1; i++) {
            add(nums[i]);
        }

        ll result = nums[0] + sum;
        int i = 1;
        int j = dist + 2;

        while (j < n) {
            remove(nums[i]);
            add(nums[j]);

            result = min(result, nums[0] + sum);

            i++;
            j++;
        }


        return result;
    }
};