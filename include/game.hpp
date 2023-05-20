#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <string>

class Game
{
public:
    Game(std::string name_);

    virtual ~Game();

    virtual void Run() = 0;

    std::string GetName() const;
    
private:
    std::string m_name;
};

#endif /*__GAME_HPP__*/