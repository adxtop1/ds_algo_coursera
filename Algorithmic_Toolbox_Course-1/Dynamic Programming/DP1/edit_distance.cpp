#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;
using std::string;


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

int edit_distance(const string &str1, const string &str2) {
  vector<vector<int>> done(str1.size()+1,vector<int> (str2.size()+1,0));
  
  for(int j=0;j<=str2.size();j++)
    {
      done[0][j]=j;
    }
  for(int i=0;i<=str1.size();i++)
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
      if(str1[i-1]==str2[j-1])
        d3=done[i-1][j-1];
      else
        d3=done[i-1][j-1]+1;
      done[i][j]=mini(d1,d2,d3);
    }
  }

  int val=done[done.size()-1][done[0].size()-1];
/*  
  int temp;

  for(int i=done.size()-1, j=done[0].size()-1; j>=0 && i>=0;)
  { 
    if((i-1)<0 || (j-1)<0)
      d1=numeric_limits<int>::max();
    else  
      d1=done[i-1][j-1];
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
        if( (i-1)>0 && (j-1)>0 && str1[i-1]!=str2[j-1])
          val++;
        i=i-1;j=j-1;
        
      }
    else if(temp==d2)
      {i=i-1;val++;}
    else
      {j=j-1; val++;}
  }
 */
  display(done);
  return val;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;

}
