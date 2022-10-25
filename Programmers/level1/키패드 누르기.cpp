#include <bits/stdc++.h>
using namespace std;

pair<int, int> leftHand = {3, 0}, rightHand = {3, 2};

pair<int, int> calculatePosition(int num) {
    if(num == 0) {
        return {3, 1};
    }
    num--;
    int x = num / 3;
    int y = num % 3;
    return {x, y};
}

int calculateDistance(pair<int, int> numPos, pair<int, int> hand) {
    return (abs(numPos.first - hand.first) + abs(numPos.second - hand.second));
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(auto number : numbers) {
        const pair<int, int> &numPos = calculatePosition(number);
        if(numPos.second == 0) {
            leftHand = numPos;
            answer.append("L");
        } else if(numPos.second == 2) {
            rightHand = numPos;
            answer.append("R");
        } else {
            int leftLen = calculateDistance(numPos, leftHand);
            int rightLen = calculateDistance(numPos, rightHand);
            if(leftLen < rightLen) {
                leftHand = numPos;
                answer.append("L");
            } else if(leftLen > rightLen) {
                rightHand = numPos;
                answer.append("R");
            } else {
                if(hand == "right") {
                    rightHand = numPos;
                    answer.append("R");
                } else {
                    leftHand = numPos;
                    answer.append("L");
                }
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand = "right";
    cout << solution(numbers, hand);

    return 0;
}