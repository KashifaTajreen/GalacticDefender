#include "../include/collision.h"
#include "../include/game.h"

#include <stdlib.h>

void CheckBulletEnemyCollision(
    Bullet bullets[],
    int bulletCount,
    Enemy enemies[],
    int enemyCount,
    Explosion explosions[],
    int *score,
    Sound explosionSound)
{
    for(int i=0;i<bulletCount;i++)
    {
        if(!bullets[i].active)
            continue;

        for(int j=0;j<enemyCount;j++)
        {
            if(!enemies[j].active)
                continue;

            if(CheckCollisionRecs(
                GetBulletRect(&bullets[i]),
                GetEnemyRect(&enemies[j])))
            {
                bullets[i].active = 0;

                enemies[j].health -= bullets[i].damage;

                if(enemies[j].health <= 0)
                {
                    CreateExplosion(
                        explosions,
                        enemies[j].x + enemies[j].width/2,
                        enemies[j].y + enemies[j].height/2
                    );
                    PlaySound(explosionSound);

                    if(enemies[j].type == ENEMY_BIG)
                        *score += SCORE_BIG;
                    else
                        *score += SCORE_SMALL;

                    // Respawn enemy
                    enemies[j].y = -(rand()%700) - 100;
                    enemies[j].x = rand() % (SCREEN_WIDTH - (int)enemies[j].width);

                    if(rand()%5==0)
                    {
                        enemies[j].type = ENEMY_BIG;
                        enemies[j].width = ENEMY2_WIDTH;
                        enemies[j].height = ENEMY2_HEIGHT;
                        enemies[j].speed = ENEMY2_SPEED;
                        enemies[j].health = ENEMY2_HEALTH;
                    }
                    else
                    {
                        enemies[j].type = ENEMY_SMALL;
                        enemies[j].width = ENEMY1_WIDTH;
                        enemies[j].height = ENEMY1_HEIGHT;
                        enemies[j].speed = ENEMY1_SPEED;
                        enemies[j].health = ENEMY1_HEALTH;
                    }
                }

                break;
            }
        }
    }
}