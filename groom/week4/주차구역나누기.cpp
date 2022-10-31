#include <bits/stdc++.h>
#define MOD 100000007

using namespace std;

int N;
int colorArr[100001];
int DP[200002][100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill_n(colorArr, sizeof(colorArr), 2);
    cin >> N;

    int len = N * 2;
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= N; j++) {
            if(colorArr[j] > 0) {
                colorArr[j] -= 1;
                for(int k = 1; k <= N; k++) {
                    if(j == k) continue;
                    if(colorArr[k] > 0) {
                        DP[i][j] += (DP[i-1][k] % MOD);
                    }
                }
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= N; i++) {
        sum += DP[len][i];
    }

    cout << sum % MOD;

    return 0;
}