#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 1001
#define INF 987654321

int N, M;
int dx[4] = { -1,0,1,0};
int dy[4] = { 0,1,0,-1};
char MAP[MAX][MAX];
int findSafe[MAX][MAX];
int res = 1;

int DFS(int x, int y) {
    if(findSafe[x][y] != -1) {
        return findSafe[x][y];
    }

    findSafe[x][y] = res;
    int dir;
    if (MAP[x][y] == 'U') {
        dir = 0;
    } else if (MAP[x][y] == 'R') {
        dir = 1;
    } else if (MAP[x][y] == 'D') {
        dir = 2;
    }else if(MAP[x][y] == 'L') {
        dir = 3;
    }

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    int ret = DFS(nx, ny);
    findSafe[x][y] = ret;
    return findSafe[x][y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
            findSafe[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (findSafe[i][j] == -1) {
                DFS(i, j);
                res++;
            }
        }
    }
    set<int> s;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            s.insert(findSafe[i][j]);
    cout << s.size();

    return 0;
}

