#include <bits/stdc++.h>

using namespace std;

int N, K;
long long DP[200001][2]; // 0은 끌고가는, 1은 들고가는 비용
long long arr[200001][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> K;

    int num = 0;
    for(int i = 1; i <= N; i++) {
        cin >> num;
        arr[i][0] = num;
    }

    for(int i = 1; i <= N; i++) {
        cin >> num;
        arr[i][1] = num;
    }

    DP[1][0] = arr[1][0];
    DP[1][1] = arr[1][1];

    for(int i = 2; i <= N; i++) {
        long long cost = DP[i - 1][0] + arr[i][0];
        long long swapCost = DP[i - 1][1] + arr[i][0] + K;
        DP[i][0] = min(cost, swapCost);

        cost = DP[i - 1][1] + arr[i][1];
        swapCost = DP[i - 1][0] + arr[i][1] + K;
        DP[i][1] = min(cost, swapCost);
    }

    long long res = DP[N][0] < DP[N][1] ? DP[N][0] : DP[N][1];
    cout << res;

    return 0;
}
