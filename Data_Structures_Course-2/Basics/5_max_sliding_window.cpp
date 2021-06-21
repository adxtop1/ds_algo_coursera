#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


void max_sliding_window_naive(vector<int> const & A, int w) {
    queue <int> m1;
    vector <int> maxx;
    //initializing
    for(int i=0;i<w;i++)
        {
            m1.push(A[i]);
            if(maxx.size()==0)
                maxx.push_back(A[i]);
            else
            {
                while(maxx.size()>0  && maxx.back()<A[i])
                    maxx.pop_back();
                maxx.push_back(A[i]);
            }
        }
    //window shifting

    cout<<maxx[0]<<" ";
    if(m1.front()==maxx[0])
            maxx.erase(maxx.begin());
    int temp;
    m1.pop();
    for(int i=w;i<A.size();i++)
    {
        m1.push(A[i]);
        temp=m1.front();
        
        while(maxx.size()>0  && maxx.back()<A[i])
                    maxx.pop_back();
        maxx.push_back(A[i]);
        
        cout<<maxx[0]<<" ";
        if(temp==maxx[0])
            maxx.erase(maxx.begin());
        m1.pop();
    }

}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
