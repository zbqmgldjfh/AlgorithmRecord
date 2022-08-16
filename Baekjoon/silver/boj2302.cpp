#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 41

int N, M;
int DP[MAX];
int vip[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> vip[i];
    }

    DP[0] = 1;
    DP[1] = 1;
    for(int i = 2; i <= N; i++) {
        DP[i] = DP[i-1] + DP[i-2];
    }

    int res = 1;
    int start = 0;

    for(int i = 0; i < M; i++) {
        int end = vip[i];
        res = res * DP[end - start - 1];
        start = end;
    }
    res = res * DP[N - start];
    cout << res;

    return 0;
}

