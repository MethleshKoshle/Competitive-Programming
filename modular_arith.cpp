int mod=998244353;

//long long integer range gcd
ll gcd(ll a, ll b){
    if(!a)
        return b;
    return gcd(b%a, a);
}

//modular exponentation
ll modpow(int x, int y)
{
    ll res = 1, tmp;
    x = x % mod;

    while (y > 0)
    {
        if (y & 1)
        {
            tmp=res;
            tmp*=x;
            res = tmp % mod;
        }
        y = y>>1;
        tmp=x;
        tmp*=x;
        x = tmp % mod;
    }
    return res;
}

//modular multiplication
ll mulmod(ll a, ll b){
    ll res = 0;
    a = a % mod;
    while (b > 0){
        if (b % 2 == 1)
            res = (res + a) % mod;
        a = (a * 2) % mod;
        b /= 2;
    }
    return res % mod;
}

//modular addition
ll addmod(ll a, ll b){
    a = a % mod;
    b = b % mod;
    return (a+b)%mod;
}

//modular multiplicative inverse
ull modInverse(ll a){
	ll z = mod;
    ll q = 0, p = 1;
    while(a > 1){
        ll s = a/mod;
        ll t = mod;
        mod = a % mod, a = t;
        t = q;
        q = p - s * q;
        p = t;
    }
    if (p < 0)
       p += z;
	mod=z;
    return p;
}
