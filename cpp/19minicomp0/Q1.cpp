#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    double circle = 3.14159265358979323846264338*(x/4.0)*(x/4.0);
    double triangle = x*y/2.0;
    printf("%.11f", circle+triangle);
    return 0;
}