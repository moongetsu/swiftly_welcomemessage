#include <swiftly/swiftly.h>
#include <swiftly/server.h>
#include <swiftly/configuration.h>

Configuration *config = nullptr;
Server *server = nullptr;
PlayerManager *g_playerManager = nullptr;

void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);
    g_playerManager = new PlayerManager();  
    server = new Server();
    config = new Configuration();
}

void OnPlayerSpawn(Player *player)
{
    if(player->IsFirstSpawn()) {
    player->SendMsg(HUD_PRINTTALK, "------------------------------------------------------------------------------------------------------------------");
    player->SendMsg(HUD_PRINTTALK, FetchTranslation("welcomemessage.message1"), player->GetName());
    player->SendMsg(HUD_PRINTTALK, FetchTranslation("welcomemessage.message2"));
    player->SendMsg(HUD_PRINTTALK, FetchTranslation("welcomemessage.message3"));
    player->SendMsg(HUD_PRINTTALK, FetchTranslation("welcomemessage.message4"));
    player->SendMsg(HUD_PRINTTALK, "------------------------------------------------------------------------------------------------------------------");
    }
}

void OnPluginStart()
{

}

void OnPluginStop()
{

}

const char *GetPluginWebsite()
{
    return "";  
}

const char *GetPluginAuthor()
{
    return "Moongetsu";
}

const char *GetPluginVersion()
{
    return "1.0.0";
}

const char *GetPluginName()
{
    return "Welcome Message";
}