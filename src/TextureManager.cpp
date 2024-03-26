#include "include/TextureManager.h"

void TextureManager::instantiate_textures()
{
    shipText.loadFromFile(TEXT_RELATIVE_PATH_SHIP);
    bulletText.loadFromFile(TEXT_RELATIVE_PATH_BULLET);
    playButtonText.loadFromFile(TEXT_RELATIVE_PATH_PLAY);
    exitButtonText.loadFromFile(TEXT_RELATIVE_PATH_EXIT);
    resumeButtonText.loadFromFile(TEXT_RELATIVE_PATH_RESUME);
    quitButtonText.loadFromFile(TEXT_RELATIVE_PATH_QUIT);
    backgText.loadFromFile(TEXT_RELATIVE_PATH_BACKG);
    asteroidText.loadFromFile(TEXT_RELATIVE_PATH_ASTEROID);
    explosionText.loadFromFile(TEXT_RELATIVE_PATH_EXPLOSION);
    soundEnableText.loadFromFile(TEXT_RELATIVE_SOUND_ENABLE);
    soundDisableText.loadFromFile(TEXT_RELATIVE_SOUND_DISABLE);
    backgroundText.loadFromFile(TEXT_RELATIVE_PATH_BACKGROUND);
    crosshairText.loadFromFile(TEXT_RELATIVE_PATH_CROSSHAIR);
    barBorderText.loadFromFile(TEXT_RELATIVE_PATH_BARBORDER);
    hbarText.loadFromFile(TEXT_RELATIVE_PATH_HBAR);
}
