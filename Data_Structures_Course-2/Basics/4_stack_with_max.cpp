#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

class StackWithMax {
    vector<int> stack1,stack2;
    int maxx;

  public:

    StackWithMax()
    {
        maxx=0;
    }

    void maxf(int maxi=0)
    {
        maxx=maxi;
    }
    void Push(int value) {
        stack1.push_back(value);
        stack2.push_back(maxx);
    }

    void Pop() {
        assert(stack1.size());
        stack1.pop_back();
        stack2.pop_back();
    }

    int Max() const {
        assert(stack1.size());
        return stack2.back();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    int value;

    StackWithMax stack;
    int maxx=0;
    
    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            if(value>maxx)
               {
                    stack.maxf(value);
                    maxx=value;
               } 
            stack.Push(value);
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}