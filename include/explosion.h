#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "raylib.h"

#define MAX_EXPLOSIONS 20
#define EXPLOSION_TIME 0.35f

typedef struct
{
    float x;
    float y;

    float width;
    float height;

    float timer;

    int active;

} Explosion;

void InitExplosions(Explosion explosions[]);

void CreateExplosion(Explosion explosions[],
                     float x,
                     float y);

void UpdateExplosions(Explosion explosions[]);

void DrawExplosions(Explosion explosions[],
                    Texture2D texture);

#endif