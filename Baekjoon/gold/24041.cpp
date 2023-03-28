#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, G, K;

class Food {
public:
    int s;
    int l;
    int o;
public:
    Food(int _s, int _l, int _o) : s(_s), l(_l), o(_o) {}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> G >> K;
    vector<Food> vec;
    for (int i = 0; i < N; i++) {
        int S, L, O;
        cin >> S >> L >> O;
        vec.push_back(Food(S, L, O));
    }

    ll res = 0ll;
    ll left = 0, right = 2e9 + 1;
    while (left <= right) {
        ll mid = (left + right) / 2;

        vector<ll> temp;
        ll bacteria_sum = 0ll;
        for(int i = 0; i < vec.size(); i++) {
            Food &food = vec[i];

            ll bacteria_cnt = food.s * max(1ll, mid - food.l);
            bacteria_sum += bacteria_cnt;
            if(food.o == 1) {
                temp.push_back(bacteria_cnt);
            }
        }

        sort(temp.begin(), temp.end(), greater<ll>()); // 내림차순

        int len;
        if(K > temp.size()) {
            len = temp.size();
        } else {
            len = K;
        }

        for(int i = 0; i < len; i++) {
            bacteria_sum -= temp[i];
        }

        if(bacteria_sum <= G) {
            res = max(res, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << res;

    return 0;
}
