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

vector< vector< pair<int,int> > > v(100010);	
int V[100010] = {0};
int X[100010] = {0};
typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


 //1 2 3
 //1 5 4
 //1 6 4

 //2 5 1

//↑があったら2 6 は0 
//3 5 2

bool judge = true;

void dfs(int n)
{
    V[n] = 1;

    for(int i = 0; i <  v[n].size(); ++i)
    {
        if(X[v[n][i].first] == MOD)
        {
            X[v[n][i].first] = X[n] + v[n][i].second;
        }
        else if(X[v[n][i].first] != X[n] + v[n][i].second)
        {
            judge = false;
        }

        if(V[v[n][i].first] == 0)dfs(v[n][i].first);
    }

}

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        X[i] = MOD;
    }
    REP(i,M)
    {
        int l,r,d;
        cin >> l >> r >> d;
        --l;--r;
        v[l].push_back({r,d});
        v[r].push_back({l,-d});
    
    }

    REP(i,N)
    {
		if(V[i] == 0)
        {
			X[i] = 0;
			dfs(i);
		}
	}
    if(judge) cout << "Yes" << endl;
	else cout << "No" << endl;






    return 0;
}