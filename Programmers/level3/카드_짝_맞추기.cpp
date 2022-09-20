#include <bits/stdc++.h>

#define INF 2147000000
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> Board;

class Position {
public:
    int x;
    int y;
    int cnt;
public:
    Position(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
};

int BFS(const Position& p1, const Position& p2) {
    bool visited[4][4] = {false, };
    queue<Position> Q;
    Q.push(p1);
    visited[p1.x][p1.y] = true;

    while(!Q.empty()) {
        int nowX = Q.front().x;
        int nowY = Q.front().y;
        int nowCnt = Q.front().cnt;
        Q.pop();

        if(nowX == p2.x && nowY == p2.y) return nowCnt;

        for(int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;

            if(!visited[nx][ny]) {
                Q.push(Position(nx, ny, nowCnt+1));
                visited[nx][ny] = true;
            }

            for(int j = 0; j < 2; j++) {
                if(Board[nx][ny] != 0) break;
                if(nx + dx[i] < 0 || ny + dy[i] < 0 || nx + dx[i] >= 4 || ny + dy[i] >= 4) break;
                nx += dx[i];
                ny += dy[i];
            }

            if(!visited[nx][ny]) {
                Q.push(Position(nx, ny, nowCnt+1));
                visited[nx][ny] = true;
            }
        }
    }
}

int permutate(Position pos) {
    int res = INF;

    for(int t = 1; t <= 6; t++) {
        vector<Position> cards;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(Board[i][j] == t) {
                    cards.push_back(Position(i, j, 0));
                }
            }
        }

        if(cards.empty()) continue;

        int one = BFS(pos, cards[0]) + BFS(cards[0], cards[1]) + 2;
        int two = BFS(pos, cards[1]) + BFS(cards[1], cards[0]) + 2;

        for(int i = 0; i < 2; i++) {
            Board[cards[i].x][cards[i].y] = 0;
        }

        res = min(res, one + permutate(cards[1]));
        res = min(res, two + permutate(cards[0]));

        for(int i = 0; i < 2; i++) {
            Board[cards[i].x][cards[i].y] = t;
        }
    }

    if(res == INF) {
        return 0;
    }

    return res;
}

int solution(vector<vector<int>> board, int r, int c) {
    Board = board;
    return permutate(Position(r, c, 0));
}
