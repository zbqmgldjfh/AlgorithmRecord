#include <bits/stdc++.h>
using namespace std;
#define MAX 501
#define INF 2147000000;

int N;
int DP[MAX][MAX];
int matrix[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        int r, c;
        cin >> r >> c;
        matrix[i][0] = r;
        matrix[i][1] = c;
    }

    for(int i = 1; i < N; i++) {
        for(int j = 1; i + j <= N; j++) {
            DP[i][i+j] = INF;
            for(int k = j; k <= i + j; k++) {
                DP[j][i+j] = min(DP[j][i+j], DP[j][k] + DP[k+1][i+j] + (matrix[j][0] * matrix[k][1] * matrix[i+j][1]));
            }
        }
    }

    cout << DP[1][N];

    return 0;
}

