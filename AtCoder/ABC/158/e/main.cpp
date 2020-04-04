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


int main()
{
    int n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    ll res = 0;
    if(p == 2)
    {
        REP(i,n)
        {
            if((s[i] - '0') % 2 == 0)
            {
                //1の位の桁になる組み合わせ数分足す
                res += i + 1;
            }
        }

    }
    else if(p == 5)
    {
        REP(i,n)
        {
            if(s[i] == '0' || s[i] == '5')
            {
                //1の位の桁になる組み合わせ数分足す
                res += i + 1;
            }
        }
    }
    else
    {
        map<int,ll> m;
        int tmp = 0;
        m[tmp]++;
        ll k = 1;
        //sの右から
        for(int i = n-1; i >= 0; --i)
        {
            


        }

    }


    return 0;
}