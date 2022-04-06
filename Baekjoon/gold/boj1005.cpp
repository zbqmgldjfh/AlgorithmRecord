#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int T, N, K, W;
int inDegree[MAX];
int buildTime[MAX];
int totalTime[MAX];
vector<int> vec[MAX];

void init(){
    memset(inDegree, 0, sizeof(inDegree));
    memset(buildTime, 0, sizeof(buildTime));
    memset(totalTime, 0, sizeof(totalTime));
    for (int i = 0; i < MAX; i++) vec[i].clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> T;
    while(T--){
        cin >> N >> K;
        for(int i = 1; i <= N; i++) {
            cin >> buildTime[i];
        }
        for(int i = 0; i < K; i++) {
            int from, to;
            cin >> from >> to;
            vec[from].push_back(to);
            inDegree[to]++;
        }
        cin >> W;

        queue<int> Q;
        for(int i = 1; i <= N; i++){
            if(inDegree[i] == 0) {
                Q.push(i);
                totalTime[i] = buildTime[i];
            }
        }

        while(!Q.empty()) {
            int nowV = Q.front();
            Q.pop();

            for(int nextV : vec[nowV]) {
                inDegree[nextV] -= 1;
                totalTime[nextV] = max(totalTime[nextV], totalTime[nowV] + buildTime[nextV]);
                if(inDegree[nextV] == 0){
                    Q.push(nextV);
                }
            }
        }
        cout << totalTime[W] << "\n";
        init();
    }

    return 0;
}

