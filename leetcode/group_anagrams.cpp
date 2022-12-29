#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> word_map;

        for (auto word : strs) {
            string temp = word;
            sort(temp.begin(), temp.end());
            word_map[temp].push_back(word);
        }

        vector<vector<string>> res;
        for(auto it : word_map) {
            res.push_back(it.second);
        }
        return res;
    }
};