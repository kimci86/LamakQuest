#include "state/Level.hpp"
#include "entity/Overlay.hpp"
#include "state/Pause.hpp"

Level::Level(Stack& stack, const Assets& assets, const World& world)
 : State(stack, assets), m_launched(false), m_world(world)
{}

void Level::mouseReleased(const sf::Vector2f& position)
{
    if(!m_launched)
    {
        for(Ball& b : m_world.balls)
            b.launch(position);
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

    for(Ball& b : m_world.balls)
        b.update(deltaTime);

    for(Magnet& m : m_world.magnets)
    {
        m.update(deltaTime);
        for(Ball& b : m_world.balls)
            m.interact(b, deltaTime);
    }

    collisions();
    if(m_world.hole.contains(m_world.balls[0]))
        m_world.balls[0].applyFriction(0.95f);

    if(checkLost())
        ; // TODO: push(End)
    else
    {
        bool won = true;
        for(Ball& b : m_world.balls)
            won = won && m_world.hole.isWon(b);
        if(won)
            ; // TODO: push(End)
    }
}

void Level::draw(sf::RenderTarget& target) const
{
    target.draw(m_levelCover);
    for(const Wall& w : m_world.walls)
        target.draw(w);
    for(const Magnet& m : m_world.magnets)
        target.draw(m);
    //target.draw(m_hole);
    for(const Ball& b : m_world.balls)
        target.draw(b);
}

bool Level::checkLost()
{
    bool lost = false;
    for(Ball& b : m_world.balls)
    {
        const sf::Vector2f& position = b.getPosition();
        lost = lost || position.x < 0 || 1024 < position.x || position.y < 0 || 768 < position.y;
    }
    return lost;
}

void Level::collisions()
{
    sf::Vector2f hitPoint, normal;
    for(const Wall& w : m_world.walls)
        for(Ball& b : m_world.balls)
            if(b.intersects(w, hitPoint, normal))
                b.bounce(hitPoint, normal);
}
