// This file is part of Noggit3, licensed under GNU General Public License (version 3).

#pragma once

#include <noggit/UICloseWindow.h>

class nameEntry;
class UITexture;
class World;

class UITextureSwitcher : public UICloseWindow
{
public:
  UITextureSwitcher (World*, float x, float y);

  void getTextures (nameEntry* lSelection);
  void setTexture (size_t id);
  void setPosition (float x, float y);

private:
  UITexture* _texture;
  float xPos;
  float zPos;

  World* _world;
};
