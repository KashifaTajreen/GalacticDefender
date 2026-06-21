#ifndef COLLISION_H
#define COLLISION_H

#include "bullet.h"
#include "enemy.h"
#include "explosion.h"
#include "raylib.h"

void CheckBulletEnemyCollision(
    Bullet bullets[],
    int bulletCount,
    Enemy enemies[],
    int enemyCount,
    Explosion explosions[],
    int *score,
    Sound explosionSound);

#endif