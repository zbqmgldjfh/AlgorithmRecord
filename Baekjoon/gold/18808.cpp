#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int R, C;

int MAP[41][41];
int sticker[41][41];
int cpy_sticker[41][41];

void solution();

bool isPossibleStick(int x, int y) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (MAP[x + i][y + j] == 1 && sticker[i][j] == 1) return false;
        }
    }
    return true;
}

void rotate() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cpy_sticker[j][R - 1 - i] = sticker[i][j];
        }
    }

    int tmp = C;
    C = R;
    R = tmp;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            sticker[i][j] = cpy_sticker[i][j];
        }
    }
}

void stick(int x, int y) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (sticker[i][j] == 1) MAP[x + i][y + j] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M >> K;
    while (K--) {
        cin >> R >> C;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> sticker[i][j];
            }
        }

        solution();

        memset(sticker, 0, sizeof(sticker));
        memset(cpy_sticker, 0, sizeof(cpy_sticker));
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j]) answer++;
        }
    }
    cout << answer << "\n";

    return 0;
}

void solution() {
    for (int rotation = 0; rotation < 4; rotation++) {
        for (int i = 0; i + R <= N; i++) {
            for (int j = 0; j + C <= M; j++) {
                if (isPossibleStick(i, j)) {
                    stick(i, j);
                    return;
                }
            }
        }
        rotate();
    }
}

