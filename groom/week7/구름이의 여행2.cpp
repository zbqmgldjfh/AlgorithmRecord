#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int N, M, K;
vector<int> adj[MAX];
int dist[MAX];
int MAP[MAX][MAX];

void dijkstra(int initNum) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, initNum});
    dist[initNum] = 0;

    while(!pq.empty()) {
        int cost = pq.top().first;
        int nowV = pq.top().second;
        pq.pop();

        if(dist[nowV] < cost) continue; // 이미 최단경로 체크한 경우

        for (int i = 0; i < adj[nowV].size(); i++) {    // 현재 방문한 정점의 주변 정점 모두 조사
            int next = adj[nowV][i];    // 조사할 다음 정점
            int nCost = cost + 1;    // 현재 방문한 정점을 거쳐서 다음 정점을 갈때의 비용
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
    freopen("input.txt", "rt", stdin);

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            MAP[i][j] = 2147000000;
        }
    }

    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    for(int i = 1; i <= N; i++) {
        for(int k = 0; k <= N; k++) {
            dist[k] = 2147000000;
        }
        dijkstra(i);
        for(int j = 1; j <= N; j++) {
            if(dist[j] == 0) continue;
            MAP[i][j] = dist[j];
        }
    }

    int res = 2147000000;
    for(int i = 1; i <= N; i++) {
        if(MAP[K][i] != 2147000000 && MAP[i][K] != 2147000000) {
            res = min(res, MAP[K][i] + MAP[i][K]);
        }
    }

    if(res == 2147000000) {
        cout << -1;
    } else {
        cout << res;
    }

    return 0;
}
