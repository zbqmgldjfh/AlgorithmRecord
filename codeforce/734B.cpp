#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,k) for(i = 0; i < k; i++)
#define REP(i,n,k) for(i = n; i < k; i++)
#define eof while (cin >> n)
#define cinstr cin >> str
#define getstr getline (cin,str)
#define vi vector <int>
#define pii pair <int,int>
#define mii map <int,int>
#define pb push_back
#define in insert
#define llu unsigned long long
#define lld long long
#define U unsigned int

using namespace std;

int main() {
    fastio;

    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;

    int sum = 0;
    int min56 = min(k5, k6);
    if(min56 >= k2) {
        cout << 256 * k2;
        return 0;
    } else {
        sum += 256 * min56;
        k2 -= min56;
    }

    sum += (32 * min(k2, k3));
    cout << sum;
    return 0;
}
