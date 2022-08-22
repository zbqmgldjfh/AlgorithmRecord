#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 101

int N;
int maxHeight, res;
int MAP[MAX][MAX];
bool flooded[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void init() {
    memset(visited, false, sizeof(visited));
}

void show() {
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << flooded[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void BFS(int x, int y) {
    visited[x][y] = true;
    queue<pair<int, int>> Q;
    Q.push({x, y});

    while(!Q.empty()) {
        int nowX = Q.front().first;
        int nowY = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if(!visited[nx][ny] && !flooded[nx][ny]) {
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
    int num;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;
            MAP[i][j] = num;
            if(maxHeight < num) {
                maxHeight = num;
            }
        }
    }

    for(int h = 0; h <= maxHeight; h++) {
        init();
        // 높이 이하의 지역 채크
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!flooded[i][j] && MAP[i][j] <= h) {
                    flooded[i][j] = true;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!flooded[i][j] && !visited[i][j]) {
                    cnt++;
                    BFS(i, j);
                }
            }
        }
        if(res < cnt) {
            res = cnt;
        }
    }

    cout << res;
    return 0;
}

