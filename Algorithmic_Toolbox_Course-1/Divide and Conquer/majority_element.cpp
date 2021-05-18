#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_majority_element(vector<long int> &a) {
  long int n=a.size();
  sort(a.begin(),a.end());
  long int max=0,count=0;
  for(int i=0;i<n;i++)
  {
    
    if( (i+1)!=n && a[i+1]==a[i])
    {
      count++;
    }
    else
    {
      count=0;
    }
    
    if(count>=max)
    max=count+1;

  }

  if(max>n/2)
  return 1;
  return 0;
}

int main() {
  long int n;
  std::cin >> n;
  vector<long int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a) << '\n';
}
