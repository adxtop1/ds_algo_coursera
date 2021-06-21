#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxx=1e7+19;

struct Query {
    string type, name;
    int number;
    Query(){
        number=0;
        type="empty";
        name="empty";
    }
};
struct conta {
    string  name;
    int number;
    conta(){
        number=-1;
        name="empty";
    }
};
vector<conta> contacts(maxx);
vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    
    
    for(size_t i=0;i<queries.size();i++)
    {
        if(queries[i].type=="add")
        {
            if(contacts[queries[i].number].number==-1){
                contacts[queries[i].number].name=queries[i].name;
                contacts[queries[i].number].number=queries[i].number;
                }
            else
                contacts[queries[i].number].name=queries[i].name;

        }
        else if(queries[i].type=="del")
        {
            contacts[queries[i].number].number=-1;
        }
        else{
            if(contacts[queries[i].number].number!=-1)
                result.push_back(contacts[queries[i].number].name);
            else
                result.push_back("not found");
        }
    }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
