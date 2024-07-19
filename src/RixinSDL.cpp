#include "../include/RixinSDL.h"

#include <thread>
#include <chrono>
#include <list>
#include <iostream>
#include <SDL3_image/SDL_image.h>

#include "../include/RixinSDLContext.h"
#include "../include/interfaces/IUpdateable.h"
#include "../include/interfaces/IDrawable.h"

RixinSDL::RixinSDL::RixinSDL() {
    SDL_CreateWindowAndRenderer(gameName,
    kWindowWidth,kWindowHeight, 0,
    &window, &renderer);

    drawManager = new DrawManager(renderer);
}

void RixinSDL::RixinSDL::init() {
    SDL_Init(kInitFlags);
    std::cout << "I love Sammie" << std::endl;
}

void RixinSDL::RixinSDL::mainLoop() {
    while (!gameContext.ShouldClose) {
        processEvents();
        drawManager->DrawEverything();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(kMainLoopDelay));
    }
}

void RixinSDL::RixinSDL::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        eventDispatcher.HandleEvent(event);
    }
}

void RixinSDL::RixinSDL::update() {
    for (auto updateable : updateables) {
        updateable->Update();
    }
}

void RixinSDL::RixinSDL::Run() {
    mainLoop();
    cleanup();
}

void RixinSDL::RixinSDL::AddDrawable(IDrawable* drawable) {
    drawManager->AddDrawable(drawable);
}

void RixinSDL::RixinSDL::RemoveDrawable(IDrawable* drawable) {
    drawManager->RemoveDrawable(drawable);
}

void RixinSDL::RixinSDL::AddUpdateable(IUpdateable* updateable) {
    updateables.push_back(updateable);
}

void RixinSDL::RixinSDL::RemoveUpdateable(IUpdateable* updateable) {
    updateables.remove(updateable);
}

RixinSDL::RixinSDLContext& RixinSDL::RixinSDL::GetRixinSDLContext() {
    return this->gameContext;
}

RixinSDL::EventDispatcher& RixinSDL::RixinSDL::GetEventDispatcher() {
    return eventDispatcher;
}

void RixinSDL::RixinSDL::cleanup() {
    SDL_DestroyWindow(window);
    delete drawManager;
    SDL_Quit();
}

SDL_Window* RixinSDL::RixinSDL::initWindow(const std::string& name, int width, int height) {
    SDL_Window* win = SDL_CreateWindow(name.c_str(), width, height, 0);
    
    if (win == NULL) {
        std::cout << "Window not created!" << std::endl;
    }

    return win;
}
