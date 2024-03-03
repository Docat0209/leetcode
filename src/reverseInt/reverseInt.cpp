// Source : https://leetcode.com/problems/reverse-integer/
// Author : Docat
// Date   : 03-03-2024

/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        string answer = "";

        bool negative = false;
        if(str[0] == '-'){
            negative = true;
        }
        
        for(int i = str.length() - 1 ; i >= 0+negative ; i--){
            answer += str[i];
        }

        if(negative){
            answer = "-"+answer;
        }

        try{
            return stoi(answer);
        }catch(...){
            return 0;
        }
    }
};
