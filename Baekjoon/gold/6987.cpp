#include <bits/stdc++.h>

using namespace std;

int input[6][3] = {0,};
int match[6][4] = {0,};
vector<int> vec(4);
int team1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int team2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };

void DFS(int tc, int round) {
    if (round >= 15) {
        // 이미 가능한 경우로 판단된 경우
        if (vec[tc] == 1) return;

        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 3; c++) {
                if (match[r][c] != input[r][c])
                    return;
            }
        }

        // 모든 예측이 일치한다면 가능한 결과로 처리
        vec[tc] = 1;
        return;
    }

    int team = team1[round];
    int other_team = team2[round];

    for (int j = 0; j < 3; j++) {
        match[team][j]++;
        match[other_team][2 - j]++;

        DFS(tc, round + 1);

        match[team][j]--;
        match[other_team][2 - j]--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> input[i][j];
            }
        }
        DFS(t, 0);
    }

    for (int i = 0; i < 4; i++)
        cout << vec[i] << ' ';
    cout << "\n";

    return 0;
}

