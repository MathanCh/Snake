#include "game.hpp"

Game::Game(std::string name_):
m_name(name_)
{
}

Game::~Game()
{
}

std::string Game::GetName() const
{
    return m_name;
}