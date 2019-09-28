#include "texture.h"

#include <SDL2_image/SDL_image.h>

namespace alientd {

Texture::Texture() {
  // Initialize
  mTexture = NULL;
  mWidth = 0;
  mHeight = 0;
}

Texture::~Texture() {
  // Deallocate
  free();
}

bool Texture::loadFromFile(SDL_Renderer *renderer, std::string path) {
  // Get rid of preexisting texture
  free();

  // The final texture
  SDL_Texture *newTexture = NULL;

  // Load image at specified path
  SDL_Surface *loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL) {
    return false;
  }
  // Color key image
  SDL_SetColorKey(loadedSurface, SDL_TRUE,
                  SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

  // Create texture from surface pixels
  newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  if (newTexture == NULL) {
    return false;
  }
  // Get image dimensions
  mWidth = loadedSurface->w;
  mHeight = loadedSurface->h;

  // Get rid of old loaded surface
  SDL_FreeSurface(loadedSurface);

  // Return success
  mTexture = newTexture;
  return mTexture != NULL;
}

bool Texture::loadFromRenderedText(SDL_Renderer *renderer, TTF_Font *font,
                                   std::string textureText,
                                   SDL_Color textColor) {
  free();

  SDL_Surface *textSurface =
      TTF_RenderText_Solid(font, textureText.c_str(), textColor);
  if (textSurface == NULL) {
    return false;
  }
  // Create texture from surface pixels
  mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  if (mTexture == NULL) {
    return false;
  }
  // Get image dimensions
  mWidth = textSurface->w;
  mHeight = textSurface->h;

  // Get rid of old surface
  SDL_FreeSurface(textSurface);

  // Return success
  return mTexture != NULL;
}

void Texture::free() {
  if (mTexture != NULL) {
    SDL_DestroyTexture(mTexture);
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
  }
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
  SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending) {
  SDL_SetTextureBlendMode(mTexture, blending);
}

void Texture::setAlpha(Uint8 alpha) { SDL_SetTextureAlphaMod(mTexture, alpha); }

void Texture::render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip,
                     double angle, SDL_Point *center, SDL_RendererFlip flip) {
  SDL_Rect renderQuad = {x, y, mWidth, mHeight};

  if (clip != NULL) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int Texture::getWidth() { return mWidth; }

int Texture::getHeight() { return mHeight; }

}
