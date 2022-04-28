#include <iostream>
using namespace std;

int fib(int n)//求阶乘
{
	if(n<=1)
		return 1;
	else{
		return fib(n-1)*n;
	}
}

int order(int data[],int n)//计算排列的字典序值
{
	int ans = 0;
	for(int i=0; i<n; i++){
		int cnt = 0;
		for(int j=i; j<n; j++){
			if(data[i]>data[j]){
				cnt++;
            }
		}
		ans+=cnt*fib(n-i-1);
	}
	return ans;
}

void reverse(int a[],int min,int n)//数组逆置 
{
    int i,j,temp;
    for(i=min,j=n-1;i<j;i++,j--){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}

void next_perm(int data[],int n)//求出下一个字典序
{ 
    int min,max;
    for(int i=n-1;i>=0;i--){//找出升序截止点的数组下标 
        if(data[i-1]<data[i]){
            min=i-1;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){//从尾部开始找出比a[min]大的第一个数 
        if(data[i]>data[min]){
            max=i;
            break;
        }
    }  
    swap(data[min],data[max]);
    reverse(data,min+1,n); 
}

int main()
{
	int n;
	cin>>n;
	int data[1000];
	for(int i=0; i<n; i++){
		cin>>data[i];
    }
	cout<<order(data,n)<<endl;
	next_perm(data,n);
	for(int i=0; i<n; i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
	return 0;
}

