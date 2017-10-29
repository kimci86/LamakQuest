#include "Assets.hpp"

Assets::Assets()
{
    if(!font.loadFromFile("assets/DejaVuSans.ttf"))
        throw Error("Can not load font.");
    if(!vortex.loadFromFile("assets/vortex.png"))
        throw Error("Can not load picture.");
    if(!hit.loadFromFile("assets/hit.flac") ||
       !launch.loadFromFile("assets/launch.flac") ||
       !win.loadFromFile("assets/win.flac") ||
       !lose.loadFromFile("assets/lose.flac") ||
       !tada.loadFromFile("assets/tada.flac"))
        throw Error("Can not load sound.");
}

Assets::Error::Error(const std::string& description)
 : std::runtime_error(description)
{}
