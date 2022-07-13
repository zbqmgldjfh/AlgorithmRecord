#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 55

long long A, B;
long long DP[MAX];

long long countOne(long long num) {
    long long ans = num & 1;

    for(int i = MAX-1; i > 0; i--) {
        if(num & (1LL << i)) { // 해당 비트가 1이면
            ans += DP[i-1] + (num - (1LL << i) + 1);
            num -= 1LL << i;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> A >> B;
    DP[0] = 1;
    for (int i = 1; i < MAX; i++) {
        DP[i] = 2 * DP[i - 1] + (1LL << i);
    }
    cout << countOne(B) - countOne(A-1);

    return 0;
}

