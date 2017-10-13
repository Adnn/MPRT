#include <Tools/VecTmp.h>

using namespace MPRT;

typedef VecTmp<3, int> Vec3;

void foo(const Vec3 &)
{}

int main()
{
    int origin[3] = {11, 11, 11};
    Vec3 a(origin);

    Vec3 b = a-a;
    foo(b);


    return 0;
}
