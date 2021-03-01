/*****************************************************************************************/
/*  opensource
/*
/*  Header main class of an Insect.
/*
/* created by Blakrunner
/*****************************************************************************************/
#ifndef __INSECT_CLASS__
#define __INSECT_CLASS__

#include <SFML/Graphics.hpp>
#include <cstring>

#include "Create.hpp"

namespace Insect
{

class Insect : public Create
{
public:

    Insect(std::string type = "Ant");
    virtual ~Insect() {}

};

} // end namespace Insect

#endif // __INSECT_CLASS__