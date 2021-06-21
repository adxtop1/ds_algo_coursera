#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
using namespace std;
using std::vector;
using std::ios_base;
using std::cin;
using std::cout;


class TreeOrders {
  
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  int n;
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

void inorder(int i, vector<int> &r)
{
  if(i==-1)
    return;
    inorder(left[i],r);
    r.push_back(key[i]);
    inorder(right[i],r);
}

  vector <int> in_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    inorder(0,result);
    return result;
  }

};

void check(vector <int> a) {
  bool flag=true;
  for (int i = 1; i < a.size()-1; i++) {
    if(a[i+1]<a[i] || a[i-1]>a[i])
     { 
       flag=false;
       break;
     }
  }
  if(flag)
    cout<<"CORRECT";
  else
    cout<<"INCORRECT";
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  if(t.n!=0)
    check(t.in_order());
  else
    cout<<"CORRECT";
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

