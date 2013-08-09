#ifndef MPRT_RGB
#define MPRT_RGB

#include "Tools_Export.h"

#include "AbstractVec3.h"

#include <cmath>

namespace MPRT
{

class Tools_Export Rgb : public AbstractVec3<Rgb>
{
public:
	Rgb() :
	  AbstractVec3()
	{
	}

	Rgb(FLOAT_TYPE aX, FLOAT_TYPE aY, FLOAT_TYPE aZ) :
		AbstractVec3(aX, aY, aZ)
	{
	}

	inline FLOAT_TYPE r() const
	{
		return mElements[0];
	}
	inline FLOAT_TYPE g() const
	{
		return mElements[1];
	}
	inline FLOAT_TYPE b() const
	{
		return mElements[2];
	}

	inline const Rgb correctGama(double aGamma) const
	{
		FLOAT_TYPE power = 1./aGamma;

		return Rgb(
			pow(mElements[0],power),
			pow(mElements[1],power),
			pow(mElements[2],power));
	}
};

} // namespace

#endif
