#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int len = height.size();
        int res = 0;

        stack<int> height_stack;

        for (int i = 0; i < len; i++) {
            while (!height_stack.empty() && height[i] > height[height_stack.top()]) {
                int top = height_stack.top();
                height_stack.pop();

                if (height_stack.empty()) {
                    break;
                }

                int distance = i - height_stack.top() - 1;
                int h = min(height[i], height[height_stack.top()]) - height[top];
                res += (distance * h);
            }

            height_stack.push(i);
        }

        return res;
    }
};

