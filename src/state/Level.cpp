#include "state/Level.hpp"
#include "entity/Overlay.hpp"
#include "state/Pause.hpp"
#include "state/Lost.hpp"
#include "state/Won.hpp"

Level::Level(Stack& stack, const Assets& assets, const World& world)
 : State(stack, assets), m_launched(false), m_world(world)
{}

void Level::mouseReleased(const sf::Vector2f& position)
{
    if(!m_launched)
    {
        m_world.ball.launch(position);
        m_launched = true;
    }
}

void Level::keyPressed(sf::Keyboard::Key key)
{
    if(key == sf::Keyboard::Space)
        pop(); // restart
    else if(key == sf::Keyboard::Escape)
        push(std::unique_ptr<State>(new Pause(getStack(), m_assets, *this)));
}

void Level::lostFocus()
{
    push(std::unique_ptr<State>(new Pause(getStack(), m_assets, *this)));
}

void Level::update(sf::Time deltaTime)
{
    m_levelCover.update(deltaTime);

    m_world.ball.update(deltaTime);

    for(Magnet& m : m_world.magnets)
    {
        m.update(deltaTime);
        m.interact(m_world.ball, deltaTime);
    }

    collisions();
    if(m_world.hole.contains(m_world.ball))
        m_world.ball.applyFriction(0.95f);

    if(checkLost())
        push(std::unique_ptr<State>(new Lost(getStack(), m_assets, *this)));
    else if(m_world.hole.isWon(m_world.ball))
        push(std::unique_ptr<State>(new Won(getStack(), m_assets, *this)));
}

void Level::draw(sf::RenderTarget& target) const
{
    target.draw(m_levelCover);
    for(const Wall& w : m_world.walls)
        target.draw(w);
    for(const Magnet& m : m_world.magnets)
        target.draw(m);
    //target.draw(m_hole);
    target.draw(m_world.ball);
}

bool Level::checkLost()
{
    const sf::Vector2f& position = m_world.ball.getPosition();
    return position.x < 0 || 1024 < position.x || position.y < 0 || 768 < position.y;
}

void Level::collisions()
{
    sf::Vector2f hitPoint, normal;
    for(const Wall& w : m_world.walls)
        if(m_world.ball.intersects(w, hitPoint, normal))
            m_world.ball.bounce(hitPoint, normal);
}
