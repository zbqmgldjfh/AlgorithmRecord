#include <bits/stdc++.h>

using namespace std;

int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int MAP[101][101];
bool visited[101][101];

void init() {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            visited[i][j] = false;
        }
    }
}

bool isSeparate() {
    int cnt = 0;
    init();
    queue<pair<int, int>> Q;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!visited[i][j] && MAP[i][j] == 1) {
                cnt++;
                if(cnt == 2) {
                    return true;
                }

                Q.push({i, j});
                visited[i][j] = true;
                while(!Q.empty()) {
                    int nowX = Q.front().first;
                    int nowY = Q.front().second;
                    Q.pop();

                    for(int i = 0; i < 4; i++) {
                        int nx = nowX + dx[i];
                        int ny = nowY + dy[i];

                        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                        if(!visited[nx][ny] && MAP[nx][ny] == 1) {
                            visited[nx][ny] = true;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    queue<pair<int, int>> sea;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> MAP[i][j];
            if(MAP[i][j] == 0) {
                sea.push({i, j});
            }
        }
    }

    int cnt = 0;
    while(!sea.empty()) {
        cnt++;
        int seaSize = sea.size();
        for(int i = 0; i < seaSize; i++) {
            int nowX = sea.front().first;
            int nowY = sea.front().second;
            sea.pop();

            for(int i = 0; i < 4; i++) {
                int nx = nowX + dx[i];
                int ny = nowY + dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                if(MAP[nx][ny] == 1) {
                    MAP[nx][ny] = 0;
                    sea.push({nx, ny});
                }
            }
        }
        if(isSeparate()) {
            cout << cnt;
            exit(0);
        }
    }

    cout << -1;

    return 0;
}
