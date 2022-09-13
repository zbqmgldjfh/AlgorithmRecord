#include <bits/stdc++.h>

using namespace std;
#define MAX 501

bool comp(pair<int, double> a, pair<int, double> b) {
    if (a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double temp[MAX] = {0,};
    vector<pair<int, float>> result;

    double stageSize = stages.size();
    for (int i = 0; i < stageSize; i++) {
        temp[stages[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        if (temp[i] == 0) {
            result.push_back({i, 0});
        } else {
            double t = temp[i] / stageSize;
            result.push_back({i, t});
            stageSize -= temp[i];
        }
    }

    int resultSize = result.size();

    sort(result.begin(), result.end(), comp);

    for (int i = 0; i < resultSize; i++) {
        answer.push_back(result[i].first);
    }
    return answer;
}