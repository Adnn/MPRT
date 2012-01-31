#include "OrthonormalBasis.h"

using namespace MPRT;

OrthonormalBasis::OrthonormalBasis() :
	mU(Vec3(1., 0., 0.)),
	mV(Vec3(0., 1., 0.)),
	mW(Vec3(0., 0., 1.))
{
}

OrthonormalBasis::OrthonormalBasis(const Vec3 &u, const Vec3 &v, const Vec3 &w) :
	mU(u),
	mV(v),
	mW(w)
{
}

