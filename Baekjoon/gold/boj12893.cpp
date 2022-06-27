#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 1000001
#define INF 987654321

int N, M;
int parent[2001];
int enemyGroup[2001];
vector<int> adj[MAX];

int find(int u) {
    if(parent[u] == u) {
        return u;
    }

    return parent[u] = find(parent[u]);
}

void join(int a, int b) {
    int ap = find(a);
    int bp = find(b);

    if(ap == bp) {
        return;
    }
    parent[ap] = bp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;

    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        int ap = find(a);
        int bp = find(b);

        if(ap == bp) {
            cout << 0;
            exit(0);
        }
        int& aEnemy = enemyGroup[a];
        int& bEnemy = enemyGroup[b];

        if(aEnemy != 0) { // 적 그룹이 이미 있는경우
            join(aEnemy, b);
        }else{
            aEnemy = b;
        }

        if(bEnemy != 0) {
            join(bEnemy, a);
        }else{
            bEnemy = a;
        }
    }

    cout << 1;
    return 0;
}

