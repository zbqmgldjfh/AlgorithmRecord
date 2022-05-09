#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3) {
    ll temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    temp = temp - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;
    if(temp > 0) return 1;
    else if(temp == 0) return 0;
    else if(temp < 0) return -1;
}

bool isOverlapped(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C, pair<ll, ll> D) {
    int ans1 = ccw(A, B, C) * ccw(A, B, D);
    int ans2 = ccw(C, D, A) * ccw(C, D, B);

    if(ans1 == 0 && ans2 == 0) {
        if (A > B)swap(A, B);
        if (C > D)swap(C, D);
        //first 비교가 아닌 것은 x가 같고 y가 달라서 일직선일 수 있으므로..
        if (A <= D && C <= B){
            return true;
        }else{
            return false;
        }
    }else if(ans1 <= 0 && ans2 <= 0) {
        return true;
    }else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    pair<ll, ll> A;
    pair<ll, ll> B;
    pair<ll, ll> C;
    pair<ll, ll> D;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;
    cin >> D.first >> D.second;

    if(isOverlapped(A, B, C, D)) {
        cout << 1;
    }else{
        cout << 0;
    }

    return 0;
}

