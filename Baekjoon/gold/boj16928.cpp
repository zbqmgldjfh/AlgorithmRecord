#include <bits/stdc++.h>

using namespace std;
#define MAX 101

int N, M;
int nextNumber[MAX];
int counter[MAX];
bool visited[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;

    int from, to;
    for(int i = 0; i < N; i++) {
        cin >> from >> to;
        nextNumber[from] = to;
    }
    for(int i = 0; i < M; i++) {
        cin >> from >> to;
        nextNumber[from] = to;
    }

    queue<int> Q;
    visited[1] = true;
    Q.push(1);

    while(!Q.empty()) {
        int now = Q.front();
        Q.pop();

        for(int i = 1; i <= 6; i++) {
            int nx = now + i;

            if(nextNumber[nx] != 0) {
                nx = nextNumber[nx];
            }

            if(nx > 100) continue;

            if(!visited[nx]) {
                counter[nx] = counter[now] + 1;
                visited[nx] = true;
                Q.push(nx);
            }
        }
    }

    cout << counter[100];

    return 0;
}

