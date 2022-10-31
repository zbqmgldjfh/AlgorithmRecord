#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> adj[10];

char calculate(int number, int cnt) {
    cnt--;
    int len = adj[number][0].size();
    cnt %= len;
    char &ch = adj[number][0].at(cnt);
    return ch;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    int cnt = 1;

    adj[1].push_back("1.,?!");
    adj[2].push_back("2ABC");
    adj[3].push_back("3DEF");
    adj[4].push_back("4GHI");
    adj[5].push_back("5JKL");
    adj[6].push_back("6MNO");
    adj[7].push_back("7PQRS");
    adj[8].push_back("8TUV");
    adj[9].push_back("9WXYZ");

    string str;
    cin >> str;

    string res = "";
    for(int i = 0; i < N; i++) {
        if(i == 0) continue;
        if(str[i] == str[i-1]) {
            cnt++;
        } else {
            char now = str[i-1];
            res += calculate(now - '0', cnt);
            cnt = 1;
        }
    }
    res += calculate(str[N-1] - '0', cnt);


    cout << res;

    return 0;
}