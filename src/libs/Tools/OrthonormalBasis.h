#ifndef MPRT_ONB
#define MPRT_ONB

#include "Tools_Export.h"

#include "Vec3.h"

namespace MPRT
{

class Tools_Export OrthonormalBasis
{
public:
	OrthonormalBasis();
	OrthonormalBasis(const Vec3 &u, const Vec3 &v, const Vec3 &w);

	OrthonormalBasis(const Vec3 &aW, const Vec3 &aUp);

public:
	Vec3 mU, mV, mW;
};

} // namespace

#endif