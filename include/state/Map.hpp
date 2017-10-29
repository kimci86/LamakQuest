#ifndef MAP_HPP
#define MAP_HPP

#include "gui/RoundButton.hpp"
#include "state/State.hpp"
#include "entity/LevelCover.hpp"
#include "World.hpp"

class Map : public State
{
    public:
        Map(Stack& stack, const Assets& assets);

        virtual void mouseMoved(const sf::Vector2f& position);
        virtual void mouseReleased(const sf::Vector2f& position);

        virtual void update(sf::Time deltaTime);

        virtual void draw(sf::RenderTarget& target) const;

    private:
        int m_page = 0;
        int m_nbLevels = 20;
        float m_sizeButton;
        std::vector<RoundButton> m_buttons;
        LevelCover m_stars;
        sf::Sprite m_path;
        std::vector<World> m_worlds;
        int m_id;
};

#endif
