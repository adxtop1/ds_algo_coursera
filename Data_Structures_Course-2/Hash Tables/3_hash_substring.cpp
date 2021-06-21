#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};
ull power(ull x, int y,ull p)
{
    ull data=1;
    for(int i=0;i<y;i++)
       {
            data=(((data%p+p)%p*(x%p))%p+p)%p;
            data=(data%p+p)%p;
       }
    return data;
}
Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (int i = output.size()-1; i >= 0; --i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}
ull hashf(string &k,int start,int end)
{
    ull x=1;
    ull p=1e13+7;
    ull code=0;
    for(int i=end;i>=start;i--)
    {
        code=((code*x+k[i])%p+p)%p;
    }
    return code;
}
 
std::vector<int> get_occurrences(const Data& input) {
    string p = input.pattern, t = input.text;
    std::vector<int> ans;
    // for (size_t i = 0; i + s.size() <= t.size(); ++i)
    //     if (t.substr(i, s.size()) == s)
    //         ans.push_back(i);
    ull code_p=hashf(p,0,p.size()-1);
    ull code_t=0;
    bool test=false;
    ull x=1;
    ull pr=1e13+7;
    ull y=power(x,p.size(),pr);
    ull prev=hashf(t,t.size()-p.size(),t.size()-1);
    // ull curr=((x*code_i1+t[0]-t[p.size()]*y)%pr+pr)%pr;
    if(prev==code_p)
        { 
            test=false;
            for(int j=0;j<p.size();j++)
                if(t[t.size()-p.size()+j]!=p[j])
                   { 
                       test=true;
                       break;
                   }
            if(test==false)
                ans.push_back(t.size()-p.size());

        }
    for(int i=t.size()-p.size()-1;i>=0;i--)
    {
        code_t=((x*prev+t[i]-t[i+p.size()]*y)%pr+pr)%pr;
        // code_t=hashf(t,i,i+p.size()-1);
        
        if(code_t==code_p)
        { 
            test=false;
            for(int j=0;j<p.size();j++)
                if(t[i+j]!=p[j])
                   { 
                       test=true;
                       break;
                   }
            if(test==false)
                ans.push_back(i);

        }
        prev=code_t;
    }

    // ull code_i1=hashf(t,1,p.size());
    // ull temp=hashf(t,0,p.size()-1);
    
    // ull code_i=((x*code_i1+t[0]-t[p.size()]*y)%pr+pr)%pr;
   
    return ans;

}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
