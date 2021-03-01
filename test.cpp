#include <SFML/Graphics.hpp>
#include <Touched/Touched.hpp>
#include <unordered_map>
#include <cstring>
#include <cmath>
#include <vector>

#include "Insect.hpp"

int main()
{
    sf::VideoMode screen = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(screen,"Test");
    window.setFramerateLimit(20);

    sf::IntRect screenRect = sf::IntRect(0,0,screen.width,screen.height);
    sf::FloatRect fscreen = sf::FloatRect(0,0,screen.width,screen.height);
    sf::Vector2f screenmode = sf::Vector2f(screen.width,screen.height);
    sf::Vector2f screenCenter = screenmode * 0.5f;

    sf::Font font;
    if (!font.loadFromFile("./assets/fonts/Roboto-Regular.ttf"))
        return EXIT_FAILURE;

    sf::Text text("Testing Insects.", font, 64);
    text.setFillColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(10, 10));

    Insect::Insect egg("Egg");
    egg.create();
    egg.setPosition(sf::Vector2f(200,100));
    
    Insect::Insect hatch("Hatchling");
    hatch.create();
    hatch.setPosition(sf::Vector2f(200,125));

    Insect::Insect larva1("LarvaOne");
    larva1.create();
    larva1.setPosition(sf::Vector2f(200,150));

    Insect::Insect larva2("LarvaMed");
    larva2.create();
    larva2.setPosition(sf::Vector2f(200,175));

    Insect::Insect larva("LarvaFull");
    larva.create();
    larva.setPosition(sf::Vector2f(200,200));

    Insect::Insect mosi("Mosquito");
    mosi.create();
    mosi.setPosition(sf::Vector2f(200,250));

    Insect::Insect ant("Ant");
    ant.create();
    ant.setPosition(sf::Vector2f(200,300));

    Insect::Insect redant("AntRed");
    redant.create();
    redant.setPosition(sf::Vector2f(200,350));
  
    Insect::Insect lady("Ladybug");
    lady.create();
    lady.setPosition(sf::Vector2f(200,425));

    Insect::Insect fly("Fly");
    fly.create();
    fly.setPosition(sf::Vector2f(200,500));

    Insect::Insect drag("Dragonfly");
    drag.create();
    drag.setPosition(sf::Vector2f(600,700));

    Insect::Insect bee("Bee");
    bee.create();
    bee.setPosition(sf::Vector2f(200, 700));

    Insect::Insect spid("Spider");
    spid.create();
    spid.setPosition(sf::Vector2f(200, 950));

    Insect::Insect wasp("Wasp");
    wasp.create();
    wasp.setPosition(sf::Vector2f(400,450));

    Insect::Insect daddy("Daddylonglegs");
    daddy.create();
    daddy.setPosition(sf::Vector2f(400,185));

    Insect::Insect grasshopper("Grasshopper");
    grasshopper.create();
    grasshopper.setPosition(sf::Vector2f(400,625));

    sf::Vector2f scaling = {1.f,1.f};
    
    sf::Color backgroundColor = sf::Color(128,186,157);

    bool active = true;
    bool bentleft = false;
    bool straight = true;
    bool turned = false;
    bool folded = true;
    bool down = false;
    bool ladydown = false;

   // fly.wingsFold(60.0f);

    Touched::Touch touched;
 
    sf::Clock clock;
   
    while (window.isOpen())
    {
        sf::Event event;
        float delta = clock.restart().asSeconds();

        while (active ? window.pollEvent(event) : window.waitEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
                case sf::Event::LostFocus:
                    backgroundColor = sf::Color::Black;
                    break;
                case sf::Event::GainedFocus:
                    backgroundColor = sf::Color(168,186,157);
                    break;
                
                // On Android MouseLeft/MouseEntered are (for now) triggered,
                // whenever the app loses or gains focus.
                case sf::Event::MouseLeft:
                    active = false;
                    break;
                case sf::Event::MouseEntered:
                    active = true;
                    break;
                case sf::Event::TouchEnded:
                    if(!sf::Touch::isDown(0))
                    {
                        daddy.stop(4.0f);
                        if(!daddy.mid)
                        {
                            (daddy.left) ? daddy.wobbleRight(20.0f) : daddy.wobbleLeft(20.0f);
                            daddy.mid = true;
                        }
                        grasshopper.stop(2.0f);
                        lady.stop(1.0f);
                        spid.stop(3.0f);
                        ant.stop(1.0f);
                        bee.stop(2.0f);
                        redant.stop(1.0f);
                        fly.stop(1.0f);
                        mosi.stop(1.0f);
                        drag.stop(4.0f);
                        wasp.stop(2.0f);
                    }
                    
                   // backgroundColor = sf::Color((std::rand() % 255),(std::rand() % 255),(std::rand() % 255));
                    if(event.touch.finger == 0)
                    {
                        //mosi.walk(false);
                    }
                    break;
                case sf::Event::TouchMoved:
                    if (event.touch.finger == 0)
                    {
                       // mosi.setPosition(sf::Vector2f(event.touch.x, event.touch.y));
                    }
                    break;
                case sf::Event::TouchBegan:
                        if(straight)
                        {
                            (turned) ? lady.turnHead(10.0f) : lady.turnHead(-10.0f);
                            (turned) ? wasp.turnHead(15.0f) : wasp.turnHead(-15.0f);
                            (turned) ? ant.turnHead(15.0f) : ant.turnHead(-15.0f);
                            (turned) ? bee.turnHead(15.0f) : bee.turnHead(-15.0f);
                            (turned) ? drag.turnHead(15.0f) : drag.turnHead(-15.0f);
                            (turned) ? fly.turnHead(15.0f) : fly.turnHead(-15.0f);
                            (turned) ? redant.turnHead(15.0f) : redant.turnHead(-15.0f);
                            (turned) ? mosi.turnHead(30.0f) : mosi.turnHead(-30.0f);
                            turned = (turned)? false : true;
                            straight = false;
                        }
                        else
                        {
                            (turned) ? lady.turnHead(10.0f) : lady.turnHead(-10.0f);
                            (turned) ? wasp.turnHead(15.0f) : wasp.turnHead(-15.0f);
                            (turned) ? ant.turnHead(15.0f) : ant.turnHead(-15.0f);
                            (turned) ? bee.turnHead(15.0f) : bee.turnHead(-15.0f);
                            (turned) ? drag.turnHead(15.0f) : drag.turnHead(-15.0f);
                            (turned) ? fly.turnHead(15.0f) : fly.turnHead(-15.0f);
                            (turned) ? redant.turnHead(15.0f) : redant.turnHead(-15.0f);
                            (turned) ? mosi.turnHead(10.0f) : mosi.turnHead(-10.0f);
                            straight = true;
                        }
                    if(!sf::Touch::isDown(1))
                    {
                        if(!down)
                        {
                            (folded) ? lady.wingsUnfold(90.0f) : lady.wingsFold(90.0f);
                            (folded) ? wasp.wingsUnfold(85.0f) : wasp.wingsFold(85.0f);
                            (folded) ? bee.wingsUnfold(85.0f) : bee.wingsFold(85.0f);
                            (folded) ? mosi.wingsUnfold(95.0f) : mosi.wingsFold(95.0f);
                            (folded) ? fly.wingsUnfold(75.0f) : fly.wingsFold(75.0f);
                            folded = (folded)? false : true;
                        }
                    }
                    break;
            }
        }
        
        if(sf::Touch::isDown(0))
        {
            grasshopper.walk(2.0f);
            spid.walk(3.0f);
            ant.walk(1.0f);
            hatch.wiggle();
            larva1.wiggle();
            larva2.wiggle();
            larva.wiggle();
            redant.walk(1.0f);
            if(folded)
            {
            daddy.walk(4.0f);
             //   bee.walk(2.0f);
                bee.wiggle();
                drag.walk(4.0f);
                mosi.walk(1.0f);
                fly.walk(1.0f);
                wasp.walk(2.0f);
                lady.walk(1.0f);
            }
            else
            {
                daddy.wobble(20.0f);
                lady.wingsFlap();
                wasp.wingsFlap();
                bee.wingsFlap();
                drag.wingsFlap();
                fly.wingsFlap();
                mosi.wingsFlap();
            }
        }
        
        
        if(sf::Touch::isDown(0) && sf::Touch::isDown(1))
        {
            touched.Touching2(sf::Touch::getPosition(0).x, sf::Touch::getPosition(0).y, sf::Touch::getPosition(1).x, sf::Touch::getPosition(1).y);
            if(touched.Pinched)
            {
                scaling *= 0.9f;
                if(scaling.x < 0.75) scaling = {0.75,0.75};
           /*     mosi.setScale(scaling);
                redant.setScale(scaling);
                fly.setScale(scaling);
                larva.setScale(scaling);
                drag.setScale(scaling);
                lady.setScale(scaling);*/
                daddy.setScale(scaling);
            }
            else
            {
                scaling *= 1.1f;
                if(scaling.x > 10.f) scaling = {10.f,10.f};
          /*      mosi.setScale(scaling);
                redant.setScale(scaling);
                fly.setScale(scaling);
                larva.setScale(scaling);
                drag.setScale(scaling);
                lady.setScale(scaling);*/
                daddy.setScale(scaling);
            }
        }
        if (active)
        {
            window.clear(backgroundColor);
            window.draw(text);
            window.draw(egg);
            window.draw(hatch);
            window.draw(larva1);
            window.draw(larva2);
            window.draw(larva);
            window.draw(mosi);
            window.draw(ant);
            window.draw(redant);
            window.draw(lady);
            window.draw(daddy);
            window.draw(grasshopper);
            window.draw(fly);
            window.draw(bee);
            window.draw(wasp);
            window.draw(spid);
            window.draw(drag);
            window.display();
        }
        else {
            sf::sleep(sf::milliseconds(100));
        }
    }
    return 0;
}