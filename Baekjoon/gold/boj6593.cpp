#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 31

int L, R, C;
char MAP[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

class Position {
public:
    int x, y, z;
    int minute;
public:
    Position() {}

    Position(int x, int y, int z, int minute) : x(x), y(y), z(z), minute(minute) {}
};

static Position start, endPosition;

void init() {
    memset(MAP, 0, sizeof(MAP));
    memset(visited, false, sizeof(visited));
}

int BFS(int x, int y, int z) {
    queue<Position> Q;
    visited[x][y][z] = true;
    Q.push(Position(x, y, z, 0));

    while(!Q.empty()) {
        int nowX = Q.front().x;
        int nowY = Q.front().y;
        int nowZ = Q.front().z;
        int minute = Q.front().minute;
        Q.pop();

        if(nowX == endPosition.x && nowY == endPosition.y && nowZ == endPosition.z) {
            return minute;
        }

        for(int i = 0; i < 6; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];
            int nz = nowZ + dz[i];

            if(nx < 0 || ny < 0 || nz < 0 || nx >= R || ny >= C || nz >= L) continue;

            if(!visited[nx][ny][nz]) {
                if (MAP[nx][ny][nz] == '.' || MAP[nx][ny][nz] == 'E') {
                    visited[nx][ny][nz] = true;
                    Q.push(Position(nx, ny, nz, minute + 1));
                }
            }
        }
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    while (true) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) {
            break;
        }

        for (int h = 0; h < L; h++) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    cin >> MAP[i][j][h];
                    if (MAP[i][j][h] == 'S') {
                        start.x = i;
                        start.y = j;
                        start.z = h;
                    } else if (MAP[i][j][h] == 'E') {
                        endPosition.x = i;
                        endPosition.y = j;
                        endPosition.z = h;
                    }
                }
            }
        }

        int m = BFS(start.x, start.y, start.z);
        if(m == -1) {
            cout << "Trapped!" << "\n";
        }else {
            cout << "Escaped in " << m << " minute(s)." << "\n";
        }
        init();
    }

    return 0;
}

