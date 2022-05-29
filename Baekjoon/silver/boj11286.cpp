#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 101

int T;
priority_queue<int, vector<int>, greater<int>> plusQ;
priority_queue<int, vector<int>, greater<int>> minusQ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> T;
    while (T--) {
        int num;
        cin >> num;

        if (num == 0) {
            if(plusQ.size() == 0 && minusQ.size() == 0) {
                cout << 0 << "\n";
                continue;
            }else if(plusQ.size() == 0){
                cout << minusQ.top() * -1 << "\n";
                minusQ.pop();
                continue;
            }else if(minusQ.size() == 0) {
                cout << plusQ.top() << "\n";
                plusQ.pop();
                continue;
            }

            int plusFront = plusQ.top();
            int minusFront = minusQ.top();

            if(plusFront > minusFront) {
                cout << minusFront * -1 << "\n";
                minusQ.pop();
            }else if(plusFront < minusFront){
                cout << plusFront << "\n";
                plusQ.pop();
            }else {
                cout << minusFront * -1 << "\n";
                minusQ.pop();
            }
        } else {
            if (num > 0) {
                plusQ.push(num);
            } else {
                minusQ.push(abs(num));
            }
        }
    }

    return 0;
}

