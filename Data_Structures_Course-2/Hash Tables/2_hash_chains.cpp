#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
  public: 
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
    vector<vector<string>> table;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }


    explicit QueryProcessor(int buck_cnt){
        bucket_count=buck_cnt;
        table.resize(buck_cnt);
        } 

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        //query.ind--;
      
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            /* for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
                if (hash_func(elems[i]) == query.ind)
                    std::cout << elems[i] << " "; */
            if(table[query.ind].size()!=0)
            {
                for(int i=table[query.ind].size()-1;i>=0;i--)
                    cout<<table[query.ind][i]<<" ";
            }

            std::cout << "\n";
        } else {
            // vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
            size_t code=hash_func(query.s);
            bool present=false;
            size_t pos=0;
            for(size_t i=0;i<table[code].size();i++)
            {
                if(table[code][i]==query.s)
                    {
                        present=true;
                        pos=i;
                        break;
                    }
            }
            if (query.type == "find")
                writeSearchResult(present);
            else if (query.type == "add") {
                if(present==false)
                    table[code].push_back(query.s);
            } else if (query.type == "del") {
                if(present)
                    table[code].erase(table[code].begin()+pos);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
