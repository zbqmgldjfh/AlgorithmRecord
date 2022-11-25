#include <bits/stdc++.h>
#define pii pair<ll, ll>
typedef long long ll;
using namespace std;

const int MAX = 100007;
vector<pii> G[MAX];
ll D[MAX][10]; // 이전 정점의 범위가 제한되었으므로, 더 이상 map을 쓸 필요가 없습니다.
int A[MAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, M, ans = -1;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= M; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> PQ;
    memset(D, 0x3f, sizeof(D));
    PQ.emplace(D[1][0] = 0, pii {1, 0});

    while (!PQ.empty()) {
        auto [cd, c] = PQ.top(); PQ.pop();
        auto [cur, prev] = c;
        if (cd > D[cur][prev]) continue;
        if (cur == N) {
            ans = cd;
            break;
        }
        for (auto& [next, nd] : G[cur]) {
            if (cd + nd >= D[next][cur % A[next]]) continue;
            if (cur != 1 && prev % A[cur] != next % A[cur]) continue;
            PQ.emplace(D[next][cur % A[next]] = cd + nd, pii {next, cur % A[next]});
        }
    }

    cout << ans;
    return 0;
}