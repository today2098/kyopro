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
    ll n;
    ll a,b;
    ll p,q,r,s;
    cin>>n>>a>>b>>p>>q>>r>>s;
    
    ll l1=max(1-a,1-b), r1=min(n-a,n-b);
    ll l2=max(1-a,b-n), r2=min(n-a,b-1);
    
    vector<string> vs(q-p+1, string(s-r+1,'.'));
    for(ll i=p;i<=q;++i)for(ll j=r;j<=s;++j){
        if(i-a==j-b) {
            ll k=i-a;
            if(l1<=k and k<=r1) vs[i-p][j-r]='#';
        }
        if(i-a==b-j){
            ll k=i-a;
            if(l2<=k and k<=r2) vs[i-p][j-r]='#';
        }
    }
    
    for(const auto &s:vs) cout<<s<<endl;
}
