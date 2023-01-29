#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool deleted;
    Node* prev;
    Node* next;
};

Node nodeArray[1000001];

string solution(int n, int k, vector<string> cmd) {
    for (int i = 1; i < n; i++) {
        nodeArray[i-1].next = &nodeArray[i];
        nodeArray[i].prev = &nodeArray[i-1];
    }

    Node* curr = &nodeArray[k];
    stack<Node*> history;

    for(string str : cmd) {
        if(str[0] == 'U') {
            int cnt = atoi(str.c_str() + 2);
            for(int i = 0; i < cnt; i++) {
                curr = curr->prev;
            }
        } else if (str[0] == 'D') {
            int cnt = atoi(str.c_str() + 2);
            for(int i = 0; i < cnt; i++) {
                curr = curr->next;
            }
        } else if (str[0] == 'C') {
            history.push(curr);
            curr->deleted = true;
            Node* up = curr->prev;
            Node* down = curr->next;
            if(up != nullptr) {
                up->next = down;
            }
            if(down != nullptr) {
                down->prev = up;
                curr = down;
            } else {
                curr = up;
            }
        } else if (str[0] == 'Z') {
            Node* node = history.top();
            history.pop();
            node->deleted = false;
            Node* up = node->prev;
            Node* down = node->next;
            if(up != nullptr) {
                up->next = node;
            }
            if(down != nullptr) {
                down->prev = node;
            }
        }
    }

    string answer = "";
    for(int i = 0; i < n; i++) {
        if(nodeArray[i].deleted) {
            answer.push_back('X');
        } else {
            answer.push_back('O');
        }
    }

    return answer;
}