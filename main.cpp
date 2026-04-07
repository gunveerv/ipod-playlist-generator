#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

std::string error(std::string message)
{
    std::cout << message << std::endl;

    return "";
}

void readPlaylist(std::string pathToPlaylist)
{
    std::string playlistText;
    std::ifstream myReadFile(pathToPlaylist);

    std::cout << "Reading playlist: " + pathToPlaylist << std::endl;

    while(getline(myReadFile, playlistText))
    {
        std::cout << playlistText << std::endl;
    }

    std::cout << playlistText << std::endl;

    myReadFile.close();
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

    //Check for empty folders
    if (fs::is_empty(playerPath))
    {
        std::string msg = "Error Path '" + playerPath + "' is empty";
        error(msg);
    }

    if (!fs::exists(playerPath + "/Music") || fs::is_empty(playerPath + "/Music"))
    {
        std::string msg = "Error Path " + playerPath + "/Music is empty";
        error(msg);
    }

    if (!fs::exists(playerPath + "/Playlists") || fs::is_empty(playerPath + "/Playlists"))
    {
        std::string msg = "Error Path " + playerPath + "/Playlists is empty";
        error(msg);
    }

    // Read Arugments
    readPlaylist(playerPath + "/Playlists/AAA.m3u8");


    // loops through entire dir
    // for (const auto & entry : fs::directory_iterator(playerPath))
    //     std::cout << entry.path() << std::endl;

    return 0;
}
