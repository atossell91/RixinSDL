#include "../include/DrawHelper.h"

#include <SDL3/SDL.h>

#include "../include/Point.h"
#include "../include/Rectangle.h"
#include "../include/Image.h"
#include "ImageReference.h"

#include <iostream>
using namespace RixinSDL;

void DrawHelper::FillRectangle(const Rectangle& rectangle, const Colour& colour) const {
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(renderer, &rectangle.rectangle);
}

void DrawHelper::DrawImage(const ImageReference& imageRef, const Rectangle& rectangle) const {
    SDL_Texture* texture = textureRepo->AccessTexture(imageRef);

    if (texture != nullptr) {
        SDL_RenderTexture(renderer, texture, NULL, &rectangle.rectangle);
    }
}

void DrawHelper::DrawLine(const Point& p1, const Point& p2, const Colour& colour) const {
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderLine(renderer, p1.point.x, p1.point.y, p2.point.x, p2.point.y);
}
