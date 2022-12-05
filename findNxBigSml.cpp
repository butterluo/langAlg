#include "btutils.h"

using namespace std;
//类似'查找下一个最大(/最小)元素'的题目
//解法有[单调栈]

//环形数组找下一个最大:https://leetcode.cn/problems/next-greater-element-ii/, https://labuladong.github.io/algo/2/23/63/ [单调栈]
vector<int> nextGreaterElements(vector<int>& nums) {
  int sz = nums.size();
  vector<int> ret(sz);
  stack<int> stkB2s;
  for (int i = 2 * sz - 1; i >= 0; --i) {
    while (!stkB2s.empty() && stkB2s.top() <= nums[i % sz]) {
      stkB2s.pop();
    }
    ret[i % sz] = stkB2s.empty() ? -1 : stkB2s.top();
    stkB2s.push(nums[i % sz]);
  }
  return ret;
}

void doNextGreaterElements() {
  vector<vector<int>> inLs = {
    {1,2,1}, {1,2,3,4,3}, {1,2,2,2,4,3}
  };
  for (auto it = inLs.begin(); it != inLs.end(); ++it) {
    vector<int> inp = *it;
    printItrRange(inp.begin(), inp.end());
    cout << " ===>  ";
    vector<int> outp = nextGreaterElements(inp);
    printItrRange(outp.begin(), outp.end(), ",");
    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  doNextGreaterElements();
  return 0;
}