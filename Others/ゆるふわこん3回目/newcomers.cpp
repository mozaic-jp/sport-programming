#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <map>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    string s;
    
    map <string, int> m;
    REP(i,a)
    {
        cin >> s;
        m[s] = 1;
    }
    REP(i,b)
    {
        cin >> s;
        m[s] = 1;
    }
    int res = 0;
    REP(i,c)
    {
        cin >> s;
        decltype(m)::iterator it = m.find(s);
        if (it == m.end()) 
        {// 見つからない
            ++res;
        }

    }

    cout << res << endl;


    return 0;
}