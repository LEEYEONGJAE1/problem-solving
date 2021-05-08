#include<chrono>
#include <random>
//로컬에서 안될 시 추가

mt19937 rd = mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> ran(0, 2147483647); //위에 추가

ran(rd) //랜덤 수