#include <bits/stdc++.h>

using namespace std;
#define MAX 101
#define INF 1000000000

int n, m, r;
int items[MAX];
int dist[MAX][MAX];

void show(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        cin >> items[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }

    int from, to, weight;
    for(int i = 0; i < r; i++){
        cin >> from >> to >> weight;
        dist[from][to] = weight;
        dist[to][from] = weight;
    }

    for(int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = (dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int res = -1;
    for(int i = 1; i <= n; i++){
        int temp = items[i];
        for(int j = 1; j <= n; j++){
            if(i == j) continue;

            if(dist[i][j] <= m){
                temp += items[j];
            }
        }
        res = max(res, temp);
    }

    cout << res;

    return 0;
}

