/*****************************************************************************************/
/*  opensource
/*
/*  
/*
/* created by Blakrunner
/*****************************************************************************************/
#include "Entity.hpp"
#include <cmath>

namespace Insect
{

sf::Vector2f getPoint(std::size_t index, std::size_t count, sf::Vector2f radius)
{
    static float pi = 3.141592654f;
    sf::Vector2f returnRadius = sf::Vector2f(radius.x * 0.5f, radius.y  * 0.5f);

    float angle = index * 2 * pi / count - pi / 2;
    float x = std::cos(angle) * radius.x;
    float y = std::sin(angle) * radius.y;

    return sf::Vector2f(radius.x + x, radius.y + y);
}

sf::Vector2f computeNormal(sf::Vector2f p1, sf::Vector2f p2)
{
    sf::Vector2f normal(p1.y - p2.y, p2.x - p1.x);
    float length = std::sqrt(normal.x * normal.x + normal.y * normal.y);
    if (length != 0.f)
        normal /= length;
    return normal;
}

float dotProduct(sf::Vector2f p1, sf::Vector2f p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}

void Entity::setupColors(std::unordered_map<std::string, sf::Color> colors)
{
    std::unordered_map<std::string,sf::Color>::const_iterator gotColor = colors.find("fill");
    if(gotColor != colors.end())
    {
        this->m_fillColor = colors.at(gotColor->first);
        this->m_eyeColor = this->m_fillColor;
        this->m_gasterColor = this->m_fillColor;
        this->m_headColor = this->m_fillColor;
        this->m_petoileColor = this->m_fillColor;
        this->m_postPetoileColor = this->m_fillColor;
        this->m_thoraxColor = this->m_fillColor;
    }

    gotColor = colors.find("highlight");
    if(gotColor != colors.end())
    {
        this->m_highlightColor = colors.at(gotColor->first);
        this->m_eyeHighlightColor = this->m_highlightColor;
        this->m_gasterHighlightColor = this->m_highlightColor;
        this->m_headHighlightColor = this->m_highlightColor;
        this->m_petoileHighlightColor = this->m_highlightColor;
        this->m_postPetoileHighlightColor = this->m_highlightColor;
        this->m_thoraxHighlightColor = this->m_highlightColor;
    }

    gotColor = colors.find("outline");
    if(gotColor != colors.end())
    {
        this->m_outlineColor = colors.at(gotColor->first);
        this->m_eyeOutlineColor = this->m_outlineColor;
        this->m_gasterOutlineColor = this->m_outlineColor;
        this->m_headOutlineColor = this->m_outlineColor;
        this->m_petoileOutlineColor = this->m_outlineColor;
        this->m_postPetoileOutlineColor = this->m_outlineColor;
        this->m_thoraxOutlineColor = this->m_outlineColor;
    }

    gotColor = colors.find("eye");
    if(gotColor != colors.end())
    {
        this->m_eyeColor = gotColor->second;
    }

    gotColor = colors.find("eyeHighlight");
    if(gotColor != colors.end())
    {
        this->m_eyeHighlightColor = gotColor->second;
    }

    gotColor = colors.find("eyeOutline");
    if(gotColor != colors.end())
    {
        this->m_eyeOutlineColor = gotColor->second;
    }

    gotColor = colors.find("gaster");
    if(gotColor != colors.end())
    {
        this->m_gasterColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("gasterHighlight");
    if(gotColor != colors.end())
    {
        this->m_gasterHighlightColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("gasterOutline");
    if(gotColor != colors.end())
    {
        this->m_gasterOutlineColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("head");
    if(gotColor != colors.end())
    {
        this->m_headColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("headHighlight");
    if(gotColor != colors.end())
    {
        this->m_headHighlightColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("headOutline");
    if(gotColor != colors.end())
    {
        this->m_headOutlineColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("petoile");
    if(gotColor != colors.end())
    {
        this->m_petoileColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("petoileHighlight");
    if(gotColor != colors.end())
    {
        this->m_petoileHighlightColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("petoileOutline");
    if(gotColor != colors.end())
    {
        this->m_petoileOutlineColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("postPetoile");
    if(gotColor != colors.end())
    {
        this->m_postPetoileColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("postPetoileHighlight");
    if(gotColor != colors.end())
    {
        this->m_postPetoileHighlightColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("postPetoileOutline");
    if(gotColor != colors.end())
    {
        this->m_postPetoileOutlineColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("spot");
    if(gotColor != colors.end())
    {
        this->m_spotColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("spotHighlight");
    if(gotColor != colors.end())
    {
        this->m_spotHighlightColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("spotOutline");
    if(gotColor != colors.end())
    {
        this->m_spotOutlineColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("thorax");
    if(gotColor != colors.end())
    {
        this->m_thoraxColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("thoraxHighlight");
    if(gotColor != colors.end())
    {
        this->m_thoraxHighlightColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("thoraxOutline");
    if(gotColor != colors.end())
    {
        this->m_thoraxOutlineColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("wing");
    if(gotColor != colors.end())
    {
        this->m_wingColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("wingHighlight");
    if(gotColor != colors.end())
    {
        this->m_wingHighlightColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("wingOutline");
    if(gotColor != colors.end())
    {
        this->m_wingOutlineColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("topWing");
    if(gotColor != colors.end())
    {
        this->m_topWingColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("topWingHighlight");
    if(gotColor != colors.end())
    {
        this->m_topWingHighlightColor = colors.at(gotColor->first);
    }

    gotColor = colors.find("topWingOutline");
    if(gotColor != colors.end())
    {
        this->m_topWingOutlineColor = colors.at(gotColor->first);
    }

    return;
}

Entity::Entity() :
HASANTENNAE(false),
HASEIGHTLEGS(false),
HASHEAD(false),
HASLEGS(false),
HASLEGVISIBILITY(false),
HASMANDIBLES(false),
HASPETOILE(false),
HASPOSTPETOILE(false),
HASSPOTS(false),
HASSPOTSONGASTER(false),
HASSPOTSONTHORAX(false),
HASSPOTSONWINGS(false),
HASWINGS(false),
HASTWOSETSWINGS(false),
HASTHREESETSWINGS(false),
HASTOPWINGS(false),
HASWINGVISIBILITY(false),
HASVISIBILITY(false),
INITIALIZED(false),
m_eyes(0),
m_legs(0),
m_petoiles(0),
m_spots(0),
m_topWings(0),
m_wings(0),
m_outlineThickness(0.5f),
m_eyeColor(15,15,15),
m_eyeHighlightColor(55,55,55),
m_eyeOutlineColor(5,5,5),
m_fillColor(255,255,255),
m_gasterColor(15,15,15),
m_gasterHighlightColor(55,55,55),
m_gasterOutlineColor(5,5,5),
m_headColor(15,15,15),
m_headHighlightColor(55,55,55),
m_headOutlineColor(5,5,5),
m_highlightColor(255,255,255),
m_outlineColor(0,0,0),
m_thoraxColor(15,15,15),
m_thoraxHighlightColor(55,55,55),
m_thoraxOutlineColor(5,5,5),
m_topWingColor(255,255,255,128),
m_topWingHighlightColor(255,255,255),
m_topWingOutlineColor(255,255,255),
m_wingColor(222,222,222,128),
m_wingHighlightColor(255,255,255,128),
m_wingOutlineColor(192,192,192)
{
}

Entity::~Entity()
{
    this->m_entity.clear();
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = NULL;

    if(this->HASLEGS && this->HASLEGVISIBILITY)
    {
        for(int i = 0; i < this->m_legs/2; ++i)
        {
            target.draw(this->m_entity.at("legLeft"+std::to_string(i)), states);
            target.draw(this->m_entity.at("legRight"+std::to_string(i)), states);
        }
    }
    
    if(!this->m_entity.empty())
    {
        for(auto part : this->m_entity)
        {
            std::size_t isWings = part.first.find("wing");
            if(isWings != std::string::npos) continue;
            std::size_t isLegs = part.first.find("leg");
            if(isLegs != std::string::npos) continue;
            std::size_t isSpots = part.first.find("spot");
            if(isSpots != std::string::npos) continue;
            std::size_t isTopwings = part.first.find("topWing");
            if(isTopwings != std::string::npos) continue;

            target.draw(part.second, states);
        }
        if(this->HASEYES)
        {
            for(int i = 0; i < this->m_eyes/2; ++i)
            {
                target.draw(this->m_entity.at("eyeLeft"+std::to_string(i)), states);
                if(this->m_outlineThickness != 0.0f)
                    target.draw(this->m_entity.at("eyeLeft"+std::to_string(i)+"Outline"), states);
                target.draw(this->m_entity.at("eyeRight"+std::to_string(i)), states);
                if(this->m_outlineThickness != 0.0f)
                    target.draw(this->m_entity.at("eyeRight"+std::to_string(i)+"Outline"), states);
            }
        }
    }

    if(this->HASWINGS)
    {
        if(this->HASWINGVISIBILITY)
        {
            for(int i = 0; i < this->m_wings/2; ++i)
            {
                target.draw(this->m_entity.at("wingLeft"+std::to_string(i)), states);
                if(this->m_outlineThickness != 0.0f)
                    target.draw(this->m_entity.at("wingLeft"+std::to_string(i)+"Outline"), states);
                target.draw(this->m_entity.at("wingRight"+std::to_string(i)), states);
                if(this->m_outlineThickness != 0.0f)
                    target.draw(this->m_entity.at("wingRight"+std::to_string(i)+"Outline"), states);
            }
        }
        if(this->HASTOPWINGS)
        {
            target.draw(this->m_entity.at("topWingLeft"), states);
            target.draw(this->m_entity.at("topWingRight"), states);
        }
    }

    if(this->HASSPOTS)
    {
        for(int i = 0; i < this->m_spots;++i)
            target.draw(this->m_entity.at("spot"+std::to_string(i)), states);
    }

    return;
}

void Entity::update(const std::string part, const sf::Vector2f size)
{
    std::size_t count = 36;
    std::size_t index = 1;
    sf::FloatRect bounds;
    sf::VertexArray temp(sf::TriangleFan);

    temp.resize(count + 2);

    for (std::size_t i = 0; i < count; ++i)
    {
        temp[index].position = getPoint(i,count,size);
        ++index;
    }
    temp[index].position = temp[1].position;

    temp[0] = temp[1]; // so that the result of getBounds() is correct
    bounds = temp.getBounds(); 

    // Compute the center and make it the first vertex
    temp[0].position.x = bounds.left + bounds.width / 2;
    temp[0].position.y = bounds.top + bounds.height / 2;

    this->m_entity[part] = temp;

    temp.clear();

    return;
}

void Entity::updateQuarterCircle(const std::string part, const sf::Vector2f size)
{
    std::size_t count = 36;
    std::size_t index = 1;
    sf::FloatRect bounds;
    sf::VertexArray temp(sf::TriangleFan);

    temp.resize(13);

    std::size_t isLeft = part.find("Left");
    if(isLeft != std::string::npos)
    {
        for(std::size_t i = 27; i < count; ++i)
        {
            temp[index].position = getPoint(i,count,size);
            ++index;
        }
        for(std::size_t i = 0; i < 2; ++i)
        {
            temp[index].position = getPoint(i,count,size);
            ++index;
        }
        temp[index].position = sf::Vector2f(temp[index-2].position.x, temp[1].position.y);
        ++index;
        temp[index].position = temp[1].position;
        temp[0].position = sf::Vector2f(temp[10].position.x, temp[1].position.y);
    }

    std::size_t isRight = part.find("Right");
    if(isRight != std::string::npos)
    {
        for(std::size_t i = 17; i < 28; ++i)
        {
            temp[index].position = getPoint(i,count,size);
            ++index;
        }
        temp[index].position = sf::Vector2f(temp[2].position.x, temp[11].position.y);
        ++index;
        temp[index].position = temp[1].position;
        temp[0].position = sf::Vector2f(temp[2].position.x, temp[11].position.y);
    }

    this->m_entity[part] = temp;

    temp.clear();

    return;
}

void Entity::updateSemiCircle(const std::string part, const sf::Vector2f size)
{
    std::size_t count = 36;
    std::size_t index = 1;
    sf::FloatRect bounds;
    sf::VertexArray temp(sf::TriangleFan);

    temp.resize(20);

    std::size_t isLeft = part.find("Left");
    if(isLeft != std::string::npos)
    {
        for(std::size_t i = 18; i < count; ++i)
        {
            temp[index].position = getPoint(i,count,size);
            ++index;
        }
        temp[index].position = temp[1].position;
        temp[0].position = sf::Vector2f(temp[1].position.x, temp[10].position.y);
    }

    std::size_t isRight = part.find("Right");
    if(isRight != std::string::npos)
    {
        for(std::size_t i = 0; i < 19; ++i)
        {
            temp[index].position = getPoint(i,count,size);
            ++index;
        }
        temp[index].position = temp[1].position;
        temp[0].position = sf::Vector2f(temp[1].position.x, temp[10].position.y);
    }

    this->m_entity[part] = temp;

    temp.clear();

    return;
}

void Entity::updateOutline(const std::string part)
{
    std::string outPart = part + "Outline";
    std::size_t count = this->m_entity.at(part).getVertexCount() - 2;

    std::unordered_map<std::string, sf::VertexArray>::const_iterator gotPart = this->m_entity.find(outPart);
    if(gotPart != this->m_entity.end())
        this->m_entity.at(outPart).clear();

    sf::VertexArray temp(sf::TriangleStrip);
    temp.resize((count + 1) * 2);

    for (std::size_t i = 0; i < count; ++i)
    {
        std::size_t index = i + 1;
        // Get the two segments shared by the current point
        sf::Vector2f p0 = (i == 0) ? this->m_entity.at(part)[count].position : this->m_entity.at(part)[index - 1].position;
        sf::Vector2f p1 = this->m_entity.at(part)[index].position;
        sf::Vector2f p2 = this->m_entity.at(part)[index + 1].position;
        // Compute their normal
        sf::Vector2f n1 = computeNormal(p0, p1);
        sf::Vector2f n2 = computeNormal(p1, p2);
        // Make sure that the normals point towards the outside of the shape
        // (this depends on the order in which the points were defined)
        if (dotProduct(n1, this->m_entity.at(part)[0].position - p1) > 0)
            n1 = -n1;
        if (dotProduct(n2, this->m_entity.at(part)[0].position - p1) > 0)
            n2 = -n2;
        // Combine them to get the extrusion direction
        float factor = 1.f + (n1.x * n2.x + n1.y * n2.y);
        sf::Vector2f normal = (n1 + n2) / factor;
        // Update the outline points
        temp[i * 2 + 0].position = p1;
        temp[i * 2 + 1].position = p1 + normal * Entity::m_outlineThickness;
    }
    // Duplicate the first point at the end, to close the outline
    temp[count * 2 + 0].position = temp[0].position;
    temp[count * 2 + 1].position = temp[1].position;

    this->m_entity[outPart] = temp;

    temp.clear();

    return;
}

void Entity::updateAntennae(const sf::Color color, const sf::Vector2f size)
{
    float ax = size.x * 0.5f;
    float ay = size.y * 0.5f;
    float sp = ay / 5;

    this->m_entity["antennaeRight"] = sf::VertexArray(sf::TriangleStrip);
    this->m_entity["antennaeLeft"] = sf::VertexArray(sf::TriangleStrip);

    this->m_entity.at("antennaeRight").append(sf::Vertex(sf::Vector2f(0,ay), color));
    this->m_entity.at("antennaeRight").append(sf::Vertex(sf::Vector2f(sp,ay), color));
    this->m_entity.at("antennaeRight").append(sf::Vertex(sf::Vector2f(0,ay*2), color));
    this->m_entity.at("antennaeRight").append(sf::Vertex(sf::Vector2f(sp,ay*2), color));
    this->m_entity.at("antennaeRight").append(sf::Vertex(sf::Vector2f(ax+sp,ay*3+sp), color));
    this->m_entity.at("antennaeRight").append(sf::Vertex(sf::Vector2f(ax+sp,ay*3), color));
    this->m_entity.at("antennaeRight").append(sf::Vertex(sf::Vector2f(ax*3,ay*3), color));

    this->m_entity.at("antennaeLeft").append(sf::Vertex(sf::Vector2f(0,-ay), color));
    this->m_entity.at("antennaeLeft").append(sf::Vertex(sf::Vector2f(sp,-ay), color));
    this->m_entity.at("antennaeLeft").append(sf::Vertex(sf::Vector2f(0,-(ay*2)), color));
    this->m_entity.at("antennaeLeft").append(sf::Vertex(sf::Vector2f(sp,-(ay*2)), color));
    this->m_entity.at("antennaeLeft").append(sf::Vertex(sf::Vector2f(ax+sp,-(ay*3)-sp), color));
    this->m_entity.at("antennaeLeft").append(sf::Vertex(sf::Vector2f(ax+sp,-(ay*3)), color));
    this->m_entity.at("antennaeLeft").append(sf::Vertex(sf::Vector2f(ax*3,-(ay*3)), color));

    return;
}

void Entity::updateLegs(const int legpair, const sf::Color color, const sf::Vector2f size)
{
    float lx = size.x;
    float ly = size.y;
    float tx = size.x * 0.125;

    for(int i = 0; i < legpair; ++i)
    {
        m_entity["legLeft"+std::to_string(i)] = sf::VertexArray(sf::TriangleStrip);
        m_entity["legRight"+std::to_string(i)] = sf::VertexArray(sf::TriangleStrip);

        this->m_entity.at("legLeft"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(0,-tx), color));
        this->m_entity.at("legLeft"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(tx,-tx), color));
        this->m_entity.at("legLeft"+std::to_string(i)).append(sf::Vertex(sf::Vector2f((0),-(ly*0.5)), color));
        this->m_entity.at("legLeft"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(tx,-(ly*0.5)), color));
        this->m_entity.at("legLeft"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(lx*0.5,-(ly*2)), color));
        this->m_entity.at("legLeft"+std::to_string(i)).append(sf::Vertex(sf::Vector2f((lx*0.5)+tx,-(ly*2)), color));
        this->m_entity.at("legLeft"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(-(lx*0.5),-(ly*3)), color));
        this->m_entity.at("legLeft"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(-(lx*0.5)+tx,-(ly*3)), color));
        this->m_entity.at("legLeft"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(-(lx*0.5),-(ly*3.5)), color));

        this->m_entity.at("legRight"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(0,tx), color));
        this->m_entity.at("legRight"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(tx,tx), color));
        this->m_entity.at("legRight"+std::to_string(i)).append(sf::Vertex(sf::Vector2f((0),(ly*0.5)), color));
        this->m_entity.at("legRight"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(tx,(ly*0.5)), color));
        this->m_entity.at("legRight"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(lx*0.5,(ly*2)), color));
        this->m_entity.at("legRight"+std::to_string(i)).append(sf::Vertex(sf::Vector2f((lx*0.5)+tx,(ly*2)), color));
        this->m_entity.at("legRight"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(-(lx*0.5),(ly*3)), color));
        this->m_entity.at("legRight"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(-(lx*0.5)+tx,(ly*3)), color));
        this->m_entity.at("legRight"+std::to_string(i)).append(sf::Vertex(sf::Vector2f(-(lx*0.5),(ly*3.5)), color));
    }


    return;
}

void Entity::updateMandibles(const std::string type, const sf::Color color, const sf::Vector2f size)
{
    m_entity["mandibleLeft"] = sf::VertexArray(sf::TriangleStrip);
    m_entity["mandibleRight"] = sf::VertexArray(sf::TriangleStrip);

    float lx = size.x * 0.5f;
    float ly = size.y * 0.5f;

    if(type == "Mosquito")
    {
        lx = size.x;
        ly = size.y*0.1f;

        this->m_entity.at("mandibleLeft").append(sf::Vertex(sf::Vector2f(lx,-ly), color));
        this->m_entity.at("mandibleLeft").append(sf::Vertex(sf::Vector2f(lx*3,0), color));
        this->m_entity.at("mandibleLeft").append(sf::Vertex(sf::Vector2f(lx,ly), color));

        this->m_entity.at("mandibleRight").append(sf::Vertex(sf::Vector2f(lx,-ly), color));
        this->m_entity.at("mandibleRight").append(sf::Vertex(sf::Vector2f(lx*2,0), color));
        this->m_entity.at("mandibleRight").append(sf::Vertex(sf::Vector2f(lx,ly), color));

        return;
    }

    this->m_entity.at("mandibleLeft").append(sf::Vertex(sf::Vector2f(lx,-(ly*0.5)), color));
    this->m_entity.at("mandibleLeft").append(sf::Vertex(sf::Vector2f(lx,-ly), color));
    this->m_entity.at("mandibleLeft").append(sf::Vertex(sf::Vector2f(lx*1.5,-ly), color));
    this->m_entity.at("mandibleLeft").append(sf::Vertex(sf::Vector2f(lx*1.5,-(ly*1.5)), color));
    this->m_entity.at("mandibleLeft").append(sf::Vertex(sf::Vector2f(lx*1.75,-ly), color));
    this->m_entity.at("mandibleLeft").append(sf::Vertex(sf::Vector2f(lx*2,-(ly*1.5)), color));
    this->m_entity.at("mandibleLeft").append(sf::Vertex(sf::Vector2f(lx*2,-(ly*0.75)), color));
    this->m_entity.at("mandibleLeft").append(sf::Vertex(sf::Vector2f(lx*2.5,-ly), color));

    this->m_entity.at("mandibleRight").append(sf::Vertex(sf::Vector2f(lx,(ly*0.5)), color));
    this->m_entity.at("mandibleRight").append(sf::Vertex(sf::Vector2f(lx,ly), color));
    this->m_entity.at("mandibleRight").append(sf::Vertex(sf::Vector2f(lx*1.5,ly), color));
    this->m_entity.at("mandibleRight").append(sf::Vertex(sf::Vector2f(lx*1.5,(ly*1.5)), color));
    this->m_entity.at("mandibleRight").append(sf::Vertex(sf::Vector2f(lx*1.75,ly), color));
    this->m_entity.at("mandibleRight").append(sf::Vertex(sf::Vector2f(lx*2,(ly*1.5)), color));
    this->m_entity.at("mandibleRight").append(sf::Vertex(sf::Vector2f(lx*2,(ly*0.75)), color));
    this->m_entity.at("mandibleRight").append(sf::Vertex(sf::Vector2f(lx*2.5,ly), color));

    return;
}

void Entity::updateCenter(const std::string part)
{
    this->setOrigin(this->m_entity.at(part)[0].position);

    return;
}

void Entity::updateColors(const std::string type)
{
    std::unordered_map<std::string,sf::VertexArray>::const_iterator gotPart = this->m_entity.find("gaster");
    if(gotPart != this->m_entity.end())
    {
        this->m_entity.at(gotPart->first)[0].color = this->m_gasterHighlightColor;
        for(std::size_t i = 1; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].color = this->m_gasterColor;
    }

    gotPart = this->m_entity.find("gasterOutline");
    if(gotPart != this->m_entity.end())
    {
        for(std::size_t i = 0; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].color = this->m_gasterOutlineColor;
    }

    gotPart = this->m_entity.find("head");
    if(gotPart != this->m_entity.end())
    {
        this->m_entity.at(gotPart->first)[0].color = this->m_headHighlightColor;
        for(std::size_t i = 1; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].color = this->m_headColor;
    }

    gotPart = this->m_entity.find("headOutline");
    if(gotPart != this->m_entity.end())
    {
        for(std::size_t i = 0; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].color = this->m_headOutlineColor;
    }

    gotPart = this->m_entity.find("postPetoile");
    if(gotPart != this->m_entity.end())
    {
        this->m_entity.at(gotPart->first)[0].color = this->m_postPetoileHighlightColor;
        for(std::size_t i = 1; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].color = this->m_postPetoileColor;
    }

    gotPart = this->m_entity.find("postPetoileOutline");
    if(gotPart != this->m_entity.end())
    {
        for(std::size_t i = 0; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].color = this->m_postPetoileOutlineColor;
    }

    gotPart = this->m_entity.find("thorax");
    if(gotPart != this->m_entity.end())
    {
        if(type == "Dragonfly")
        {
            this->m_entity.at(gotPart->first)[0].color = this->m_thoraxHighlightColor;
            for(std::size_t i = 1; i < this->m_entity.at(gotPart->first).getVertexCount()/2; ++i)
                this->m_entity.at(gotPart->first)[i].color = this->m_thoraxColor;
            for(std::size_t i = this->m_entity.at(gotPart->first).getVertexCount()/2; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
                this->m_entity.at(gotPart->first)[i].color = this->m_petoileColor;
        }
        else
        {
            this->m_entity.at(gotPart->first)[0].color = this->m_thoraxHighlightColor;
            for(std::size_t i = 1; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
                this->m_entity.at(gotPart->first)[i].color = this->m_thoraxColor;
        }
    }

    gotPart = this->m_entity.find("thoraxOutline");
    if(gotPart != this->m_entity.end())
    {
        for(std::size_t i = 0; i < this->m_entity.at(gotPart->first).getVertexCount(); ++i)
            this->m_entity.at(gotPart->first)[i].color = this->m_thoraxOutlineColor;
    }

    for(auto part : this->m_entity)
    {
        std::string pname = part.first;
        std::size_t gotEye = pname.find("eye");
        if(gotEye != std::string::npos)
        {
            std::size_t gotOutline = pname.find("Outline");
            if(gotOutline != std::string::npos)
            {
                for(std::size_t i = 0; i < this->m_entity.at(part.first).getVertexCount(); ++i)
                    this->m_entity.at(part.first)[i].color = this->m_eyeOutlineColor;
            }
            else
            {
                this->m_entity.at(part.first)[0].color = this->m_eyeHighlightColor;
                for(std::size_t i = 1; i < this->m_entity.at(part.first).getVertexCount(); ++i)
                    this->m_entity.at(part.first)[i].color = this->m_eyeColor;
            }
        }
        std::size_t gotPetoile = pname.find("petoile");
        if(gotPetoile != std::string::npos)
        {
            std::size_t gotOutline = pname.find("Outline");
            if(gotOutline != std::string::npos)
            {
                for(std::size_t i = 0; i < this->m_entity.at(part.first).getVertexCount(); ++i)
                    this->m_entity.at(part.first)[i].color = this->m_petoileOutlineColor;
            }
            else
            {
                this->m_entity.at(part.first)[0].color = this->m_petoileHighlightColor;
                for(std::size_t i = 1; i < this->m_entity.at(part.first).getVertexCount(); ++i)
                    this->m_entity.at(part.first)[i].color = this->m_petoileColor;
            }
        }
        std::size_t gotSpot = pname.find("spot");
        if(gotSpot != std::string::npos)
        {
            std::size_t gotOutline = pname.find("Outline");
            if(gotOutline != std::string::npos)
            {
                for(std::size_t i = 0; i < this->m_entity.at(part.first).getVertexCount(); ++i)
                    this->m_entity.at(part.first)[i].color = this->m_spotOutlineColor;
            }
            else
            {
                this->m_entity.at(part.first)[0].color = this->m_spotHighlightColor;
                for(std::size_t i = 1; i < this->m_entity.at(part.first).getVertexCount(); ++i)
                    this->m_entity.at(part.first)[i].color = this->m_spotColor;
            }
        }
        std::size_t gotWing = pname.find("wing");
        if(gotWing != std::string::npos)
        {
            std::size_t gotOutline = pname.find("Outline");
            if(gotOutline != std::string::npos)
            {
                for(std::size_t i = 0; i < this->m_entity.at(part.first).getVertexCount(); ++i)
                    this->m_entity.at(part.first)[i].color = this->m_wingOutlineColor;
            }
            else
            {
                this->m_entity.at(part.first)[0].color = this->m_wingHighlightColor;
                for(std::size_t i = 1; i < this->m_entity.at(part.first).getVertexCount(); ++i)
                    this->m_entity.at(part.first)[i].color = this->m_wingColor;
            }
        }
        std::size_t gotTopWing = pname.find("topWing");
        if(gotTopWing != std::string::npos)
        {
            std::size_t gotOutline = pname.find("Outline");
            if(gotOutline != std::string::npos)
            {
                for(std::size_t i = 0; i < this->m_entity.at(part.first).getVertexCount(); ++i)
                    this->m_entity.at(part.first)[i].color = this->m_topWingOutlineColor;
            }
            else
            {
                this->m_entity.at(part.first)[0].color = this->m_topWingHighlightColor;
                for(std::size_t i = 1; i < this->m_entity.at(part.first).getVertexCount(); ++i)
                    this->m_entity.at(part.first)[i].color = this->m_topWingColor;
            }
        }
    }

    return;
}

} // end namespace Insect