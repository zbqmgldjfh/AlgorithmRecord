#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0)

using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;

    while(n--) {
        string str;
        cin >> str;

        int len = str.length();

        if(len <= 10) {
            cout << str << "\n";
        } else {
            cout << str[0] + to_string((len - 2)) + str[len-1] << "\n";
        }
    }

    return 0;
}
