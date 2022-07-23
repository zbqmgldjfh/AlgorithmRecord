#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 129

int N;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    while(N--) {
        map<string, int> closet;
        int num, res = 1;
        cin >> num;

        string key, value;
        for(int i = 0; i < num; i++) {
            cin >> value >> key;

            if(closet.find(key) == closet.end()) {
                closet.insert({key, 1});
            }else{
                closet[key]++;
            }
        }
        for(auto e : closet) {
            res *= (e.second + 1);
        }
        cout << res-1 << "\n";
    }

    return 0;
}

