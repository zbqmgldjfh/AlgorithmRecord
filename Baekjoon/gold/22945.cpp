#include <bits/stdc++.h>
using namespace std;

int N;

int calculate(const vector<int> &vec, int left, int right) {
    return (right - left - 1) * min(vec[left], vec[right]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    int res = -1;
    int left = 0, right = N - 1;
    while (left < right) {
        res = max(res, calculate(vec, left, right));

        if (vec[left] < vec[right]) {
            left += 1;
        } else {
            right -= 1;
        }
    }

    cout << res;

    return 0;
}
