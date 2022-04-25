#include <bits/stdc++.h>

using namespace std;
#define MAX 1000001

int N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> K;
    vector<pair<int, int>> jewelry(N);
    vector<int> bag(K);
    for(int i = 0; i < N; i++) {
        int M, V;
        cin >> M >> V;
        jewelry[i] = {M, V};
    }
    for(int i = 0; i < K; i++) {
        int num;
        cin >> num;
        bag[i] = num;
    }

    // 가방, 보석 오름차순 정렬
    sort(jewelry.begin(), jewelry.end());
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;
    long long res = 0;
    int index = 0;
    for(int i = 0; i < K; i++) {
        while(index < N && jewelry[index].first <= bag[i]){
            pq.push(jewelry[index++].second);
        }
        if(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
    }
    cout << res << "\n";

    return 0;
}

