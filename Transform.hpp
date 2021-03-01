/*****************************************************************************************/
/*  opensource
/*
/*  Header for the transformations of an Insect.
/*
/* created by Blakrunner
/*****************************************************************************************/
#ifndef __INSECT_TRANSFORM_CLASS__
#define __INSECT_TRANSFORM_CLASS__

#include <SFML/Graphics.hpp>
#include <cstring>
#include <vector>

#include "Entity.hpp"

namespace Insect
{

class Transform : public Entity
{
public:

    void bendBody(const float rotate);
    void bendGaster(const float rotate); // only for spider
    void curlBody(const float rotate); // used for dead carcus and makes good wiggle
    void step(int step, const float multiply);
    void stop(const float multiply);
    void turnHead(const float rotate);
    void walk(const float multiply);
    void wiggle();
    void wingsDown(const float size);
    void wingsFlap();
    void wingsFold(const float rotate);
    void wingsUnfold(const float rotate);
    void wingsUp(const float size);
    void wobble(const float size);
    void wobbleLeft(const float size);
    void wobbleRight(const float size);

    bool mid;
    bool left;

protected:

    Transform(std::string type);
    virtual ~Transform() {}

protected:

    // Rotations
    void rotatePart(const std::string part, const float rotate);

    // Scaling
    void scalePart(const std::string part, const sf::Vector2f scale);
    void scaleXpart(const std::string part, const float scale);
    void scaleYpart(const std::string part, const float scale);

    // Translations
    void translateConnected(const std::string part, const std::string body, const int indexpart, const int indexbody, sf::Vector2f offset = {0.0f,0.0f});  //  called once in intial setup. !!! DON'T USE ANYWHERE ELSE !!!
    void translatePart(const std::string part, const std::string body, const int indexpart, const int indexbody, sf::Vector2f offset = {0.0f,0.0f});
    void translatePartPoint(const std::string part, const int index, const sf::Vector2f size);

    // Deformations
    void adjustWings(const std::string type, const std::string part, const float size);
    void dimpleLeft(const std::string part, const float size);
    void dimpleRight(const std::string part, const float size);
    void extrudeBottom(const std::string part, const sf::Vector2f size);
    void extrudeLeft(const std::string part, const sf::Vector2f size);
    void extrudeLeftBottom(const std::string part, const sf::Vector2f size);
    void extrudeLeftTop(const std::string part, const sf::Vector2f size);
    void extrudeRight(const std::string part, const sf::Vector2f size);
    void extrudeRightBottom(const std::string part, const sf::Vector2f size);
    void extrudeRightTop(const std::string part, const sf::Vector2f size);
    void extrudeTop(const std::string part, const sf::Vector2f size);
    void translateToPointX(const std::string part, const std::size_t indexTo, const std::size_t indexFrom);
    
    // Moves
    void translateFoot(const std::string part, const sf::Vector2f size);
    void translateHip(const std::string part, const std::string body, const int indexpart, const int indexbody); // hold legs to body
    void translateLeg(const std::string part, const sf::Vector2f size);
    void translateLegsFold();
    void translateShin(const std::string part, const sf::Vector2f size);
    void translateThigh(const std::string part, const sf::Vector2f size);
    // translateLeg moves by x, y. but we only want to move x
    void moveLeg(const std::string part, const float size);
    void moveShin(const std::string part, const float size);
    void startWalk(const float multiply);
    void stopWalk(const float multiply);

protected:

    bool straight;
    bool down;
    bool bent;

    int spotsOnHead;
    int spotsOnGaster;
    int spotsOnThorax;
    int spotsOnWings;

    // used for translations
    std::vector<std::string> connectedToEyePart; // required for spider
    std::vector<std::string> connectedToLegPart;
    std::vector<std::string> connectedToMandible; // required only for spider, but handy
    std::vector<std::string> connectedToSpotPart;
    std::vector<std::string> connectedToTopWingPart;
    std::vector<std::string> connectedToWingPart;

    // connected parts vertices index,
    // Vector2i used as x for leg index, y for body part index which is connected
    std::vector<sf::Vector2i> antennaeIndex;
    std::vector<sf::Vector2i> eyeIndex; // required by spider
    std::vector<sf::Vector2f> eyeOffsetIndex; // required by spider
    std::vector<sf::Vector2i> legIndex;
    std::vector<sf::Vector2i> mandibleIndex; // required by spider
    std::vector<sf::Vector2i> spotIndex;
    std::vector<sf::Vector2f> spotOffsetIndex;
    std::vector<sf::Vector2i> topWingIndex;
    std::vector<sf::Vector2i> wingIndex;

    int counterWalking;
    int spotcounter;

    std::string m_type;
};

} // end namespace Insect

#endif  // __INSECT_TRANSFORM_CLASS__