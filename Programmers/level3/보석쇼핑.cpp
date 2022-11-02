#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    unordered_map<string, int> MAP;
    set<string> SET(gems.begin(), gems.end());

    int left = 0, right = 0;
    for(auto gem : gems) {
        MAP[gem] += 1;
        if(MAP.size() == SET.size()) break;
        right++;
    }

    int minLen = right - left;
    answer[0] = left + 1;
    answer[1] = right + 1;
    while(left < right && right < gems.size()) {
        string nowGem = gems[left++];
        MAP[nowGem] -= 1;

        if(MAP[nowGem] == 0) {
            right++;
            for(; right < gems.size(); right++) {
                MAP[gems[right]] += 1;
                if(MAP[nowGem] != 0) break;
            }
            //if(right >= gems.size()) break;
        }

        if(minLen > right - left) {
            minLen = right - left;
            answer[0] = left + 1;
            answer[1] = right + 1;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "rt", stdin);

    vector<string> vec = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<int> res = solution(vec);
    for(auto e : res) {
        cout << e << ", ";
    }

    return 0;
}
