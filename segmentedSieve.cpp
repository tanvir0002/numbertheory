#include<bits/stdc++.h>
using namespace std;

#define mx 100005
int prime[mx];
long long int prime_num[mx];

long long int l,r;

void SieveOfEratosthenes()
{
    for(int i=4; i<=mx; i+=2)
        prime[i]=1;

    for(int i=2; i*i<=mx; i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=mx; j+=i)
            {
                prime[j]=1;
            }
        }
    }
    int j=0;
    for(int i=2; i<=mx; i++)
    {
        if(prime[i]==0)
        {
            prime_num[j++]=i;
        }

    }

}

int  SegmentedSieve()
{
    bool segArr[r-l+1];

    for(int i=0 ; i<=r-l+1 ; i++)
        segArr[i]=true;

    if(l==1)
        segArr[0]=false;

    for(int i=0; prime_num[i]*prime_num[i]<=r; i++)
    {
        long long curprime,base;

        curprime=prime_num[i];
        base=curprime*curprime;
        if(base<l)
            base=((l+curprime-1)/curprime)*curprime;

        for(long long j=base; j<=r; j+=curprime)
            segArr[j-l]=false;
    }

    int cnt=0;
    for(int i=0; i<=r-l; i++)
    {
        if(segArr[i]==true)
            cnt++;
    }
    return cnt;

}

int main()
{
    SieveOfEratosthenes();

    int tc;
    cin>>tc;
    int cases=1;
    while(tc--)
    {
        cin>>l>>r;

        int cnt=SegmentedSieve();
        cout<<"Case "<<cases<<": "<<cnt<<endl;
        cases++;

    }

    return 0;
}
