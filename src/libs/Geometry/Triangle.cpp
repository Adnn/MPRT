#include "Triangle.h"

using namespace MPRT;

Triangle::Triangle(const Vec3 &aVertexA, const Vec3 &aVertexB, const Vec3 &aVertexC, Material aMaterial) :
    Surface(aMaterial),
	mA(aVertexA),
	mB(aVertexB),
	mC(aVertexC),
    mNormal((mB-mA).crossP(mC-mA))
{
    mNormal.normalize();
}

bool Triangle::hit(const HitParameters &aParams, HitRecord &aRecord) const
{
	FLOAT_TYPE A = mA.x() - mB.x();
	FLOAT_TYPE B = mA.y() - mB.y();
	FLOAT_TYPE C = mA.z() - mB.z();

	FLOAT_TYPE D = mA.x() - mC.x();
	FLOAT_TYPE E = mA.y() - mC.y();
	FLOAT_TYPE F = mA.z() - mC.z();

	FLOAT_TYPE G = aParams.ray.direction().x();
	FLOAT_TYPE H = aParams.ray.direction().y();
	FLOAT_TYPE I = aParams.ray.direction().z();

	FLOAT_TYPE J = mA.x() - aParams.ray.origin().x();
	FLOAT_TYPE K = mA.y() - aParams.ray.origin().y();
	FLOAT_TYPE L = mA.z() - aParams.ray.origin().z();

	FLOAT_TYPE EIHF = E*I - H*F;
	FLOAT_TYPE GFDI = G*F - D*I;
	FLOAT_TYPE DHEG = D*H - E*G;

	FLOAT_TYPE denom = (A*EIHF + B*GFDI + C*DHEG);
	
	FLOAT_TYPE beta = (J*EIHF + K*GFDI + L*DHEG) / denom;
	// Note : replaced by strict boundaries (to include vertices)
	if (beta < 0. || beta > 1.) return false;

	FLOAT_TYPE AKJB = A*K - J*B;
	FLOAT_TYPE JCAL = J*C - A*L;
	FLOAT_TYPE BLKC = B*L - K*C;

	FLOAT_TYPE gamma = (I*AKJB + H*JCAL + G*BLKC) / denom;
	// Note : replaced by strict boundaries (to include vertices)
	if (gamma < 0. || beta+gamma > 1.) return false;

	FLOAT_TYPE tval = -(F*AKJB + E*JCAL + D*BLKC) / denom;
	if ((tval >= aParams.tMin) && (tval <= aParams.tMax))
	{
		aRecord.t=tval;
        aRecord.hitSurface = this;

        return true;
	}

	return false;
}

Vec3 Triangle::getNormalAt(const Vec3 &aSurfacePoint) const
{
    return mNormal;
}