#include <bits/stdc++.h>

using namespace std;
#define MAX 101

int N;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void BFS(int x, int y) {
    queue<pair<int, int> > Q;
    Q.push({x, y});
    visited[x][y] = true;
    
    while(!Q.empty()) {
        int nowX = Q.front().first;
        int nowY = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if(!visited[nx][ny] && (MAP[nx][ny] == MAP[nowX][nowY])) {
                visited[nx][ny] = true;
                Q.push({nx, ny});
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < N; j++) {
            MAP[i][j] = str[j];
        }
    }
    int res = 0;
    int rgRes = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) {
                BFS(i, j);
                res++;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (MAP[i][j] == 'G') MAP[i][j] = 'R';
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) {
                BFS(i, j);
                rgRes++;
            }
        }
    }

    cout << res << " " << rgRes;

    return 0;
}

