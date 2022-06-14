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
    Q.push(1);
    visited[1] = true;

    while(!Q.empty()) {
        int now = Q.front();
        Q.pop();

        for(int i = 1; i <= N; i++) {
            if(friendMap[now][i] == false && !visited[i]) {
                visited[i] = visited
            }
        }
    }
    sort(teamA.begin(), teamA.begin());
    cout << teamA.size() << "\n";
    for (const auto &a: teamA) {
        cout << a << " ";
    }
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

