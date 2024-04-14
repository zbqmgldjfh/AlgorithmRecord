#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

long long DP[100001][2];
unordered_map<int, long long> MAP;

int main() {
    fastio;

    int n;
    cin >> n;

    int num;
    vector<long long> vec;
    for (int i = 0; i < n; i++) {
        cin >> num;
        MAP[num] += 1;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    int len = vec.size();
    DP[0][1] = MAP[vec[0]] * vec[0];
    for (int i = 1; i < len; i++) {
        if (vec[i] - vec[i - 1] == 1) {
            DP[i][1] = DP[i - 1][0] + (MAP[vec[i]] * vec[i]);
            DP[i][0] = max(DP[i - 1][1], DP[i - 1][0]);
        } else {
            DP[i][1] = max(DP[i - 1][1], DP[i - 1][0]) + (MAP[vec[i]] * vec[i]);
            DP[i][0] = max(DP[i - 1][1], DP[i - 1][0]);
        }
    }

    cout << max(DP[len - 1][0], DP[len - 1][1]);

    return 0;
}
