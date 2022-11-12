#include <bits/stdc++.h>
//https://school.programmers.co.kr/learn/courses/30/lessons/67259

using namespace std;
// 방향, 시계방향 0123, 무방향 -1
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int DP[25][25][4];

class Car {
public:
    int x;
    int y;
    int cost;
    int dir;
public:
    Car(int x, int y, int cost, int dir) : x(x), y(y), cost(cost), dir(dir) {}
};

int solution(vector<vector<int>> board) {
    int answer = 2147000000;

    int N = board.size();
    int M = board[0].size();

    queue<Car> Q;
    Q.push(Car(0, 0, 0, 1));
    Q.push(Car(0, 0, 0, 2));

    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < 25; j++) {
            for(int k = 0; k < 4; k++) {
                DP[i][j][k] = INT_MAX;
            }
        }
    }

    DP[0][0][1] = 0;
    DP[0][0][2] = 0;

    while (!Q.empty()) {
        Car &nowCar = Q.front();
        int nowX = nowCar.x;
        int nowY = nowCar.y;
        int nowCost = nowCar.cost;
        int nowDir = nowCar.dir;
        Q.pop();

        if (nowX == N - 1 && nowY == M - 1) {
            answer = min(answer, nowCost);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            int add = 0;

            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) continue;

            if (board[nextX][nextY] != 1) {
                if (nowDir == i) add = nowCost + 100;
                else add = nowCost + 600;

                if (DP[nextX][nextY][i] >= add) {
                    DP[nextX][nextY][i] = add;
                    Q.push(Car(nextX, nextY, add, i));
                }
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "rt", stdin);

    vector<vector<int>> board = {{0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 0, 1, 1, 1, 1, 1, 0},
                                 {1, 0, 0, 1, 0, 0, 0, 0},
                                 {1, 1, 0, 0, 0, 1, 1, 1},
                                 {1, 1, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 0}};
    int res = solution(board);
    cout << res;

    return 0;
}
