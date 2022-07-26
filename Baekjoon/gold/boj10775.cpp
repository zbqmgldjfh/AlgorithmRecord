#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 100001

int G, P;
int cnt;
int parent[MAX];

int find(int u) {
    if(parent[u] == u) {
        return u;
    }
    return parent[u] = find(parent[u]);
}

void join(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if(pa != pb) {
        parent[pa] = pb;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> G >> P;
    for(int i = 0; i < MAX; i++) {
        parent[i] = i;
    }

    while(P--) {
        int num;
        cin >> num;

        if(find(num) == 0) break;
        else{
            cnt++;
            join(find(num), find(num)-1);
        }
    }
    cout << cnt;

    return 0;
}

