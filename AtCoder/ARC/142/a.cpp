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

template<typename Type> inline bool chmax(Type &a,const Type &b){if(a<b){a=b;return true;}return false;}
template<typename Type> inline bool chmin(Type &a,const Type &b){if(a>b){a=b;return true;}return false;}

ll f(ll x){
    while(1){
        string s=to_string(x);
        reverse(ALL(s));
        ll y=stoll(s);
        // debug(y);
        
        if(!chmin(x,y)) break;
    }

    // debug(x);
    return x;
}

int main(){
    ll n,k;
    cin>>n>>k;
    
    if(f(k)<k){
        cout<<0<<endl;
        return 0;
    }
    
    ll k2=0;
    for(ll tmp=k;tmp>0;tmp/=10) k2=10*k2+tmp%10;
    bool flag=(k!=k2);
    
    ll ans=0;
    while(k<=n){
        ans++;
        k*=10;
    }
    if(flag){
        while(k2<=n){
            ans++;
            k2*=10;
        }
    }
    
    cout<<ans<<endl;
}

// I refered explanations.
