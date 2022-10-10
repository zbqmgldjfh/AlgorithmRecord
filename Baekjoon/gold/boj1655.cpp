#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    max_pq.push(-10001);
    min_pq.push(10001);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        int num;
        cin >> num;

        if(i % 2 == 1) {
            if(num < min_pq.top()) {
                max_pq.push(num);
            } else {
                int top = min_pq.top();
                min_pq.pop();
                max_pq.push(top);
                min_pq.push(num);
            }
        } else {
            if(num > max_pq.top()) {
                min_pq.push(num);
            } else {
                int top = max_pq.top();
                max_pq.pop();
                min_pq.push(top);
                max_pq.push(num);
            }
        }
        cout << max_pq.top() << "\n";
    }

    return 0;
}
