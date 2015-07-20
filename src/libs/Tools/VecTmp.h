#ifndef VecTmp_h__
#define VecTmp_h__

#include <cstddef>

namespace MPRT
{

template <std::size_t N_size, typename T_element>
class VecTmp
{
public:
    VecTmp(T_element aValues[N_size])
    {
       for(size_t elemId = 0; elemId < N_size; ++elemId)
       {
           mElements[elemId] = aValues[elemId];
       }
        
    }

   const VecTmp operator-(const VecTmp<N_size, T_element> &aRhs)
   {
       T_element constructedArray[N_size];
       for(size_t elemId = 0; elemId < N_size; ++elemId)
       {
           constructedArray[elemId] = mElements[elemId] - aRhs.mElements[elemId];
       }

       return VecTmp<N_size, T_element>(constructedArray);
   }

private:
    T_element mElements[N_size];
};

} //namespace

#endif // VecTmp_h__