#include "../include/explosion.h"
#include "../include/game.h"

void InitExplosions(Explosion explosions[])
{
    for(int i = 0; i < MAX_EXPLOSIONS; i++)
    {
        explosions[i].active = 0;
        explosions[i].timer = 0;

        explosions[i].width = EXPLOSION_SIZE;
        explosions[i].height = EXPLOSION_SIZE;
    }
}

void CreateExplosion(Explosion explosions[],
                     float x,
                     float y)
{
    for(int i = 0; i < MAX_EXPLOSIONS; i++)
    {
        if(!explosions[i].active)
        {
            explosions[i].active = 1;

            explosions[i].x = x;
            explosions[i].y = y;

            explosions[i].timer = 0;

            break;
        }
    }
}

void UpdateExplosions(Explosion explosions[])
{
    for(int i = 0; i < MAX_EXPLOSIONS; i++)
    {
        if(!explosions[i].active)
            continue;

        explosions[i].timer += GetFrameTime();

        if(explosions[i].timer >= EXPLOSION_TIME)
        {
            explosions[i].active = 0;
        }
    }
}

void DrawExplosions(Explosion explosions[],
                    Texture2D texture)
{
    Rectangle source = {
        0,
        0,
        (float)texture.width,
        (float)texture.height
    };

    for(int i = 0; i < MAX_EXPLOSIONS; i++)
    {
        if(!explosions[i].active)
            continue;

        Rectangle destination = {
            explosions[i].x,
            explosions[i].y,
            explosions[i].width,
            explosions[i].height
        };

        DrawTexturePro(
            texture,
            source,
            destination,
            (Vector2){
                explosions[i].width / 2,
                explosions[i].height / 2
            },
            0,
            WHITE
        );
    }
}