#include "Game.hpp"
#include "state/Transition.hpp"
#include "state/Level.hpp"
#include "state/LevelChoice.hpp"

Game::Game()
 : m_window(sf::VideoMode(1024, 768), "Lamak Quest")
{
    m_window.setFramerateLimit(60);
}

bool Game::run()
{
    World w("levels/4.txt");
    // m_stack.push(std::unique_ptr<State>(new Level(m_stack, m_assets, w)));
    m_stack.push(std::unique_ptr<State>(new LevelChoice(m_stack, m_assets)));
    sf::Clock clock;
    while(!m_stack.empty())
        if(handleEvents() && update(clock.restart()))
            render();
    return true;
}

bool Game::handleEvents()
{
    bool sameState = true;
    sf::Event event;
    while(sameState && m_window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                m_window.close();
                while(!m_stack.empty())
                    m_stack.pop();
                return false;

            case sf::Event::MouseButtonPressed:
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    getState().mousePressed(getWorldCoordinates(event.mouseButton.x, event.mouseButton.y));
                    mousePressed = true;
                }
                break;

            case sf::Event::MouseButtonReleased:
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    getState().mouseReleased(getWorldCoordinates(event.mouseButton.x, event.mouseButton.y));
                    mousePressed = false;
                }
                break;

            case sf::Event::MouseMoved:
                {
                    sf::Vector2f position = getWorldCoordinates(event.mouseMove.x, event.mouseMove.y);
                    getState().mouseMoved(position);
                    if(mousePressed)
                        getState().mouseDragged(position);
                }
                break;

            case sf::Event::KeyPressed:
                getState().keyPressed(event.key.code);
                break;

            case sf::Event::LostFocus:
                getState().lostFocus();
                break;

            default:
                break;
        }

        if(getState().hasTransition())
        {
            getState().doTransition();
            sameState = false;
        }
    }

    return sameState;
}

sf::Vector2f Game::getWorldCoordinates(int x, int y) const
{
    return m_window.mapPixelToCoords(sf::Vector2i(x, y));
}

bool Game::update(sf::Time deltaTime)
{
    getState().update(deltaTime);
    if(getState().hasTransition())
    {
        getState().doTransition();
        return false;
    }
    else
        return true;
}

void Game::render()
{
    m_window.clear(sf::Color(32, 32, 32));
    getState().draw(m_window);
    m_window.display();
}

State& Game::getState()
{
    return *m_stack.top();
}

const State& Game::getState() const
{
    return *m_stack.top();
}
