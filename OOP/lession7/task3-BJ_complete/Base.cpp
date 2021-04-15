#include "Game.h"

int main(int argc, char const* argv[])
{
    std::vector<std::string> names
        { "Alex", "Den", "Anna" };

    Game game(names);
    game.play();

    return 0;
}
