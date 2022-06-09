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
    int n,k;
    int len;
    cin>>n>>len>>k;
    
    vi a(n);
    for(auto &in:a) cin>>in;
    
    vi b(n+1);
    b[0]=a[0];
    FOR(i,1,n) b[i]=a[i]-a[i-1];
    b[n]=len-a[n-1];
    
    int l=1, r=1e9+10;
    while(r-l>1){
        int mid=(l+r)/2;
        
        int tmp=0;
        int cnt=0;
        REP(i,n+1){
            tmp+=b[i];

            if(tmp>=mid){
                cnt++;
                tmp=0;
            }
        }
        
        bool jud=(cnt>=k+1);
        if(jud) l=mid;
        else r=mid;
    }
    
    cout<<l<<endl;
}
