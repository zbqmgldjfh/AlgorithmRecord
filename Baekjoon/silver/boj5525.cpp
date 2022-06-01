#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 101

int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    string str;
    cin >> str;

    int res = 0;
    for (int i = 0; i < M; i++) {
        int len = 0; // IOI의 길이
        if (str[i] == 'O') {
            continue;
        } else {
            while(str[i+1] == 'O' && str[i+2] == 'I') {
                len++;
                if(len == N) {
                    res++;
                    len--;
                }
                i += 2;
            }
        }
        len = 0;
    }

    cout << res;

    return 0;
}

