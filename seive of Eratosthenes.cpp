#include<bits/stdc++.h>

using namespace std;
#define mx 10000001
int prime[mx];
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

}

void printPrimes(int n)
{
    for(int i=2; i<=n; i++)
    {
        if(prime[i]==0)
        {
            cout<<i<<endl;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    SieveOfEratosthenes();
    printPrimes(n);


    return 0;
}
