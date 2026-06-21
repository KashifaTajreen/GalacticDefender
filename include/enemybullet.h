#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "raylib.h"

#define MAX_ENEMY_BULLETS 40

typedef struct
{
    float x;
    float y;

    float width;
    float height;

    float speed;

    bool active;

} EnemyBullet;

// Function declarations
void InitEnemyBullets(
    EnemyBullet bullets[]);

void FireEnemyBullet(
    EnemyBullet bullets[],
    float x,
    float y);

void UpdateEnemyBullets(
    EnemyBullet bullets[]);

void DrawEnemyBullets(
    EnemyBullet bullets[],
    Texture2D texture);

Rectangle GetEnemyBulletRect(
    EnemyBullet *bullet);

#endif