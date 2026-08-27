#ifndef CONFIG_H
#define CONFIG_H

// Если ваш репозиторий приватный – то нужен токен для работы. Но если вам не нужен это функционал просто за комментируйте это строчку
//#define AUTH "ghp_#######################"
#define CHANGELOG_URL "https://raw.githubusercontent.com/teamexeempire/disaster-launcher/refs/heads/main/servers.json"
#define LATEST_URL "https://api.github.com/repos/FakerNull0/td2dr-files-launcher/releases/latest"
#define STATUS_SERVER "127.0.0.1"

#ifdef _WIN32
#define GAME_EXEC "\"game/Sonicexe The Disaster 2D Remake.exe\""
#define SERVER_EXEC "server/DisasterServer.exe"
#define DISASTER_NAME "DisasterWin"
#define SERVER_NAME "ServerWin"
#else
#define GAME_EXEC "\"./Sonicexe The Disaster 2D Remake.AppImage\""
#define SERVER_EXEC "./BetterServer"
#define DISASTER_NAME "DisasterLinux"
#define SERVER_NAME "ServerLinux"
#endif

#endif //CONFIG_H
