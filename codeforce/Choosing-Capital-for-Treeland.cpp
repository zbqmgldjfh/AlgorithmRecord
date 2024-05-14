#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

vector<pair<int, int>> adj[200001];
int DP[200001];

int dfs(int now, int parent) {
    int res = 0;

    for (auto next: adj[now]) {
        if (next.second == parent) continue;

        if (next.first == 0) {
            res++;
        }

        res += dfs(next.second, now);
    }

    return res;
}

void dfs_all(int now, int parent) {
    DP[now] += DP[parent];

    for (auto next: adj[now]) {
        if (next.second == parent) continue;

        if (next.first == 1) {
            DP[next.second]++;
        } else {
            DP[next.second]--;
        }

        dfs_all(next.second, now);
    }
}

int main(int argc, char **argv) {
    fastio;

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    int s, t;
    for (int i = 0; i < n - 1; i++) {
        cin >> s >> t;
        adj[s].push_back({1, t});
        adj[t].push_back({0, s});
    }

    DP[1] = dfs(1, 0);
    dfs_all(1, 0);

    int minRes = INT_MAX;
    for (int i = 1; i <= n; i++) {
        minRes = min(minRes, DP[i]);
    }

    cout << minRes << "\n";
    for (int i = 1; i <= n; i++) {
        if (minRes == DP[i]) {
            cout << i << " ";
        }
    }

    return 0;
}

