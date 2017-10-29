#include "World.hpp"
#include <fstream>
#include <iomanip>

World::World(const std::string& filename)
{
    if(std::ifstream ifs = std::ifstream(filename.c_str()))
    {
        char c;
        sf::Vector2f p1, p2;

        std::getline(ifs, title);

        ifs >> p1.x >> p1.y;
        hole.setPosition(p1);
        magnets.push_back(Magnet(100.f, 4, 2, sf::Color::Blue));
        magnets.back().setPosition(p1);

        ifs >> p1.x >> p1.y;
        ball.setPosition(p1);

        while(ifs)
        {
            if(ifs >> c)
                switch(c)
                {
                    case 'W':
                        ifs >> p1.x >> p1.y >> p2.x >> p2.y;
                        walls.push_back(Wall(p1, p2));
                        break;

                    case 'M':
                        {
                            float intensity;
                            sf::Uint32 color;
                            ifs >> p1.x >> p1.y >> intensity >> std::hex >> color >> std::dec;
                            magnets.push_back(Magnet(100.f, 4, intensity, sf::Color((color << 8) + 0xff)));
                            magnets.back().setPosition(p1);
                        }
                        break;

                    default:
                        throw Error(std::string("Unknow entity type \"")+c+"\"");
                }
        }
    }
    else
        throw Error("Unable to open file "+filename);
}

World::Error::Error(const std::string& description)
 : std::runtime_error(description)
{

}
