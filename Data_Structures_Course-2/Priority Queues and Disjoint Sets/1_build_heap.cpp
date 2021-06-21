#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;
  int n;
  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void down(int i){
      if(i>=n)
        return;
      int c1,c2,cur;
       cur=data_[i];
       c1=2*i+1<n?data_[2*i+1]:-1;
       c2=2*i+2<n?data_[2*i+2]:-1; 
       if((c2!=-1 && c1==min(min(c1,c2),cur)) || (c1!=-1 && c2==-1 && c1==min(c1,cur)))
       {
          swap(data_[2*i+1],data_[i]);
          swaps_.push_back(make_pair(i,2*i+1));
          down(2*i+1);
       } 
       else if(c2!=-1 && c2==min(min(c1,c2),cur))
       {
         swap(data_[2*i+2],data_[i]);
         swaps_.push_back(make_pair(i,2*i+2));
         down(2*i+2);
       }
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    /*
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
      */
     
     for(int i=n/2;i>=0;i--)
     { 
       down(i);
     }

  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
