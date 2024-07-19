#include "../include/DrawManager.h"

#include <SDL3/SDL.h>
#include <iostream>

#include "../include/Image.h"
#include "../include/ImageReference.h"

using namespace RixinSDL;

DrawManager::~DrawManager() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    delete drawHelper;
    delete textureRepo;
}

ImageReference DrawManager::AddImage(const Image& image) {
    return textureRepo->AddImage(image);
}

ImageReference DrawManager::AddImage(const char* path) {
    return textureRepo->AddImage(path);
}

void DrawManager::RemoveImage(const ImageReference& imageRef) {
    textureRepo->RemoveImage(imageRef);
}

void DrawManager::AddDrawable(IDrawable* drawable) {
    drawables.push_back(drawable);
}

void DrawManager::RemoveDrawable(IDrawable* drawable) {
    drawables.remove(drawable);
}

void DrawManager::DrawEverything() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    for (auto drawable : drawables) {
        drawable->Draw(drawHelper);
    }
    SDL_RenderPresent(renderer);
}
