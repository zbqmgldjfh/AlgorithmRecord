
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define MAX 50001

using namespace std;

vector<int> res;
vector<pair<int, int>> adj[MAX];
int intensity[MAX];
bool isSummit[MAX];

void go(vector<int>& gates) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> temp;

    memset(intensity, -1, sizeof(intensity));

    for(auto g : gates) {
        pq.push({0, g});
        intensity[g] = 0;
    }

    while(!pq.empty()) {
        int cost = pq.top().first;
        int nowV = pq.top().second;
        pq.pop();

        if(cost > intensity[nowV]) continue;

        if(isSummit[nowV]) {
            temp.push_back({cost, nowV});
            continue;
        }

        for(auto p : adj[nowV]) {
            int weight = p.first;
            int to = p.second;

            if(intensity[to] == -1 || max(cost, weight) < intensity[to]) {
                intensity[to] = max(cost, weight);
                pq.push({intensity[to], to});
            }
        }
    }

    sort(ALL(temp));
    res.push_back(temp[0].second);
    res.push_back(temp[0].first);
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    for (auto e : paths) {
        adj[e[0]].push_back({e[2], e[1]});
        adj[e[1]].push_back({e[2], e[0]});
    }

    for(auto s : summits) {
        isSummit[s] = true;
    }

    go(gates);
    return res;
}