#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=1e9+7;


void sieve(int n)
{
    vector<bool> primes(n,true);         // initially consider all the numbers to be prime
    primes[0]= primes[1] =false;        // because 0 and 1 is not prime

    for(int i=2; i<=sqrt(n); i++)
    {
        if(primes[i] ==true)                // if current number is prime
        {
            for(int j=i*i; j<=n; j+=i)
                primes[j] =false;             //  set all its multiple as not prime
        }
    }

   int cnt=0;
    for(int i=0; i<n; i++)
    {
        if(primes[i]== true)
            {
                cout<<i<<"  ";
                cnt++;
            }
    }
    cout<<endl;
     cout<<"Total  = "<<cnt<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int n=1000000;
    sieve(n);





    return 0;
}
