#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#define min(x, y, z) (((x)>(y) ? ((y)>(z) ? (z): (y)) : ((x)>(z) ? (z) : (x))))

using namespace std;


main(){
    float one, two, three, a, b, c, factor;

    cin >> one >> two >> three >> a >> b >> c;

    c = c/a;
    b = b/a;
    a = 1;

    factor =  min(one/a, two/b, three/c);
    cout << fixed << setprecision(8) << one - a*factor << " " << two - b*factor << " " << three - c*factor;

}
