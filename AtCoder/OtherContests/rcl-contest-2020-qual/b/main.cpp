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
const int MAX = 2100000;
const int MOD = 1000000007;


int main()
{
    int n;
    int res = 0;
    while(cin >> n)
    {
        res += n;
    }
    cout << res << endl;

    int N,M;
    cin >> N >> M;
    vector <vector <int> > dan(N, vector<int> (N));

    REP(i,N)
    {
        REP(j,N)
        {
            cin >> dan[i][j];
        }
    }

    REP(i,M)
    {
        int y,x;
        char dir;
        if(M % i == 0)
        {
            dir = 'R';
            y = i / 4;
            x = 0;
        }
        else if(M % i == 1)
        {
            dir = 'L';
            y = i / 4;
            x = N-1;
        }
        else if(M % i == 2)
        {
            dir = 'R';
            y = N-1 - i / 4;
            x = 0;
        }
        else if(M % i == 3)
        {
            dir = 'L';
            y = N-1 - i / 4;
            x = N-1;
        }

        cout << y << " ";
        cout << x << " ";
        cout << dir << endl;

    }


    return 0;
}