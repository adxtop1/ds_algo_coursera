#include <iostream>
#include <vector>

using namespace std;
using std::vector;

/*long long get_number_of_inversions(vector<int> &a, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, left, ave);
  number_of_inversions += get_number_of_inversions(a, ave, right);
  //write your code here
  
  return number_of_inversions;
}*/

long long inversions(vector<int>&a,size_t l,size_t r)
{
  long long noi=0;
  if(r<=l)
    return noi;
  size_t center=l+(r-l)/2;
  noi += inversions(a,l,center);
  noi += inversions(a,center+1,r);
  size_t k=center+1;
  size_t i=l;
  vector<int> temp;
  for(k,i; k<=r && i<=center;)
  {
    if(a[i]<=a[k])
    {
      temp.push_back(a[i]);
      i++;
    }
    else
    {
      noi+=(center-i)+1;
      temp.push_back(a[k]);
      k++;
    }

  }

  if(k>r)
  {
    for(i;i<=center;i++)
      temp.push_back(a[i]);
  }
  else if(i>center)
  {
    for(k;k<=r;k++)
      temp.push_back(a[k]);
  }

  for(size_t m=l,n=0;m<=r;m++,n++)
  {
    a[m]=temp[n];
  }

  return noi;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  std::cout << inversions(a, 0, a.size()-1) << '\n';

 /* for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";*/
}
