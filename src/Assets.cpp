#include "Assets.hpp"

Assets::Assets()
{
    if(!font.loadFromFile("assets/DejaVuSans.ttf"))
        throw Error("Can not load font.");
    if(!vortex.loadFromFile("assets/vortex.png"))
        throw Error("Can not load picture.");
}

Assets::Error::Error(const std::string& description)
 : std::runtime_error(description)
{}
