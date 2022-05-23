#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;

void swap(int* arr, int index, int parent)
{
    int temp=arr[index];
    arr[index]=arr[parent];
    arr[parent]=temp;
}

void heap_insert(int* arr,int index,int value)
{
    arr[index]=value;
    while(index>=0){
        int parent=(index-1)/2;
        if(arr[index]>arr[parent]){
            swap(arr,index,parent);
            index=parent;
        }
        else{
            break;
        }
    }
}

void heap_adjust(int* arr,int index,int k)
{
    int left=2*index+1;
    while(left<k){
        int right=left+1;
        int largest=right<k?(arr[left]>arr[right]?left:right):left;
        largest=arr[largest]>arr[index]?largest:index;
        if(index==largest){
           break;
        }
        else{
            swap(arr,largest,index);
            index=largest;
            left=index*2+1;
        }
    }
}

void heap_sort(int* arr,int n,int k)
{
    int* kheap=new int[k];
    for(int i=0;i<k;i++){
        heap_insert(kheap,i,arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]<kheap[0]){
            kheap[0]=arr[i];
            heap_adjust(kheap,0,k);
        }  
    }
    cout<<kheap[0]<<endl;
}

//以arr[p]为基准对数组arr进行划分
int partition(int* arr,int p,int r)
{
    int i=p,j=r+1;
    int x=arr[p];
    while(1){
        while(arr[++i]<x&&i<r);
        while(arr[--j]>x);
        if(i>=j){
            break;
        }
        swap(arr,i,j);
    }
    arr[p]=arr[j];
    arr[j]=x;
    return j;
}

int random_partition(int* arr,int p,int r)
{
     int i=(rand() % (r-p+1))+ p;
     swap(arr[i],arr[p]);
     return partition(arr,p,r);
}

void random_select(int* arr,int p,int r,int k)
{
    if(p==r){
        cout<<arr[p]<<endl;
        return;
    }
    int i=random_partition(arr,p,r);
    int j=i-p+1;
    if(k<=j){
        random_select(arr,p,i,k);
    }
    else{
        random_select(arr,i+1,r,k-j);
    }
}

//以x为基准对数组a进行划分
int Partition(int* a, int l, int r, int x)
{
	int i = l;	//枢纽元素的索引号
	int j = r;	//a[]序列右边界索引号
	while(i < j)
	{
		//从序列最右边开始查找，找到一个小于a[l]的为止;
		while (a[j] >= x && i < j) --j;
		if(i < j)
		{
			a[i] = a[j];
			i++;
		} 
		//从a[l]后面元素开始查找，找到一个比a[l]大的为止; 
		while (a[i] < x && i < j) ++i; 
		if (i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = x; //将a[i]的值写回
	return i; //返回分割点的索引
} 

int select(int* arr2,int p,int r,int k)   
{  
    if(r-p<75){  
        sort(arr2+p,arr2+r+1);
        return arr2[p+k-1];  
    }
    for(int i=0; i<=(r-p-4)/5; i++){//将arr2[l+5*i] - arr2[l + 5*i + 4]的第3小元素与arr2[l+i]交换位置;  
        sort(arr2+p+5*i,arr2+p+5*i+5);
        int tmp=arr2[p+5*i+2];
        arr2[p+5*i+2]=arr2[p+i];
        arr2[p+i]=tmp;
    }  
    int x = select(arr2,p,p+(r-p-4)/5,(r-p-4)/10);  //找中位数的中位数
    int i = Partition(arr2,p,r,x); //以x为基准对数组arr2进行划分 
    int j = i-p+1;  
    if(k<=j){ 
        return select(arr2,p,i,k);  
    }  
    else{  
        return select(arr2,i+1,r,k-j);  
    }  
}  

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    int* arr=new int[n];
    int* arr2=new int[n];
    for(int i=0;i<n;i++){
       cin>>arr[i];
       arr2[i]=arr[i];
    }

    //基于堆的选择
    //heap_sort(arr,n,k);

    //随机划分线性选择
    //srand((int)time(0));
    //random_select(arr,0,n-1,k);

    //利用中位数的线性时间选择
    int ans=select(arr2,0,n-1,k);
    cout<<ans<<endl;

    return 0;
}