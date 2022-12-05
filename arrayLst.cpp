#include "btutils.h"

using namespace std;


namespace int_node{

  using ListNode = _ListNode<int>;

  //#206 https://leetcode.cn/problems/reverse-linked-list/
  ListNode* reverseList(ListNode* head) {
    if (nullptr == head || nullptr == head->next) {
      return head;
    }
    if (nullptr == head->next->next) {
      head->next->next = head;
      head = head->next;
      head->next->next = nullptr;
      return head;
    } else {
      ListNode* next;
      ListNode* pre = nullptr;
      while (nullptr != head) {
        next = head->next;
        head->next=pre;
        pre = head;
        head = next;
      }
      return pre;
    }
  }

  void tst_reverseList() {
    list<int> a{1,2};
    auto h = stlList2LCList(a);
    printLCList(h);
    cout << "----call----" << endl;
    auto r = reverseList(h);
    printLCList(r);
  }

  //#141 https://leetcode.cn/problems/linked-list-cycle/
  bool hasCycle(ListNode* head) {
    if (nullptr == head || nullptr == head->next) {
      return false;
    }
    ListNode* fast = head->next;
    ListNode* slow = head;
    while (nullptr != fast && nullptr != fast->next) {
      if (slow == fast) {
        return true;
      }
      fast = fast->next->next;
      slow = slow->next;
    }
    return false;
  }
  void tst_hasCycle() {
    list<int> a{3,2};
    auto h = stlList2LCList(a);
    auto c = cycleLCList(h, -1);
    printCycLCList(h, "__", c);
    bool isC = hasCycle(h);
    cout << isC << endl;
  }

  //#24 https://leetcode.cn/problems/swap-nodes-in-pairs/
  ListNode* swapPairs(ListNode* head) {
    if (nullptr == head || nullptr == head->next) {
      return head;
    }
    ListNode* two = head->next->next;
    ListNode* one = head->next;
    head->next = two;
    one->next = head;
    head = one;
    one = head->next;
    while(nullptr != two && nullptr != two->next) {
      one->next = two->next;
      two->next = two->next->next;
      one->next->next = two;
      one = one->next->next;
      two = one->next;
    }
    return head;
  }

  void tst_swapPairs() {
    list<int> a{1};
    auto h = stlList2LCList(a);
    printLCList(h);
    cout << "----call----" << endl;
    auto r = swapPairs(h);
    printLCList(r);
  }
}


int main(int argc, char *argv[]) {
  // int_node::tst_reverseList();
  int_node::tst_swapPairs();
  return 0;
}