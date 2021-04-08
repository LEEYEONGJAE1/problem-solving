#define MXNUM 10000000
ll mindiv[MXNUM + 13],val[MXNUM+13]; //mindiv[i]= mininum prime divisor of i, val[i] = the number of prime divisors of i
void fac_init() {
    for (int i = 2; i <= MXNUM; i++) mindiv[i] = i;
    for (int i = 2; i * i <= MXNUM; i++) {
        if (mindiv[i] != i) continue;
        for (int j = i; j <= MXNUM; j += i) {
            mindiv[j] = Min(mindiv[j], i);
        }
    }
    for (int i = 2; i <= MXNUM; i++) {
        int j = i / mindiv[i];
        val[i] = val[j] + (mindiv[i] != mindiv[j]);
    }
}
vl fac(ll num) {//just giving primes
    vl ret;
    ll curVal = num;
    while (curVal != 1) {
        if (ret.empty() || ret.back() != mindiv[curVal]) {
            ret.push_back(mindiv[curVal]);
        }
        curVal /= mindiv[curVal];
    }
    return ret;
}
vp fac_i(ll num){
    vp ret;
    ll curVal = num;
    while(curVal!=1){
        if (ret.empty() || ret.back().first != mindiv[curVal]) {
            ret.push_back({ mindiv[curVal],1 });
        }
        else if(ret.back().first==mindiv[curVal]){
            ret.back().second++;
        }
        curVal /= mindiv[curVal];
    }
    return ret;
}
//don't for get to write fac_init(); in main()
