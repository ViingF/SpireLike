#include <SFML/Graphics.hpp>
#include <iostream>
#include <clocale>

#if defined(_WIN32)
#include <windows.h>
#endif

#include "core/Game.hpp"
#include "core/Logger.hpp"
#include "config/Paths.hpp"

static void setupConsoleEncoding()
{
#if defined(_WIN32)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    std::setlocale(LC_ALL, ".UTF-8");
}

int main() {
    setupConsoleEncoding();

    Logger::instance().init(
        FILEPATH + "/logs/game.log",
        LogLevel::Debug,
        true
    );

    LOG_INFO("Program started");

    Game game;
    game.run();

    LOG_INFO("Program ended");
    Logger::instance().shutdown();

    return 0;
}
