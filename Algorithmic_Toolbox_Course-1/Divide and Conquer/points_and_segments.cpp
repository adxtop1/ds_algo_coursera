#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
using std::vector;

bool sec(const pair<int,int> &a,const pair<int,int> &b)
{
  if(a.first==b.first)
    return (a.second<b.second);
  return (a.first<b.first);
}


vector<pair<int,int>> fast_count_segments(vector<pair<int,int>> &data) {
  vector<pair<int,int>> cnt;
  //write your code here
  sort(data.begin(),data.end(),sec);
  int count=0;
  for(int i=0;i<data.size();i++)
  {
    if(data[i].second==1)
      count++;
    else if(data[i].second==2)
      count--;
    else if(i>0 && data[i].first==data[i-1].first)
     {
       int k=0,l=0;
       for(int j=i-1; j>=0 && data[j].first==data[i].first;j--)
       {
         if(data[j].second==2 || data[j].second==1) 
          k++;
         if(data[j].second==1)
          l++;
       }
       cnt.push_back(make_pair(data[i].second,count+k-l));
     }
    else
      cnt.push_back(make_pair(data[i].second,count));
    //cout<<data[i].first<<" ";
  }


  sort(cnt.begin(),cnt.end());
  return cnt;
}

/*vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}*/

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<pair<int,int>>data(2*n+m);
  
  for (size_t i = 0; i < 2*n; i=i+2) {
    cin>>data[i].first;
    cin>>data[i+1].first;
    data[i].second=1;
    data[i+1].second=2;
  }
  
  for (size_t i = 2*n; i < 2*n+m; i++) {
    cin>>data[i].first;
    data[i].second=i+3;
    
  }
  //use fast_count_segments
  //vector<int> cnt = naive_count_segments(starts, ends, points);
  vector<pair<int,int>> cnt = fast_count_segments(data);

  for (size_t i = 0; i < cnt.size(); i++) {
    cout<<cnt[i].second<<' ';
  }
}

/* Good trial cases-
Input 
4 6 0 5 -3 2 7 10 10 10 1 6 -3 2 10 10
Output
2 1 0 2 2 2 

*/