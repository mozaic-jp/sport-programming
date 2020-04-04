#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <map>
#include <set> 

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

int res = 0;
vector <vector<pair<int, int>>> v;

//a<c -> 同じ組を別のものと認識しない
int main()
{
    int n,m;
    cin >> n >> m;
    v.resize(n);

    REP(i,m)
    {
        int a,b,l;
        cin >> a >> b >> l;
        --a;--b;
        //a<bより
        v[a].push_back({l,b});
        v[b].push_back({l,a});
    }

    ll res = 0;
    //bを固定して、
    for(int i = 0; i < n; ++i)
    {
        map <int, int> m;
        sort(v[i].begin(), v[i].end());
        for(int j = 0; j < v[i].size(); ++j)
        {
            res += m[2540 - v[i][j].first];
            m[v[i][j].first]++;
        }
    }

    cout << res << endl;
    return 0;
}