#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int DP[202][1001];

int go(int my, int cnt) {
    int& value = DP[my][cnt];
    if(value != -1) {
        return value;
    }
    if(my == 0 || my == N+M) {
        return 1;
    }
    if(cnt == 0) {
        return 0;
    }

    int res = 0;
    res = go(my+1, cnt - 1) + go(my-1, cnt - 1) + go(my, cnt - 1);
    res %= 100000007;
    DP[my][cnt] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M >> K;
    memset(DP, -1, sizeof(DP));

    cout << go(N, K);

    return 0;
}
