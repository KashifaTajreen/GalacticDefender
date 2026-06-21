#include "../include/enemy.h"
#include "../include/game.h"
#include "../include/enemybullet.h"

#include <stdlib.h>
#include <time.h>

void InitEnemies(Enemy enemies[], int count)
{
    srand(time(NULL));

    for(int i=0;i<count;i++)
    {
        enemies[i].active = 1;

        enemies[i].shootTimer = 0;

        // 1 out of 5 enemies is a BIG enemy
        if(rand()%5==0)
        {
            enemies[i].type = ENEMY_BIG;

            enemies[i].width = ENEMY2_WIDTH;
            enemies[i].height = ENEMY2_HEIGHT;

            enemies[i].speed = ENEMY2_SPEED;

            enemies[i].health = ENEMY2_HEALTH;
        }
        else
        {
            enemies[i].type = ENEMY_SMALL;

            enemies[i].width = ENEMY1_WIDTH;
            enemies[i].height = ENEMY1_HEIGHT;

            enemies[i].speed = ENEMY1_SPEED;

            enemies[i].health = ENEMY1_HEALTH;
        }

        enemies[i].x = rand() % (SCREEN_WIDTH - (int)enemies[i].width);

        enemies[i].y = -(rand()%1200);
    }
}

void UpdateEnemies(Enemy enemies[], int count)
{
    for(int i=0;i<count;i++)
    {
        if(!enemies[i].active)
            continue;

        enemies[i].y += enemies[i].speed;

        enemies[i].shootTimer += GetFrameTime();

        if(enemies[i].y > SCREEN_HEIGHT + 100)
        {
            // Respawn
            enemies[i].y = -(rand()%800)-100;

            enemies[i].x = rand()%(SCREEN_WIDTH-(int)enemies[i].width);

            enemies[i].shootTimer = 0;

            if(rand()%5==0)
            {
                enemies[i].type = ENEMY_BIG;

                enemies[i].width = ENEMY2_WIDTH;
                enemies[i].height = ENEMY2_HEIGHT;

                enemies[i].speed = ENEMY2_SPEED;

                enemies[i].health = ENEMY2_HEALTH;
            }
            else
            {
                enemies[i].type = ENEMY_SMALL;

                enemies[i].width = ENEMY1_WIDTH;
                enemies[i].height = ENEMY1_HEIGHT;

                enemies[i].speed = ENEMY1_SPEED;

                enemies[i].health = ENEMY1_HEALTH;
            }
        }
    }
}

void DrawEnemies(Enemy enemies[],
                 int count,
                 Texture2D enemy1,
                 Texture2D enemy2)
{
    Rectangle source;

    source.x = 0;
    source.y = 0;

    for(int i=0;i<count;i++)
    {
        if(!enemies[i].active)
            continue;

        Texture2D texture;

        if(enemies[i].type == ENEMY_BIG)
            texture = enemy2;
        else
            texture = enemy1;

        source.width = texture.width;
        source.height = texture.height;

        Rectangle destination;

        destination.x = enemies[i].x;
        destination.y = enemies[i].y;
        destination.width = enemies[i].width;
        destination.height = enemies[i].height;

        DrawTexturePro(
            texture,
            source,
            destination,
            (Vector2){0,0},
            0,
            WHITE
        );

        // ---------- Enemy Health Bar ----------

// Health percentage
float percent;

if(enemies[i].type == ENEMY_BIG)
    percent = (float)enemies[i].health / ENEMY2_HEALTH;
else
    percent = (float)enemies[i].health / ENEMY1_HEALTH;

// Health bar colour
Color healthColor;

if(percent > 0.6f)
    healthColor = GREEN;
else if(percent > 0.3f)
    healthColor = YELLOW;
else
    healthColor = RED;

// Small health bar
float barWidth = enemies[i].width * 0.6f;

float x = enemies[i].x +
          (enemies[i].width - barWidth) / 2;

DrawRectangle(
    x,
    enemies[i].y - 8,
    barWidth,
    4,
    DARKGRAY);

DrawRectangle(
    x,
    enemies[i].y - 8,
    barWidth * percent,
    4,
    healthColor);
    }
}
Rectangle GetEnemyRect(Enemy *enemy)
{
    Rectangle rect;

    rect.x = enemy->x + 12;
    rect.y = enemy->y + 12;

    rect.width = enemy->width - 24;
    rect.height = enemy->height - 24;

    return rect;
}
void EnemyShoot(
    Enemy enemies[],
    int count,
    EnemyBullet bullets[])
{
    for(int i = 0; i < count; i++)
    {
        if(!enemies[i].active)
            continue;

        // Only the boss shoots
        if(enemies[i].type != ENEMY_BIG)
            continue;

        if(enemies[i].y < 0)
            continue;

        if(enemies[i].shootTimer >= 2.0f)
        {
           FireEnemyBullet(
                bullets,
                enemies[i].x + enemies[i].width * 0.5f - 14,
                enemies[i].y + enemies[i].height - 5);

            enemies[i].shootTimer = 0;
        }
    }
}