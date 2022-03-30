#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int MAP[9][9];
int emptySize;
vector<pair<int, int>> points;

void show() {
    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << MAP[i][j] << ' ';
        cout << '\n';
    } // 결과 출력
    cout << "\n";
}

bool validPosition(pair<int, int>& p) {
    int squareX = p.first / 3;
    int squareY = p.second / 3;

    for(int i = 0; i <= 9; i++) {
        if( (p.first != i) && (MAP[i][p.second] == MAP[p.first][p.second]) ) { //열 비교
            return false;
        }
        if( (p.second != i) && (MAP[p.first][i] == MAP[p.first][p.second]) ) { //행 비교
            return false;
        }
    }
    for(int i = 3*squareX; i < 3*squareX+3; i++)
        for(int j = 3*squareY; j < 3*squareY+3; j++) {
            if(MAP[i][j] == MAP[p.first][p.second] && (i != p.first && j != p.second)) {
                return false;
            }
        }
    return true;
}

void run(int num) {
    if(num == emptySize) {
        for(int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << MAP[i][j];
            cout << '\n';
        } // 결과 출력
        exit(0);
    }
    for(int i = 1; i <= 9; i++) {
        MAP[points[num].first][points[num].second] = i;
        if(validPosition(points[num])) {
            run(num + 1);
        }
        MAP[points[num].first][points[num].second] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    for(int i = 0; i < 9; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < 9; j++){
            MAP[i][j] = str[j] - '0';
            if(MAP[i][j] == 0) {
                points.push_back({i, j});
                emptySize++;
            }
        }
    }

    run(0);

    return 0;
}

