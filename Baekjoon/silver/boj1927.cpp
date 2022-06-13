#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 1001
#define INF 987654321

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if(num == 0) {
            if(pq.size() == 0) {
                cout << 0 << "\n";
            }else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }else {
            pq.push(num);
        }
    }


    return 0;
}

