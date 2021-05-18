#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;


/*vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}*/
int mini(int &d1,int &d2, int &d3)
{
   if(d1<=d2 && d1<=d3)
    return d1;
   if(d2<=d1 && d2<=d3)
    return d2;
  return d3;
}

void display(vector<int> &done,int n)
{
  vector<int> sequence1;
  sequence1.push_back(n);
  for(;done[n]!=1 && n>0;)
 { 
   if(n%2==0 && n%3!=0)
    {
      if(done[n/2]<=done[n-1])
      {sequence1.push_back(n/2); n=n/2;}
      else
      {sequence1.push_back(n-1); n=n-1;}
    }
  else if(n%3==0 && n%2!=0)
    {
      if(done[n/3]<=done[n-1])
      {sequence1.push_back(n/3); n=n/3;}
    else
      {sequence1.push_back(n-1); n=n-1;}
    }
  else if (n%6==0)
    {
      if(done[n/3]<=done[n/2] && done[n/3]<=done[n-1])
      {sequence1.push_back(n/3); n=n/3;}
    else if(done[n/2]<=done[n/3] && done[n/2]<=done[n-1])
      {sequence1.push_back(n/2); n=n/2;}
    else
      {sequence1.push_back(n-1); n=n-1;}
    }
  else
    {
      sequence1.push_back(n-1); n=n-1;
    }
    
    }

    sequence1.push_back(1);
    
    for (int i = sequence1.size()-1; i>=0 ; i--) {
      std::cout << sequence1[i] << " ";
 }

}
int optimal_sequence(int n, vector<int> &done){
  
  if (done[n]!=0)
    return done[n];
  
  if(n<0)
    return numeric_limits<int>::max();
  
  int d1,d2,d3;
  
  if (n%3==0)
    d3=optimal_sequence(n/3,done)+1;
  else
    d3=numeric_limits<int>::max();
  if(n%2==0)
    d2=optimal_sequence(n/2,done)+1;
  else
    d2=numeric_limits<int>::max();
  d1=optimal_sequence(n-1,done)+1;
  
  done[n]=mini(d1,d2,d3);
  /*if(done[n]==d1)
    sequence.push_back(n-1);
  else if (done[n]==d2)
    sequence.push_back(n/2);
  else
    sequence.push_back(n/3);*/
  
  return done[n];

}

int main() {
  int n;
  std::cin >> n;
  vector<int> done(n+1,0);
  int val;
  done[0]=0;
  done[1]=0;
  done[2]=1;
  done[3]=1;
  if(n==1)
    {cout<<"0"<<endl<<"1";
    return 0;}
  val = optimal_sequence(n,done);

  std::cout << val << std::endl;
  /*for(int i=0;i<done.size();i++)
    cout<<done[i]<<" ";*/
  display(done, n);
  /*for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }*/
return 1;
}
