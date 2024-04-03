#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i, k) for(i = 0; i < k; i++)
#define REP(i, n, k) for(i = n; i < k; i++)
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

#define MAX 50001
using namespace std;


int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> vec;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());
    int sum = accumulate(vec.begin(), vec.end(), 0);
    int len = vec.size();

    int our = 0;
    int cnt = 0;
    for(int i = len - 1; i >= 0; i--) {
        our += vec[i];
        cnt++;
        if(sum - our < our) {
            break;
        }
    }

    cout << cnt;

    return 0;
}
