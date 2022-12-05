#include "bits/stdc++.h"
#include "btutils.h"

using namespace std;

//零钱兑换 https://leetcode.cn/problems/coin-change/ , https://labuladong.github.io/algo/3/25/69/
int coinChange(vector<int>& coins, int amount) {
  if (amount == 0) {
    return 0;
  }
  if (amount < 0) {
    return -1;
  }
  int numPick = INT_MAX;
  for (int coin : coins) {
    int numRet = coinChange(coins, amount - coin);
    if (numRet == -1) {
      continue;
    }
    numPick = min(numPick, 1 + numRet);
  }
  return numPick == INT_MAX ? -1 : numPick;
}

int coinChangeLoop(vector<int>& coins, int amount) {
  int moreAmt = amount + 1;
  int amtStages[moreAmt];
  for (int i = 0; i <= amount; ++i) {
    amtStages[i] = moreAmt;
  }
  amtStages[0] = 0;
  for (int i = 1; i <= amount; ++i) {
    for (int coin : coins) {
      if (i - coin < 0) {
        continue;
      }
      amtStages[i] = min(amtStages[i], 1 + amtStages[i - coin]);
    }
  }
  return amtStages[amount] == moreAmt ? -1 : amtStages[amount];
}

void doCoinChange() {
  unordered_map<int, vector<int>> amtCoinMap {
    {11, {1,2,5}},
    {3, {2}},
    {0, {1}}
  };

  cout << "==== USING RECU ===" << endl;

  for (auto itm : amtCoinMap) {
    int numPick = coinChange(itm.second, itm.first);
    cout << itm.first << ": [" ;
    printItrRange(begin(itm.second),end(itm.second),","); 
    cout << "] =" << numPick << endl;
  }

  cout << "==== USING FOR LOOP ===" << endl;
  for (auto itm : amtCoinMap) {
    int numPick = coinChangeLoop(itm.second, itm.first);
    cout << itm.first << ": [" ;
    printItrRange(begin(itm.second),end(itm.second),","); 
    cout << "] =" << numPick << endl;
  }
}


//300. 最长递增子序列  https://leetcode.cn/problems/longest-increasing-subsequence/  https://labuladong.github.io/algo/3/25/70/ 
int lengthOfLIS(vector<int>& nums) {
  vector<int> res(nums.size(), 1);
  
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          res[i] = max(res[i], 1 + res[j]);
        }
    }
  }

  return *max_element(res.begin(), res.end());
}

void doLengthOfLIS() {
  vector<vector<int>> inLs{
    {10,9,2,5,3,7,101,18},
    {0,1,0,3,2,3},
    {7,7,7,7,7,7,7}
  };
  for (vector<int> in : inLs) {
    int ret = lengthOfLIS(in);
    cout << "[";
    printItrRange(begin(in), end(in), ",");
    cout << "] => " << ret << endl;
  }
}

//354. 俄罗斯套娃信封问题  https://leetcode.cn/problems/russian-doll-envelopes/  https://labuladong.github.io/algo/3/25/70/ 
struct WAsc {
  bool  operator()(vector<int> v1, vector<int> v2) const {
    if (v1[0] == v2[0]) {
      return v1[1] > v2[1];
    }
    return v1[0] < v2[0];
  }
};
int maxEnvelopes(vector<vector<int>>& envelopes) {
  sort(envelopes.begin(), envelopes.end(), WAsc());
  vector<int> hLs(envelopes.size());
  for (int i = 0; i < envelopes.size(); ++i) {
    hLs[i] = envelopes[i][1];
  }
  return lengthOfLIS(hLs);
}

void doMaxEnvelopes() {
  vector<vector<vector<int>>> inLs{
    {{5,4},{6,4},{6,7},{2,3}},
    {{1,1},{1,1},{1,1}}
  };
  for (vector<vector<int>> in : inLs) {
    int r = maxEnvelopes(in);
    for (auto it = in.begin(); it != in.end(); ++it) {
      cout << " [" << (*it)[0] << ", " << (*it)[1] << "] " ;
    }
    cout << " => " << r << endl;  
  }
}

int main(int argc, char *argv[]) {
  // doCoinChange();
  // doLengthOfLIS();
  doMaxEnvelopes();
  return 0;
}