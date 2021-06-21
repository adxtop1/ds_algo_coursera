#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// using std::vector;
// using std::cin;
// using std::cout;

long long mini(long long a, long long b)
{
  if(a<b)
    return a;
  if(a==b)
    return -1;
  return b;
}
class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }
  void down( vector<pair<long long,long long>> &data_,int i )
  {
    if(i>=data_.size())
      return;

    pair<long long,long long> *c1,*c2,*cur;
    int n=data_.size();
       cur=&data_[i];
       c1=2*i+1<n?&data_[2*i+1]:NULL;
       c2=2*i+2<n?&data_[2*i+2]:NULL; 
       if(c1!=NULL && c2!=NULL)
       {
         if(mini(c1->second,c2->second)!=-1)
         {
            if(c1->second==mini(c1->second,c2->second))
            {
              if(c1->second<cur->second || (c1->second==cur->second && c1->first<cur->first))
              {  
                swap(*c1,*cur);
                down(data_,2*i+1);
              }
            }
            else if(c2->second==mini(c1->second,c2->second))
            {
              if(c2->second<cur->second || (c2->second==cur->second && c2->first<cur->first))
              {  
                swap(*c2,*cur);
                down(data_,2*i+2);
              }
            }
         }
         else {
           if(c1->first==mini(c1->first,c2->first))
            {
              if(c1->second<cur->second || (c1->second==cur->second && c1->first<cur->first))
              {  
                swap(*c1,*cur);
                down(data_,2*i+1);
              }
            }
            else if(c2->first==mini(c1->first,c2->first))
            {
              if(c2->second<cur->second || (c2->second==cur->second && c2->first<cur->first))
              {  
                swap(*c2,*cur);
                down(data_,2*i+2);
              }
            }
         }
       }
       else if(c1!=NULL)
       {
          if(c1->second<cur->second || (c1->second==cur->second && c1->first<cur->first))
          {  
            swap(*c1,*cur);
            down(data_,2*i+1);
          
          }

       }
      
  }

  void up( vector<pair<long long,long long>> &data_,int i )
  {
    if(i<=0)
      return;

    pair<long long,long long> *par,*cur;
    int n=data_.size();
       cur=&data_[i];
       par=(i-1)/2>=0?&data_[(i-1)/2]:NULL;
      if(par!=NULL)
       {
          if(par->second>cur->second || (par->second==cur->second && par->first>cur->first))
          {  
            swap(*par,*cur);
            up(data_,(i-1)/2);
          }

       }
     
  }
  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<pair<long long,long long>> heap_(num_workers_);
    for(int i=0;i<heap_.size();i++)
    {
      heap_[i].first=i;
      heap_[i].second=0;
    }
    /*
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
    */
    for(int i=0;i<jobs_.size();i++)
    {
      int duration=jobs_[i];
      assigned_workers_[i]=heap_[0].first;
      start_times_[i]=heap_[0].second;
      heap_[0].second+=duration;
      swap(heap_.back(),heap_[0]);
      pair<long long, long long> last_=heap_.back();
      heap_.pop_back();
      down(heap_,0);
      heap_.push_back(last_);
      up(heap_,heap_.size()-1);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
