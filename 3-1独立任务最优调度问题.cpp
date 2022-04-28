#include<iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m=0; //m为所有任务中耗时最大的任务的时间
    cin>>n;
    int a[20]={0};
    int b[20]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>m){
            m=a[i];
        }
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]>m){
            m=b[i];
        }
    }
    int mn=m*n;
    int p[100][100][10]={0}; 
    //p[i][j][k] 前k个作业可以在处理机A用时不超过i时间且在处理机B用时不超过j时间内完成
    int i,j,k;
    for(i=0;i<=mn;i++){  //数组初始化
        for(j=0;j<=mn;j++){
            p[i][j][0]=true;
            for(k=1;k<=n;k++){
                p[i][j][k]=false;
            }
        }
    }
    for(k=1;k<=n;k++){
        for(i=0;i<=mn;i++){
            for(j=0;j<=mn;j++){
                if(i-a[k-1]>=0){
                    p[i][j][k]=p[i-a[k-1]][j][k-1];
                }
                if(j-b[k-1]>=0){
                    p[i][j][k]=p[i][j][k]||p[i][j-b[k-1]][k-1];
                }
            }
        }
    }
    int ans=mn;
    for(i=0;i<=mn;i++){
        for(j=0;j<=mn;j++){
            if(p[i][j][n]){
                int tmp=(i>j)? i: j;
                if(tmp<ans){
                    ans=tmp;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}