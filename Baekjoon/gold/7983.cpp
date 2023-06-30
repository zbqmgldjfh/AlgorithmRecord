#include <bits/stdc++.h>

using namespace std;

int N;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int> > vec;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int d, t;
        cin >> d >> t;
        vec.push_back(make_pair(d, t));
    }

    sort(vec.begin(), vec.end(), compare);

    int lastIdx = vec[0].second - vec[0].first;
    for (int i = 1; i < N; i++) {
        auto &pair = vec[i];
        int d = pair.first;
        int t = pair.second;

        if (lastIdx >= t) { // 안겹치는
            lastIdx = t - d;
        } else { //  겹치는
            lastIdx -= d;
        }
    }

    cout << lastIdx;

    return 0;
}
