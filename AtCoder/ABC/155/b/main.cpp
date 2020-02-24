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


int main()
{
    int N;
    cin >> N;
    string res = "APPROVED";

    REP(i,N)
    {
        int a;
        cin >> a;

        if(a % 2 == 0)
        {
            if(a % 3 == 0 || a % 5 == 0)
            {

            }
            else
            {
                res = "DENIED";
            }
            
        }
    }

    cout << res << endl;
    return 0;
}