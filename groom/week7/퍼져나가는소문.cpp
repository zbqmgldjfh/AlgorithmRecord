#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<int> adj[10001];
int visited[10001];

void BFS(int initNum) {
    queue<int> Q;
    Q.push(initNum);
    visited[initNum] = 0;

    while (!Q.empty()) {
        int nowNum = Q.front();
        Q.pop();

        for (auto nextNum: adj[nowNum]) {
            if (visited[nextNum] == 0) {
                visited[nextNum] = visited[nowNum] + 1;
                Q.push(nextNum);
            }
            if (nextNum == K) break;
        }
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    BFS(K);

    if (visited[K] == 0) {
        cout << -1;
    } else {
        cout << visited[K];
    }

    return 0;
}
