#include "btutils.h"

using namespace std;

//242 https://leetcode.cn/problems/valid-anagram/
bool isAnagram(string s, string t) {
  int sSz = s.size();
  int tSz = t.size();
  if (sSz != tSz) {
    return false;
  }
  vector<char> dic(26, 0);
  for (int i = 0; i < sSz; ++i) {
    ++dic[s[i] - 'a'];
  }
  for (int i = 0; i < tSz; ++i) {
    --dic[t[i] - 'a'];
  }
  for(int i = 0; i < 26; ++i) {
    if (dic[i] != 0) {
      return false;
    }
  }
  return true;
}

void tst_isAnagram() {
  vector<vector<string>> vv{
    {"anagram","rat"},
    {"nagaram","car"}
  };
  vector<bool> rVec;
  for (int i = 0; i < vv[0].size(); ++i) {
    bool r = isAnagram(vv[0][i], vv[1][i]);
    rVec.push_back(r);
  }
  printItrRange(begin(rVec), end(rVec));
}

//1 https://leetcode.cn/problems/two-sum/ 
vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> numIdxMp;
  for (int i = 0; i < nums.size(); ++i) {
    numIdxMp.emplace(nums[i], i);
  }
  for (int i = 0; i < nums.size(); ++i) {
    if (numIdxMp.count(target - nums[i])) {
      int idx = numIdxMp[target - nums[i]];
      if (i != idx) {
        return {i, idx};
      }
    }
  }
  return {};
}
//官方只遍历一次，因为前面的数即使不在map中，放进去后，拿着后面的数去找匹配时也能找到,而且有个好处是不用判断下标相同 *** 另外，map.find比count快，c++17还有contain
vector<int> twoSum_2(vector<int>& nums, int target) {
  unordered_map<int, int> numIdxMp;
  for (int i = 0; i < nums.size(); ++i) {
    if (numIdxMp.end() == numIdxMp.find(target - nums[i])) {
      numIdxMp.emplace(nums[i], i);
    } else {
      return {i, numIdxMp[target - nums[i]]};
    }
  }
  return {};
}

//15 https://leetcode.cn/problems/3sum/
struct Vector3Hash {
  size_t operator()(const std::vector<int>& v) const {
    std::hash<int> hasher;
    return hasher(v[0]) + hasher(v[1]) * 10 + hasher(v[2]) * 100;
  }
};
vector<vector<int>> threeSum(vector<int>& nums) {
  int target = 0;
  int sz = nums.size();
  if (sz < 3) {
    return {};
  }
  if (sz == 3 ) {
    if (nums[0] + nums[1] + nums[2] == target) {
      return {nums};
    } else {
      return {};
    }
  }
  
  sort(begin(nums), end(nums));
  unordered_set<vector<int>, Vector3Hash> resSet;
  for (int i = 0; i < sz; ++i) {
    int rem = target - nums[i];
    int left = i + 1;
    int right = sz - 1;
    while (right > left) {
      if (nums[left] + nums[right] > rem) {
        right = right - 1;
      } else if (nums[left] + nums[right] < rem) {
        left = left + 1;
      } else {
        vector<int> r{nums[i], nums[left], nums[right]};
        if (resSet.end() == resSet.find(r))
          resSet.insert(r);
        left = left + 1;
      }
    }
  }
  vector<vector<int>> ret;
  ret.assign(begin(resSet), end(resSet));
  return ret;
}
//参考了官方3Sum和4sum的解法，官方还是做了很多剪枝的, 以下版本就双超90%了，处理4sum也是类似的
vector<vector<int>> threeSum2(vector<int>& nums) {
  int target = 0;
  int sz = nums.size();
  if (sz < 3) {
    return {};
  }
  if (sz == 3 ) {
    if (nums[0] + nums[1] + nums[2] == target) {
      return {nums};
    } else {
      return {};
    }
  }
  //*** 排序的好处是可以让重复的数字排一起便于跳过；而且可以用由小到大和由大到小的双指针去逼近；同时也可以通过判断前后3sum是否比target大或小来判断是否要继续循环查找答案
  sort(begin(nums), end(nums));
  //*** 排序后，如果整体上最小的3sum都比target大而往后取数会更大，证明整体上是没有等于target的3sum了；同理，若最大的3sum都比target小，也可认为没有等于target的3sum了
  if(nums[0] + nums[1] + nums[2] > target || nums[sz - 1] + nums[sz - 2] + nums[sz - 3] < target) {
    return {};
  }
  vector<vector<int>> ret;
  for (int i = 0; i < sz - 2; ++i) {//*** 因为i 与 sz - 2, sz - 1 的求和会在下一层循环做，所以这里循环到sz - 2就可以结束了
    if (i > 0) {
      if (nums[i] + nums[i + 1] + nums[i + 2] > target) {//***排序后，如果该轮循环中可取的最小的3sum都比target大而往后取数会更大，证明该轮和后续循环中都没有等于target的3sum了
        break;
      }
      if(nums[i] == nums[i - 1]) {//*** 由于已排序，相同值会连续排在一起，所以此处可以跳过重复值
        continue;
      }
    }
    if (nums[i] + nums[sz - 1] + nums[sz - 2] < target) {//***同理，若该轮循环中最大的3sum都比target小，可认为该轮没有等于target的3sum了，但后续轮次可能会有，因为随着i的增大，nums[i]会越来越大
      continue;
    }
    
    int rem = target - nums[i];
    int left = i + 1;
    int right = sz - 1;
    while (right > left) {                       //??? 双指针从中间向两步散开貌似缓存更友好?；判断双指针的距离不能大于sz - i还是分别判断两边不能越界好?
      int remSum = nums[left] + nums[right];
      if ( remSum > rem) {
        do {
          right = right - 1;
        } while(nums[right] == nums[right + 1] && right > left);//*** 由于已排序，相同值会连续排在一起，所以此处可以跳过重复值
      } else if (remSum < rem) {
        do {
          left = left + 1;
        } while(nums[left] == nums[left - 1] && right > left);
      } else {
        ret.push_back({nums[i], nums[left], nums[right]});
        do {
          left = left + 1;
        } while(nums[left] == nums[left - 1] && right > left);
      }
    }
  }
  return ret;
}

void tst_threeSum() {
  vector<vector<int>> numsLs = {
    {-1,0,1,2,-1,-4},
    {0,1,1},
    {0,0,0,0},
    {-2,0,1,1,2}
  };
  vector<vector<vector<int>>> res;
  for (vector<int> nums : numsLs) {
    res.push_back(threeSum2(nums));
  }
  for(vector<vector<int>> r : res) {
    cout << "{";
    for (vector<int> e : r) {
      cout << "[";
      for (int i:e) {
        cout << i << ", ";
      }
      cout << "], ";
    }
    cout << "}" << endl;
  }
}

//454  https://leetcode.cn/problems/4sum-ii/
int fourSumCount_1(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {//这个参考4sum官方的旧解法超时了
  int target = 0;
  int n = nums1.size();
  if (!n) {
    return 0;
  }
  if (1 == n) {
    if (nums1[0] + nums2[0] + nums3[0] + nums4[0] == target) {
      return 1;
    }
    return 0;
  }
  sort(begin(nums1), end(nums1));
  sort(begin(nums2), end(nums2));
  sort(begin(nums3), end(nums3));
  // auto p = minmax_element(cbegin(nums4), cend(nums4));  //边初始化map边找min,max
  // int mn4 = *(p.first);
  // int mx4 = *(p.second);
  int mn4 = INT_MAX;
  int mx4 = INT_MIN;
  // unordered_map<int, vector<int>> mp4; //重复值也算
  unordered_map<int, int> mp4; //不用返回具体值和下标，所以val给个值出现的总数就可以
  for (int i = 0; i < n; ++i) {
    int elm = nums4[i];
    if (mp4.end() == mp4.find(elm)) {
      mp4.insert(pair<int, int>(elm, 1));
      if (elm > mx4) {
        mx4 = elm;
      }
      if (elm < mn4) {
        mn4 = elm;
      }
    } else {
      ++mp4[elm];
    }
  }

  int las = n - 1;
  if ((long)nums1[0] + nums2[0] + nums3[0] + mn4 > target || (long)nums1[las] + nums2[las] + nums3[las] + mx4 < target) 
    return 0;
  int resCnt = 0;
  int mn2 = nums2[0];
  int mn3 = nums3[0];
  int mx2 = nums2[las];
  int mx3 = nums3[las];
  for (int x = 0; x < n; ++x) {
    if (x > 0) {
      if (nums1[x] + mn2 + mn3 + mn4 > target) {
        break;
      }
      // if(nums1[x] == nums1[x - 1]) {
      //   continue;
      // }
    }
    if (nums1[x] + mx2 + mx3 + mx4 < target) {
      continue;
    }

    for (int y = 0; y < n; ++y) {
      if (y > 0) {
        if (nums1[x] + nums2[y] + mn3 + mn4 > target) {
          break;
        }
        // if(nums2[y] == nums2[y - 1]) {
        //   continue;
        // }
      }
      if (nums1[x] + nums2[y] + mx3 + mx4 < target) {
        continue;
      }

      for (int z = 0; z < n; ++z) {
        int rem = target - (nums1[x] + nums2[y] + nums3[z]);
        if (mp4.end() != mp4.find(rem)) {
          resCnt = resCnt + mp4[rem];
        }
      }
    }
  }
  return resCnt;
}

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {//速度比99%快
  //int target = 0;
  int n = nums1.size();
  //处理异常场景和可提前返回的场景
  if (!n) {
    return 0;
  }
  if (1 == n) {
    if (!(nums1[0] + nums2[0] + nums3[0] + nums4[0])) {
      return 1;
    }
    return 0;
  }

  if (n < 155) {//此处以155为阈值时，速度超过99%用户，因为该if block适合小数据操作，下面的block用了一些时间做剪枝，适合大数据操作
    //该代码块比官方题解快25%
    unordered_map<int, int> mp4; //不用返回具体值和下标，所以val给个值出现的总数就可以
    for (int j : nums3) {
      for (int i : nums4) {//***用for(:)代替for(idx)貌似更快些,里面做了加速???四个vector循环都改成for(:)会快5%
        ++mp4[j + i];
      }
    }
    int resCnt = 0;
    auto end = mp4.end();
    for (int x : nums1) {
      for (int y : nums2) {
        auto it = mp4.find(- x - y);//find的时候把it直接用于后续取数比下面的(注释块)可快10%
        if (end != it) {//***把mp4.end()拿到循环外会快5%，因减少了循环内的缓存
          resCnt += it->second;
        }
      }
    }
    return resCnt;
  }

  sort(begin(nums1), end(nums1));
  auto mnx2 = minmax_element(cbegin(nums2), cend(nums2));  //边初始化map边找min,max
  int mn2 = *(mnx2.first);
  int mx2 = *(mnx2.second);
  int mn34 = INT_MAX;
  int mx34 = INT_MIN;
  // unordered_map<int, vector<int>> mp4; //重复值也算
  unordered_map<int, int> mp4; //不用返回具体值和下标，所以val给个值出现的总数就可以
  for (int j : nums3) {
    for (int i : nums4) {
      int elm = j + i;
      if ((++mp4[elm]) == 1) {//map[key]时，如果map中无该key会先创建一个有default val的key，对于int的default就是0
        //第一次遇到elm这个key时，判断elm是最大还是最小值
        if (elm > mx34) {
          mx34 = elm;
        }
        if (elm < mn34) {
          mn34 = elm;
        }
      }
    }
  }
  if (((long)nums1[0] + mn2 + mn34) > 0 || (long)nums1[n - 1] + mx2 + mx34 < 0) //如果可取的最小和都比目标和大或可取的最大和都比目标和小，则表示无解，提前返回
    return 0;
  int resCnt = 0;
  int ind1 = 0;
  auto end = mp4.end();
  for (int x : nums1) {
    if (ind1) {//当不是第一次进该循环时(indi=1)才走以下判断
      if ((x + mn2 + mn34) > 0) {//由于已排序，所以x之后的值只会比x大，若这个所有最小值相加的和都比目标和0大，那么x后面的更不可能接近目标和0，所以直接break跳过后续循环
        break;
      }
    } else {
      ind1 = 1;
    }
    if (x + mx2 + mx34 < 0) {//若该次循环能取的最大和都比目标和0小，所以该次循环可跳过，但由于已排序，x之后的值比x大，所以后续循环的x参与的最大和会增大以至可能接近目标和0，所以后续循环不能跳过
      continue;
    }
    for (int y : nums2) {
      auto it = mp4.find(- x - y);//***find的时候把返回的iterator直接用于后续取数比下面的(注释块)快10%
      if (end != it) {
        resCnt += it->second;  //*** += 操作符比下面的加法(注释块)略快5%
      }
      // int rem = - x - y;
      // if (end != mp4.find(rem)) { //这种会多一次操作，上面find的时候把it直接用于取数可快10%
      //   resCnt = resCnt + mp4[rem];
      // }
    }
  }
  return resCnt;
}


int fourSumCount_2(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {//
  int target = 0;
  int n = nums1.size();
  if (!n) {
    return 0;
  }
  if (1 == n) {
    if (nums1[0] + nums2[0] + nums3[0] + nums4[0] == target) {
      return 1;
    }
    return 0;
  }
  unordered_map<int, int> mp4; //不用返回具体值和下标，所以val给个值出现的总数就可以
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      int elm = nums3[j] + nums4[i];
      if (mp4.end() == mp4.find(elm)) {
        mp4.insert(pair<int, int>(elm, 1));
      } else {
        ++mp4[elm];
      }
    }
  }
  int resCnt = 0;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      int rem = target - nums1[x] - nums2[y];
      if (mp4.end() != mp4.find(rem)) {
        resCnt = resCnt + mp4[rem];
      }
    }
  }
  return resCnt;
}


void tst_fourSumCount() {
  vector<vector<vector<int>>> inp{
    { {1,2}, {-2,-1}, {-1,2}, {0,2}  },     //2
    { {0}, {0}, {0}, {0}  },                //1
    { {-1,-1}, {-1,1}, {-1,1}, {1,-1}  },    //6
    { {0,1,-1}, {-1,1,0}, {0,0,1}, {-1,1,1}  }    //17
  };
  vector<int> res;
  for (vector<vector<int>> inin : inp) {
    res.push_back(fourSumCount(inin[0],inin[1],inin[2],inin[3]));
  }
  printItrRange(begin(res), end(res));
}


int main(int argc, char *argv[]) {
  tst_fourSumCount();
  return 0;
}