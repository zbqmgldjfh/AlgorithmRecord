#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int arr[101];
int DP[101];

int main() {
    fastio;

    int n;
    int sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(n == 1) {
        cout << (arr[0] == 1 ? 0 : 1);
        return 0;
    }

    int res = INT_MIN;
    DP[0] = (arr[0] == 1 ? -1 : 1);
    for (int i = 1; i < n; i++) {
        DP[i] = max(DP[i - 1] + (arr[i] == 1 ? -1 : 1), (arr[i] == 1 ? -1 : 1));
        res = max(res, DP[i]);
    }

    cout << sum + res;

    return 0;
}
