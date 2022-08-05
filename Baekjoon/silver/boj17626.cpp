#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 50001

int DP[MAX];

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        DP[i] = i;
        for (int j = 1; j * j <= i; j++) {
            DP[i] = min(DP[i], 1 + DP[i - j*j]);
        }
    }
    cout << DP[n];

    return 0;
}

