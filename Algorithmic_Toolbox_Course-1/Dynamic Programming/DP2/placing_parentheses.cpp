#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>

using namespace std;
using std::vector;
using std::string;
using std::max;
using std::min;

#define ll long long

void display(vector<vector<int>> &done)
{
  for(int i=0;i<done.size();i++)
  {  for(int j=0;j<done[0].size();j++)
    {
      cout<<done[i][j]<<" ";
    }
    cout<<endl;
  }
}

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

ll int conv(char k)
{
  return k-'0';
}


long long get_maximum_value(const string &exp) {
  //write your code here
  int n=(exp.size()+1)/2;
  vector<vector<ll int>> M(n,vector<ll int> (n,0)),m(n, vector<ll int>(n,0));
  for(int i=0;i<n;i++)
    {
      M[i][i]=conv(exp[2*i]);
      m[i][i]=conv(exp[2*i]);
    }
  int j=0;
  ll int d1,d2,d3,d4,mx=numeric_limits<int>::min(),mi=numeric_limits<int>::max();
  char op;
  for(int k=1;k<n;k++)  
  { 
    for(int i=0;i<n;i++)
    {
      j=i+k;
      if(j>=n)
        break;
      mx=numeric_limits<int>::min();
      mi=numeric_limits<int>::max();
      for(int l=0;l<k;l++)
      {
        op=exp[2*l+2*i+1];
        d1=eval(m[i][i+l],m[i+l+1][j],op);
        d2=eval(M[i][i+l],M[i+l+1][j],op);
        d3=eval(M[i][i+l],m[i+l+1][j],op);
        d4=eval(m[i][i+l],M[i+l+1][j],op);

        d1=max(max(max(d1,d2),d3),d4);
        d2=min(min(min(d1,d2),d3),d4);
        if(d1>mx)
          mx=d1;
        if(d2<mi)
          mi=d2;
      }
      M[i][j]=mx;
      m[i][j]=mi;
     
    }
  }
  //display(M);
  //cout<<"\n";
  //display(m);

  return M[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
