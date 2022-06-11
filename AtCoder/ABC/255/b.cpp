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
Type euclidean_distance(Type dy, Type dx) { return dy * dy + dx * dx; }

int main(){
    int n,k;
    cin>>n>>k;
    
    vi a(k);
    for(auto &in:a){
        cin>>in;
        in--;
    }
    
    vector<pair<ll,ll> > posi(n);
    for(auto &[x,y]:posi) cin>>x>>y;
    
    ll ans=0;
    REP(i,n){
        const auto &[x,y]=posi[i];
        
        ll tmp=LINF;
        for(auto j:a){
            const auto &[nx,ny]=posi[j];
            chmin(tmp,euclidean_distance(y-ny,x-nx));
        }
        
        chmax(ans,tmp);
    }
    
    printf("%.12lf\n",sqrt(ans));
}
