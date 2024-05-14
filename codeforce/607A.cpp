#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;


struct Node {
    int a, b;

    bool operator<(const Node other) const {
        return a < other.a;
    }
} node[100001];

int DP[100001];

int main() {
    fastio;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> node[i].a >> node[i].b;
    }

    sort(node + 1, node + n + 1);

    DP[1] = 1;
    for (int i = 2; i <= n; i++) {
        int left = 1;
        int right = i;

        while (left < right) {
            int mid = (left + right) / 2;

            if (node[i].a - node[mid].a <= node[i].b) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        DP[i] = DP[right - 1] + 1;
    }

    int ans = n - DP[n];
    for (int i = n; i >= 1; i--) {
        ans = min(ans, n - DP[i]);
    }

    cout << ans;

    return 0;
}
