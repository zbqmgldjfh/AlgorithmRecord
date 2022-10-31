#include <bits/stdc++.h>
#include <set>
using namespace std;

int N;
int arr[100001];
set<int> store;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if(store.find(-1 * num) != store.end()) {
            std::remove(store.begin(), store.end(), -1 * num);
            continue;
        }

        store.insert(num);
    }

    int sum = 0;
    for(auto e : store) {
        sum += e;
    }

    cout << sum;

    return 0;
}