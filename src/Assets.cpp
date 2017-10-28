#include "Assets.hpp"

Assets::Assets()
{
    if(!font.loadFromFile("assets/DejaVuSans.ttf"))
        throw Error("Can not load font.");
}

Assets::Error::Error(const std::string& description)
 : std::runtime_error(description)
{}
