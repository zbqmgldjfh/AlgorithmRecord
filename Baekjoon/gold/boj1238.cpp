#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 987654321

int N, M, X;
vector<pair<int, int>> adj[2][MAX];
int dist[2][MAX];

void Dijkstra(int level, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[level][start] = 0;

    while(!pq.empty()) {
        int nowCost = pq.top().first;
        int nowVertex = pq.top().second;
        pq.pop();

        if(nowCost > dist[level][nowVertex]) continue;
        
        for(auto e : adj[level][nowVertex]) {
            int nextCost = e.first;
            int nv = e.second;
            if(dist[level][nv] > nowCost + nextCost) {
                dist[level][nv] = nowCost + nextCost;
                pq.push({dist[level][nv], nv});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M >> X;
    int from, to, w;
    for(int i = 0; i < M; i++){
        cin >> from >> to >> w;
        adj[0][from].push_back({w, to}); // 일반 단방향 경로
        adj[1][to].push_back({w, from});
    }

    for(int i = 0; i <= N; i++){
        dist[0][i] = INF;
        dist[1][i] = INF;
    }

    Dijkstra(1, X);
    Dijkstra(0, X);

    int res = 0;
    for(int i = 1; i <= N; i++){
        res = max(res, dist[0][i] + dist[1][i]);
    }

    cout << res;

    return 0;
}

