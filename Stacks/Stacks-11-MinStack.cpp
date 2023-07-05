#include <iostream>
#include <vector>
using namespace std;

class MinStack
{
public:

    vector<pair<int, int>> st;

    void push(int val)
    {
        if (st.empty())
        {
            pair<int, int> p = make_pair(val, val);
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            p.second = min(val, st.back().second);
            st.push_back(p);
        }
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st.back().first;
    }

    int getMin()
    {
        return st.back().second;
    }
};

int main()
{

    MinStack mst;

    mst.push(95);
    mst.push(18);
    mst.push(77);
    mst.push(47);

    mst.pop();

    cout << mst.top() << endl;
    cout << mst.getMin() << endl;

    return 0;
}
