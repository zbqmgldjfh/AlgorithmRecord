#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int x;
    int y;
    int num;
    Node* left;
    Node* right;
public:
    Node(int x, int y, int num) : x(x), y(y), num(num) {
        left = nullptr;
        right = nullptr;
    }

public:
    bool operator < (const Node &temp) {
        return this->y > temp.y;
    }
};

void preOrder(vector<int> &arr, Node* node) {
    if(node != NULL) {
        arr.push_back(node->num);
        preOrder(arr, node->left);
        preOrder(arr, node->right);
    }
}

void postOrder(vector<int> &arr, Node* node) {
    if(node != NULL) {
        postOrder(arr, node->left);
        postOrder(arr, node->right);
        arr.push_back(node->num);
    }
}

void connectNode(Node* parent, Node* child) {
    if (parent->x > child->x) {
        if(parent->left == NULL) {
            parent->left = child;
        }else{
            connectNode(parent->left, child);
        }
    } else {
        if(parent->right == NULL) {
            parent->right = child;
        }else{
            connectNode(parent->right, child);
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer = {{}, {}};

    vector<Node> nodeList;

    int len = nodeinfo.size();
    for (int i = 0; i < len; i++) {
        nodeList.push_back(Node(nodeinfo[i][0], nodeinfo[i][1], i + 1));
    }

    sort(nodeList.begin(), nodeList.end());
    Node* root = &nodeList[0];

    for(int i = 1; i < nodeList.size(); i++) {
        connectNode(root, &nodeList[i]);
    }

    preOrder(answer[0], root);
    postOrder(answer[1], root);

    return answer;
}
