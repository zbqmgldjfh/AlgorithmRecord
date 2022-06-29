#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 100001
#define INF 987654321

int N, M;
vector<int> adj[MAX];
int parent[MAX];
int cnt;

int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void unionGroup(int a, int b) {
    int ap = find(a);
    int bp = find(b);

    if(ap != bp) {
        parent[ap] = bp;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;

    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if(find(u) != find(v)) {
            unionGroup(u, v);
        }else{
            cnt++;
        }
    }

    for(int i = 1; i <= N; i++) {
        if(find(i) == i) {
            cnt++;
        }
    }
    cout << cnt - 1;

    return 0;
}

