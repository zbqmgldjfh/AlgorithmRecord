#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 1500001

int DP[MAX];

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    vector<pair<int, int>> vec;

    vec.push_back({0, 0});
    int day, cost;
    for(int i = 0; i < N; i++) {
        cin >> day >> cost;
        vec.push_back({day, cost});
    }

    int currentMax = 0;
    for(int i = 1; i <= N+1; i++) {
        currentMax = max(currentMax, DP[i]);
        if(i + vec[i].first > N+1) continue;
        DP[i + vec[i].first] = max(DP[i + vec[i].first], currentMax + vec[i].second);
    }

    cout << currentMax;

    return 0;
}

