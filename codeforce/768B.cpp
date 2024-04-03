#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define llu unsigned long long

using namespace std;

llu len = 1;

int go(llu start, llu end, llu left, llu right, llu num) {
    llu res = 0;

    if(left > right || right <= 0 || left > len) {
        return 0;
    }

    if(start == left && end == right) {
        return num;
    }

    llu mid = ((end + start) / 2);
    llu half_num = num / 2;

    if (right < mid) {
        res += go(start, mid - 1, left, right, half_num);
    } else if (left > mid) {
        res += go(mid + 1, end, left, right, half_num);
    } else {
        if(num % 2 == 1) res += 1;
        res += go(start, mid - 1, left, mid - 1, half_num);
        res += go(mid + 1, end, mid + 1, right, half_num);
    }

    return res;
}


int main() {
    fastio;

    llu n, l, r;
    cin >> n >> l >> r;

    llu tempn = n;
    while (tempn >= 2) {
        tempn /= 2;
        len = (len * 2) + 1;
    }

    cout << go(1, len, l, r, n);

    return 0;
}
