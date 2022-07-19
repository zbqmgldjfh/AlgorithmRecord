#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 129

bool checked[MAX][MAX];
int MAP[MAX][MAX];
int N;
int white, blue;

bool isWhite(int x, int y, int len) {
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if(MAP[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

bool isBlue(int x, int y, int len) {
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if(MAP[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void go(int x, int y, int len) {
    if(isWhite(x, y, len)) {
        white++;
        return;
    }
    if(isBlue(x, y, len)) {
        blue++;
        return;
    }

    int halfLen = len / 2;
    go(x, y, halfLen);
    go(x, y + halfLen, halfLen);
    go(x + halfLen, y, halfLen);
    go(x + halfLen, y + halfLen, halfLen);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }

    go(0, 0, N);

    cout << white << "\n" << blue;

    return 0;
}

