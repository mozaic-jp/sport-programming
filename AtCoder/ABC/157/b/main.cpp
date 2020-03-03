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
    vector <vector <int>> a(3,vector<int>(3));
    REP(i,3)
    {
        REP(j,3)
        {
            cin >> a[i][j];
        }
    }
    int N;
    cin >> N;
    map <int,int> m;
    REP(i,N)
    {
        int b;
        cin >> b;
        m[b] = 1;
    }

    string res = "No";
    //縦
    bool flg;
    REP(i,3)
    {
        flg = true;
        REP(j,3)
        {
            decltype(m)::iterator it = m.find(a[i][j]);
            if (it == m.end())
            {
                flg = false;
                break;
            }
        }
        if(flg)res = "Yes";

        flg = true;
        //横
        REP(j,3)
        {
            decltype(m)::iterator it = m.find(a[j][i]);
            if (it == m.end())
            {
                flg = false;
                break;
            }
        }
        if(flg)res = "Yes";
    }

    //斜め
    flg = true;
    REP(i,3)
    {
        decltype(m)::iterator it = m.find(a[i][i]);
        if (it == m.end())
        {
            flg = false;
            break;
        }
    }
    if(flg)res = "Yes";

    //斜め
    flg = true;
    REP(i,3)
    {
        decltype(m)::iterator it = m.find(a[i][2-i]);
        if (it == m.end())
        {
            flg = false;
            break;
        }
    }
    if(flg)res = "Yes";

    cout << res << endl;

    return 0;
}