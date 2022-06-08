#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 101
#define INF 987654321

int N, M;
int MAP[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        MAP[a][b] = 1;
        MAP[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if (MAP[i][k] != 0 && MAP[k][j] != 0) {
                    if (MAP[i][j] == 0) {
                        MAP[i][j] = MAP[i][k] + MAP[k][j];
                    } else {
                        MAP[i][j] = min(MAP[i][j], MAP[i][k] + MAP[k][j]);
                    }
                }
            }
        }
    }

    int ans = INF;
    int person = -1;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += MAP[i][j];
        }
        if (ans > sum) {
            person = i;
            ans = sum;
        }
    }
    cout << person;

    return 0;
}

