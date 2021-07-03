#include<bits/stdc++.h>

using namespace std;
int mx=100000001;
int prime[100000001/32];

bool check(int n,int pos)
{
    return (bool)(n&(1<<pos));
}

int setval(int n,int pos)
{
    return n=(n|(1<<pos));
}

void bitwiseSeive()
{
    for(int i=3; i*i<=mx; i+=2)
    {
        if(check(prime[i/32],i%32)==0)
        {
            for(int j=i*i; j<=mx; j+=2*i)
            {
                prime[j/32]=setval(prime[j/32],j%32);
            }
        }
    }

}
void printprime(int n)
{
    puts("2");

    for(int i=3; i<=n; i+=2)
    {
        if(check(prime[i/32],i%32)==0)
        {
            cout<<i<<endl;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    bitwiseSeive();
    printprime(n);

    return 0;
}
