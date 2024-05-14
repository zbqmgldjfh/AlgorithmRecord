#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

vector<int> adj[100001];
bool affected_pos[100001];
int maxDistanceDown[100001];
int maxDistanceUp[100001];
int n, m, d;


int dfs(int now, int parent) {
    maxDistanceDown[now] = affected_pos[now] ? 0 : -1;

    for (int next: adj[now]) {
        if (next == parent) continue;

        int child_max_distance = dfs(next, now);

        if (child_max_distance != -1) {
            maxDistanceDown[now] = max(maxDistanceDown[now], child_max_distance + 1);
        }
    }

    return maxDistanceDown[now];
}

void dfs_all(int now, int parent) {
    int mx1 = -1, mx2 = -1;

    for (int next: adj[now]) {
        if (next == parent) continue;

        if (maxDistanceDown[next] > mx1) {
            mx2 = mx1;
            mx1 = maxDistanceDown[next];
        } else if (maxDistanceDown[next] > mx2) {
            mx2 = maxDistanceDown[next];
        }
    }

    for (int next: adj[now]) {
        if (next == parent) continue;

        int siblingDistance = (maxDistanceDown[next] == mx1 ? mx2 : mx1);
        if (siblingDistance != -1) {
            siblingDistance += 2;
        }

        maxDistanceUp[next] = siblingDistance;
        if (maxDistanceUp[now] != -1) {
            maxDistanceUp[next] = max(maxDistanceUp[next], maxDistanceUp[now] + 1);
        }
        if (affected_pos[next]) {
            maxDistanceUp[next] = max(maxDistanceUp[next], 0);
        }

        dfs_all(next, now);
    }
}


int main(int argc, char **argv) {
    fastio;

    //freopen("input.txt", "r", stdin);

    cin >> n >> m >> d;

    int num;
    for (int i = 0; i < m; i++) {
        cin >> num;
        affected_pos[num] = true;
    }

    int s, t;
    for (int i = 0; i < n - 1; i++) {
        cin >> s >> t;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }

    dfs(1, 0);
    maxDistanceUp[1] = affected_pos[1] ? 0 : -1;
    dfs_all(1, 0);

    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += (maxDistanceUp[i] <= d && maxDistanceDown[i] <= d);

    cout << ans;

    return 0;
}

