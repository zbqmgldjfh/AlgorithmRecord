#include <bits/stdc++.h>

using namespace std;
#define MAX 1001

int N, M;
int zeroSpaceNum;
int zeroSpaceMap[MAX][MAX];
int Answer[MAX][MAX];
int MAP[MAX][MAX];
bool visited[MAX][MAX];
vector<int> vec;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void show() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << zeroSpaceMap[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void BFS(int x, int y) {
    int cnt = 1;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    visited[x][y] = true;
    zeroSpaceMap[x][y] = zeroSpaceNum;

    while (!Q.empty()) {
        show();
        int nowX = Q.front().first;
        int nowY = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                continue;
            }

            if (!visited[nx][ny] && MAP[nx][ny] == 0) {
                visited[nx][ny] = true;
                cnt++;
                zeroSpaceMap[nx][ny] = zeroSpaceNum;
                Q.push({nx, ny});
            }
        }
    }

    vec.push_back(cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            MAP[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 0 && !visited[i][j]) {
                BFS(i, j);
                zeroSpaceNum++;
            }
        }
    }
//    for(auto e : vec) {
//        cout << e << " ";
//    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 1) {
                set<int> search;
                int canGoPath = 1;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                        if (MAP[nx][ny] == 0 && search.find(zeroSpaceMap[nx][ny]) == search.end()) {
                            canGoPath += vec[zeroSpaceMap[nx][ny]];
                            search.insert(zeroSpaceMap[nx][ny]);
                        }
                    }
                }
                Answer[i][j] = canGoPath;
                Answer[i][j] = Answer[i][j] % 10;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << Answer[i][j];
        }
        cout << "\n";
    }

    return 0;
}

