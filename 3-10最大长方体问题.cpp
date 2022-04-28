#include <iostream>
using namespace std;

int maxsum(int n,int *a)
{
    int sum=0,b=0;
    for (int i = 1; i <=n ; i++) {
        if(b>0){
            b += a[i];
        }
        else{
            b = a[i];
        }
        if(b>sum){//记录最大值
            sum=b;
        }
    }
    return sum;
}

int maxsum2(int m,int n, int **a)
{
    int sum=0;
    int *b=new int [n+1];
    for (int i = 1; i <=m ; i++) {
        for (int k = 1; k <=n ; k++){
            b[k]=0;//置0
        }
        for (int j = i; j <=m ; j++) {//动态规划，将m分成1~i和i+1~m两段
            for (int k = 1; k <=n ; k++){
                b[k] += a[j][k];
            }
            int max=maxsum(n,b);
            if(max>sum){
                sum=max;
            }
        }
    }
    return sum;
}

int maxsum3(int m,int n,int p,int ***a)
{
    int sum=0;
    int **c=new int*[n+1];
    for (int i = 1; i <=n ; i++) {
        c[i]=new int [p+1];
    }
    for (int i = 1; i <=m ; i++) {
        for (int j = 1; j <=n ; j++) {
            for (int k = 1; k <=p ; k++) {
                c[j][k]=0;//置0
            }
        }
        for (int l = i; l <=m ; l++) {
            for (int j = 1; j <=n ; j++) {
                for (int k = 1; k <=p ; k++) {
                    c[j][k]+=a[l][j][k];
                }
            }
            int max=maxsum2(n,p,c);
            if(max>sum){
                sum=max;
            }
        }
    }
    return sum;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,n,p,***a;
    cin>>m>>n>>p;
    a=new int**[m+1];//一维
    for (int i = 1; i <=m ; i++) {
        a[i]=new int*[n+1];
    }//二维
    for (int i = 1; i <=m ; i++) {
        for (int j = 1; j <=n ; j++) {
            a[i][j]=new int[p+1];
        }
    }//三维

    for (int i = 1; i <=m ; i++) {
        for (int j = 1; j <=n ; j++) {
            for (int k = 1; k <=p ; k++) {
                cin>>a[i][j][k];
            }
        }
    }
    cout<<maxsum3(m,n,p,a);
}

