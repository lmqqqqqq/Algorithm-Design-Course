#include<iostream>
using namespace std;

void move (int n,char start,char end)
{
    cout<<n<<' '<<start<<' '<<end<<endl;
}

void Hanoi(int n, char start, char end, char transit)
{
    if(n==1){
        move(n,start,end);
    }
    else{
        Hanoi(n-1,start,transit,end);
        move(n,start,end);
        Hanoi(n-1,transit,end,start);
    }
}

int main()
{
    int n;
    cin>>n;
    Hanoi(n,'A','B','C');
    return 0;
}