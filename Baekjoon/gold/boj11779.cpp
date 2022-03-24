#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 987654321

int N, M;
int S, E;
vector<pair<int, int>> adj[MAX];
int dist[MAX];
int road[MAX];

void Dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int nowCost = pq.top().first;
        int nowVertex = pq.top().second;
        pq.pop();

        if(nowCost > dist[nowVertex]) continue;
        
        for(auto e : adj[nowVertex]) {
            int nextCost = e.first;
            int nv = e.second;
            if(dist[nv] > nowCost + nextCost) {
                dist[nv] = nowCost + nextCost;
                road[nv] = nowVertex;
                pq.push({dist[nv], nv});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    int from, to, w;
    for(int i = 0; i < M; i++){
        cin >> from >> to >> w;
        adj[from].push_back({w, to}); // 일반 단방향 경로
    }
    cin >> S >> E;
    for (int i = 1; i <= N; i++) dist[i] = INF;
    Dijkstra(S);

    vector<int> roadVec;
    int num = E;
    while(num != 0) {
        roadVec.push_back(num);
        num = road[num];
    }

    cout << dist[E] << "\n";
    cout << roadVec.size() << "\n";
    for (int i = roadVec.size() - 1; i >= 0; i--) {
        cout << roadVec[i] << " ";
    }

    return 0;
}

