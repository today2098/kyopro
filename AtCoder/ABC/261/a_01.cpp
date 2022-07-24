#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(int)(n);++i)
#define FOR(i,l,r) for(int i=(int)(l);i<(int)(r);++i)
#define ALL(v)     (v).begin(),(v).end()
using ll  = long long;
using vi  = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using namespace std;
constexpr int       INF  = 1e9;
constexpr long long LINF = 1e18;
constexpr double    EPS  = 1e-10;
constexpr int       MOD  = 1e9+7;

int main(){
    int l[2],r[2];
    REP(i,2) cin>>l[i]>>r[i];
    
    vi dp(110,0);
    REP(i,2){
        dp[l[i]]++;
        dp[r[i]]--;
    }
    FOR(i,1,110) dp[i]+=dp[i-1];
    
    int ans=0;
    REP(i,110){
        if(dp[i]==2) ans++;
    }
    
    cout<<ans<<endl;
}
