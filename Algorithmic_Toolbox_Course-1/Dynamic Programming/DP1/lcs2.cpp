#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using std::vector;

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

int mini(int &d1,int &d2, int &d3)
{
   if(d1<=d2 && d1<=d3)
    return d1;
   if(d2<=d1 && d2<=d3)
    return d2;
  return d3;
}

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  vector<vector<int>> done(a.size()+1,vector<int> (b.size()+1,0));
  
  for(int j=0;j<=b.size();j++)
    {
      done[0][j]=j;
    }
  for(int i=0;i<=a.size();i++)
    {
      done[i][0]=i;
    }
  
  
  int d1,d2,d3;
  for(int i=1;i<done.size();i++)
  { 
     for(int j=1;j<done[0].size();j++)
    {
      d1=done[i-1][j]+1;
      d2=done[i][j-1]+1;
      if(a[i-1]==b[j-1])
        d3=done[i-1][j-1];
      else
        d3=numeric_limits<int>::max();
      done[i][j]=mini(d1,d2,d3);
    }
  }
  //display(done);
  int val=0;
  
  
  int temp;
  for(int i=done.size()-1, j=done[0].size()-1; j>0 && i>0;)
  { 
    if((i-1)<0 || (j-1)<0 || a[i-1]!=b[j-1])
      d1=numeric_limits<int>::max();
    else  
      d1=0;
    if((i-1)<0)  
      d2=numeric_limits<int>::max();
    else
      d2=done[i-1][j];
    if((j-1)<0)
      d3=numeric_limits<int>::max();
    else
      d3=done[i][j-1];
    
    temp=mini(d1,d2,d3);
    if(temp==d1)
      {
        val++;
        i=i-1;j=j-1;  
      }
    else if(temp==d2)
      {
        /*if( (i-1)>=0 && (j-1)>=0 && a[i-1]==b[j-1])
          val++;*/
        i=i-1;
      }
    else
      {
        /*if( (j-1)>=0 && (i-1)>=0 && a[i-1]==b[j-1])
          val++;*/
        j=j-1;
      }
  }

  return val;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
