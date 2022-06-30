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

int query(int u,int v){
    int res;
    printf("? %d %d\n",u,v);
    cout<<flush;
    cin>>res;
    if(res==-1) exit(1);
    
    return res;
}

int main(){
    int n;
    cin>>n;
    
    vvi nodes(2*n); // nodes[d]:=(ノード1, 2からの距離の和がdであるノードの集合).
    int ans=INF;
    FOR(v,3,n+1){
        int d1=query(1,v);
        int d2=query(2,v);
        
        nodes[d1+d2].push_back(v);
        ans=min(ans,d1+d2);
    }
    
    if(ans==3){
        if(nodes[3].size()==2){
            int d=query(nodes[3][0],nodes[3][1]);
            printf("! %d\n",(d==1?3:1));
            return 0;
        }
        
        cout<<"! 1"<<endl;
        return 0;
    }
    
    printf("! %d\n",ans);
}

// I refered explanations.
