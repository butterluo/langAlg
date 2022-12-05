#include "btutils.h"

using namespace std;


//#20 https://leetcode.cn/problems/valid-parentheses/
bool isValidParentheses(string s) {
  if (s.size() < 2) {
    return false;
  }
  char stk4lft[s.size()];
  int stkCnt = 0;
  for (auto itr = begin(s); itr != end(s); ++itr) {
    char elm = *itr;
    if (elm == '[' || elm == '(' || elm == '{') {
      stk4lft[stkCnt] = elm;
      ++stkCnt;
    } else {
      if (stkCnt <= 0) {
        return false;
      }
      if ((elm == ']' && stk4lft[stkCnt - 1] == '[') || 
          (elm == '}' && stk4lft[stkCnt - 1] == '{') || 
          (elm == ')' && stk4lft[stkCnt - 1] == '(')) {
        --stkCnt;
      } else {
        return false;
      }
    }
  }
  return stkCnt == 0 ? true : false;
}

void tst_isValidParentheses() {
  string s("[");
  cout << isValidParentheses(s) << endl;
}

//232 https://leetcode.cn/problems/implement-queue-using-stacks/
class MyQueue {
  public:
    MyQueue() {
    }
    
    void push(int x) {
      this->_stk.push(x);
    }
    
    int pop() {
      int x = this->peek();
      this->_stk_out.pop();
      return x;
    }
    
    int peek() {
      if (_stk_out.empty()) {
        this->fillStkOut();
      }
      return _stk_out.top();
    }
    
    bool empty() {
      return _stk.empty() && _stk_out.empty();
    }

  private:
    stack<int> _stk;
    stack<int> _stk_out;

    void fillStkOut() {
      while (!_stk.empty()) {
        _stk_out.push(_stk.top());
        _stk.pop();
      }
    }
};


//225 https://leetcode.cn/problems/implement-stack-using-queues/
class MyStack {
  public:
    MyStack() {
    }
    
    void push(int x) {
      int oldSz = _q.size();
      _q.push(x);
      for (int i = 0; i < oldSz; ++i) {
        int old = _q.front();
        _q.pop();
        _q.push(old);
      }
    }
    
    int pop() {
      int x = this->top();
      _q.pop();
      return x;
    }
    
    int top() {
      return _q.front();
    }
    
    bool empty() {
      return _q.empty();
    }
  private:
    queue<int> _q;
};

//703 https://leetcode.cn/problems/kth-largest-element-in-a-stream/
class KthLargest {
public:
  KthLargest(int k, vector<int>& nums) : _k(k) {
    int sz = nums.size();
    if (sz == 0) {
      return;
    }
    for (int i = 0; i < sz; ++i) {
      _pq.push(nums[i]);
    }

    if (sz > k) {
      int rmNum = sz - k;
      for (int i = 0; i < rmNum; ++i) {
        _pq.pop();
      }
      assert(_pq.size() == k);
    }
    assert(_k == k);
  }
  
  int add(int val) {
    if (_pq.size() < _k) {
      _pq.push(val);
      return _pq.top();
    } else if (val < _pq.top()) {
      return _pq.top();
    } else {
      _pq.push(val);
      _pq.pop();
      return _pq.top();
    }
  }
  
private:
  priority_queue<int, vector<int>, greater<int>> _pq;
  int _k;
};

//239 https://leetcode.cn/problems/sliding-window-maximum/
//官方第一个题解，注意是可以把下标与值一起作为priority_queue的元素类型的
struct pairFstLs : public less<pair<int,int>> {
  bool operator()(const pair<int,int>& __x, const pair<int,int>& __y) const { return __x.first < __y.first; }
};
vector<int> maxSlidingWindow(vector<int>& nums, int k) {//priority_queue
  int sz = nums.size();
  if (sz < 2) {
    return nums;
  }
  if (sz <= k) {
    return {*max_element(begin(nums), end(nums))};
  }
  priority_queue<pair<int,int>, vector<pair<int,int>>, pairFstLs > pq;
  for (int i = 0; i < k; ++i) {
    pq.emplace(nums[i], i);
  }
  vector<int> maxes{pq.top().first};
  for (int i = k; i < sz; ++i) {
    pq.emplace(nums[i],i);
    auto p = pq.top();
    while (p.second <= i - k) {
      pq.pop();
      p = pq.top();
    }
    maxes.push_back(p.first);
  }
  return maxes;
}

//max_element比priority_queue还慢，因内部实现就是个循环，而pq是维护了一个heap
vector<int> maxSlidingWindow_2(vector<int>& nums, int k) {
  int sz = nums.size();
  if (sz < 2) {
    return nums;
  }
  if (sz <= k) {
    return {*max_element(begin(nums), end(nums))};
  }
  vector<int> maxes(sz - k + 1);
  auto beginItr = begin(nums);
  auto endItr = end(nums);
  auto kItr  = next(beginItr,k);
  auto maxItr = max_element(beginItr, kItr);
  int mxVal = *maxItr;
  int i = 0;
  maxes[0] = mxVal;
  for (auto it = kItr; it != endItr; ++it) {
    if (*it >= mxVal) {
      mxVal = *it;
      maxItr = it;
    } else if (distance(maxItr,it) >= k) {
      maxItr = max_element(next(maxItr), next(it));
      mxVal = *maxItr;
    }
    ++i;
    maxes[i] = mxVal;
  }
  return maxes;
}
//官方第二个解法,有点像labuladong的排队高子把矮子给挡了,不算太懂,主要是两个数之间的idx会不会超过k
vector<int> maxSlidingWindow_3(vector<int>& nums, int k) {
  int sz = nums.size();
  if (sz < 2) {
    return nums;
  }
  if (sz <= k) {
    return {*max_element(begin(nums), end(nums))};
  }
  vector<int> maxes;
  maxes.reserve(sz - k + 1);
  deque<int> dq(k);
  for (int i = 0; i < k; ++i) {
    while (!dq.empty() && nums[i] >= nums[dq.back()]) {
      dq.pop_back();
    }
    dq.emplace_back(i);
  }
  maxes.emplace_back(nums[dq.front()]);
  for (int i = k; i < sz; ++i) {
    while (!dq.empty() && nums[i] >= nums[dq.back()]) {
      dq.pop_back();
    }
    dq.push_back(i);
    while (!dq.empty() && dq.front() <= i - k) {
      dq.pop_front();
    }
    maxes.push_back(nums[dq.front()]);
  }
  return maxes;
}
//官方第三个解法没看懂啊???TODO


void tst_maxSlidingWindow() {
  vector<int> v{1,3,-1,-3,5,3,6,7};
  printItrRange(begin(v), end(v));
  cout << "====call==="<<endl;
  vector<int> r = maxSlidingWindow_3(v, 3);
  printItrRange(begin(r), end(r));
}


int main(int argc, char *argv[]) {
  tst_maxSlidingWindow();
  return 0;
}