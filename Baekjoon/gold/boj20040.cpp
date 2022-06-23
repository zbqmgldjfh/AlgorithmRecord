#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 500001
#define INF 987654321

int N, M;
int cnt = 1;
int parent[MAX];

int find(int u) {
    if(parent[u] == u) {
        return u;
    }
    return parent[u] = find(parent[u]);
}

bool unionNode(int u, int v)
{
    u = find(u);
    v = find(v);

    // 부모노드가 같으면 사이클이 생기므로 true 반환
    if (u == v) return true;
    else // 노드 결합
    {
        parent[u] = v;
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if(unionNode(a, b)){
            cout << i+1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

