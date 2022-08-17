#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 1000001
#define MOD 1000000000

int N;
int DP[MAX][20];

long long find(int n, int k) {
    if(n < 0) {
        return 0;
    }else if(n == 0 || k == 0) {
        return 1;
    }

    int& value = DP[n][k];
    if(value != -1) {
        return value;
    }

    value = (find(n, k-1) % MOD + find(n-pow(2, k), k) % MOD) % MOD;
    return value;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;

    memset(DP, -1, sizeof(DP));
    cout << find(N, 19) % MOD;

    return 0;
}

