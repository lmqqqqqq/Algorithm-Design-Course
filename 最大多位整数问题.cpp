#include<iostream>
#include<algorithm>
using namespace std;

//按字符串首字母对字符串进行降序排序
bool cmp(string s1,string s2)
{
    return s1+s2>s2+s1;
}

int main()
{
    int n;
    cin>>n;
    string* p=new string[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++){
        cout<<p[i];//字符串由大到小依次连接，形成最大整数
    }
    return 0;

}