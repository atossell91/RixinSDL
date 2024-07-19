#pragma once

#include <SDL3/SDL.h>
#include <list>

#include "DrawHelper.h"
#include "interfaces/IDrawable.h"
#include "Image.h"
#include "ImageReference.h"
#include "TextureRepository.h"

namespace RixinSDL {

    class DrawManager {
     private:
        SDL_Renderer* renderer;
        TextureRepository* textureRepo;
        DrawHelper* drawHelper;
        std::list<IDrawable*> drawables;

     public:
        ~DrawManager();
        ImageReference AddImage(const Image& image);
        ImageReference AddImage(const char* path);
        void RemoveImage(const ImageReference& imageRef);
        void AddDrawable(IDrawable* drawable);
        void RemoveDrawable(IDrawable* drawable);
        void DrawEverything();
        
        DrawManager(SDL_Renderer* r) : renderer{r}, 
        textureRepo {new TextureRepository(renderer)},
        drawHelper{new DrawHelper(renderer, textureRepo)} {}
    };
}
