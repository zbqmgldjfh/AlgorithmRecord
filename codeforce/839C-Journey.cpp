#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
vector<int> adj[100001];
bool visited[100001];

double go(int now_num) {
    double sum = 0;

    int visit_cnt = 0;
    for (int next_num: adj[now_num]) {
        if (visited[next_num]) continue;

        visited[next_num] = true;
        visit_cnt++;
        sum += go(next_num);
    }

    if (visit_cnt != 0) {
        sum /= visit_cnt;
    }

    if (now_num != 1) {
        sum += 1;
    }

    return sum;
}

int main() {
    fastio;

    int n;
    cin >> n;

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited[1] = true;
    cout << fixed << setprecision(15) << go(1);

    return 0;
}
