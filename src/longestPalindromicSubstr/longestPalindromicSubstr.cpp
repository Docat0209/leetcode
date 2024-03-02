// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Author : Docat
// Date   : 03-02-2024

/*
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string lps = s.substr(0,1);
        int lps_l = lps.length();

        for(int i = 0 ; i < n - lps_l ; i++){
            for(int j = n-1 ; j > i && j-i >= lps_l ; j--){
                if(s[i] == s[j]){
                    int inward_count = 1;
                    bool is_palindromic = true;
                    
                    while(j-i-2*inward_count >= 1){
                        if(s[i+inward_count] != s[j-inward_count]){
                            is_palindromic = false;
                            break;
                        }
                        inward_count++;
                    }

                    if(is_palindromic){
                        lps = s.substr(i,j-i+1);
                        lps_l = lps.length();
                    }
                }
            }
        }

        return lps;
    }
};
