#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define MAX 1001

int N, M, K;
vector<pair<int, int>> adj[MAX];
int dist[MAX];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        int cost = pq.top().first;
        int nowV = pq.top().second;
        pq.pop();

        if(dist[nowV] < cost) continue; // 이미 최단경로 체크한 경우

        for (int i = 0; i < adj[nowV].size(); i++) {    // 현재 방문한 정점의 주변 정점 모두 조사
            int next = adj[nowV][i].second;    // 조사할 다음 정점
            int nCost = cost + adj[nowV][i].first;    // 현재 방문한 정점을 거쳐서 다음 정점을 갈때의 비용
            if (nCost < dist[next] ) {     // 기존 비용보다 현재 방문한 정점을 거친 비용이 더 싸다면
                dist[next] = nCost;    // 갱신
                pq.push({nCost, next});    // pq에 저장
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(dist, dist + MAX, INT_MAX);

    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back({1, to});
        adj[to].push_back({1, from});
    }

    dijkstra();

    if(dist[N] <= K) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}