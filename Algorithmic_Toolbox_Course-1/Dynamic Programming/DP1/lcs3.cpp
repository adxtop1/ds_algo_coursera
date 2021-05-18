#include <iostream>
#include <vector>

using namespace std;
using std::vector;


int maxx(int &d1,int &d2, int &d3)
{
   if(d1>=d2 && d1>=d3)
    return d1;
   if(d2>=d1 && d2>=d3)
    return d2;
  return d3;
}


int lcs3(vector<int> &a, vector<int> &b, vector<int> &c, int an,int bn, int cn) {
  //write your code here
  vector<vector<vector<int>>> done(an+1,vector<vector<int>>(bn+1,vector<int> (cn+1,0)));
  /*if(a[an]==b[bn] && a[an]==c[cn])
    return lcs3(a,b,c,an-1,bn-1,cn-1)+1;

  if(an==0 || bn==0 || cn==0)
    return 0;

    int d1,d2,d3;
    d1=lcs3(a,b,c,an-1,bn,cn);
    d2=lcs3(a,b,c,an,bn-2,cn);
    d3=lcs3(a,b,c,an,bn,cn-1);
  
  return maxx(d1,d2,d3);*/
 
  int d1,d2,d3;
  for(int i=1;i<done.size();i++)
    for(int j=1;j<done[0].size();j++)
      for(int k=1;k<done[0][0].size();k++)
      {
        if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
          done[i][j][k]=done[i-1][j-1][k-1]+1;
        else
          {
            d1=done[i-1][j][k];
            d2=done[i][j-1][k];
            d3=done[i][j][k-1];
            done[i][j][k]=maxx(d1,d2,d3);
          }
      }
  return done[done.size()-1][done[0].size()-1][done[0][0].size()-1];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c,an,bn,cn) << std::endl;
}
