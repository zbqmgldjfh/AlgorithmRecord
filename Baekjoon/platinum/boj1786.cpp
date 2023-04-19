#include <bits/stdc++.h>

using namespace std;

string text, pattern;
int res;
vector<int> temp;

vector<int> failureFunction() {
    int patternLen = pattern.length();
    vector<int> failure(patternLen);

    int j = 0;
    for (int i = 1; i < patternLen; i++) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = failure[j - 1];
        }

        if (pattern[j] == pattern[i]) {
            failure[i] = ++j;
        }
    }

    return failure;
}

void kmp(const vector<int>& failList) {
    int i = 0;
    int matchPatternLen = 0;

    while (i < text.length()) {
        if (pattern[matchPatternLen] == text[i]) {
            i++;
            matchPatternLen++;
            if (matchPatternLen == pattern.length()) {
                res++;
                temp.push_back(i - pattern.size() + 1);
            }
        } else {
            if(matchPatternLen == 0) {
                i++;
            } else {
                matchPatternLen = failList[matchPatternLen - 1];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, text);
    getline(cin, pattern);

    const vector<int> &failList = failureFunction();
    kmp(failList);

    cout << res << "\n";
    for(auto &w : temp){
        cout << w << " ";
    }

    return 0;
}
