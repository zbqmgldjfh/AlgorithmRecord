#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100001];
int DP[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    DP[0] = arr[0];
    for (int i = 1; i < N; i++) {
        DP[i] = max(DP[i-1] + arr[i], arr[i]);
    }

    int res = -1;
    for (int i = 0; i < N; i++) {
        res = max(res, DP[i]);
    }

    cout << res;

    return 0;
}

