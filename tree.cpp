#include "btutils.h"

using namespace std;

namespace int_tre{
  using TreeNode = _TreeNode<int>;

  struct NotBSTException : public exception {
    const char * what () const throw () {
      return "NotBST";
    }
  } notBstException;

  optional<pair<int, int>> findMinMax(TreeNode* root) {
    if (nullptr == root) {
      return nullopt;
    }
    auto rp = findMinMax(root->right);
    auto lp = findMinMax(root->left);
    if (nullopt == rp && nullopt == lp) {
      return optional<pair<int, int>>{in_place, root->val, root->val} ;
    }
    int mn = root->val;
    int mx = root->val;
    if (nullopt != lp) { 
      if (lp->second >= root->val) {
        throw notBstException;
      } else {
        mn = lp->first < mn ? lp->first : mn;
        mx = lp->second > mx ? lp->second : mx;
      }
    }
    if (nullopt != rp) { 
      if (rp->first <= root->val) {
        throw notBstException;
      } else {
        mn = rp->first < mn ? rp->first : mn;
        mx = rp->second > mx ? rp->second : mx;
      }
    }
    return optional<pair<int, int>>{in_place, mn,mx};
  }

  bool isValidBST(TreeNode* root) {
    try {
      auto rih = findMinMax(root->right);
      auto lft = findMinMax(root->left);
      return (nullopt == rih || (rih->first > root->val)) && (nullopt == lft || (lft->second < root->val));
    } catch (NotBSTException e) {
      return false;
    }
    return false;
  }

  bool helper(TreeNode* root, long long lower, long long upper) {
    if (root == nullptr) {
      return true;
    }
    if (root -> val <= lower || root -> val >= upper) {
      throw notBstException;
    }
    return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
  }

  bool isValidBST_1(TreeNode* root) {//官方题解1，用了异常能在发现不是BST时及时中断，但貌似这样不大好，虽然速度超99%
    try {
      return helper(root, LONG_MIN, LONG_MAX);
    } catch (NotBSTException e) {
      return false;
    }
    return false;
  }

  void tst_isValidBST() {
    // vector<int> inp{2,1,3};    //1
    // vector<int> inp{5,1,4,NULL,NULL,3,6};    //0
    vector<int> inp{32,26,47,19,NULL,NULL,56,NULL,27};  //0
    // vector<int> inp{5,14,NULL,1};   //0
    // vector<int> inp{120,70,140,50,100,130,160,20,55,75,110,119,135,150,200};    //0
    // vector<int> inp{24,-60,NULL,-60,-6};       //0
    auto t = createBinTreeFromDFSArray(inp);
    bool b = isValidBST(t);
    cout << b << endl;
  }

  //235 https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
  //236 https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
  // static const TreeNode* notFoundNod = new TreeNode(INT_MIN);
  static TreeNode* found = nullptr;
  TreeNode* postOrder(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (nullptr == root) {
      return root;
    }
    TreeNode* l = postOrder(root->left, p, q);
    TreeNode* r = postOrder(root->right, p, q);
    int lV = l ? l->val : root->val;
    int rV = r ? r->val : root->val;
    int pV = p->val;
    int qV = q->val;
    int rootV = root->val;
    if ((lV == qV && rV ==pV) || 
        ( lV == pV && rV ==qV) ||
        (rootV == pV || rootV == qV) ) {
      found = root;
      return root;
    }
    if (lV == pV || lV == qV) {
      return l;
    }
    if (rV == pV || rV == qV) {
      return r;
    }
    return nullptr;
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return postOrder(root, p, q);
  }

  void tst_lowestCommonAncestor() {
    // vector<int> inp{6,2,8,0,4,7,9,NULL,NULL,3,5}; TreeNode* p = new TreeNode(2); TreeNode* q = new TreeNode(8);  //6
    // vector<int> inp{6,2,8,0,4,7,9,NULL,NULL,3,5}; TreeNode* p = new TreeNode(2); TreeNode* q = new TreeNode(4);  //2
    // vector<int> inp{2,1}; TreeNode* p = new TreeNode(2); TreeNode* q = new TreeNode(1);  //2
    // vector<int> inp{3,5,1,6,2,0,8,NULL,NULL,7,4}; TreeNode* p = new TreeNode(5); TreeNode* q = new TreeNode(1);  //3
    // vector<int> inp{3,5,1,6,2,0,8,NULL,NULL,7,4}; TreeNode* p = new TreeNode(5); TreeNode* q = new TreeNode(4);  //5
    vector<int> inp{-1,10,3,-2,4,NULL,NULL,8}; TreeNode* p = new TreeNode(8); TreeNode* q = new TreeNode(4);  //0
    auto t = createBinTreeFromDFSArray(inp);
    TreeNode* b = lowestCommonAncestor(t, p, q);
    cout << (found ? to_string(found->val) : "NULL") << endl;
  }
}


int main(int argc, char *argv[]) {
  int_tre::tst_lowestCommonAncestor();
  return 0;
}
//platform select remote-android ; platform connect connect://172.24.48.1:9090 ; 172.24.52.20 ; 172.27.64.1 ; platform connect connect://localhost:9090
///home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/python3/lib/libpython3.9.so.1.0
//export LD_LIBRARY_PATH=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/python3/lib/:$LD_LIBRARY_PATH
/*
httpd = make_server('', 9090, demo_app)
print "Serving HTTP on port 9090..."
httpd.serve_forever()
httpd.handle_request()


*/