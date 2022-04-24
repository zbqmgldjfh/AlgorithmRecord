#include <bits/stdc++.h>

using namespace std;
#define MAX 1000001

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    vector<int> vec;
    vec.push_back(INT_MIN);
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;

        if (vec.back() < num) {
            vec.push_back(num);
        } else {
            const vector<int>::iterator &iter = lower_bound(vec.begin(), vec.end(), num);
            *iter = num;
        }
    }

    cout << vec.size() - 1;

    return 0;
}

