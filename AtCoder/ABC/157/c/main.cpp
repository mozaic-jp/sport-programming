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
    int N, M;
    cin >> N >> M;

    vector <int> kimari(N, -1);
    REP(i,M)
    {
        int s,c;
        cin >> s >> c;
        --s;
        if(kimari[s] != -1 && kimari[s] != c)
        {
            cout << -1 << endl;
            return 0;
        }
        kimari[s] = c;
    }
    string res = "";

    if(N != 1)
    {
        if(kimari[0] == 0)
        {
            cout << -1 << endl;
            return 0; 
        }
    }

    REP(i,N)
    {
        if(kimari[i] != -1)
        {
            res += to_string(kimari[i]); 
        }
        else
        {
            char tmp;
            if(i != 0 || N == 1)tmp = '0';
            else tmp = '1';
            res += tmp; 
        }
    }

    cout << res << endl;

    return 0;
}