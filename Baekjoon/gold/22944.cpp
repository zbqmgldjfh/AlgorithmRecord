#include <bits/stdc++.h>

using namespace std;

int N, H, D;
char MAP[501][501];
int visited[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
pair<int, int> start, finish;

class Person {
public:
    int x;
    int y;
    int u;
    int health;
    int cnt;
public:
    Person(int _x, int _y, int _u, int _health, int _cnt) : x(_x), y(_y), u(_u), health(_health), cnt(_cnt) {}
};

int BFS(int x, int y) {
    queue<Person> Q;
    visited[x][y] = H;
    Q.push(Person(x, y, 0, H, 0));

    while (!Q.empty()) {
        int size = Q.size();
        for(int k = 0; k < size; k++) {
            int nowX = Q.front().x;
            int nowY = Q.front().y;
            int nowU = Q.front().u;
            int nowHealth = Q.front().health;
            int nowCnt = Q.front().cnt;
            Q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = nowX + dx[i];
                int ny = nowY + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (nx == finish.first && ny == finish.second) {
                    return nowCnt + 1;
                }

                int nu = nowU;
                int nh = nowHealth;
                if (MAP[nx][ny] == 'U') {
                    nu = D;
                }

                if (nu != 0) {
                    nu--;
                } else {
                    nh--;
                }

                if (nh == 0) continue;

                if (visited[nx][ny] < (nh + nu)) {
                    visited[nx][ny] = nh + nu;
                    Q.push(Person(nx, ny, nu, nh, nowCnt + 1));
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];

            if (MAP[i][j] == 'S') {
                start = {i, j};
            } else if (MAP[i][j] == 'E') {
                finish = {i, j};
            }
        }
    }

    cout << BFS(start.first, start.second);

    return 0;
}
