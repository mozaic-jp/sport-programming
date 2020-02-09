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


map <int, int> x;
int main()
{
    int N;
    string res = "YES";
    
    cin >> N;

    REP(i,N)
    {
        int a;
        cin >> a;
        decltype(x)::iterator it = x.find(a);
        if (it != x.end())  // 見つかった
        {
            res = "NO";
            break;
        }
        x[a] = 1;

    }
    
    cout << res << endl;

    return 0;
}