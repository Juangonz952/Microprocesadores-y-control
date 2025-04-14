#ifndef USUARIOS_H
#define USUARIOS_H

/* Librerias */
#include <stdio.h>
#include <string.h>

/*Constantes*/
#define USER_LENGTH 20
#define PASS_LENGTH 20
#define _MAXDB 4
#define CORRECTO 1
#define INCORRECTO -1
#define NO_MATCH 0

/*Estructuras */

typedef struct users{
    char usuario[USER_LENGTH];
    char password[PASS_LENGTH];
    void (*imprimir)(char *usuario,char *password);
}user_t;

user_t inicializar_usario(char*u,char*p);
int validar_user(user_t *u);
void cambiar_usario(user_t*u , char*usuario);
void cambiar_contraseña(user_t*u,char *password);







#endif