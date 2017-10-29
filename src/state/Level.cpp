#include "state/Level.hpp"
#include "entity/Overlay.hpp"
#include "state/LevelChoice.hpp"

Level::Level(Stack& stack, const Assets& assets, const World& world)
 : State(stack, assets), m_launched(false),
   m_initialWorld(world),
   m_world(world),
   m_menus({
    Menu(sf::Vector2f(340.f,500.f),
    L"Pause",
    assets.font,
    {
    Button(300.f,L"Restart", assets.font),
    Button(300.f,L"Resume", assets.font),
    Button(300.f,L"Level Menu", assets.font)
   }),
   Menu(sf::Vector2f(1024.f,400.f),
    L"Loose",
    assets.font,
    {
    Button(300.f,L"Retry", assets.font),
    Button(300.f,L"Level Menu", assets.font)
   }),
   Menu(sf::Vector2f(340.f,500.f),
    L"Win !",
    assets.font,
    {
    Button(300.f,L"Next Level", assets.font),
    Button(300.f,L"Retry", assets.font),
    Button(300.f,L"Level Menu", assets.font)
   })
})

{
    m_menus[0].setPosition(sf::Vector2f(342.f,43.f));
    m_menus[2].setPosition(sf::Vector2f(342.f,43.f));
}

void Level::initialize()
{
    m_launched = false;
    m_world = m_initialWorld;
    m_overlay = Overlay();
    m_levelCover = LevelCover();
}

void Level::mouseReleased(const sf::Vector2f& position)
{
    int idButtonClicked;
    if(isPaused())
    {
        if(m_menus[0].numButtonClicked(position, idButtonClicked))
        {
            switch(idButtonClicked)
            {
                case 0:
                    restart();
                    break;
                case 1:
                    resume();
                    break;
                case 2:
                    menu();
                    break;
            }
        }
    }
    else if(isLost())
    {
        if(m_menus[1].numButtonClicked(position, idButtonClicked))
        {
            switch(idButtonClicked)
            {
                case 0:
                    restart();
                    break;
                case 1:
                    menu();
                    break;
            }
        }
    }
    else if(isWon())
    {
        if(m_menus[2].numButtonClicked(position, idButtonClicked))
        {
            switch(idButtonClicked)
            {
                case 0:
                    nextLevel();
                    break;
                case 1:
                    restart();
                    break;
                case 2:
                    menu();
                    break;
            }
        }
    }
    else if(!m_launched)
    {
        for(Ball& b : m_world.balls)
            b.launch(position);
        m_launched = true;
    }
}

void Level::mouseMoved(const sf::Vector2f& position)
{
    for(Menu& m : m_menus)
    {
        m.changeColor(position);
    }
}

void Level::restart()
{
    initialize();
    resume();
}

void Level::update(sf::Time deltaTime)
{
    m_levelCover.update(deltaTime);
    if(isNotRunning())
    {
        m_overlay.update(deltaTime);
    }
    else
    {
        for(Ball& b : m_world.balls)
            b.update(deltaTime);

        for(Magnet& m : m_world.magnets)
        {
            m.update(deltaTime);
            for(Ball& b : m_world.balls)
                m.interact(b, deltaTime);
        }

        collisions();

        if(checkLost())
            lose();
        else
        {
            // bool contains = true;
            // for(Ball& b : m_world.balls)
            //     contains = contains && m_world.hole.contains(b);
            if(m_world.hole.contains(m_world.balls[0]))
                m_world.balls[0].applyFriction(0.95f);

            if(m_world.hole.isWon(m_world.balls[0]))
                win();
        }
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

    if(isNotRunning())
    {
        target.draw(m_overlay);
        if(isPaused())
        {
            target.draw(m_menus[0]);
        }
        if(isLost())
        {
            target.draw(m_menus[1]);
        }
        if(isWon())
        {
            target.draw(m_menus[2]);
        }
    }
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

void Level::nextLevel()
{
    pop();
    //getStack().top() -> nextLevel();
}

void Level::menu()
{
    pop();
}
