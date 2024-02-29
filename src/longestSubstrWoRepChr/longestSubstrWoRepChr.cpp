// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Docat
// Date   : 02-28-2024

/*
Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mLen = 0;
        int len = s.length();
        int left = 0;

        unordered_set<char> charSet;

        for(int right = 0 ; right < len; right++){
            if(charSet.count(s[right])){
                while(charSet.count(s[right])){
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }else{
                charSet.insert(s[right]);
                mLen = max(mLen , right - left + 1);
            }
        }

        return mLen;
    }
};