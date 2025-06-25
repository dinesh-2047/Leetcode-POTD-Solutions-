// 2040. Kth Smallest Product of Two Sorted Arrays


/*
✨ LeetCode POTD: Kth Smallest Product of Two Sorted Arrays (2040) 🔢🔍

⁉️ Problem Statement (LeetCode):
🔸 You are given two sorted integer arrays nums1 and nums2, and an integer k.
🔸 Your task is to find the k-th smallest product that can be formed by multiplying one element from nums1 with one from nums2.
🔸 Return this k-th smallest product.

🔎 Approach I Used (C++):

▶️ Binary Search on Product Space + Two-Pointer Counting Strategy

🔹 Perform binary search over a very large number range (−1e10 to 1e10) to find the smallest product mid such that there are at least k products ≤ mid.

🔹 To do this efficiently, use a helper function findCountSmallest():
• For each element in nums1, binary search in nums2 to count how many products with it are ≤ mid.
• If nums1[i] < 0, product decreases as nums2[j] increases → search for the leftmost index satisfying nums1[i] * nums2[j] ≤ mid.
• If nums1[i] ≥ 0, product increases with nums2[j] → search for the rightmost index satisfying the condition.
• Accumulate counts across all elements.

🔹 Based on total count of products ≤ mid, move the binary search window:
• If count ≥ k, update result and move left.
• If count < k, move right.

🔹 The answer converges to the exact k-th smallest product.








*/






//Approach (Binary Search on Answer)
//T.C : O(log(maxP-minP) * n * log(m)
//S.C : O(1)
class Solution {
public:

    long long findCountSmallest(vector<int>& nums1, vector<int>& nums2, long long midProduct) {
        long long productsCount = 0;

        int n = nums2.size();

        for(int i = 0; i < nums1.size(); i++) {
            //nums1[i]

            if(nums1[i] >= 0) {
                int l = 0;
                int r = n-1;
                int m = -1; //invalid index on left hand side

                while(l <= r) {
                    int mid = l + (r-l)/2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct) {
                        m = mid;
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }
                productsCount += (m+1); //covered by nums1[i]
            } else {
                //product will be negative and right hand side will contain smaller products and left hand side larger
                int l = 0;
                int r = n-1;
                int m = n; //invalid index on the right hand side

                while(l <= r) {
                    int mid = l + (r-l)/2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct) {
                        m = mid;
                        r = mid-1;
                    } else {
                        l = mid+1;
                    }
                }
                                                    
                productsCount += (n - m);
            }
        }
        return productsCount;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long result = 0;

        long long l = -1e10; //min product possible
        long long r = 1e10; //max product possible

        while(l <= r) {
            long long midProduct = l + (r-l)/2;

            //check if this is kth smallest or not

            long long countSmallest = findCountSmallest(nums1, nums2, midProduct);

            if(countSmallest >= k) {
                result = midProduct;
                r = midProduct-1;
            } else {
                l = midProduct+1;
            }
        }
        return result;
    }
};