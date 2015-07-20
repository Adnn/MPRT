#ifndef Material_h__
#define Material_h__


//http://www1.cs.columbia.edu/CAVE/databases/tvbrdf/tvbrdf.php
//http://cg.cs.uni-bonn.de/en/projects/btfdbb/download
//http://people.csail.mit.edu/addy/research/brdf (see supplemental document)
//http://www.merl.com/brdf

#include "Tools_Export.h"

#include "Rgb.h"

namespace MPRT
{
    
struct Tools_Export Material
{
    Material(Rgb ambient, Rgb diffuse, Rgb specular):
        ambientColor(ambient),
        diffuseColor(diffuse),
        specularColor(specular),
        reflectiveColor(Rgb::BLACK)
    {}

    Rgb ambientColor, diffuseColor, specularColor;
    Rgb reflectiveColor;
    int specularExponent;
};

} //namespace

#endif // Material_h__
