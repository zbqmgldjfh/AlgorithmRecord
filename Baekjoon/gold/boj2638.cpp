#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int N, M;
int cnt;
int MAP[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void show() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isClear() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(MAP[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void BFS() {
    queue<pair<int, int>> Q;
    Q.push({0,0});
    MAP[0][0] = -1;

    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(MAP[nx][ny] >= 1) {
                MAP[nx][ny] += 1;
            }else if(MAP[nx][ny] == 0) {
                MAP[nx][ny] = -1;
                Q.push({nx, ny});
            }
        }
    }
}

void melt() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(MAP[i][j]==1 || MAP[i][j]==2){
                MAP[i][j] = 1;
            }
            else MAP[i][j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }

    while(!isClear()){
        BFS();
        melt();
        cnt++;
    }

    cout << cnt;

    return 0;
}

