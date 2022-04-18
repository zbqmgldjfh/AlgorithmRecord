#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int N, M;
int inDegree[MAX];
vector<int> vec[MAX];
vector<int> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;

        int from;
        cin >> from;
        for(int j = 0; j < num-1; j++) {
            int to;
            cin >> to;
            vec[from].push_back(to);
            inDegree[to] += 1;
            from = to;
        }
    }

    queue<int> Q;
    for(int i = 1; i <= N; i++){
        if(inDegree[i] == 0) {
            Q.push(i);
        }
    }

    while(!Q.empty()) {
        int now = Q.front();
        res.push_back(now);
        Q.pop();

        for(auto next : vec[now]) {
            inDegree[next] -= 1;
            if(inDegree[next] == 0) {
                Q.push(next);
            }
        }
    }

    if(res.size() != N) {
        cout << 0;
    }else {
        for (int i = 0; i < N; i++) {
            cout << res[i] << "\n";
        }
    }

    return 0;
}

