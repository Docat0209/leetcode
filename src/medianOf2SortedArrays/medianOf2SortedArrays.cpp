// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Docat
// Date   : 02-29-2024

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;

        int m = nums1.size();
        int m_left = 0;
        int n = nums2.size();
        int n_left = 0;

        while(m-m_left&&n-n_left){
            if(nums1[m_left] < nums2[n_left]){
                merge.push_back(nums1[m_left]);
                m_left++;
            }else{
                merge.push_back(nums2[n_left]);
                n_left++;
            }
        }

        if(m-m_left){
            merge.insert(merge.end(), nums1.begin()+m_left, nums1.end());
        }else{
            merge.insert(merge.end(), nums2.begin()+n_left, nums2.end());
        }
        
        return (m+n)%2 ? merge[(m+n+1)/2 - 1] : (merge[(m+n)/2-1] + merge[(m+n)/2])/2.0;
    }
};