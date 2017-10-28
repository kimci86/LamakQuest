#ifndef WORLD_HPP
#define WORLD_HPP

#include <exception>
#include <string>

#include "entity/Ball.hpp"
#include "entity/Hole.hpp"
#include "entity/Wall.hpp"
#include "entity/Magnet.hpp"

class World
{
    public:
        World(const std::string& filename);

        class Error : public std::runtime_error
        {
            public:
                Error(const std::string& description);
        };

        std::string title;
        Hole hole;
        std::vector<Ball> balls;
        std::vector<Wall> walls;
        std::vector<Magnet> magnets;
};

#endif
