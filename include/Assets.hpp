#ifndef ASSETS_HPP
#define ASSETS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Assets
{
    public:
        Assets();

        class Error : public std::runtime_error
        {
            public:
                Error(const std::string& description);
        };

        sf::Font font;
        sf::Texture vortex;
};

#endif
