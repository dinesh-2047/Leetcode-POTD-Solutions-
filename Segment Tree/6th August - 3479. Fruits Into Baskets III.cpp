// 3479. Fruits Into Baskets III

/*
✨ LeetCode POTD: Fruits Into Baskets III (3479) 🧠

⁉️ Problem Statement:
🔸 You are given two integer arrays fruits and baskets, both of length n.
🔸 Each fruits[i] denotes the size (or quantity) of fruit type i, and each baskets[j] represents the capacity of basket j.
🔸 You must place each fruit into the leftmost available basket whose capacity is ≥ the fruit’s size.
🔸 Each basket can hold at most one fruit.
🔸 Any fruit that cannot be placed into any suitable basket is left unplaced.
🔸 Return the number of fruits that remain unplaced after attempting to fit all.

🔎 My Approach:

🔹 Segment Tree Construction (build)
We construct a segment tree over the baskets[] array.
Each node stores the maximum capacity among baskets in that segment range.
This preprocessing allows us to quickly check whether any basket in a given range can hold a particular fruit.

🔹 Placing Fruits with Greedy Logic (segQuery)
For each fruit:
🔹 Start at the root of the segment tree and attempt to find the leftmost basket that can accommodate the fruit.
🔹 If the current segment’s maximum is less than the fruit size, skip the entire segment (early pruning).
🔹 If we're at a leaf node (i.e., one basket), and it fits, we place the fruit and mark the basket as used by setting the node value to -1.
🔹 After a successful placement, propagate updated max values up the tree to reflect the new availability.

🔹 Tracking Unplaced Fruits
If no valid basket is found during the query, we increment the unplaced fruit counter.




*/



class Solution {
public:
vector<int>segTree; 
void build(int i , int l, int r , vector<int> &baskets){
     if(l==r){
        segTree[i] = baskets[l];
        return ; 
     }

     int mid = l + (r- l) /2; 
     build(2*i+1, l , mid , baskets);
     build(2*i+2, mid + 1, r , baskets);

     segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
}


bool segQuery(int i , int l , int r , int &fruit , vector<int> &baskets){
    if(segTree[i]  < fruit){
        return false; 
    }

    if(l==r){
        segTree[i] = -1; 
        return true; 
    }

    int mid = l + (r-l)/2; 
    bool placed = false; 
    if(segTree[2*i+1] >= fruit){
          placed = segQuery(2*i+1, l , mid , fruit , baskets);
    } 
    else{
        placed = segQuery(2*i +2, mid + 1, r, fruit , baskets);
    }
    

    segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);

    return placed; 
}

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int n = fruits.size();

          segTree.resize(4*n, -1);

          build(0, 0 , n-1 , baskets);
          int unplaced = 0; 
          for(auto &fruit : fruits){
              if(!segQuery(0, 0, n-1 , fruit, baskets)){
                unplaced++;
              }
          }
          return unplaced; 
    }
};