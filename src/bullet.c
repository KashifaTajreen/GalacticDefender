#include "../include/bullet.h"
#include "../include/game.h"

void InitBullets(Bullet bullets[], int count)
{
    for (int i = 0; i < count; i++)
    {
        bullets[i].active = 0;

        bullets[i].x = 0;
        bullets[i].y = 0;

        bullets[i].width = BULLET_WIDTH;
        bullets[i].height = BULLET_HEIGHT;

        bullets[i].speed = BULLET_SPEED;

        bullets[i].damage = 1;
    }
}

void FireBullet(Bullet bullets[],
                int count,
                float x,
                float y)
{
    for (int i = 0; i < count; i++)
    {
        if (!bullets[i].active)
        {
            bullets[i].active = 1;

            bullets[i].x = x - BULLET_WIDTH / 2;
            bullets[i].y = y;

            return;
        }
    }
}

void UpdateBullets(Bullet bullets[],
                   int count)
{
    for (int i = 0; i < count; i++)
    {
        if (!bullets[i].active)
            continue;

        bullets[i].y -= bullets[i].speed;

        if (bullets[i].y < -bullets[i].height)
        {
            bullets[i].active = 0;
        }
    }
}

void DrawBullets(Bullet bullets[],
                 int count,
                 Texture2D texture)
{
    Rectangle source = {
        0,
        0,
        (float)texture.width,
        (float)texture.height
    };

    for (int i = 0; i < count; i++)
    {
        if (!bullets[i].active)
            continue;

        Rectangle destination = {
            bullets[i].x,
            bullets[i].y,
            bullets[i].width,
            bullets[i].height
        };

        DrawTexturePro(
            texture,
            source,
            destination,
            (Vector2){0, 0},
            0.0f,
            WHITE
        );
    }
}

Rectangle GetBulletRect(Bullet *bullet)
{
    Rectangle rect;

    rect.x = bullet->x;
    rect.y = bullet->y;

    rect.width = bullet->width;
    rect.height = bullet->height;

    return rect;
}