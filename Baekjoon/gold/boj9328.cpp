#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 102
#define INF 987654321

int T;
int h, w;
char MAP[MAX][MAX];
bool visited[MAX][MAX];
bool keySet[26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;

void init() {
    memset(MAP, 0, sizeof(MAP));
    memset(visited, false, sizeof(visited));
    memset(keySet, false, sizeof(visited));
    res = 0;
}

void show(){
    for (int i = 0; i <= h+1; i++) {
        for (int j = 0; j <= w+1; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
}

void searchMap(int x, int y) {
    queue<pair<int, int>> Q;
    queue<pair<int, int>> Door[26];
    Q.push({x, y});
    visited[x][y] = true;

    while (!Q.empty()) {
        int nowX = Q.front().first;
        int nowY = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if (nx < 0 || ny < 0 || nx > h+1 || ny > w+1) continue;
            // 이미 방문했거나, 벽인경우 제외
            if(MAP[nx][ny] == '*' || visited[nx][ny] == true) continue;

            visited[nx][ny] = true;
            if (MAP[nx][ny] >= 'A' && MAP[nx][ny] <= 'Z') { // 문인 경우
                if (keySet[MAP[nx][ny] - 'A'] == true) {
                    Q.push({nx, ny});
                } else {
                    Door[MAP[nx][ny] - 'A'].push({nx, ny});
                }
            } else if (MAP[nx][ny] >= 'a' && MAP[nx][ny] <= 'z') { // 열쇠인 경우
                Q.push({nx, ny});

                if(keySet[MAP[nx][ny] - 'a'] == false) {
                    keySet[MAP[nx][ny] - 'a'] = true;
                    while (!Door[MAP[nx][ny] - 'a'].empty()) {
                        Q.push(Door[MAP[nx][ny] - 'a'].front());
                        Door[MAP[nx][ny] - 'a'].pop();
                    }
                }
            } else {
                Q.push({nx, ny});
                if (MAP[nx][ny] == '$') {
                    res++;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> T;
    while (T--) {
        cin >> h >> w;
        for (int i = 1; i <= h; i++) {
            string str;
            cin >> str;
            for (int j = 1; j <= w; j++) {
                MAP[i][j] = str[j-1];
            }
        }
        string str;
        cin >> str;
        if (str[0] != '0') {
            for (int i = 0; i < str.length(); i++) {
                keySet[str[i] - 'a'] = true;
            }
        }

        searchMap(0, 0);
        cout << res << "\n";
        init();
    }

    return 0;
}

