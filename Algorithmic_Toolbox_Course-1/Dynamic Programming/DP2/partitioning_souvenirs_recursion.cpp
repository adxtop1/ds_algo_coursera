#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int partition3(vector<int> &A,int a,int b,int c,int i) {
  //write your code here
  if(i==A.size())
    if(a==b && a==c)
      return 1;
    else
      return 0;
  
  int d1,d2,d3;
  
  d1=partition3(A,a+A[i],b,c,i+1);
  if(d1==1)
  return 1;
  d2=partition3(A,a,b+A[i],c,i+1);
  if(d2==1)
  return 1;
  d3=partition3(A,a,b,c+A[i],i+1);
  if(d3==1)
  return 1;

  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A,0,0,0,0) << '\n';
}
