#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 16

int N;
int MAP[MAX][MAX];
int cnt;
int r, c;

void findZ(int x, int y, int len) {
    if(x == r && y == c) {
        cout << cnt << "\n";
        exit(0);
    }

    if(r >= x && c >= y && r < x+len && c < y+len) {
        int halfLen = len / 2;
        findZ(x, y, halfLen);
        findZ(x, y + halfLen, halfLen);
        findZ(x + halfLen, y, halfLen);
        findZ(x + halfLen, y + halfLen, halfLen);
    }else{
        cnt += len*len;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    cin >> r >> c;

    findZ(0, 0, (1<<N));

    return 0;
}

