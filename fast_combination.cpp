ll fact[200005];
ll mod = 1e9 + 7;
ll mul(ll x, ll y) { return (x * y) % mod; }
ll pow(ll x, ll y) {
    ll z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}
ll inv(ll x, ll mod) { return pow(x, mod - 2); }
ll nCk(ll n, ll k, ll p) {
    if (n < k)return 0;
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}

// write this in main()
/*fact[0] = 1;
for (int i = 1; i <= 200002; i++) {
    fact[i] = mul(fact[i - 1], i);
}*/
