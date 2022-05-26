#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<deque>

using namespace std;
#define MAX 101

int T;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> T;
    for(int i = 0; i < T; i++) {
        bool isReverse = false;
        bool isError = false;
        deque<int> dq;

        string func;
        cin >> func;

        int len;
        cin >> len;

        string numArr;
        cin >> numArr;

        string str = "";
        unsigned long size = numArr.size();
        for(int j = 0; j < size; j++) {
            if(isdigit(numArr[j])) {
                str += numArr[j];
            }else{
                if(!str.empty()) {
                    dq.push_back(stoi(str));
                    str = "";
                }
            }
        }

        for(auto o : func) {
            if(o == 'R') {
                isReverse = (isReverse == true) ? false : true;
            }else{
                if(dq.empty()) {
                    cout << "error" << '\n';
                    isError = true;
                    break;
                }
                if(isReverse){
                    dq.pop_back();
                }else{
                    dq.pop_front();
                }
            }
        }

        if(!isError) {
            cout << "[";
        }

        if(isReverse && !dq.empty()) {
            for(auto e = dq.rbegin(); e != dq.rend(); e++){
                if(e == dq.rend() - 1) {
                    cout << *e;
                }else {
                    cout << *e << ",";
                }
            }
        }

        if(!isReverse && !dq.empty()) {
            for(auto e = dq.begin(); e != dq.end(); e++){
                if(e == dq.end() - 1) {
                    cout << *e;
                }else {
                    cout << *e << ",";
                }
            }
        }

        if(!isError) {
            cout << "]\n";
        }

    }

    return 0;
}

