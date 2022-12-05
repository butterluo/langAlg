#include "bits/stdc++.h"


using namespace std;

template <typename Itr>
void printItrRange(Itr begin, Itr end, string sep = " ") {
  for (auto it = begin; it != end; ++it) {
    cout << *it << " " << sep ;
  }
  cout << endl;
}


template<typename T>
struct _ListNode {
  T val;
  _ListNode *next;
  _ListNode() : val(0), next(nullptr) {}
  _ListNode(T x) : val(x), next(nullptr) {}
  _ListNode(T x, _ListNode *next) : val(x), next(next) {}
};

template<typename T>
_ListNode<T>* stlList2LCList(list<T> stlLst) {
  _ListNode<T> tmpHead;
  _ListNode<T>* tmp = &tmpHead;
  for (auto itr = begin(stlLst); itr != end(stlLst); ++itr) {
    tmp->next = new _ListNode<T>(*itr);
    tmp = tmp->next;
  }
  return tmpHead.next;
}

template<typename T>
_ListNode<T>* cycleLCList(_ListNode<T>* head, int cycPos = -1) {
  if (cycPos < 0) {
    return nullptr;
  }
  _ListNode<T>* cycNode = (cycPos == 0 ? head : nullptr);
  _ListNode<T>* tmp = head;
  int idx = 1;
  while(tmp->next != nullptr) {
    tmp = tmp->next;
    if (idx == cycPos) {
      cycNode = tmp;
    }
    ++idx;
  }
  tmp->next = cycNode;
  return cycNode;
}

template<typename T>
void printLCList(_ListNode<T>* head, string sep = " ") {
  cout << head->val << sep;
  _ListNode<T>* tmp = head->next;
  while(tmp != nullptr) {
    cout << tmp->val << sep;
    tmp = tmp->next; 
  }
  cout << endl;
}

template<typename T>
void printCycLCList(_ListNode<T>* head, string sep = " ", _ListNode<T>* cycNode = nullptr) {
  if (nullptr == cycNode) {
    cout << "no cyc node" << endl;
    return;
  }
  int meetCyc = 0;
  if (head == cycNode) {
    cout << "[" << head->val << "]" << meetCyc << "]" << sep;
    ++meetCyc;
  } else {
    cout << head->val << sep;
  }
  _ListNode<T>* tmp = head->next;
  while(tmp != nullptr && meetCyc < 3) {
    if (tmp == cycNode) {
      cout  << "[" << tmp->val << "]" << meetCyc << "]" << sep;
      ++meetCyc;
    } else {
      cout << tmp->val << sep;
    }
    tmp = tmp->next; 
  }
  cout << endl;
}
template<typename T>
struct _TreeNode {
    T val;
    _TreeNode *left;
    _TreeNode *right;
    _TreeNode() : val(0), left(nullptr), right(nullptr) {}
    _TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    _TreeNode(T x, _TreeNode *left, _TreeNode *right) : val(x), left(left), right(right) {}
};


_TreeNode<int>* _createBinTreeFromDFSArray(vector<int>& inp, int idx) {
  if (idx <= inp.size()) {
    int val = inp[idx - 1];
    if (val != NULL) {
      _TreeNode<int>* r = new _TreeNode<int>(val);
      r->left = _createBinTreeFromDFSArray(inp, idx * 2);
      r->right = _createBinTreeFromDFSArray(inp, idx * 2 + 1);
      return r;
    }
  }
  return nullptr;
}

_TreeNode<int>* createBinTreeFromDFSArray(vector<int>& inp) {
  return _createBinTreeFromDFSArray(inp, 1);
}
