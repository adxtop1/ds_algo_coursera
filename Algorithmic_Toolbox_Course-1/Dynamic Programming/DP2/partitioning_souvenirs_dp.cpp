#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int partition3(vector<int> &A,int sum) {
  //write your code here
  int m=sum/3;
  vector<vector<vector<int>>> dp(A.size()+1,vector<vector<int>> (m+1,vector<int>(m+1,0)));
  dp[0][0][0]=1;
  

  for(int i=1;i<dp.size();i++)
    for(int j=0;j<dp[0].size();j++)
      for(int k=0;k<dp[0][0].size();k++)
      {
        
        if(dp[i-1][j][k]==1)
          dp[i][j][k]=1;
        else if((j-A[i-1]) >=0 && dp[i-1][j-A[i-1]][k]==1)
          dp[i][j][k]=1;
        else if((k-A[i-1]) >=0 && dp[i-1][j][k-A[i-1]]==1)
          dp[i][j][k]=1;
        else
          dp[i][j][k]=0;
      }

  return dp[A.size()][m][m];    
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  int sum=0;
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
    sum+=A[i];
  }
  if(sum%3!=0)
    cout<<"0"<<'\n';
  else
  std::cout << partition3(A,sum) << '\n';
}
