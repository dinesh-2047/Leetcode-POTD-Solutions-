// 135. Candy

/*
✨ LeetCode POTD: Candy (135) 🍭

 ⁉️ Problem Statement:
 🔸 There are n children standing in a line.
 🔸 Each child is assigned a rating value.
 🔸 You must give each child at least one candy.
 🔸 Children with a higher rating than their neighbors must get more candies.
 🔸 Return the minimum number of candies you need to distribute.

🔎 Approaches Used:
1️⃣ Sorting + Greedy with Index Mapping
 🔹 Pair each child’s rating with their index, then sort based on rating.
 🔹 Iterate over sorted children:
 - For each child, check left and right neighbors.
 - If the current child has a higher rating than a neighbor, update their candy count to max(current, neighbor + 1).
 🔹 Ensures minimum candies while respecting both neighbors.

2️⃣ Two Pass Greedy (Left to Right & Right to Left)
 🔹 Left pass: if a child has a higher rating than the left neighbor, give one more candy.
 🔹 Right pass: if a child has a higher rating than the right neighbor, take the max of current and right neighbor's candy + 1.

3️⃣ Single Pass with Peaks and Dips (Space Optimized)
 🔹 Initialize total candies to n (1 per child).
 🔹 Traverse from left to right using a single pass:
 - Increasing sequence (peak):
 - If ratings[i] > ratings[i-1], increment peak++ and add it to total candies.
 - Decreasing sequence (dip):
 - If ratings[i] < ratings[i-1], increment dip++ and add it to total candies.
 🔹 Adjustment Step:
 - When a peak is followed by a dip (i.e., a "mountain"), the peak element is double-counted.
 - To fix this, subtract min(peak, dip) from total candies.
 */



// Approach 1 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int, int>> vec(n);

        for (int i = 0; i < n; i++) {
            vec[i] = {ratings[i], i};  // {rating, index}
        }

        sort(vec.begin(), vec.end());  // Sort by rating (low to high)

        vector<int> distribution(n, 1);  // Everyone gets at least 1 candy

        for (int i = 0; i < n; i++) {
            int idx = vec[i].second;

            // Check left neighbor
            if (idx - 1 >= 0 && ratings[idx] > ratings[idx - 1]) {
                distribution[idx] = max(distribution[idx], distribution[idx - 1] + 1);
            }

            // Check right neighbor
            if (idx + 1 < n && ratings[idx] > ratings[idx + 1]) {
                distribution[idx] = max(distribution[idx], distribution[idx + 1] + 1);
            }
        }

        // Uncomment to see distribution
        // for (int d : distribution) cout << d << " ";

        return accumulate(distribution.begin(), distribution.end(), 0);
    }
};






//Approach 2 

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int>candies(n, 1);

        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1; 
            }
        }

        for(int i = n-2; i >=0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }

        return accumulate(begin(candies), end(candies),0);
    }
};





//Approach 3 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = n; 
     

          
    int i = 1 ; 
    while(i < n ){
            if(ratings[i] == ratings[i-1]) {
                i++;
                continue; 
            }
            int peak = 0 ; 
            while(ratings[i]>ratings[i-1]){
                peak++;
                candies += peak;
                i++;
                if(i==n) return candies;  

            }

         int dip = 0 ; 
         while(i<n && ratings[i] < ratings[i-1]){
            dip++;
            candies += dip ; 
            i++;
        
         }


       candies -= min(peak , dip );
        }
        return candies; 
    }
};