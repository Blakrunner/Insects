/*****************************************************************************************/
/*  opensource
/*
/*  Header for the creation an Insect.
/*
/* created by Blakrunner
/*****************************************************************************************/
#ifndef __INSECT_CREATE_CLASS__
#define __INSECT_CREATE_CLASS__

#include <SFML/Graphics.hpp>
#include <cstring>

#include "Transform.hpp"

namespace Insect
{

class Create : public Transform
{
public:

    void create();

protected:

    Create(std::string type);
    virtual ~Create() {}

    void assemble();

};

}// end namespace Insect

#endif // __INSECT_CREATE_CLASS__