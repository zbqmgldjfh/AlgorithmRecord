#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    string str;
    cin >> str;

    int res = 1;
    for(int i = 1; i < N; i++) {
        if(str[i] == str[i-1]) {
            continue;
        } else {
            res++;
        }
    }

    cout << res;

    return 0;
}