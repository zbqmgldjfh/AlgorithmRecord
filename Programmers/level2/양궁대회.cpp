#include <bits/stdc++.h>

using namespace std;


int maxDiff;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11);
    vector<int> arr(11);

    for(int i = 1; i < (1 << 10); i++) {
        int ryan = 0, peach = 0, cnt = 0;
        for(int j = 0; j < 10; j++) {
            if(i & (1 << j)) { // 라이언이 이기는
                ryan += (10 - j);
                arr[j] = info[j] + 1;
                cnt += arr[j];
            } else { // 라이언이 이기지 않는 (지거나 비기는)
                arr[j] = 0;
                if(info[j] > 0) {
                    peach += (10 - j);
                }
            }
        }
        if(cnt > n) continue;

        arr[10] = n - cnt;


        if(maxDiff == ryan - peach) {
            for(int i = 10; i >= 0; i--) {
                if(arr[i] > answer[i]){
                    answer = arr;
                    break;
                } else if (arr[i] < answer[i]) {
                    break;
                }
            }
        } else if (maxDiff < ryan - peach) {
            maxDiff = ryan - peach;
            answer = arr;
        }
    }

    if(maxDiff == 0) {
        return {-1};
    }


    return answer;
}