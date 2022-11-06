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

bool isSurvive(int x, int y) {
    init();
    queue<pair<pair<int, int>, int>> Q;
    visited[x][y] = true;
    Q.push({{x, y}, 0});

    while(!Q.empty()) {
        int nowX = Q.front().first.first;
        int nowY = Q.front().first.second;
        int nowLength = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;

            if(MAP[nextX][nextY] == 2) {
                return true;
            }

            if(!visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                if(nowLength + 1 < M) {
                    Q.push({{nextX, nextY}, nowLength + 1});
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
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(MAP[i][j] == 1) {
                if(isSurvive(i, j)) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}
