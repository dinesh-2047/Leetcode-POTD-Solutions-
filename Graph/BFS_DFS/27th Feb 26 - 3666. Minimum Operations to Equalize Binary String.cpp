// 3666. Minimum Operations to Equalize Binary String

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();

        int startZeros = 0;
        for(char &ch : s) {
            if(ch == '0')
                startZeros++;
        }

        if(startZeros == 0) {
            return 0; 
        }

        vector<int> operations(n+1, -1);
      
        set<int> evens;
        set<int> odds;

        for(int count = 0; count <= n; count++) {
            if(count%2 == 0) {
                evens.insert(count);
            } else {
                odds.insert(count);
            }
        }

        queue<int> q;
        q.push(startZeros);
        operations[startZeros] = 0;
        if(startZeros % 2 == 0) {
            evens.erase(startZeros);
        } else {
            odds.erase(startZeros);
        }

        while(!q.empty()) {
            int z = q.front();
            q.pop();
            
            int min_new_z = z + k - 2*min(k, z);
            int max_new_z = z + k - 2*max(0, k-n+z);

            set<int> &currSet = (min_new_z%2 == 0) ? evens : odds;

            auto it = currSet.lower_bound(min_new_z);

            while(it != currSet.end() && *it <= max_new_z) {
                int newZ = *it;

                if(operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;

                    if(newZ == 0) {
                        return operations[newZ];
                    }

                    q.push(newZ);
                }

                it = currSet.erase(it);
            }
        }

        return -1;
    }
};