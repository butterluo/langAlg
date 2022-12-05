#include "bits/stdc++.h"
#include "btutils.h"

using namespace std;
//类似'去重'的题目
//解法有[单调栈]


//去重,且要保证原字母顺序,且保证去重后的字典序最小(即大部分都是从a到b到c之类的char从小到大的排序) https://leetcode.cn/problems/remove-duplicate-letters/ https://app.yinxiang.com/shard/s30/nl/5421460/7eec701d-7fbc-4ec4-a3b4-d1f52887a3b1 [单调栈]
string removeDuplicateLetters(string s) {
  vector<int> existInResult(26, 0), numOfNotProcess(26, 0);
  for (char c : s) {
    ++numOfNotProcess[c - 'a'];
  }
  string result;//用一个单调栈的形式去对待,尽量保证字符串中char从小到大的字典序
  for (char c : s) {
    if(!existInResult[c - 'a']) {
      while(!s.empty() && result.back() > c) {
        char stktop = result.back();
        if(numOfNotProcess[ stktop - 'a'] > 0) {
          result.pop_back();
          existInResult[stktop - 'a'] = 0;
        } else {
          break;
        }
      }
      result.push_back(c);
      existInResult[c - 'a'] = 1;
    }
    --numOfNotProcess[c - 'a'];
  }
  return result;
}

void doRemoveDuplicateLetters() {
  vector<string> inLs = {
    "bcabc", "cbacdcbc", "bbcaac"
  };
  for (auto it = inLs.begin(); it != inLs.end(); ++it) {
    string inp = *it;
    cout << inp << " ==> ";
    string outp = removeDuplicateLetters(inp);
    cout << outp << endl;
  }
}



int main(int argc, char *argv[]) {
  doRemoveDuplicateLetters();
  return 0;
}
