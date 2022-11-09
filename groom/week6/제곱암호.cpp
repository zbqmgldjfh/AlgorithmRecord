#include <bits/stdc++.h>

using namespace std;

int N;

char deCode(char ch, char num) {
    int len = (num-'0') * (num-'0');
    int index = ((ch - 'a') + len) % 26;
    return 'a' + index;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    string str;
    cin >> str;

    string res = "";
    for(int i = 0; i < N; i += 2) {
        char ch = deCode(str[i], str[i+1]);
        res.push_back(ch);
    }

    cout << res;

    return 0;
}
