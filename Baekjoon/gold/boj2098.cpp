#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 16
#define INF 987654321

int MAP[MAX][MAX];
int DP[MAX][1 << 16];

int N;
int fullBit;

int dfs(int curNode, int curBit) {
    if(curBit == fullBit) {
        if(MAP[curNode][0] != 0) {
            return MAP[curNode][0];
        }
        return INF;
    }
    int& ret = DP[curNode][curBit];
    if(ret != -1) {
        return ret;
    }

    ret = INF;
    for(int i = 0; i < N; i ++) {
        int cost = MAP[curNode][i];
        if(curBit & (1 << i) || cost == 0) continue;

        ret = min(ret, dfs(i, curBit | (1 << i)) + cost);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }
    fullBit = (1 << N) - 1;

    memset(DP, -1, sizeof(DP));
    cout << dfs(0, 1);

    return 0;
}

