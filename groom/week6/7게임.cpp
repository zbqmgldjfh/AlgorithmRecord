#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    string str;
    while(cin >> str) {
        int res = 0;
        for(int i = 0; i < 7; i++) {
            if((i % 2) == 0) {
                res += (str[i] - '0');
            }
        }
        for(int i = 0; i < 7; i++) {
            if((i % 2) == 1 && (str[i] - '0') != 0) {
                res *= (str[i] - '0');
            }
        }
        cout << res % 10 << "\n";
    }

    return 0;
}
