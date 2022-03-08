#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 2147000000

vector<int> vec;

void postOrder(int start, int end){
    if(start >= end){
        return;
    }
    int rootNum = vec[start];

    int i = 0;
    for(i = start+1; i < end; i++){
        if(rootNum < vec[i]){
            break;
        }
    }
    postOrder(start+1, i);
    postOrder(i, end);

    cout << vec[start] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    int num;
    while(cin >> num){
        vec.push_back(num);
    }

    postOrder(0, vec.size());

    return 0;
}

