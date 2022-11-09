#include <bits/stdc++.h>

using namespace std;

int MAP[1001][1001];
int N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> K;
    int x1, y1, x2, y2;
    for(int k = 0; k < N; k++) {
        cin >> x1 >> y1 >> x2 >> y2;
        int n = x2 - x1;
        int m = y2 - y1;

        MAP[x1][y1] += 1;
        MAP[x1 + n][y1] -= 1;
        MAP[x1][y1 + m] -= 1;
        MAP[x1 + n][y1 + m] += 1;
    }

    // 위 -> 아래
    for(int i = 1; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) {
            MAP[i][j] += MAP[i-1][j];
        }
    }

    // 왼 -> 오른
    for(int i = 0; i < 1001; i++) {
        for(int j = 1; j < 1001; j++) {
            MAP[i][j] += MAP[i][j-1];
        }
    }

    int res = 0;
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) {
            if(MAP[i][j] == K) {
                res++;
            }
        }
    }
    cout << res;

    return 0;
}
