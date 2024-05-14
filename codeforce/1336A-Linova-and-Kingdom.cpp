#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
vector<int> adj[200001];
bool visited[200001];

class Node {
public:
    long long score;
public:
    Node(int score) : score(score) {}

public:
    bool operator<(const Node &rhs) const {
        return this->score > rhs.score;
    }
};

vector<Node> vec;

long long go(int now_num, int happy_score) {
    long long temp_cnt = 0;
    for (int next_num: adj[now_num]) {
        if (!visited[next_num]) {
            visited[next_num] = true;

            temp_cnt += go(next_num, happy_score + 1);
        }
    }
    vec.emplace_back(Node(happy_score - temp_cnt - 1));

    return temp_cnt + 1;
}


int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited[1] = true;
    go(1, 1);

    sort(vec.begin(), vec.end());

    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += vec[i].score;
    }

    cout << sum;

    return 0;
}
