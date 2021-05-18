#include <iostream>
#include <vector>
#include <limits>


using namespace std;
using std::vector;

/*void display(vector<vector<int>> &done)
{
  for(int i=0;i<done.size();i++)
  {  for(int j=0;j<done[0].size();j++)
    {
      cout<<done[i][j]<<" ";
    }
    cout<<endl;
  }
}*/
int optimal_weight(int tot, const vector<int> &w) {
  //write your code here
  vector<vector<int>> done(w.size()+1,vector<int>(tot+1,0));

 
  int d1,d2;


  for(int i=1;i<done.size();i++)
    for(int j=1;j<done[0].size();j++)
    {
      d1=done[i-1][j];
      if((j-w[i-1])>=0)
        d2=done[i-1][j-w[i-1]]+w[i-1];
      else
        d2=0;
      done[i][j]=max(d1,d2);
    }
   //display(done);
  return done[w.size()][tot];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  
  std::cout << optimal_weight(W, w) << '\n';
}
