#include <bits/stdc++.h>

using namespace std;
#define MAX 101

int N, M;
int useMemory[MAX];
int restartTime[MAX];
int DP[MAX][10001]; // i번째 앱까지 중 j코스트로 얻을 수 있는 최대의 메모리

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> useMemory[i];
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> restartTime[i];
        sum += restartTime[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (restartTime[i] <= j) {
                DP[i][j] = max(DP[i - 1][j - restartTime[i]] + useMemory[i], DP[i - 1][j]);
            } else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    for (int i = 0; i <= sum; i++) {
        if (DP[N][i] >= M) {
            cout << i;
            break;
        }
    }

    return 0;
}

