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

//標準形を出力する
//n<10



//n=1
//string tar[] = {"a"};
//
////n = 2のとき
//{"aa","ab"};
//
////n = 3
//{"aaa","aba","aab","abc"};
//
////n = 4
//{"aaaa","aaab","aaba","abaa","aabc","abac","abca","abcd"};
//
////n = 5
//{"aaaaa","aaaab","aaaba","aabaa","abaaa","aaabc","aabac","abaac","abaca","abcaa",
//"aabcd","abacd","abcad","abcda","abcde"};
//
////n = 6
//aaaaaa,aaaaab,aaaaba,aaabaa,aabaaa,abaaaa,
//aaaabc,aaabac,aabaac,abaaac,abaaca,abacaa,abcaaa,
//aaabcd,aabacd,aabcad,aabcda,
//abbcc;

//

int n;
int shutu(string v)
{
    cout << v <<endl;
    return 0;
}
//aaaacが捨てれてない
int dfs(string v, int cnt, int syu)
{
    
    if(cnt == n)
    {
        shutu(v);
        return syu;
    }
    for(int i = 0; i <= syu; ++i)
    {
        char c = i + 'a';
        syu = i;
        dfs(v+c, cnt+1, syu+1);
    }
    return 0;
}


int main()
{

    //これのすきに撮ったやつをならべたやつだ
    //{0,0,0,0,0,0,0,0}
    //{0,0,0,0,0,0,0,1}
    //{0,1,1,1,1,1,1,1}はよいのか
    //{0,1,2,3,4,5,6,7}
    //までのやつ?

    cin >> n;
    string s = "";

    dfs(s,0,0);


    return 0;
}