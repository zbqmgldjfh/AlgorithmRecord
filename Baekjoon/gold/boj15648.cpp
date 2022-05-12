#include <bits/stdc++.h>
using namespace std;
#define INF 2147000000

int N, M, H;
bool ladder[31][11];
int res = INF;

bool isValid(){
    for(int col = 1; col <= N; col++){
        int nowLine = col;
        for(int row = 1; row <= H; row++){
            if(ladder[row][nowLine]) nowLine++;
            else if(ladder[row][nowLine - 1]) nowLine--;
        }
        if(nowLine != col) return false;
    }
    return true;
}

void make_ladder(int index, int cnt) {
    if(cnt >= 4) {
        return;
    }
    if(isValid()) {
        res = min(res, cnt);
        return;
    }

    for(int i = index; i <= H; i++) {
        for(int j = 1; j <= N; j++) {
            if(ladder[i][j] == true) continue;
            if(ladder[i][j-1] == true) continue;
            if(ladder[i][j+1] == true) continue;
            ladder[i][j] = true;
            make_ladder(i, cnt+1);
            ladder[i][j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M >> H;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    make_ladder(1, 0);

    cout << ((res == INF) ? -1 : res) << "\n";

    return 0;
}

