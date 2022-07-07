#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 100001

int N, M;
int sum;
int parent[MAX];

class Line{
public:
    int a, b;
    int weight;

public:
    Line(int a, int b, int weight) : a(a), b(b), weight(weight) {}

    bool operator < (const Line& temp) const {
        return this->weight < temp.weight;
    }
};

int find(int u) {
    if(parent[u] == u) {
        return u;
    }

    return parent[u] = find(parent[u]);
}

void join(int a, int b) {
    int ap = find(a);
    int bp = find(b);

    if(ap != bp) {
        parent[ap] = bp;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;

    vector<Line> lines;
    vector<int> result;

    int A, B, C;
    for(int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        lines.push_back(Line(A, B, C));
    }

    sort(lines.begin(), lines. end());
    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < lines.size(); i++) {
        Line &line = lines[i];

        if(find(line.a) == find(line.b)){
            continue;
        }

        join(line.a, line.b);
        result.push_back(line.weight);
    }

    for(int i = 0; i < result.size()-1; i++) {
        sum += result[i];
    }

    cout << sum;
    return 0;
}

