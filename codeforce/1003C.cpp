#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false), cin.tie(0)

using namespace std;

int N, K;
int arr[5001];
int sum[5001];

int main() {
    fastio;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    double res = 0.0;
    for (int i = 1; i <= N - K + 1; i++) {
        for (int j = i + K - 1; j <= N; j++) {
            double tempSum = (double) sum[j] - (double) sum[i - 1];
            res = max(res, (double) (tempSum / (j - i + 1)));
        }
    }
    cout << fixed << setprecision(15) << res;

    return 0;
}
