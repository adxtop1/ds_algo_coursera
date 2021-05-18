#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

using namespace std;
using std::vector;
using std::string;
using std::pair;
using std::min;

double mini(double d1,double d2)
{
  if(d1>d2)
  return d2;
  return d1;
}

bool sec(const pair<int,int> &a, const pair<int,int> &b)
{
  return (a.second<b.second);
}

double distance(pair<int,int> a,pair<int,int> b)
{
  double x,y;
  x=a.first-b.first;
  y=a.second-b.second;
  return sqrt(pow(x,2)+pow(y,2));
}

double minimal_distance(vector<pair<int,int>> &points,int l, int r) {
  //write your code here
  int m;
  m=l+(r-l)/2;
  if(r<=l)
    return std::numeric_limits<double>::infinity();
  
  double d1,d2,d_temp;

  d1=minimal_distance(points,l,m);
  d2=minimal_distance(points,m+1,r);
  d_temp=mini(d1,d2);
  
  int p1=m,p2=m;
  for(int i=m;i<=r;i++)
  {
    if((points[m].first+d_temp)>points[i].first)
      p2=i;
    else
      break;
  }
  for(int i=m;i>=l;i--)
  {
    if((points[m].first-d_temp)<points[i].first)
      p1=i;
    else
      break;
  }

  sort(points.begin()+p1,points.begin()+p2,sec);

  double d=std::numeric_limits<double>::infinity();
  double temp;
  for(int i=p1;i<=p2;i++)
  {
    for(int j=i+1;j<=p2 && j<=i+7;j++)
     {
      temp=distance(points[i],points[j]);
      if(temp<d)
        d=temp;
     }
  }
   

  return mini(d_temp, d);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<pair<int,int>> points(n);
  //vector<int> x(n);
 // vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> points[i].first>>points[i].second;
  }
  std::cout << std::fixed;
  sort(points.begin(),points.end());
  std::cout << std::setprecision(9) << minimal_distance(points,0,n-1) << "\n";
}
