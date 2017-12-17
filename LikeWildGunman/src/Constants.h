#ifndef CONSTANTS_H
#define CONSTANTS_H
// ----------------------------------------------------------------------------
#include <string>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
/**
* Constantes Globales, se utilizan en distintas partes del proyecto.
*/
typedef unsigned int uint_t;

const uint_t	WINDOW_WIDTH_MAX = 1080;
const uint_t	WINDOW_HEIGHT_MAX = 700;

const std::string pathCrooshairImage = "assets/textures/crosshair.png";
const std::string pathBackgroundImage = "assets/textures/background-hud.png";
const std::string pathTagetsImage = "assets/textures/targets.png";

const std::string pathFont = "assets/fonts/PaytoneOne-Regular.ttf";

const std::string path9mmGunshotAudio = "assets/audio/9mm-gunshot.ogg";
const std::string pathBulletWhizzingAudio = "assets/audio/bullet-whizzing.ogg";
const std::string pathM1GunshotAudio = "assets/audio/m1-garand-gunshot.ogg";
const std::string pathPoliceChatterAudio = "assets/audio/police-scanner-chatter.ogg";
const std::string pathShotgunReloadAudio = "assets/audio/shotgun-reload.ogg";

const std::string pathTitleScreenImage = "assets/textures/screen-title-1080.jpg";
const std::string pathTargetsScreenImage = "assets/textures/target-information-1080.png";
const std::string pathGameOverScreenImage = "assets/textures/screen-game-over-1080.jpg";

// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // CONSTANTS_H

