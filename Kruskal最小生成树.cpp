#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge
{
    int u;
    int v;
    int weight;
};
edge e[20];

bool cmp(edge e1, edge e2)
{
    return e1.weight<e2.weight;
}

int parent[20]={0};

void init(int V)
{
    for(int i=1;i<=V;i++){
        parent[i]=i;
    }
}

int seek(int i)
{
    if(parent[i]==i){
        return i;
    }
    else{
        return seek(parent[i]);
    }
}

void merge(int a,int b)
{
    int x=seek(a);
    int y=seek(b);
    parent[y]=x;
}

int V,N;

int main()
{
    cout<<"请输入顶点数"<<endl;
    cin>>V;
    cout<<"请输入边数"<<endl;
    cin>>N;
    cout<<"请依次输入每条边及权重"<<endl;
    for(int i=0;i<N;i++){
       cin>>e[i].u>>e[i].v>>e[i].weight;
    }
    sort(e,e+N,cmp);
    init(V);
    int cost=0;
    int cnt=0;
    for(int i=0;i<N;i++){
        if(seek(e[i].u)!=seek(e[i].v)){
            merge(e[i].u,e[i].v);
            cost+=e[i].weight;
            cnt++;
        }
        if(cnt==N-1){
            break;
        }
    }
    cout<<"最小生成树的代价为"<<cost<<endl;
    system("pause");
    return 0;
}