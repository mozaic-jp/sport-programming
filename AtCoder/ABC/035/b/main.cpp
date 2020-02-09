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


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


int main()
{
    string s;
    cin >> s;
    int T;
    cin >> T;
    int x = 0;
    int y = 0;
    int q = 0;
    REP(i,s.size())
    {
        if(s[i] == 'L')--x;
        if(s[i] == 'R')++x;
        if(s[i] == 'U')++y;
        if(s[i] == 'D')--y;
        if(s[i] == '?')++q;
    }
    int res = 0;

    if(T == 1)
    {
        res = abs(x) + abs(y) + q;
    }
    else
    {
        if(s.size() % 2 == 0)
        {
            res = max(0, abs(x) + abs(y) - q);
        }
        else
        {
            res = max(1, abs(x) + abs(y) - q);
        }
    }
    
    cout << res << endl;

    return 0;
}
