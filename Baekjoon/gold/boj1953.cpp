#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 101
#define INF 987654321

int N;
bool friendMap[MAX][MAX];
int visited[MAX];

void BFS() {
    vector<int> teamA, teamB;
    queue<int> Q;

    for(int i = 1; i <= N; i++) {
        if(visited[i] != 0) continue;
        visited[i] = 1;
        Q.push(i);

        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();

            for (int j = 1; j <= N; j++) {
                if (friendMap[now][j] == false && !visited[j]) {
                    visited[j] = visited[now] * -1;
                    Q.push(j);
                }
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(visited[i] == 1) teamA.push_back(i);
        else if(visited[i] == -1) teamB.push_back(i);
    }
    cout << teamA.size() << "\n";
    for (const auto &a: teamA) {
        cout << a << " ";
    }
    cout << "\n";
    cout << teamB.size() << "\n";
    for (const auto &b: teamB) {
        cout << b << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    memset(friendMap, true, sizeof(friendMap));

    cin >> N;
    for(int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        for(int j = 0; j < num; j++) {
            int personNum;
            cin >> personNum;
            friendMap[i][personNum] = false;
            friendMap[personNum][i] = false;
        }
    }

    BFS();

    return 0;
}

