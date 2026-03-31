#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

std::string error(std::string message)
{
    std::cout << message << std::endl;

    return "";
}

int main(int argc, char *argv[])
{
    std::cout << "iPod Playlist Generator" << std::endl;

    // Capture path
    std::string playerPath = argc == 2 ? argv[1] : error("No folder path passed");

    //Open Path
    if (playerPath.length() == 0) {
        return 0;
    }

    for (const auto & entry : fs::directory_iterator(playerPath))
        std::cout << entry.path() << std::endl;

    return 0;
}
