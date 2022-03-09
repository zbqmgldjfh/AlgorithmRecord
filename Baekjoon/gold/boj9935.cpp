#include <bits/stdc++.h>

using namespace std;
#define MAX 1001
#define INF 2147000000

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    string s, bomb;
    cin >> s >> bomb;

    string answer = "";

    int bombIdx = bomb.length() - 1;
    for (int i = 0; i < s.length(); i++) {
        answer += s[i];
        if (answer[answer.length() - 1] == bomb[bombIdx]) {
            if (answer.length() >= bomb.length()) {
                int cnt = 1;

                for (int j = bombIdx - 1; j >= 0; j--) {
                    if (answer[answer.length() - (bombIdx - j) - 1] == bomb[j]) {
                        cnt++;
                    }
                }

                if (bomb.length() == cnt) {
                    for (int b = 0; b < bomb.length(); b++) {
                        answer.pop_back();
                    }
                }
            }
        }
    }


    if (answer.length() > 0) {
        cout << answer << endl;
    } else {
        cout << "FRULA" << endl;
    }

    return 0;
}

