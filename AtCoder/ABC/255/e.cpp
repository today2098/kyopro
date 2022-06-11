#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(int)(n);++i)
#define FOR(i,l,r) for(int i=(int)(l);i<(int)(r);++i)
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   std::cerr<<"(L"<<__LINE__<<") "<<#x<<": "<<(x)<<std::endl
using ll  = long long;
using vi  = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using namespace std;
constexpr int       INF  = 1e9;
constexpr long long LINF = 1e18;
constexpr double    EPS  = 1e-10;
constexpr int       MOD  = 1e9+7;
template<class Class> void line(const Class &a,std::ostream &os=std::cerr){int cnt=0;for(const auto &elem:a)os<<(cnt++==0?"":" ")<<elem;os<<std::endl;}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<ll> s(n-1);
    for(auto &in:s) cin>>in;
    
    vector<ll> x(m);
    for(auto &in:x) cin>>in;
    
    vector<ll> a(n);
    a[0]=0;
    REP(i,n-1) a[i+1]=s[i]-a[i];
    
    map<ll,int> mp;
    REP(j,m)REP(i,n){
        ll diff=x[j]-a[i];
        if(i&1) diff=-diff;
        mp[diff]++;
    }
    
    int ans=0;
    for(const auto &[ignore,cnt]:mp) ans=max(ans,cnt);
    
    cout<<ans<<endl;
}
