#include<chrono>
#include <random>
//���ÿ��� �ȵ� �� �߰�

mt19937 rd = mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> ran(0, 2147483647); //���� �߰�

ran(rd) //���� ��