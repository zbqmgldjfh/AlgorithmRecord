#include <bits/stdc++.h>

using namespace std;
bool visited[5][5];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

struct Point {
    int x;
    int y;
    int cnt;
};

void show() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool BFS(int x, int y, vector<string> map) {
    queue<Point> Q;
    visited[x][y] = true;
    Q.push({x, y, 0});

    while (!Q.empty()) {
        int nowX = Q.front().x;
        int nowY = Q.front().y;
        int nowCnt = Q.front().cnt;
        show();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

            if (!visited[nx][ny] && map[nx][ny] != 'X') {
                if (map[nx][ny] == 'P' && nowCnt + 1 <= 2) {
                    visited[nx][ny] = true;
                    return false;
                }
                visited[nx][ny] = true;
                Q.push({nx, ny, nowCnt + 1});
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    int cnt = places.size();
    vector<int> answer;

    for (int idx = 0; idx < cnt; idx++) {
        vector<string> &map = places[idx];

        bool flag = false;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (!visited[i][j] && map[i][j] == 'P' && flag == false) {
                    bool res = BFS(i, j, map);
                    if (res == false) {
                        flag = true;
                    }
                }
                memset(visited, false, sizeof(visited));
            }
        }

        if (flag) {
            answer.push_back(0);
        } else {
            answer.push_back(1);
        }
    }

    return answer;
}