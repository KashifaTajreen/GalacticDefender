#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "enemybullet.h"

typedef enum
{
    ENEMY_SMALL,
    ENEMY_BIG
} EnemyType;

typedef struct
{
    float x;
    float y;

    float width;
    float height;

    float speed;

    int health;

    int active;

    float shootTimer;

    EnemyType type;

} Enemy;

void InitEnemies(Enemy enemies[],
                 int count);

void UpdateEnemies(Enemy enemies[],
                   int count);

void DrawEnemies(Enemy enemies[],
                 int count,
                 Texture2D enemy1,
                 Texture2D enemy2);

Rectangle GetEnemyRect(Enemy *enemy);

void EnemyShoot(
    Enemy enemies[],
    int count,
    EnemyBullet bullets[]);

#endif