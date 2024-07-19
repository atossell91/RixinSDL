#pragma once

#include <SDL3/SDL.h>
#include <list>
#include <string>
#include <iostream>

#include "RixinSDLContext.h"
#include "EventDispatcher.h"

#include "interfaces/IDrawable.h"
#include "DrawManager.h"

#include "interfaces/IUpdateable.h"

namespace RixinSDL {
   class RixinSDL {
   private:
      const int kInitFlags = SDL_INIT_VIDEO;

      int WindowWidth = 1280;
      int WindowHeight = 720;
      std::string gameName = "Rubber Duck";

      SDL_Window* window;
      SDL_Renderer* renderer;

      RixinSDLContext gameContext;
      EventDispatcher eventDispatcher;
      DrawManager* drawManager;

      const int kMainLoopDelay = 20; // Milliseconds

      std::list<IUpdateable*> updateables;

      void mainLoop();
      void processEvents();
      void update();
      void cleanup();
      SDL_Window* initWindow(const std::string& name, int width, int height);

   public:
      RixinSDL();

      void Run();
      void SetGameName(std::string& name) { gameName = name; }
      void SetWindowSize(int width, int height) { WindowWidth = width; WindowHeight = height;}
      void AddDrawable(IDrawable* drawable);
      void RemoveDrawable(IDrawable* drawable);
      void AddUpdateable(IUpdateable* updateable);
      void RemoveUpdateable(IUpdateable* updateable);
      DrawManager& GetDrawManager() { return *drawManager; }
      RixinSDLContext& GetRixinSDLContext();
      EventDispatcher& GetEventDispatcher();
   };
}