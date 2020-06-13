#define MXNUM 10000000
ll mindiv[MXNUM+4];
void fac_init(){
    for (int i = 2; i <= MXNUM; i++)mindiv[i] = i;
    for (int i = 2; i * i <= MXNUM; i++) {
        if (mindiv[i] != i) continue;
        for (int j = i; j <= MXNUM; j += i) {
            mindiv[j] = Min(mindiv[j], i);
        }
    }
}
vl fac(ll num){
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
