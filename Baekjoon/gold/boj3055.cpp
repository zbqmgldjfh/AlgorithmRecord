#include <bits/stdc++.h>
using namespace std;
#define INF 2147000000

char MAP[51][51];
int cache[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int R, C;
pair<int, int> sPos, dPos;
queue<pair<int, int>> water;

void show() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << cache[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void BFS() {
    queue<pair<int, int> > hedgehog;
    hedgehog.push(sPos);
    cache[sPos.first][sPos.second] = 1;

    while(!hedgehog.empty()) {
        int waterSize = water.size();
        // 물을 먼저 확장 시킨 후
        for(int k = 0; k < waterSize; k++) {
            int nowX = water.front().first;
            int nowY = water.front().second;
            water.pop();

            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];

                if (nextX < 0 || nextY < 0 || nextX >= R || nextY >= C) continue;
                if (MAP[nextX][nextY] == '.') {
                    MAP[nextX][nextY] = '*';
                    water.push({nextX, nextY});
                }
            }
        }
        // 고슴도치 이동
        int hSize = hedgehog.size();

        for(int k = 0; k < hSize; k++) {
            int nowX = hedgehog.front().first;
            int nowY = hedgehog.front().second;
            hedgehog.pop();

            if (nowX == dPos.first && nowY == dPos.second) {
                cout << cache[nowX][nowY] - 1;
                exit(0);
            }

            for(int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (nextX < 0 || nextY < 0 || nextX >= R || nextY >= C) continue;

                if(MAP[nextX][nextY] != '*' && cache[nextX][nextY] == 0 && MAP[nextX][nextY] != 'X') {
                    cache[nextX][nextY] = cache[nowX][nowY] + 1;
                    hedgehog.push({nextX, nextY});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> MAP[i][j];
            if(MAP[i][j] == 'S') {
                sPos.first = i;
                sPos.second = j;
            }else if(MAP[i][j] == 'D') {
                dPos.first = i;
                dPos.second = j;
            }else if(MAP[i][j] == '*') {
                water.push({i, j});
            }
        }
    }

    BFS();
    cout << "KAKTUS" << endl;

    return 0;
}

