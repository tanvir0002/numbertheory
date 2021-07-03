#include<bits/stdc++.h>

using namespace std;
#define mx 10000001
int prime[mx];
int prime_num[mx];
void SieveOfEratosthenes()
{
    memset(prime, 0, sizeof(prime));

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

int main()
{
    int n;
    cin>>n;
    SieveOfEratosthenes();
    int sum=1;
    for(int i=0; i<100000; i++)
    {
        if(n%prime_num[i]==0)
        {
            int cnt=0;
            while(n%prime_num[i]==0)
            {
                cnt++;
                n/=prime_num[i];
            }
            sum*=(cnt+1);
        }
    }
    if(n>1)
        sum*=2;
    cout<<sum<<endl;


    return 0;
}
