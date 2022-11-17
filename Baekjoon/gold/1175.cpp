#include <bits/stdc++.h>

#define MAX 51

using namespace std;

int N, M;
char MAP[MAX][MAX];
bool DP[MAX][MAX][4][2][2]; // x, y, dir, c, d

// 방향, 시계방향 0123, 무방향 -1
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Position {
public:
    int x;
    int y;
    int cnt;
    int dir;
    bool visitedC;
    bool visitedD;
public:
    Position(int x, int y, int cnt, int dir, bool visitedC, bool visitedD) : x(x), y(y), cnt(cnt), dir(dir),
                                                                             visitedC(visitedC), visitedD(visitedD) {}
};

int find(int startX, int startY) {
    queue<Position> Q;
    Q.push(Position(startX, startY, 0, -1, false, false));
    DP[startX][startY][3][0][0] = true;

    while (!Q.empty()) {
        int nowX = Q.front().x;
        int nowY = Q.front().y;
        int nowCnt = Q.front().cnt;
        int nowDir = Q.front().dir;
        bool visitedC = Q.front().visitedC;
        bool visitedD = Q.front().visitedD;
        Q.pop();

        //cout << "X : " << nowX << ", Y : " << nowY << "\n";

        if (visitedC && visitedD) {
            return nowCnt;
        }

        for (int i = 0; i < 4; i++) {
            if (i == nowDir) continue;

            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) continue;

            bool nvc = visitedC;
            bool nvd = visitedD;

            if (!DP[nextX][nextY][i][visitedC][visitedD] && MAP[nextX][nextY] != '#') {
                if(MAP[nextX][nextY] == 'C') nvc = true;
                if(MAP[nextX][nextY] == 'D') nvd = true;

                DP[nextX][nextY][i][nvc][nvd] = true;
                Q.push(Position(nextX, nextY, nowCnt + 1, i, nvc, nvd));
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int startX, startY;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'S') {
                startX = i;
                startY = j;
                MAP[i][j] = '.';
            } else if (MAP[i][j] == 'C') {
                cnt++;
                if(cnt == 2) {
                    MAP[i][j] = 'D';
                }
            }
        }
    }

    cout << find(startX, startY);

    return 0;
}
