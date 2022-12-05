#include "btutils.h"

using namespace std;


int main(int argc, char *argv[]) {
  vector<int> inp{2,1,3};
  auto t = createBinTreeFromDFSArray(inp);
  cout << t << endl;
  return 0;
}