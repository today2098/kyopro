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

void bfs(int root,const vvi &g,vi &d){
    fill(ALL(d),INF);
    d[root]=0;
    queue<int> que;
    que.push(root);
    while(!que.empty()){
        int p=que.front();
        que.pop();
        
        for(const auto &v:g[p]){
            if(d[v]==INF){
                d[v]=d[p]+1;
                que.push(v); 
            }
        }
    }
    // debug("ok");
}

int main(){
    int n;
    cin>>n;
    
    vvi g(n);
    REP(i,n-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vi d(n);
    bfs(0,g,d);
    
    int v;
    int mx=-1;
    REP(i,n){
        if(chmax(mx,d[i])) v=i;
    }
    
    bfs(v,g,d);
    mx=-1;
    REP(i,n) chmax(mx,d[i]);
    
    cout<<mx+1<<endl;
}
