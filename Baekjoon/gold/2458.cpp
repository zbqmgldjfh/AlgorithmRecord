#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int N, M;
int MAP[501][501];
int howManyVisit[501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            MAP[i][j] = INF;
        }
    }

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        MAP[a][b] = 1;
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(MAP[i][k] + MAP[k][j] < MAP[i][j]) {
                    MAP[i][j] = MAP[i][k] + MAP[k][j];
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(MAP[i][j] != INF) {
                howManyVisit[j] += 1;
                howManyVisit[i] += 1;
            }
        }
    }

    for(int i = 1; i <= N; i++){
        if(howManyVisit[i] == N - 1) cnt++;
    }

    cout << cnt;

    return 0;
}
