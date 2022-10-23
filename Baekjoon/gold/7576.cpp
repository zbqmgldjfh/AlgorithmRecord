#include <bits/stdc++.h>
using namespace std;

#define rep(i,k) for(i = 0; i < k; i++)
#define REP(i,n,k) for(i = n; i < k; i++)
#define VISITED 1

int M, N, lv(0);
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int vec[1001][1001];

queue<pair<pair<int, int>, int> > Q;

void BFS(){
    while(!Q.empty()){
        int x1 = Q.front().first.first;
        int y1 = Q.front().first.second;
        lv = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++){
            int xx = x1 + dx[i];
            int yy = y1 + dy[i];

            if(xx <= 0 || yy <= 0 || xx > M || yy > N) continue;

            if(vec[xx][yy] == 0){
                vec[xx][yy] = VISITED;
                Q.push({{xx, yy}, lv+1});
            }
        }
    }
}

void check(){
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (vec[i][j] == 0) {
                lv = -1; break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> vec[i][j];
        }
    }

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            if(vec[i][j] == 1){
                vec[i][j] = VISITED;
                Q.push({{i, j}, 0});
            }
        }
    }
    BFS();
    check();

    cout << lv;

    return 0;
}