#include<bits/stdc++.h>

using namespace std;
///co/relative prime 1 to n with n
int EulerPhi(int n)
{
    int result=n;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            result-=result/i;
        }
    }
    if(n>1)
        result-=result/n;
    return result;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==1)
            cout<<0<<endl;
        else if(n==0)
            break;
        else
            cout<<EulerPhi(n)<<endl;
    }

    return 0;
}
