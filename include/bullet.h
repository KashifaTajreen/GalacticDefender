#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

typedef struct
{
    float x;
    float y;

    float speed;

    float width;
    float height;

    int damage;

    int active;

} Bullet;

void InitBullets(Bullet bullets[],
                 int count);

void FireBullet(Bullet bullets[],
                int count,
                float x,
                float y);

void UpdateBullets(Bullet bullets[],
                   int count);

void DrawBullets(Bullet bullets[],
                 int count,
                 Texture2D texture);

Rectangle GetBulletRect(Bullet *bullet);

#endif