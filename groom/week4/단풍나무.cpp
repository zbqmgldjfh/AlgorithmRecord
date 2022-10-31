#include <bits/stdc++.h>

using namespace std;

int N;
int arr[41][41];
int cpArr[41][41];
queue<pair<int, int>> Q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void mapCopy() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cpArr[i][j] = arr[i][j];
        }
    }
}

void toOrigin() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            arr[i][j] = cpArr[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] != 0) {
                Q.push({i, j});
            }
        }
    }

    int cnt = 0;
    while(!Q.empty()) {
        cnt++;
        mapCopy();

        int len = Q.size();
        for(int i = 0; i < len; i++) {
            int nowX = Q.front().first;
            int nowY = Q.front().second;
            Q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = nowX + dx[i];
                int ny = nowY + dy[i];

                if(nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
                if(arr[nx][ny] == 0) {
                    if(cpArr[nowX][nowY] > 0) {
                        cpArr[nowX][nowY] -= 1;
                    }
                }
            }

            if(cpArr[nowX][nowY] > 0) {
                Q.push({nowX, nowY});
            }
        }

        toOrigin();
    }

    cout << cnt;

    return 0;
}