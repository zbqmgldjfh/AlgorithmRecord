#include <bits/stdc++.h>

using namespace std;

int N;
long long DP[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    DP[0] = DP[1] = 0;
    DP[2] = 1;
    for(int i = 3; i <= N; i++) {
        DP[i] = (DP[i-1] * (2 * ( i - 1)+1) + DP[i-2]) % 100000007;
    }

    cout << DP[N] % 100000007;

    return 0;
}