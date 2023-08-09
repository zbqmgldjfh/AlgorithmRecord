#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int N, M;
vector<int> adj[5001];
int height[5001];
int DP[5001];
int maxHeight = -1;

int DFS(int start, int h) {
    if(h == maxHeight || adj[start].empty()) return 1;
    int& ret = DP[start];
    if(ret != -1) return ret;

    ret = 1;
    for(auto nextV : adj[start]) {
        if(h < height[nextV]) {
            ret = max(ret, DFS(nextV, height[nextV]) + 1);
        }
    }

    return ret;
}

int main() {
    fastio;

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> height[i];
        maxHeight = max(maxHeight, height[i]);
    }

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;

        if(height[a] > height[b]) {
            adj[b].push_back(a);
        } else {
            adj[a].push_back(b);
        }
    }

    memset(DP, -1, sizeof(DP));
    for(int i = 1; i <= N; i++) {
        int num = DFS(i, DP[i]);
        cout << num << "\n";
    }

    return 0;
}
