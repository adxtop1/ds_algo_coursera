#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int mini(int d1,int d2, int d3)
{
   if(d1<=d2 && d1<=d3)
    return d1;
   if(d2<=d1 && d2<=d3)
    return d2;
  return d3;
}


int get_change(int m, vector<int> &done) {
  //write your code here 1,3,4
  if(m==1 || m==3 || m==4)
    return 1;
  if(m<0)
    return numeric_limits<int>::max();
  
  if(m==0)
    return 0;

  if(done[m]!=0)
    return done[m];
  
  int d1,d2,d3;
  
  
  d1=get_change(m-1,done)+1;
  if ((m-3)<0)
    d2=numeric_limits<int>::max();
  else
    d2=get_change(m-3,done)+1;
  if ((m-4)<0)
    d3=numeric_limits<int>::max();
  else
    d3=get_change(m-4,done)+1;

  done[m]=mini(d1,d2,d3);
  return done[m] ;
  
}

int main() {
  int m;
  std::cin >> m;
  vector<int> done(m+1,0);
  std::cout << get_change(m,done) << '\n';
}
