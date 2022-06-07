#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 101
#define INF 987654321

int N, M;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    set<string> nameSet;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        nameSet.insert(str);
    }
    vector<string> nameList;
    for(int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if(nameSet.find(str) != nameSet.end()) {
            nameList.push_back(str);
        }
    }
    cout << nameList.size() << "\n";
    sort(nameList.begin(), nameList.end());
    for (const auto &item: nameList) {
        cout << item << "\n";
    }

    return 0;
}

