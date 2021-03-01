/*****************************************************************************************/
/*  opensource
/*
/*  
/*
/* created by Blakrunner
/*****************************************************************************************/
#include "Transform.hpp"
#include <unordered_map>

namespace Insect
{

void Transform::bendBody(const float rotate)
{
    this->rotatePart("thorax", rotate);
    if(HASPETOILE)
    {
        if(this->m_petoiles == 1)
        {
            this->rotatePart("petoile", rotate);
        }
        else
        {
            this->rotatePart("petoile", rotate);
            for(int i = 1; i < this->m_petoiles; ++i)
                this->rotatePart("petoile"+std::to_string(i), rotate);
        }
    }

    if(HASPOSTPETOILE)
        this->rotatePart("postPetoile", rotate);

    this->rotatePart("gaster", rotate);

    if(HASWINGS)
    {
        for(int i = 0; i < this->m_wings/2; ++i)
        {
            this->rotatePart("wingLeft"+std::to_string(i), rotate);
            this->rotatePart("wingRight"+std::to_string(i), rotate);
        }
    }

    if(HASSPOTS)
    {
        for(int i = 0; i < this->m_spots; ++i)
        {
            if(this->connectedToSpotPart[i] != "head")
                this->rotatePart("spot"+std::to_string(i), rotate);
        }
    }

    if(HASPETOILE && HASPOSTPETOILE)
    {
        this->translatePart("thorax", "head", 10, 28);
        if(this->m_petoiles == 1)
        {
            this->translatePart("petoile", "thorax", 10, 28);
            this->translatePart("postPetoile", "petoile", 10, 28);
        }
        else
        {
            int index;
            this->translatePart("petoile", "thorax", 10, 28);
            for(int i = 1; i < this->m_petoiles; ++i)
            {
                if(i == 1)
                    this->translatePart("petoile"+std::to_string(i), "petoile", 10, 28);
                else
                {
                    this->translatePart("petoile"+std::to_string(i), "petoile"+std::to_string(i-1), 10, 28);
                }
                index = i;
            }
            this->translatePart("postPetoile", "petoile"+std::to_string(index), 10, 28);
        }
        this->translatePart("gaster", "postPetoile", 10, 28);
    }
    else if(HASPETOILE && !HASPOSTPETOILE)
    {
        this->translatePart("thorax", "head", 10, 28);
        this->translatePart("petoile", "thorax", 10, 28);
        this->translatePart("gaster", "petoile", 10, 28);
    }
    else if(!HASPETOILE && !HASPOSTPETOILE)
    {
        this->translatePart("thorax", "head", 10, 28);
        this->translatePart("gaster", "thorax", 10, 28);
    }

    if(HASLEGS)
    {
        int max = this->m_legs / 2;
        for(int i = 0; i < max; ++i)
        {
            this->translateHip("legLeft"+std::to_string(i), this->connectedToLegPart[i*2], this->legIndex[i*2].x, this->legIndex[i*2].y);
            this->translateHip("legRight"+std::to_string(i), this->connectedToLegPart[i*2+1], this->legIndex[i*2+1].x, this->legIndex[i*2+1].y);
        }
    }

    if(HASWINGS)
    {
        for(int i = 0; i < this->m_wings/2; ++i)
        {
            this->translatePart("wingLeft"+std::to_string(i), this->connectedToWingPart[i*2], this->wingIndex[i*2].x, this->wingIndex[i*2].y);
            this->translatePart("wingRight"+std::to_string(i), this->connectedToWingPart[i*2+1], this->wingIndex[i*2+1].x, this->wingIndex[i*2+1].y);
        }
    }

    if(this->HASTOPWINGS)
    {
        this->rotatePart("topWingLeft", rotate);
        this->rotatePart("topWingRight", -rotate);
        
        this->translatePart("topWingLeft", this->connectedToTopWingPart[0], this->topWingIndex[0].x, this->topWingIndex[0].y);
        this->translatePart("topWingRight", this->connectedToTopWingPart[1], this->topWingIndex[1].x, this->topWingIndex[1].y);
    }

    if(HASSPOTS)
    {
        for(int i = 0; i < this->m_spots; ++i)
        {
            if(this->connectedToSpotPart[i] != "head")
                this->translatePart("spot"+std::to_string(i), this->connectedToSpotPart[i], this->spotIndex[i].x, this->spotIndex[i].y, this->spotOffsetIndex[i]);
        }
    }

    return;
}

void Transform::bendGaster(const float rotate)
{
    this->rotatePart("gaster", rotate);
    this->translatePart("gaster", "thorax", 10, 28);

    return;
}

void Transform::curlBody(const float rotate)
{
    if(HASPETOILE && HASPOSTPETOILE)
    {
        this->rotatePart("thorax", rotate);
        if(this->m_petoiles == 1)
        {
            this->rotatePart("petoile", rotate*2);
            this->rotatePart("postPetoile", rotate*3);
            this->rotatePart("gaster", rotate*4);
        }
        else
        {
            int t = 0;
            this->rotatePart("petoile", rotate*2);
            for(int i = 1; i < this->m_petoiles; ++i)
            {
                this->rotatePart("petoile"+std::to_string(i), rotate*(2+i));
                t = i;
            }
            ++t;
            this->rotatePart("postPetoile", rotate*t);
            ++t;
            this->rotatePart("gaster", rotate*t);
        }
    }
    else if(HASPETOILE && !HASPOSTPETOILE)
    {
        this->rotatePart("thorax", rotate);
        this->rotatePart("petoile", rotate*2);
        this->rotatePart("gaster", rotate*3);
    }
    else if(!HASPETOILE && !HASPOSTPETOILE)
    {
        this->rotatePart("thorax", rotate);
        this->rotatePart("gaster", rotate*2);
    }

    if(HASWINGS)
    {
        for(int i = 0; i < this->m_wings/2; ++i)
        {
            this->rotatePart("wingLeft"+std::to_string(i), rotate);
            this->rotatePart("wingRight"+std::to_string(i), rotate);
        }
    }

    if(HASSPOTS)
    {
        for(int i = 0; i < this->m_spots; ++i)
        {
            if(this->connectedToSpotPart[i] == "thorax")
                this->rotatePart("spot"+std::to_string(i), rotate);
            else if(this->connectedToSpotPart[i] == "gaster")
                this->rotatePart("spot"+std::to_string(i), rotate*2);
        }
    }

    if(HASPETOILE && HASPOSTPETOILE)
    {
        this->translatePart("thorax", "head", 10, 28);
        if(this->m_petoiles == 1)
        {
            this->translatePart("petoile", "thorax", 10, 28);
            this->translatePart("postPetoile", "petoile", 10, 28);
        }
        else
        {
            int index;
            this->translatePart("petoile", "thorax", 10, 28);
            for(int i = 1; i < this->m_petoiles; ++i)
            {
                if(i == 1)
                    this->translatePart("petoile"+std::to_string(i), "petoile", 10, 28);
                else
                {
                    this->translatePart("petoile"+std::to_string(i), "petoile"+std::to_string(i-1), 10, 28);
                }
                index = i;
            }
            this->translatePart("postPetoile", "petoile"+std::to_string(index), 10, 28);
        }
        this->translatePart("gaster", "postPetoile", 10, 28);
    }
    else if(HASPETOILE && !HASPOSTPETOILE)
    {
        this->translatePart("thorax", "head", 10, 28);
        this->translatePart("petoile", "thorax", 10, 28);
        this->translatePart("gaster", "petoile", 10, 28);
    }
    else if(!HASPETOILE && !HASPOSTPETOILE)
    {
        this->translatePart("thorax", "head", 10, 28);
        this->translatePart("gaster", "thorax", 10, 28);
    }

    if(HASLEGS)
    {
        int max = this->m_legs / 2;
        for(int i = 0; i < max; ++i)
        {
            this->translateHip("legLeft"+std::to_string(i), this->connectedToLegPart[i*2], this->legIndex[i*2].x, this->legIndex[i*2].y);
            this->translateHip("legRight"+std::to_string(i), this->connectedToLegPart[i*2+1], this->legIndex[i*2+1].x, this->legIndex[i*2+1].y);
        }
    }

    if(HASWINGS)
    {
        for(int i = 0; i < this->m_wings/2; ++i)
        {
            this->translatePart("wingLeft"+std::to_string(i), this->connectedToWingPart[i*2], this->wingIndex[i*2].x, this->wingIndex[i*2].y);
            this->translatePart("wingRight"+std::to_string(i), this->connectedToWingPart[i*2+1], this->wingIndex[i*2+1].x, this->wingIndex[i*2+1].y);
        }
    }

    if(this->HASTOPWINGS)
    {
        this->rotatePart("topWingLeft", rotate);
        this->rotatePart("topWingRight", -rotate);
        
        this->translatePart("topWingLeft", this->connectedToTopWingPart[0], this->topWingIndex[0].x, this->topWingIndex[0].y);
        this->translatePart("topWingRight", this->connectedToTopWingPart[1], this->topWingIndex[1].x, this->topWingIndex[1].y);
    }

    if(HASSPOTS)
    {
        for(int i = 0; i < this->m_spots; ++i)
        {
            if(this->connectedToSpotPart[i] != "head")
                this->translatePart("spot"+std::to_string(i), this->connectedToSpotPart[i], this->spotIndex[i].x, this->spotIndex[i].y, this->spotOffsetIndex[i]);
        }
    }

    return;
}

void Transform::step(int step, const float multiply)
{
    if(step < 3)
        for(int i = 0; i < this->m_legs/2; ++i)
        {
            if((i % 2) == 0)
            {
                this->moveShin("legLeft"+std::to_string(i), 6.0f * multiply);
                this->moveShin("legRight"+std::to_string(i), -6.0f * multiply);
                if(i == (this->m_legs/2-1))
                {
                    if(this->m_type == "Dragonfly")
                        this->curlBody(-1.0f);
                    else if(this->HASHEAD)
                        this->bendBody(-2.5f);
                }
            }
            else
            {
                if(i == 3 && this->m_type == "Spider")
                     this->bendGaster(-5.0f);
                else if(i == 3 && this->m_type == "Daddylonglegs")
                    this->wobble(10.0f);
                this->moveShin("legLeft"+std::to_string(i), -6.0f * multiply);
                this->moveShin("legRight"+std::to_string(i), 6.0f * multiply);
            }
        }
    else if(step > 2 && step < 6)
    {
        for(int i = 0; i < this->m_legs/2; ++i)
        {
            if((i % 2) == 0)
            {
                this->moveShin("legLeft"+std::to_string(i), -6.0f * multiply);
                this->moveShin("legRight"+std::to_string(i), 6.0f * multiply);
                if(i == (this->m_legs/2-1))
                {
                    if(this->m_type == "Dragonfly")
                        this->curlBody(1.0f);
                    else if(this->HASHEAD)
                        this->bendBody(2.5f);
                }
            }
            else
            {
                if(i == 3 && this->m_type == "Spider")
                     this->bendGaster(5.0f);
                else if(i == 3 && this->m_type == "Daddylonglegs")
                    this->wobble(10.0f);
                this->moveShin("legLeft"+std::to_string(i), 6.0f * multiply);
                this->moveShin("legRight"+std::to_string(i), -6.0f * multiply);
            }
        }
    }

    return;
}

void Transform::stop(const float multiply)
{
    this->stopWalk(multiply);
    this->HASLEGVISIBILITY = true;
    if(this->down) 
    {
        this->wingsUp(2.0f);
        this->down = false;
    }
    if(!straight) 
    {
        (bent) ? this->curlBody(7.5) : this->curlBody(-7.5);
        straight = true;
    }

    return;
}

void Transform::turnHead(const float rotate)
{
    this->rotatePart("head", rotate);
    if(HASANTENNAE)
    {
        this->rotatePart("antennaeLeft", rotate);
        this->rotatePart("antennaeRight", rotate);
    }
    if(HASMANDIBLES)
    {
        this->rotatePart("mandibleLeft", rotate);
        this->rotatePart("mandibleRight", rotate);
    }
    if(HASSPOTS)
    {
        for(int i = 0; i < this->m_spots; ++i)
        {
            if(this->connectedToSpotPart[i] == "head")
                this->rotatePart("spot"+std::to_string(i), rotate);
        }
    }
    for(int i = 0; i < this->m_eyes/2; ++i)
    {
        this->rotatePart("eyeLeft"+std::to_string(i), rotate);
        this->rotatePart("eyeRight"+std::to_string(i), rotate);
    }
    this->translatePart("head", "thorax", 28, 10);
    for(int i = 0; i < this->m_eyes; i += 2)
    {
        this->translatePart("eyeRight"+std::to_string(i/2), this->connectedToEyePart[i], this->eyeIndex[i].x, this->eyeIndex[i].y);
        this->translatePart("eyeLeft"+std::to_string(i/2), this->connectedToEyePart[i+1], this->eyeIndex[i+1].x, this->eyeIndex[i+1].y);
    }

    if(HASANTENNAE)
    {
        this->translatePart("antennaeLeft", "head", this->antennaeIndex[0].x, this->antennaeIndex[0].y);
        this->translatePart("antennaeRight", "head", this->antennaeIndex[1].x , this->antennaeIndex[1].y);
    }
    if(HASMANDIBLES)
    {
        this->translatePart("mandibleLeft", this->connectedToMandible[0], this->mandibleIndex[0].x, this->mandibleIndex[0].y);
        this->translatePart("mandibleRight", this->connectedToMandible[1], this->mandibleIndex[1].x, this->mandibleIndex[1].y);
    }
    if(HASSPOTS)
    {
        for(int i = 0; i < this->m_spots; ++i)
        {
            if(this->connectedToSpotPart[i] == "head")
                this->translatePart("spot"+std::to_string(i), this->connectedToSpotPart[i], this->spotIndex[i].x ,this->spotIndex[i].y);
        }
    }


    return;
}

void Transform::walk(const float multiply)
{
    if(!HASLEGS) return;

    if(this->counterWalking == -1)
    {
        this->startWalk(multiply);
        ++this->counterWalking;
        return;
    }
    this->step(this->counterWalking, multiply);
    (this->counterWalking == 5) ? this->counterWalking = 0 : ++this->counterWalking;

    return;
}

void Transform::wiggle()
{
    if(straight)
    {
        (bent) ? this->curlBody(7.5) : this->curlBody(-7.5);
        bent = (bent) ? false : true;
        straight = false;
    }
    else
    {
        (bent) ? this->curlBody(7.5) : this->curlBody(-7.5);
        straight = true;
    }
    return;
}

void Transform::wingsDown(const float size)
{
    for(int i = 0; i < this->m_wings/2; ++i)
    {
        this->scaleYpart("wingLeft"+std::to_string(i), size);
        this->scaleYpart("wingRight"+std::to_string(i), size);
    }
    int id = 1;
    for(int i = 0; i < this->m_wings/2; ++i)
    {
        this->translatePart("wingLeft"+std::to_string(i), this->connectedToWingPart[i*2], this->wingIndex[i*2].x-id, this->wingIndex[i*2].y);
        this->translatePart("wingRight"+std::to_string(i), this->connectedToWingPart[i*2+1], this->wingIndex[i*2+1].x+id, this->wingIndex[i*2+1].y);
    }
    return;
}

void Transform::wingsFlap()
{
    (this->down) ? this->wingsUp(2.0f) : this->wingsDown(0.5f);
    this->down = (this->down) ? false : true;
    this->HASLEGVISIBILITY = false;
}

void Transform::wingsFold(const float rotate)
{
    for(int i = 0; i < this->m_wings/2; ++i)
    {
        this->rotatePart("wingLeft"+std::to_string(i), -rotate);
        this->rotatePart("wingRight"+std::to_string(i), rotate);
    }
    for(int i = 0; i < this->m_wings/2; ++i)
    {
        this->translatePart("wingLeft"+std::to_string(i), this->connectedToWingPart[i*2], this->wingIndex[i*2].x, this->wingIndex[i*2].y);
        this->translatePart("wingRight"+std::to_string(i), this->connectedToWingPart[i*2+1], this->wingIndex[i*2+1].x, this->wingIndex[i*2+1].y);
    }
    if(this->HASTOPWINGS)
    {
        float rotateMinus = rotate + 45.0f;
        this->rotatePart("topWingLeft", -rotateMinus);
        this->rotatePart("topWingRight", rotateMinus);
        
        this->translatePart("topWingLeft", this->connectedToTopWingPart[0], this->topWingIndex[0].x, this->topWingIndex[0].y);
        this->translatePart("topWingRight", this->connectedToTopWingPart[1], this->topWingIndex[1].x, this->topWingIndex[1].y);
        this->HASWINGVISIBILITY = false;
    }
    if(HASSPOTS)
    {
        for(int i = 0; i < this->m_spots; ++i)
        {
            if(this->connectedToSpotPart[i] != "head" && this->connectedToSpotPart[i] != "gaster" && this->connectedToSpotPart[i] != "thorax")
                this->translatePart("spot"+std::to_string(i), this->connectedToSpotPart[i], this->spotIndex[i].x ,this->spotIndex[i].y, this->spotOffsetIndex[i]);
        }
    }

    return;
}

void Transform::wingsUnfold(const float rotate)
{
    for(int i = 0; i < this->m_wings/2; ++i)
    {
        this->rotatePart("wingLeft"+std::to_string(i), rotate);
        this->rotatePart("wingRight"+std::to_string(i), -rotate);
    }
    for(int i = 0; i < this->m_wings/2; ++i)
    {
        this->translatePart("wingLeft"+std::to_string(i), this->connectedToWingPart[i*2], this->wingIndex[i*2].x, this->wingIndex[i*2].y);
        this->translatePart("wingRight"+std::to_string(i), this->connectedToWingPart[i*2+1], this->wingIndex[i*2+1].x, this->wingIndex[i*2+1].y);
    }
    if(this->HASTOPWINGS)
    {
        float rotateMinus = rotate + 45.0f;
        this->rotatePart("topWingLeft", rotateMinus);
        this->rotatePart("topWingRight", -rotateMinus);
        
        this->translatePart("topWingLeft", this->connectedToTopWingPart[0], this->topWingIndex[0].x, this->topWingIndex[0].y);
        this->translatePart("topWingRight", this->connectedToTopWingPart[1], this->topWingIndex[1].x, this->topWingIndex[1].y);
        this->HASWINGVISIBILITY = true;
    }
    if(HASSPOTS)
    {
        for(int i = 0; i < this->m_spots; ++i)
        {
            if(this->connectedToSpotPart[i] != "head" && this->connectedToSpotPart[i] != "gaster" && this->connectedToSpotPart[i] != "thorax")
                this->translatePart("spot"+std::to_string(i), this->connectedToSpotPart[i], this->spotIndex[i].x, this->spotIndex[i].y, sf::Vector2f(-this->spotOffsetIndex[i].x, -this->spotOffsetIndex[i].y));
        }
    }

    return;
}

void Transform::wingsUp(const float size)
{
    for(int i = 0; i < this->m_wings/2; ++i)
    {
        this->scaleYpart("wingLeft"+std::to_string(i), size);
        this->scaleYpart("wingRight"+std::to_string(i), size);
    }
    for(int i = 0; i < this->m_wings/2; ++i)
    {
        this->translatePart("wingLeft"+std::to_string(i), this->connectedToWingPart[i*2], this->wingIndex[i*2].x, this->wingIndex[i*2].y);
        this->translatePart("wingRight"+std::to_string(i), this->connectedToWingPart[i*2+1], this->wingIndex[i*2+1].x, this->wingIndex[i*2+1].y);
    }
    return;
}

void Transform::wobble(const float size)
{
    if(this->mid)
    {
        (this->left) ? this->wobbleRight(size) : this->wobbleLeft(size);
        this->left = (this->left) ? false : true;
        this->mid = false;
    }
    else
    {
        (this->left) ? this->wobbleRight(size) : this->wobbleLeft(size);
        this->mid = true;
    }

    return;
}

void Transform::wobbleLeft(const float size)
{
    this->translatePart("thorax", "thorax", 1, 1, sf::Vector2f(0,-size));
    this->translatePart("gaster","thorax", 10, 28);
    for(int i = 0; i < this->m_eyes/2; ++ i)
    {
        this->translatePart("eyeLeft"+std::to_string(i), "thorax", this->eyeIndex[i*2].x, this->eyeIndex[i*2].y, this->eyeOffsetIndex[i*2]);
        this->translatePart("eyeRight"+std::to_string(i), "thorax", this->eyeIndex[i*2+1].x, this->eyeIndex[i*2+1].y, this->eyeOffsetIndex[i*2+1]);
    }
    if(HASLEGS)
    {
        int max = this->m_legs / 2;
        for(int i = 0; i < max; ++i)
        {
            this->translateHip("legLeft"+std::to_string(i), this->connectedToLegPart[i*2], this->legIndex[i*2].x, this->legIndex[i*2].y);
            this->translateHip("legRight"+std::to_string(i), this->connectedToLegPart[i*2+1], this->legIndex[i*2+1].x, this->legIndex[i*2+1].y);
        }
    }

    return;
}

void Transform::wobbleRight(const float size)
{
    this->translatePart("thorax", "thorax", 1, 1, sf::Vector2f(0,size));
    this->translatePart("gaster","thorax", 10, 28);
    for(int i = 0; i < this->m_eyes/2; ++ i)
    {
        this->translatePart("eyeLeft"+std::to_string(i), "thorax", this->eyeIndex[i*2].x, this->eyeIndex[i*2].y, this->eyeOffsetIndex[i*2]);
        this->translatePart("eyeRight"+std::to_string(i), "thorax", this->eyeIndex[i*2+1].x, this->eyeIndex[i*2+1].y, this->eyeOffsetIndex[i*2+1]);
    }
    if(HASLEGS)
    {
        int max = this->m_legs / 2;
        for(int i = 0; i < max; ++i)
        {
            this->translateHip("legLeft"+std::to_string(i), this->connectedToLegPart[i*2], this->legIndex[i*2].x, this->legIndex[i*2].y);
            this->translateHip("legRight"+std::to_string(i), this->connectedToLegPart[i*2+1], this->legIndex[i*2+1].x, this->legIndex[i*2+1].y);
        }
    }

    return;
}

Transform::Transform(std::string type) : Entity(),
m_type(type),
spotsOnGaster(0),
spotsOnThorax(0),
spotsOnWings(0),
counterWalking(-1),
spotcounter(0),
straight(true),
mid(true),
left(false),
down(false),
bent(false)
{
}
/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/
/*                                                            DEFORMATIONS
/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/
void Transform::adjustWings(const std::string type, const std::string part, const float size)
{
    std::string::size_type left = part.find("Left");
    if(left != std::string::npos)
    {
        if(type == "Fly")
        {
            this->extrudeBottom(part, sf::Vector2f(1,size));
            this->extrudeRightBottom(part, sf::Vector2f(size, 0));
            this->extrudeLeftBottom(part, sf::Vector2f(-size, 0));
            this->extrudeTop(part, sf::Vector2f(1,-1));
            for(std::size_t i = 11; i < 19; ++i)
                this->translateToPointX(part, 10, i);
        }
        else if(this->m_type == "Dragonfly")
        {
            this->extrudeBottom(part, sf::Vector2f(0,size));
            this->extrudeTop(part, sf::Vector2f(1,-1));
            this->extrudeRightBottom(part, sf::Vector2f(5,15));
        }
        else
        {
            this->extrudeBottom(part, sf::Vector2f(0,size));
        }
    }

    std::string::size_type right = part.find("Right");
    if(right != std::string::npos)
    {
        if(type == "Fly")
        {
            this->extrudeTop(part, sf::Vector2f(1,-size));
            this->extrudeRightTop(part, sf::Vector2f(size, 0));
            this->extrudeLeftTop(part, sf::Vector2f(-size, 0));
            this->extrudeBottom(part, sf::Vector2f(1,1));
            for(std::size_t i = 2; i < 10; ++i)
                this->translateToPointX(part, 10, i);
        }
        else if(this->m_type == "Dragonfly")
        {
            this->extrudeTop(part, sf::Vector2f(0,-size));
            this->extrudeBottom(part, sf::Vector2f(1,1));
            this->extrudeRightTop(part, sf::Vector2f(5,-15));
        }
        else
        {
            this->extrudeTop(part, sf::Vector2f(0,-size));
        }
    }

    return;
}

void Transform::dimpleLeft(const std::string part, const float size)
{
    sf::Transform tl;
    tl.translate(sf::Vector2f(size,0));
    sf::Transform tm = tl;
    for(std::size_t i = 24; i < 33; ++i)
        this->m_entity.at(part)[i].position = tm.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 25; i < 32; ++i)
        this->m_entity.at(part)[i].position = tm.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 26; i < 31; ++i)
        this->m_entity.at(part)[i].position = tm.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 27; i < 30; ++i)
        this->m_entity.at(part)[i].position = tm.transformPoint(this->m_entity.at(part)[i].position);

    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
    for(std::size_t i = 46; i < 64; ++i)
        this->m_entity.at(gotPart->first)[i].position = tm.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 48; i < 62; ++i)
        this->m_entity.at(gotPart->first)[i].position = tm.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 50; i < 60; ++i)
        this->m_entity.at(gotPart->first)[i].position = tm.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 52; i < 58; ++i)
        this->m_entity.at(gotPart->first)[i].position = tm.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    }

    return;
}

void Transform::dimpleRight(const std::string part, const float size)
{
    sf::Transform tl;
    tl.translate(sf::Vector2f(-size,0));
    sf::Transform tm = tl;
    for(std::size_t i = 6; i < 15; ++i)
        this->m_entity.at(part)[i].position = tm.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 7; i < 14; ++i)
        this->m_entity.at(part)[i].position = tm.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 8; i < 13; ++i)
        this->m_entity.at(part)[i].position = tm.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 9; i < 12; ++i)
        this->m_entity.at(part)[i].position = tm.transformPoint(this->m_entity.at(part)[i].position);

    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
        for(std::size_t i = 10; i < 30; ++i)
            this->m_entity.at(gotPart->first)[i].position = tm.transformPoint(this->m_entity.at(gotPart->first)[i].position);
        for(std::size_t i = 12; i < 28; ++i)
            this->m_entity.at(gotPart->first)[i].position = tm.transformPoint(this->m_entity.at(gotPart->first)[i].position);
        for(std::size_t i = 14; i < 26; ++i)
            this->m_entity.at(gotPart->first)[i].position = tm.transformPoint(this->m_entity.at(gotPart->first)[i].position);
        for(std::size_t i = 16; i < 24; ++i)
            this->m_entity.at(gotPart->first)[i].position = tm.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    }

    return;
}

void Transform::extrudeBottom(const std::string part, const sf::Vector2f size)
{
    sf::Transform transpart;
    transpart.translate(size);
    sf::Transform transform = transpart;
    for(std::size_t i = 11; i < 28; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 12; i < 27; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 13; i < 26; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 14; i < 25; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 15; i < 24; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 16; i < 23; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 17; i < 22; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 18; i < 21; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    this->m_entity.at(part)[19].position = transform.transformPoint(this->m_entity.at(part)[19].position);

    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
    for(std::size_t i = 20; i < 54; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 22; i < 52; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 24; i < 50; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 26; i < 48; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 28; i < 46; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 30; i < 44; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 32; i < 42; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 34; i < 40; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 36; i < 38; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    }

    return;
}

void Transform::extrudeLeft(const std::string part, const sf::Vector2f size)
{
    sf::Transform transpart;
    transpart.translate(size);
    sf::Transform transform = transpart;
    for(std::size_t i = 20; i < 37; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 21; i < 36; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 22; i < 35; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 23; i < 34; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 24; i < 33; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 25; i < 32; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 26; i < 31; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 27; i < 30; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    this->m_entity.at(part)[28].position = transform.transformPoint(this->m_entity.at(part)[28].position);
    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
    for(std::size_t i = 38; i < 72; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 40; i < 70; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 42; i < 68; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 44; i < 66; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 46; i < 64; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 48; i < 62; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
     for(std::size_t i = 50; i < 60; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 52; i < 58; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 54; i < 56; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);     
    }

    return;
}

void Transform::extrudeLeftBottom(const std::string part, const sf::Vector2f size)
{
    for(std::size_t i = 19; i < 28; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 20; i < 27; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 21; i < 26; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 22; i < 25; ++i)
        this->translatePartPoint(part, i, size);
    return;
}

void Transform::extrudeLeftTop(const std::string part, const sf::Vector2f size)
{
    for(std::size_t i = 29; i < 38; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 30; i < 37; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 31; i < 36; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 32; i < 35; ++i)
        this->translatePartPoint(part, i, size);
    this->translatePartPoint(part, 1, size);
    return;
}

void Transform::extrudeRight(const std::string part, const sf::Vector2f size)
{
    sf::Transform transpart;
    transpart.translate(size);
    sf::Transform transform = transpart;

    for(std::size_t i = 2; i < 19; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 3; i < 18; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 4; i < 17; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 5; i < 16; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 6; i < 15; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 7; i < 14; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 8; i < 13; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    if(part == "head") goto next;
    for(std::size_t i = 9; i < 12; ++i)
        this->m_entity.at(part)[i].position = transform.transformPoint(this->m_entity.at(part)[i].position);
    if(this->m_type == "Spider") goto next;
    this->m_entity.at(part)[10].position = transform.transformPoint(this->m_entity.at(part)[10].position);
next:
    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
    for(std::size_t i = 2; i < 36; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 4; i < 34; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 6; i < 32; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 8; i < 30; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 10; i < 28; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 12; i < 26; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 14; i < 24; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    if(part == "head") return;
    for(std::size_t i = 16; i < 26; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    if(this->m_type == "Spider") return;
    for(std::size_t i = 18; i < 24; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 20; i < 22; ++i)
        this->m_entity.at(gotPart->first)[i].position = transform.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    }

    return;
}

void Transform::extrudeRightBottom(const std::string part, const sf::Vector2f size)
{
    for(std::size_t i = 11; i < 20; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 12; i < 19; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 13; i < 18; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 14; i < 17; ++i)
        this->translatePartPoint(part, i, size);
    return;
}

void Transform::extrudeRightTop(const std::string part, const sf::Vector2f size)
{
    for(std::size_t i = 1; i < 10; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 2; i < 9; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 3; i < 8; ++i)
        this->translatePartPoint(part, i, size);
    for(std::size_t i = 4; i < 7; ++i)
        this->translatePartPoint(part, i, size);
    this->translatePartPoint(part, 37, size);
    return;
}

void Transform::extrudeTop(const std::string part, const sf::Vector2f size)
{
    sf::Transform tl;
    tl.translate(size);
    sf::Transform tftl = tl;
    for(std::size_t i = 29; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 1; i < 10; ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 30; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 1; i < 9; ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 31; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 1; i < 8; ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 32; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 1; i < 7; ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 33; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 1; i < 6; ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 34; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 1; i < 5; ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 35; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 1; i < 4; ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 36; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    for(std::size_t i = 1; i < 3; ++i)
        this->m_entity.at(part)[i].position = tftl.transformPoint(this->m_entity.at(part)[i].position);
    this->m_entity.at(part)[37].position = tftl.transformPoint(this->m_entity.at(part)[37].position);
    this->m_entity.at(part)[1].position = tftl.transformPoint(this->m_entity.at(part)[1].position);

    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
    for(std::size_t i = 56; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 0; i < 18; ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 58; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 0; i < 16; ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 60; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 0; i < 14; ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 62; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 0; i < 12; ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 64; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 0; i < 10; ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 66; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 0; i < 8; ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 68; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 0; i < 6; ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 70; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 0; i < 4; ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 72; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    for(std::size_t i = 0; i < 2; ++i)
        this->m_entity.at(gotPart->first)[i].position = tftl.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    }

    return;
}

void Transform::translateToPointX(const std::string part, const std::size_t indexTo, const std::size_t indexFrom)
{
    sf::Transform tl;
    tl.translate(sf::Vector2f(this->m_entity.at(part)[indexTo].position.x - this->m_entity.at(part)[indexFrom].position.x, 0));
    sf::Transform trf = tl;
    this->m_entity.at(part)[indexFrom].position = trf.transformPoint(this->m_entity.at(part)[indexFrom].position);
    return;
}

void Transform::moveLeg(const std::string part, const float size)
{
    translateLeg(part, sf::Vector2f(size, 0));

    return;
}

void Transform::moveShin(const std::string part, const float size)
{
    translateShin(part, sf::Vector2f(size, 0));

    return;
}

/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/
/*                                                        ROTATION
/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/

void Transform::rotatePart(const std::string part, const float rotate)
{
    sf::Transform rot;
    rot.rotate(rotate);
    sf::Transform tfr = rot;
    for(std::size_t i = 0; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = tfr.transformPoint(this->m_entity.at(part)[i].position);

    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
        for(std::size_t i = 0; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].position = tfr.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    }
    return;
}

/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/
/*                                                        SCALING
/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/

void Transform::scalePart(const std::string part, const sf::Vector2f scale)
{
    sf::Transform sc;
    sc.scale(scale);
    sf::Transform trf = sc;
    for(std::size_t i = 0; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = trf.transformPoint(this->m_entity.at(part)[i].position);

    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
        for(std::size_t i = 0; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].position = trf.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    }
    return;
}

void Transform::scaleXpart(const std::string part, const float scale)
{
    sf::Transform sc;
    sc.scale(sf::Vector2f(scale, 1.0f));
    sf::Transform trf = sc;
    for(std::size_t i = 0; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = trf.transformPoint(this->m_entity.at(part)[i].position);

    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
        for(std::size_t i = 0; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].position = trf.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    }
    return;
}

void Transform::scaleYpart(const std::string part, const float scale)
{
    sf::Transform sc;
    sc.scale(sf::Vector2f(1.0f, scale));
    sf::Transform trf = sc;
    for(std::size_t i = 0; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = trf.transformPoint(this->m_entity.at(part)[i].position);

    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
        for(std::size_t i = 0; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].position = trf.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    }
    return;
}

/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/
/*                                                        TRANSLATIONS
/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/

//  called once in intial setup. !!! DON'T USE ANYWHERE ELSE !!!
void Transform::translateConnected(const std::string part, const std::string body, const int indexpart, const int indexbody, sf::Vector2f offset)
{
    //safe guard against reuse after setup
    if(this->INITIALIZED) return;

    sf::Transform trn;
    trn.translate(this->m_entity.at(body)[indexbody].position - this->m_entity.at(part)[indexpart].position + offset);
    sf::Transform tft = trn;
    for(std::size_t i = 0; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = tft.transformPoint(this->m_entity.at(part)[i].position);

    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
        for(std::size_t i = 0; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].position = tft.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    }

    // found? if so lets store these indexes  below...
    std::size_t isEye = part.find("eye");
    if(isEye != std::string::npos)
    {
        this->connectedToEyePart.push_back(body);
        this->eyeIndex.push_back(sf::Vector2i(indexpart,indexbody));
        this->eyeOffsetIndex.push_back(offset);
        ++this->m_eyes;
    }
    std::size_t isLeg = part.find("leg");
    if(isLeg != std::string::npos)
    {
        this->connectedToLegPart.push_back(body);
        this->legIndex.push_back(sf::Vector2i(indexpart,indexbody));
        ++this->m_legs;
    }
    std::size_t isMandible = part.find("mandible");
    if(isMandible != std::string::npos)
    {
        this->connectedToMandible.push_back(body);
        this->mandibleIndex.push_back(sf::Vector2i(indexpart,indexbody));
    }
    std::size_t isPetoile = part.find("petoile");
    if(isPetoile != std::string::npos)
    {
        std::size_t isOutline = part.find("Outline");
        if(isOutline == std::string::npos)
            ++this->m_petoiles;
    }
    std::size_t isSpot = part.find("spot");
    if(isSpot != std::string::npos)
    {
        this->connectedToSpotPart.push_back(body);
        this->spotIndex.push_back(sf::Vector2i(indexpart,indexbody));
        this->spotOffsetIndex.push_back(offset);
        ++this->m_spots;
    }
    std::size_t isTopWing = part.find("topWing");
    if(isTopWing != std::string::npos)
    {
        this->connectedToTopWingPart.push_back(body);
        this->topWingIndex.push_back(sf::Vector2i(indexpart,indexbody));
        ++this->m_topWings;
    }
    std::size_t isWing = part.find("wing");
    if(isWing != std::string::npos)
    {
        this->connectedToWingPart.push_back(body);
        this->wingIndex.push_back(sf::Vector2i(indexpart,indexbody));
        ++this->m_wings;
    }
    std::size_t isAntennae = part.find("antennae");
    if(isAntennae != std::string::npos)
    {
        this->antennaeIndex.push_back(sf::Vector2i(indexpart,indexbody));
    }

    return;
}

void Transform::translatePart(const std::string part, const std::string body, const int indexpart, const int indexbody, sf::Vector2f offset)
{
    sf::Transform trn;
    trn.translate(this->m_entity.at(body)[indexbody].position - this->m_entity.at(part)[indexpart].position + offset);
    sf::Transform tft = trn;
    for(std::size_t i = 0; i < this->m_entity.at(part).getVertexCount(); ++i)
        this->m_entity.at(part)[i].position = tft.transformPoint(this->m_entity.at(part)[i].position);

    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find(part+"Outline");
    if(gotPart != this->m_entity.end())
    {
        for(std::size_t i = 0; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].position = tft.transformPoint(this->m_entity.at(gotPart->first)[i].position);
    }

    return;
}

void Transform::translatePartPoint(const std::string part, const int index, const sf::Vector2f size)
{
    sf::Transform trl;
    trl.translate(size);
    sf::Transform tft = trl;
    this->m_entity.at(part)[index].position = tft.transformPoint(this->m_entity.at(part)[index].position);

    return;
}

/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/
/*                                                                    MOVING
/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/

void Transform::startWalk(const float multiply)
{
    for(int i = 0; i < this->m_legs/2; ++i)
    {
        if((i % 2) == 0)
        {
            if(i ==2 || i == 4)
            {
                this->moveShin("legLeft"+std::to_string(i), -24.0f * multiply);
                if(this->m_type == "Dragonfly")
                    this->curlBody(1.0f);
                else if(this->m_type == "Spider")
                    this->bendGaster(5.0f);
                else if(this->m_type == "Daddylonglegs")
                    this->wobble(10.0f);
                else if(this->HASHEAD)
                    this->bendBody(2.5f);
             }
            else
            {
                this->moveShin("legRight"+std::to_string(i), 18.0f * multiply);
            }
        }
        else
        {
            if(i == 3)
            {
                this->moveShin("legLeft"+std::to_string(i), -9.0f * multiply);
                this->moveShin("legRight"+std::to_string(i), -27.0f * multiply);
            }
            else
            {
                this->moveShin("legLeft"+std::to_string(i), 9.0f * multiply);
                this->moveShin("legRight"+std::to_string(i), -9.0f * multiply);
            }
        }
    }

    return;
}

void Transform::stopWalk(const float multiply)
{
    if(this->counterWalking != -1)
    {
        while (this->counterWalking <= 5)
        {
            step(this->counterWalking, multiply);
            ++this->counterWalking;
        }

        this->counterWalking = -1;
    }
    else return;

    for(int i = 0; i < this->m_legs/2; ++i)
    {
        if((i % 2) == 0)
        {
            if(i ==2 || i == 4)
            {
                this->moveShin("legLeft"+std::to_string(i), 24.0f * multiply);
                if(this->m_type == "Dragonfly")
                    this->curlBody(-1.0f);
                else if(this->m_type == "Spider")
                    this->bendGaster(-5.0f);
                else if(this->m_type == "Daddylonglegs")
                    this->wobble(10.0f);
                else if(this->HASHEAD)
                    this->bendBody(-2.5f);
             }
            else
            {
                this->moveShin("legRight"+std::to_string(i), -18.0f * multiply);
            }
        }
        else
        {
            if(i == 3)
            {
                this->moveShin("legLeft"+std::to_string(i), 9.0f * multiply);
                this->moveShin("legRight"+std::to_string(i), 27.0f * multiply);
            }
            else
            {
                this->moveShin("legLeft"+std::to_string(i), -9.0f * multiply);
                this->moveShin("legRight"+std::to_string(i), 9.0f * multiply);
            }
        }
    }

    return;
}

void Transform::translateFoot(const std::string part, const sf::Vector2f size)
{
    this->translatePartPoint(part, 8, size);
    this->translatePartPoint(part, 7, size);
    this->translatePartPoint(part, 6, size);

    return;
}

void Transform::translateHip(const std::string part, const std::string body, const int indexpart, const int indexbody)
{
    sf::Transform trans;
    trans.translate(this->m_entity.at(body)[indexbody].position - this->m_entity.at(part)[indexpart].position);
    sf::Transform trf = trans;
    for(std::size_t i = 0; i < 6; ++i)
        this->m_entity.at(part)[i].position = trf.transformPoint(this->m_entity.at(part)[i].position);

    return;
}

void Transform::translateLeg(const std::string part, const sf::Vector2f size)
{
    this->translatePartPoint(part, 8, size);
    this->translatePartPoint(part, 7, size);
    this->translatePartPoint(part, 6, size);
    this->translatePartPoint(part, 5, size*0.5f);
    this->translatePartPoint(part, 4, size*0.5f);
    this->translatePartPoint(part, 3, size*0.25f);
    this->translatePartPoint(part, 2, size*0.25f);

    return;
}

void Transform::translateLegsFold()
{
    for(int i = 0; i < this->m_legs; ++i)
    {
        if((i % 2) == 0)
            this->translateFoot("legLeft"+std::to_string(i/2), sf::Vector2f(2.5,5));
        else
            this->translateFoot("legRight"+std::to_string(i/2), sf::Vector2f(2.5,-5));
    }
    for(int i = 0; i < this->m_legs; ++i)
    {
        if((i % 2) == 0)
            this->translateShin("legLeft"+std::to_string(i/2), sf::Vector2f(2.5,5));
        else
            this->translateShin("legRight"+std::to_string(i/2), sf::Vector2f(2.5,-5));
    }
    for(int i = 0; i < this->m_legs; ++i)
    {
        if((i % 2) == 0)
            this->translateThigh("legLeft"+std::to_string(i/2), sf::Vector2f(2.5,5));
        else
            this->translateThigh("legRight"+std::to_string(i/2), sf::Vector2f(2.5,-5));
    }

    return;
}

void Transform::translateShin(const std::string part, const sf::Vector2f size)
{
    this->translatePartPoint(part, 8, size);
    this->translatePartPoint(part, 7, size);
    this->translatePartPoint(part, 6, size);
    this->translatePartPoint(part, 5, size*0.5f);
    this->translatePartPoint(part, 4, size*0.5f);

    return;
}

void Transform::translateThigh(const std::string part, const sf::Vector2f size)
{
    this->translatePartPoint(part, 8, size);
    this->translatePartPoint(part, 7, size);
    this->translatePartPoint(part, 6, size);
    this->translatePartPoint(part, 5, size*0.5f);
    this->translatePartPoint(part, 4, size*0.5f);
    this->translatePartPoint(part, 3, size*0.25f);
    this->translatePartPoint(part, 2, size*0.25f);

    return;
}

} // end namespace Insect