#include <bits/stdc++.h>

using namespace std;
#define MAX 801
#define INF 987654321

int N, E;
int A, B;
int dist[200001];
vector<pair<int, int>> adj[MAX];

void Dijkstra(int start) {
    for (int i = 0; i <= N; i++) dist[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for(auto e : adj[now]) {
            int nextCost = e.first;
            int nv = e.second;
            if(cost + nextCost < dist[nv]) {
                dist[nv] = cost + nextCost;
                pq.push({dist[nv], nv});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> E;
    int a, b, c;
    for(int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> A >> B;

    Dijkstra(1);
    int OneToACost = dist[A];
    int OneToBCost = dist[B];

    Dijkstra(A);
    int AtoBCost = dist[B];

    Dijkstra(N);
    int AtoEndCost = dist[A];
    int BtoEndCost = dist[B];

    int res = min(OneToACost + AtoBCost + BtoEndCost, OneToBCost + AtoBCost + AtoEndCost);
    if(res > INF || res < 0) {
        cout << -1;
    }else{
        cout << res;
    }

    return 0;
}

