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
    int n,q;
    ll x;
    cin>>n>>q>>x;
    
    vector<ll> w(2*n);
    REP(i,n){
        cin>>w[i];
        w[i+n]=w[i];
    }
    
    vector<ll> k(q);
    for(auto &in:k) cin>>in;
    
    ll all=accumulate(w.begin(),w.begin()+n,0LL); // all:=(全種のジャガイモの重さの合計).
    vector<ll> count(n,n*(x/all)); // cnt[l]:=(l番目のジャガイモから詰め始めた場合における，箱に詰めるジャガイモの個数)．
    x%=all;
    
    int l=0, r=0;
    ll sum=0;
    while(l<n){
        if(l>r){
            r=l;
            sum=0;
        }
        while(sum<x) sum+=w[r++];
        count[l]+=r-l;
        sum-=w[l++];
    }
    // line(count);
    
    vi order(n,-1);
    int next=0;
    vi path;
    int u=0;
    while(1){
        if(order[u]!=-1) break;
        order[u]=next++;
        path.push_back(u);
        u=(u+count[u])%n;
    }
    // line(path);
    
    int loop=next-order[u];
    int non_loop=(int)path.size()-loop;
    for(auto i:k){
        i--;
        
        ll ans;
        if(i<non_loop){
            ans=count[path[i]];
        }else{
            i=(i-non_loop)%loop;
            ans=count[path[non_loop+i]];   
        }
        
        cout<<ans<<endl;
    }
}

// I refered explanations.
