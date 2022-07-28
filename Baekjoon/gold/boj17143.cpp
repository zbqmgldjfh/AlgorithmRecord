#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 102

int R, C, M;
int totalSize;

class Shark {
public:
    int x, y;
    int speed;
    int direction;
    int size;
public:
    Shark(int x, int y, int speed, int direction, int size) : x(x), y(y), speed(speed), direction(direction),
                                                              size(size) {}
};

vector<Shark> Sharks[MAX][MAX];
int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void fishing(int index) {
    for (int i = 1; i <= R; i++) {
        if (!Sharks[i][index].empty()) {
            totalSize += Sharks[i][index].front().size;
            Sharks[i][index].pop_back();
            return;
        }
    }
}

int changeDir(int d) {
    if (d == 1) return 2;
    if (d == 2) return 1;
    if (d == 3) return 4;
    if (d == 4) return 3;
}

void moveAndKillShark() {
    vector<Shark> newSharks[MAX][MAX];

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (Sharks[i][j].empty()) { continue; }
            Shark &nowShark = Sharks[i][j].front();
            int& nowX = nowShark.x;
            int& nowY = nowShark.y;
            int nowSpeed = nowShark.speed;
            int& nowDirection = nowShark.direction;

            while(nowSpeed--) {
                int nx = nowX + dir[nowDirection][0];
                int ny = nowY + dir[nowDirection][1];

                if(nx < 1 || ny < 1 || nx > R || ny > C) {
                    nowDirection = changeDir(nowDirection);
                }
                nowX += dir[nowDirection][0];
                nowY += dir[nowDirection][1];
            }
            if(!newSharks[nowX][nowY].empty()) {
                if(nowShark.size > newSharks[nowX][nowY].front().size){
                    newSharks[nowX][nowY].pop_back();
                    newSharks[nowX][nowY].push_back(nowShark);
                }
            }else {
                newSharks[nowX][nowY].push_back(nowShark);
            }
        }
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            Sharks[i][j] = newSharks[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> R >> C >> M;

    int r, c, s, d, z;
    for (int i = 1; i <= M; i++) {
        cin >> r >> c >> s >> d >> z;
        if (d == 1 || d == 2) {
            s %= (R - 1) * 2;
        } else if (d == 3 || d == 4) {
            s %= (C - 1) * 2;
        }
        Sharks[r][c].push_back(Shark(r, c, s, d, z));
    }

    if (M == 0) {
        cout << 0;
        exit(0);
    }
    for (int i = 1; i <= C; i++) {
        fishing(i);
        moveAndKillShark();
    }

    cout << totalSize;

    return 0;
}

