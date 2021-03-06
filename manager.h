#include <vector>
#include <SDL.h>
#include "ioManager.h"
#include "clock.h"
#include "world.h"
#include "viewport.h"
#include "hud.h"
#include "multisprite.h"

class Manager {
public:
  Manager ();
  ~Manager ();
  void play();
  void switchSprite();
  bool checkForCollisions() const;

private:
  const bool env;
  const IOManager& io;
  Clock& clock;

  SDL_Surface * const screen;
  World world;
  World woods;
  World mountain;
  Viewport& viewport;
  
  std::vector<Drawable*> sprites;
  std::vector<MultiSprite*> deepsprites;
  int currentSprite;
  bool godMode;
  bool makeVideo;
  int frameCount;
  const std::string username;
  const std::string title;
  const int frameMax;

  void draw() const;
  void update();

  Manager(const Manager&);
  Manager& operator=(const Manager&);
  void makeFrame();
  hud& HUD;
};
