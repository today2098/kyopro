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

ll cross(ll a,ll b,ll c,ll d){
    return abs(a*d-c*b);
}

ll f(ll s,ll sub){
    return abs(s-4*sub);
}

int main(){
    int n;
    cin>>n;
    
    vector<pair<ll,ll> > vl(n);
    for(auto &[x,y]:vl) cin>>x>>y;
    
    ll s=0;
    for(int i=1;i+1<=n-1;++i){
        auto &[x0,y0]=vl[0];
        auto &[x1,y1]=vl[i];
        auto &[x2,y2]=vl[i+1];
        s+=cross(x1-x0,y1-y0,x2-x0,y2-y0);
    }
    
    ll ans=4*LINF;
    ll sub=0;
    int i=0, j=1;
    while(i<n){
        auto &[x0,y0]=vl[i];
        auto &[x1,y1]=vl[j%n];
        auto &[x2,y2]=vl[(j+1)%n];
        sub+=cross(x1-x0,y1-y0,x2-x0,y2-y0);
        chmin(ans,f(s,sub));
        
        while(i<n and i<j and 4*sub>=s){
            auto &[x0,y0]=vl[i];
            auto &[x1,y1]=vl[(i+1)%n];
            auto &[x2,y2]=vl[(j+1)%n];
            i++;
            sub-=cross(x1-x0,y1-y0,x2-x0,y2-y0);
            chmin(ans,f(s,sub));
        }
        
        j++;
    } 
    
    cout<<ans<<endl;
}

// I refered explanations.
