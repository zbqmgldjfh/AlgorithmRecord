#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int N, K;
vector<pair<int, int> > vec;
int arr[51];

int main() {
    fastio;

    int temp = 0;
    cin >> N >> K;
    if(N < K) {
        temp = K-N;
        K = N;
    }

    int num;
    for(int i = 1; i <= N; i++) {
        cin >> num;
        vec.push_back(make_pair(num, i));
    }

    sort(vec.begin(), vec.end());


    for(int i = vec.size()-1; i >= vec.size() - K; i--) {
        cout << vec[i].second << "\n";
        arr[vec[i].second-1] = vec[i].second;
        if(i == 0) break;
    }

    while(temp--) {
        cout << 0 << "\n";
    }

    for(int i = 0; i < vec.size(); i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}
