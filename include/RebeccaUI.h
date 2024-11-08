#pragma once

#include <SDL3/SDL.h>
#include <list>
#include <string>
#include <iostream>
#include <memory>

#include "RebeccaUIContext.h"
#include "Window/WindowManager.h"
#include "Event/IEventManager.h"

#include "IUpdateable.h"

#include "Event/IEventFactory.h"
#include "Event/EventFactory.h"
#include "Event/IEventRouter.h"

#include "IIndexResolver.h"

namespace RebeccaUI {
   class RebeccaUI {
   private:

      RebeccaUIContext gameContext;

      std::unique_ptr<WindowManager> windowManager;
      std::unique_ptr<IEventManager> eventManager;

      std::shared_ptr<IIndexResolver> windowResolver;
      std::shared_ptr<IEventFactory> eventFactory;
      std::shared_ptr<IEventRouter> eventRouter;

      const int kMainLoopDelay = 5; // Milliseconds

      std::list<IUpdateable*> updateables;

      void initSDL();
      void initOpenGl();
      void init();
      void registerEvents();
      void mainLoop();
      void update();
      void cleanup();

   public:
      RebeccaUI();

      void Run();
      void AddUpdateable(IUpdateable* updateable);
      void RemoveUpdateable(IUpdateable* updateable);
      RebeccaUIContext& GetRebeccaUIContext() { return gameContext; }
      WindowManager* GetWindowManager() { return windowManager.get(); }
   };
}