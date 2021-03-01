/*****************************************************************************************/
/*  opensource
/*
/*  Header for the base vertices and colors of an Insect.
/*
/* created by Blakrunner
/*****************************************************************************************/
#ifndef __INSECT_ENTITY_CLASS__
#define __INSECT_ENTITY_CLASS__

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <cstring>

namespace Insect
{

class Entity : public sf::Drawable , public sf::Transformable 
{
public:

    void setupColors(std::unordered_map<std::string, sf::Color> colors);

protected:

    Entity();
    virtual ~Entity();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void update(const std::string part, const sf::Vector2f size);
    void updateAntennae(const sf::Color color, const sf::Vector2f size);
    void updateCenter(const std::string part);
    void updateColors(const std::string type);
    void updateLegs(const int legpair, const sf::Color color, const sf::Vector2f size);
    void updateMandibles(const std::string type, const sf::Color color, const sf::Vector2f size);
    void updateOutline(const std::string part);
    void updateQuarterCircle(const std::string part, const sf::Vector2f size);
    void updateSemiCircle(const std::string part, const sf::Vector2f size);

protected:

    bool HASANTENNAE;
    bool HASEIGHTLEGS;
    bool HASEYES;
    bool HASHEAD;
    bool HASLEGS;
    bool HASLEGVISIBILITY;
    bool HASMANDIBLES;
    bool HASPETOILE;
    bool HASPOSTPETOILE;
    bool HASSPOTS;
    bool HASSPOTSONGASTER;
    bool HASSPOTSONTHORAX;
    bool HASSPOTSONWINGS;
    bool HASWINGS;
    bool HASTWOSETSWINGS;
    bool HASTHREESETSWINGS;
    bool HASTOPWINGS;
    bool HASWINGVISIBILITY;
    bool HASVISIBILITY;
    bool INITIALIZED;

protected:

    int m_eyes; // total of eyes
    int m_legs;  // total of legs
    int m_petoiles; // total if more than 1
    int m_spots; // total of spots
    int m_topWings; // Only one set but need index positions
    int m_wings; // total of wings

    float m_outlineThickness;

    sf::Color m_eyeColor;
    sf::Color m_eyeHighlightColor;
    sf::Color m_eyeOutlineColor;
    sf::Color m_fillColor;
    sf::Color m_gasterColor;
    sf::Color m_gasterHighlightColor;
    sf::Color m_gasterOutlineColor;
    sf::Color m_headColor;
    sf::Color m_headHighlightColor;
    sf::Color m_headOutlineColor;
    sf::Color m_highlightColor;
    sf::Color m_outlineColor;
    sf::Color m_petoileColor;
    sf::Color m_petoileHighlightColor;
    sf::Color m_petoileOutlineColor;
    sf::Color m_postPetoileColor;
    sf::Color m_postPetoileHighlightColor;
    sf::Color m_postPetoileOutlineColor;
    sf::Color m_spotColor;
    sf::Color m_spotHighlightColor;
    sf::Color m_spotOutlineColor;
    sf::Color m_thoraxColor;
    sf::Color m_thoraxHighlightColor;
    sf::Color m_thoraxOutlineColor;
    sf::Color m_topWingColor;
    sf::Color m_topWingHighlightColor;
    sf::Color m_topWingOutlineColor;
    sf::Color m_wingColor;
    sf::Color m_wingHighlightColor;
    sf::Color m_wingOutlineColor;

    std::unordered_map<std::string, sf::VertexArray> m_entity;
};

} // end namespace Insect

#endif // __INSECT_ENTITY_CLASS__