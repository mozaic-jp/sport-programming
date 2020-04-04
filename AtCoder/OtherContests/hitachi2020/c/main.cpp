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
    int n;
    cin >> n;
    vector <int> g(n);
    REP(i,n-1)
    {
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    //1+2
    //3 * 1

    //1-2-3-4
    //


    //距離3からきめていく

    //距離3の関係

    //線はN-1本




    return 0;
}