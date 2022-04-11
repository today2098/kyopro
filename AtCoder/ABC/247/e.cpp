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
    int n;
    int x,y;
    cin>>n>>x>>y;
    
    vi a(n);
    for(auto &in:a) cin>>in;
    
    ll ans=0;
    int l=0, r=0, b=0;
    int cnt[2]={};
    while(l<n){
        while(b<n and (y<=a[b] and a[b]<=x)) b++;
        
        while(l<b){
            while(r<b and !(cnt[0]>0 and cnt[1]>0)){
                if(a[r]==x) cnt[0]++;
                if(a[r]==y) cnt[1]++;
                r++;
            }
            
            if(cnt[0]>0 and cnt[1]>0) ans+=b-r+1;
            if(a[l]==x) cnt[0]--;
            if(a[l]==y) cnt[1]--;
            l++;
        }
        
        int next=b;
        while(next<n and !(y<=a[next] and a[next]<=x)) next++;
        l=r=b=next;
        cnt[0]=cnt[1]=0;
    }
    
    cout<<ans<<endl;
}
