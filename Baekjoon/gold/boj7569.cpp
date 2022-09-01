#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 101

int M, N, H;
int day;
int box[MAX][MAX][MAX];

int dx[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dh[6] = { 1, -1, 0, 0, 0, 0 };

void show() {
    for(int h = 0; h < H; h++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cout << box[i][j][h] << " ";
            }
            cout << "\n";
        }
    }
    cout << "\n";
}

class Position{
public:
    int x;
    int y;
    int h;
public:
    Position(int x, int y, int h) : x(x), y(y), h(h) {}
};

void isRipe() {
    for(int h = 0; h < H; h++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(box[i][j][h] == 0) {
                    cout << -1;
                    exit(0);
                }
            }
        }
    }
}

queue<Position> Q;

void BFS() {

    while(!Q.empty()) {
        int q_size = Q.size();
        day++;

        for(int size = 0; size < q_size; size++) {
            Position nowPosition = Q.front();
            Q.pop();

            for (int i = 0; i < 6; i++) {
                int nextX = nowPosition.x + dx[i];
                int nextY = nowPosition.y + dy[i];
                int nextH = nowPosition.h + dh[i];

                if (nextX < 0 || nextY < 0 || nextH < 0 || nextX >= N || nextY >= M || nextH >= H) continue;

                if (box[nextX][nextY][nextH] == 0) {
                    box[nextX][nextY][nextH] = 1;
                    Q.push(Position(nextX, nextY, nextH));
                }
            }
        }

    }
    isRipe();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> M >> N >> H;

    for(int h = 0; h < H; h++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> box[i][j][h];
            }
        }
    }

    for(int h = 0; h < H; h++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(box[i][j][h] == 1) {
                    Q.push(Position(i, j, h));
                }
            }
        }
    }

    BFS();

    cout << day - 1;

    return 0;
}

