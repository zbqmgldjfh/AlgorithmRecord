#include <bits/stdc++.h>

using namespace std;

string extend(int left, int right, string str) {
    while(left >= 0 && right < str.length() && str[left] == str[right]) {
        left -= 1;
        right += 1;
    }

    return str.substr(left + 1, right - left - 1);
}

class Solution {
public:
    string longestPalindrome(string s) {
        string temp = s;
        int str_len = s.length();

        reverse(temp.begin(), temp.end());
        if (str_len < 2 || s == temp) {
            return s;
        }

        string res = "";
        for(int i = 0; i < str_len; i++) {
            string s1 = extend(i, i + 2, s);
            string s2 = extend(i, i + 1, s);

            string t = (s1.length() < s2.length()) ? s2 : s1;
            res = (t.length() < res.length()) ? res : t;
        }

        return res;
    }
};