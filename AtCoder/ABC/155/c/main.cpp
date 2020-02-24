#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <bits/stdc++.h>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;

using Graph = vector<vector<int>>;

typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


map <string, int> m;
int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        string s;
        cin >> s;
        m[s] = m[s] + 1;
    }

    int m_max = 0;
    vector<string> res;

    for(auto t:m)
    {
        if(m_max < t.second)
        {
            m_max = t.second;
            res.clear();
            res.push_back(t.first);
        }
        else if(m_max == t.second)
        {
            res.push_back(t.first);
        }
    }
    for(auto t:res)
    {
        cout << t << endl;
    }

    return 0;
}