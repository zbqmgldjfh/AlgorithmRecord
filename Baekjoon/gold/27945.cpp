#include <bits/stdc++.h>

using namespace std;

int N, M;
int parent[100001];

int find(int a) {
    if (parent[a] == a) {
        return a;
    }

    return parent[a] = find(parent[a]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 100001; i++) {
        parent[i] = i;
    }

    vector<tuple<int, int, int>> vec;

    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        vec.push_back(make_tuple(a, c, b));
    }

    sort(vec.begin(), vec.end(), [](auto a, auto b) { return get<1>(a) < get<1>(b); });

    int i;
    for (i = 1; i <= N - 1; i++) {
        int from, to, day;
        tie(from, day, to) = vec[i - 1];

        if (i == day) {
            if (find(from) != find(to)) {
                join(from, to);
            } else { // 같은 경우
                break;
            }
        } else {
            break;
        }
    }

    cout << i;

    return 0;
}