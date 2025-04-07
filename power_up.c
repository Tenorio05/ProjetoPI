#include "raylib.h"
#include "game.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Power_up_time(EnemyList* enemyList, double time_pass, float normal_speed, int* freeze){ // função para executar o power up "timer" ele congela o tempo
    float amount_time = 3.0; // tempo de congelamento (4 segundos)

    if ( (GetTime() - time_pass) >= amount_time){ // o tempo de congelamento acabou
        *freeze = 0;
    }

    if(*freeze == 0){
        for (int i = 0; i < enemyList->qty_enemies; i++){
            enemyList->enemies[i].speed = normal_speed; // faz com que os inimigos voltem a velocidade normal antes de aceleração
        }
    }

    else { // o tempo de congelamento aida não acabou
        for (int i = 0; i < enemyList->qty_enemies; i++){ // percorre todos os enimigos e zera a velocidade deles
            enemyList->enemies[i].speed = 0;
        }
    }

}

void Power_up_delet(EnemyList* enemyList, int number_enemies){ // mata uma quantidade de inimigos

    for (int i = 0; i < number_enemies; i++){
        RemoveEnemy(enemyList, 0);    
    }

}