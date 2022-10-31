#include <bits/stdc++.h>

using namespace std;

bool visited[10001];
vector<int> cycle;
vector<int> adj[10101];
int finded = -1; // 직전 방문 노드 번호 저장
int N;

void FindCycle(int nowV, int endPoint) {
    if (visited[nowV]) {
        finded = nowV;
        cycle.push_back(nowV);
        return;
    }

    visited[nowV] = true;
    for (auto nextV : adj[nowV]) {
        if (nextV == endPoint) continue;

        FindCycle(nextV, nowV);

        if (finded == -2) return;

        if (finded == nowV) { // 이전에 방문한 곳
            finded = -2;
            return;
        }

        if (finded >= 0) {
            cycle.push_back(nowV);
            return;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    FindCycle(1, 1);

    cout << cycle.size() << "\n";
    sort(cycle.begin(), cycle.end());
    for (auto e : cycle) cout << e << ' ';

    return 0;
}