#include <bits/stdc++.h>
#include <algorithm>

#define fastio ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int T;

bool isContain(int *en, int *ori) {
    for (int i = 0; i < 26; i++) {
        if (en[i] != ori[i]) return false;
    }
    return true;
}

int main() {
    fastio;

    cin >> T;
    while (T--) {
        string encrypt;
        string originStr;

        cin >> encrypt;
        cin >> originStr;

        int enAlpha[26] = {0,};
        int oriAlpha[26] = {0,};
        int oriSize = originStr.length();
        for (int i = 0; i < oriSize; i++) {
            enAlpha[encrypt[i] - 'a'] += 1;
            oriAlpha[originStr[i] - 'a'] += 1;
        }

        if (isContain(enAlpha, oriAlpha)) {
            cout << "YES\n";
            continue;
        }

        bool findAnswer = false;
        for (int i = oriSize; i < encrypt.size(); i++) {
            enAlpha[encrypt[i] - 'a'] += 1;
            enAlpha[encrypt[i - oriSize] - 'a'] -= 1;

            if (isContain(enAlpha, oriAlpha)) {
                cout << "YES\n";
                findAnswer = true;
                break;
            }
        }

        if (!findAnswer) {
            cout << "NO\n";
        }
    }

    return 0;
}
