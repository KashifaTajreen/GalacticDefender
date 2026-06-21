#include "../include/enemybullet.h"

void InitEnemyBullets(EnemyBullet bullets[])
{
    for(int i = 0; i < MAX_ENEMY_BULLETS; i++)
    {
        bullets[i].active = 0;

        bullets[i].speed = 6;

        bullets[i].width = 28;

        bullets[i].height = 40;
    }
}

void FireEnemyBullet(
    EnemyBullet bullets[],
    float x,
    float y)
{
    for(int i = 0; i < MAX_ENEMY_BULLETS; i++)
    {
        if(!bullets[i].active)
        {
            bullets[i].active = 1;

            bullets[i].x = x;
            bullets[i].y = y;

            bullets[i].speed = 6.0f;

            break;
        }
    }
}

void UpdateEnemyBullets(
    EnemyBullet bullets[])
{
    for(int i = 0; i < MAX_ENEMY_BULLETS; i++)
    {
        if(!bullets[i].active)
            continue;

        bullets[i].y += bullets[i].speed;

        if(bullets[i].y > 800)
            bullets[i].active = 0;
    }
}

void DrawEnemyBullets(
    EnemyBullet bullets[],
    Texture2D texture)
{
    for(int i = 0; i < MAX_ENEMY_BULLETS; i++)
    {
        if(!bullets[i].active)
            continue;

        Rectangle source = {
            0,
            0,
            (float)texture.width,
            (float)texture.height
        };

        Rectangle dest = {
            bullets[i].x,
            bullets[i].y,
            40,
            60
        };

        DrawTexturePro(
            texture,
            source,
            dest,
            (Vector2){0,0},
            0,
            WHITE);
    }
}

Rectangle GetEnemyBulletRect(EnemyBullet *bullet)
{
    Rectangle rect;

    rect.x = bullet->x;
    rect.y = bullet->y;
    rect.width = bullet->width;
    rect.height = bullet->height;

    return rect;
}