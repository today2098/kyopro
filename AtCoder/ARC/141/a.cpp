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

int main(){
    int t;
    cin>>t;
    
    vector<ll> ten_pow(19); // ten_pow[k]:=10^k;
    ten_pow[0]=1;
    FOR(i,1,19) ten_pow[i]=ten_pow[i-1]*10; 
    
    while(t--){
        ll n;
        cin>>n;
        
        int cnt=0; // cnt:=(nの桁数).
        while(cnt<19 and n/ten_pow[cnt]>0) cnt++;
        // debug(cnt);
        
        ll ans=ten_pow[cnt-1]-1;
        FOR(i,1,cnt){
            if(cnt%i==0){
                REP(j,2){
                    ll m=n/ten_pow[cnt-i]-j;
                    ll tmp=0;
                    REP(j,cnt/i) tmp=ten_pow[i]*tmp+m;
                    // debug(tmp);
                    if(tmp<=n) chmax(ans,tmp);
                }
            }
        }
        
        cout<<ans<<endl;
    }
}

// I refered explanations.
