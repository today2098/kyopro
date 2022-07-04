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

template <typename Type>
std::vector<Type> table(size_t n, Type val) { return std::vector<Type>(n, val); }

template <class... Args>
auto table(size_t n, Args... args) {
    auto val = table(args...);
    return std::vector<decltype(val)>(n, std::move(val));
}

int main(){
    int n;
    cin>>n;

    vector<tuple<ll,ll,ll> > vt(n);
    for(auto &[x,y,p]:vt) cin>>x>>y>>p;

    auto &&d=table(n,n,LINF);
    REP(s,n)REP(t,n){
        if(s==t){
            d[s][t]=0;
        }else{
            const auto &[sx,sy,sp]=vt[s];
            const auto &[tx,ty,tp]=vt[t];
            ll dist=abs(sx-tx)+abs(sy-ty);
            ll need_power=(dist+sp-1)/sp;
            d[s][t]=need_power;
        }
    }

    REP(k,n)REP(s,n)REP(t,n) chmin(d[s][t],max(d[s][k],d[k][t]));

    ll ans=LINF;
    REP(s,n){
        ll tmp=0;
        REP(t,n) chmax(tmp,d[s][t]);
        chmin(ans,tmp);
    }

    cout<<ans<<endl;
}
