#include <iostream>
#include <cmath>
using namespace std;

int n,s[100][100];
double w[100][100],m[100][100];

struct node{
	double x,y;
}p[100];//存储顶点坐标 

double Weight(int i,int j,int k)//权函数，此处为最小弦长三角剖分 
{
	return w[i][j]+w[i][k]+w[j][k];
}

void MinWeightTriangulation(int n,double m[][100],int s[][100])//计算最优值 
{
	for(int i=1;i<=n;i++){
		m[i][i]=0;
    }
	for(int r=2;r<=n;r++){
		for(int i=1;i<=n-r+1;i++){
			int j=i+r-1;
			m[i][j]=m[i+1][j]+Weight(i-1,i,j);
			s[i][j]=i;
			for(int k=i+1;k<j;k++){
				double t=m[i][k]+m[k+1][j]+Weight(i-1,k,j);
				if(t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
    }
	for(int i=0;i<n;i++){
		w[i][i]=0;
    }
	for(int i=0;i<n;i++){//顶点i到顶点j的距离
	    for(int j=i+1;j<n;j++){
		    double disx=p[i].x-p[j].x;
		    double disy=p[i].y-p[j].y;
		    w[i][j]=sqrt(disx*disx+disy*disy);
	    } 
    }
	MinWeightTriangulation(n-1,m,s);//计算最优值 
    cout<<m[1][n-1]<<endl;
	return 0;
}

