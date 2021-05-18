#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
using std::vector;
using std::swap;

/* int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
} */

 pair<int,int> partition3(vector< int> &a,  int l,  int r) {
  int x = a[l];
  int j = l;
  pair<int,int> m;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  m.first=j;
  for (int i = j+1; i <= r; i++) {
    if (a[i] == x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  m.second=j;
  return m;
}

void randomized_quick_sort(vector<int> &a,int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pair<int,int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
