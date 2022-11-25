#include <bits/stdc++.h>

using namespace std;

int N, M;
unordered_map<int, int> MAP;
set<int> userNum;

class Data {
public:
    int num;
    int cnt;
public:
    Data(int num, int cnt) : num(num), cnt(cnt) {}
};

vector<Data> vec;

bool compareFunction(const Data &a, const Data &b) {
    if(a.cnt != b.cnt) {
        return a.cnt > b.cnt;
    } else {
        return a.num > b.num;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int num = 0;
        cin >> num;

        int temp = 0;
        for(int j = 0; j < num; j++) {
            cin >> temp;
            userNum.insert(temp);
            MAP[temp] += 1;
        }
    }

    for(auto e : userNum) {
        vec.push_back(Data(e, MAP[e]));
    }

    sort(vec.begin(), vec.end(), compareFunction);
    int maxCnt = vec[0].cnt;
    for(auto e : vec) {
        if(e.cnt == maxCnt) {
            cout << e.num << " ";
        }
    }

    return 0;
}
