#include <bits/stdc++.h>

using namespace std;

vector<long long> numbers;
vector<char> command;
vector<char> op = {'*', '+', '-'};

long long calculate(long long n1, long long n2, char op) {
    if (op == '*') return n1 * n2;
    if (op == '+') return n1 + n2;
    if (op == '-') return n1 - n2;
}

long long solution(string expression) {
    long long answer = 0;

    string num = "";
    unsigned long len = expression.length();
    for (int i = 0; i < len; i++) {
        if (isdigit(expression[i])) {
            num += expression[i];
        } else {
            numbers.push_back(stoll(num));
            num = "";
            command.push_back(expression[i]);
        }
    }
    numbers.push_back(stoll(num));

    do {
        vector<long long> temp = numbers;
        vector<char> tempCmd = command;
        for (int i = 0; i < 3; i++) {
            char nowCmd = op[i];
            for (int j = 0; j < tempCmd.size(); j++) {
                if (nowCmd == tempCmd[j]) {
                    long long res = calculate(temp[j], temp[j + 1], nowCmd);
                    temp[j] = res;
                    temp.erase(temp.begin() + j + 1);
                    tempCmd.erase(tempCmd.begin() + j);
                    j--;
                }
            }
        }
        answer = max(answer, abs(temp[0]));
    } while (next_permutation(op.begin(), op.end()));

    return answer;
}
