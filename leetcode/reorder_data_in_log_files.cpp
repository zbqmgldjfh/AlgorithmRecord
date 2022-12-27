#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<string> reorderLogFiles(vector<string> &logs) {
        auto alpha_first = [](auto &log) -> bool { return isalpha(log.back()); };
        auto it = stable_partition(logs.begin(), logs.end(), alpha_first);

        auto compare = [](auto a, auto b) {
            int i = a.find_first_of(' ');
            int j = b.find_first_of(' ');
            if (a.substr(i, a.size() - i) != b.substr(j, b.size() - j)) {
                return a.substr(i, a.size() - i) < b.substr(j, b.size() - j);
            }
            return a.substr(0, i) < b.substr(0, j);
        };
        sort(logs.begin(), it, compare);

        return logs;
    }
};
