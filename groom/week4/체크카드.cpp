#include <bits/stdc++.h>

using namespace std;

long long N;
int M;
queue<int> Q;

void calculate(string str, int num) {
    if (str == "deposit") {
        N += num;
        while (!Q.empty() && Q.front() <= N) {
            N -= Q.front();
            Q.pop();
        }
    } else if (str == "pay" && N >= num) {
        N -= num;
    } else if (str == "reservation") {
        if (Q.empty() && N >= num) {
            N -= num;
        } else {
            Q.push(num);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        string op;
        int num;
        cin >> op >> num;
        calculate(op, num);
    }

    cout << N;

    return 0;
}