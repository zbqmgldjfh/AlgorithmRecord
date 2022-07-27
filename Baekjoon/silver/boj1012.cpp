#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 51

int cnt;
int T, M, N, K;
bool visited[MAX][MAX];
int MAP[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void BFS(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    visited[x][y] = true;
    
    while(!Q.empty()) {
        int nx = Q.front().first;
        int ny = Q.front().second;
        Q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nextX = nx + dx[i];
            int nextY = ny + dy[i];

            if(nextX < 0 || nextY < 0 || nextX >= M || nextY >= N) {
                continue;
            }

            if(!visited[nextX][nextY] && MAP[nextX][nextY] == 1) {
                visited[nextX][nextY] = true;
                Q.push({nextX, nextY});
            }
        }
    }
}

void init() {
    memset(MAP, 0, sizeof(MAP));
    memset(visited, false, sizeof(visited));
    cnt = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> T;
    while(T--) {
        cin >> M >> N >> K;
        for(int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            MAP[x][y] = 1;
        }

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(MAP[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    BFS(i, j);
                }
            }
        }
        cout << cnt << "\n";
        init();
    }

    return 0;
}

