#include <bits/stdc++.h>
using namespace std;
#define MAX 2147000000

int N;
int before[1000001];
int DP[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;

    DP[1] = 0;
    for(int i = 2; i <= N; i++) {
        before[i] = i-1;
        DP[i] = DP[i-1] + 1;

        if(i % 3 == 0) {
            if(DP[i] > DP[i/3] + 1){
                DP[i] = DP[i/3] + 1;
                before[i] = i/3;
            }
        }
        if(i % 2 == 0) {
            if(DP[i] > DP[i/2] + 1){
                DP[i] = DP[i/2] + 1;
                before[i] = i/2;
            }
        }
    }
    cout << DP[N] << "\n";

    while (true){
        cout << N << " ";
        N = before[N];
        if (N == 0) break;
    }

    return 0;
}

