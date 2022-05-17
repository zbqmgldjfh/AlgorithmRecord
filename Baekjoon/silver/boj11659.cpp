#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int N, M;
int sum[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        sum[i] = sum[i-1] + num;
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n";
    }

    return 0;
}

