#include <bits/stdc++.h>

using namespace std;

int p;
int m, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> p;
    cin >> m >> n;

    vector<int> pizzaA(m), pizzaB(n);
    for(int i = 0; i < m; i++) {
        cin >> pizzaA[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> pizzaB[i];
    }

    vector<int> sum1(1, 0);
    for(int i = 0; i < m; i++) {
        int sum = 0;
        for(int j = i; j < i + m - 1; j++) {
            sum += pizzaA[j % m];
            sum1.push_back(sum);
        }
    }
    sum1.push_back(accumulate(pizzaA.begin(), pizzaA.end(), 0));

    vector<int> sum2(1, 0);
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < i + n - 1; j++) {
            sum += pizzaB[j % n];
            sum2.push_back(sum);
        }
    }
    sum2.push_back(accumulate(pizzaB.begin(), pizzaB.end(), 0));

    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    int res = 0;
    for (int i = 0; i < sum1.size(); i++) {
        int value = p - sum1[i];
        if(value < 0) {
            break;
        }
        int low = lower_bound(sum2.begin(), sum2.end(), value) - sum2.begin();
        int high = upper_bound(sum2.begin(), sum2.end(), value) - sum2.begin();
        res += high - low;
    }

    cout << res;

    return 0;
}
