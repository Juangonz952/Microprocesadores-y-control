#include "Usuarios.h"

static user_t db[_MAXDB]={{"Micros&Control", "22.57"},
{"Douglas Adams", "42"},
{"Jorge Luis Borges", "Aleph"},
{"Ursula K Leguin", "Terramar"}
};

void imprimir_user(char*u,char*p);
user_t inicializar_usario(char *u,char*p){
    user_t t;
    strcpy(t.usuario,u);
    strcpy(t.password,p);
    t.imprimir = imprimir_user;
    return t;
}

void imprimir_user(char *u,char*p){
    printf("User: %s \n",u);
    printf("Password: %s \n",p);
}
int comparar_user(user_t*a,user_t*b){
    if(strcmp(a->usuario,b->usuario) == 0 && strcmp(a->password,b->password)==0){
        return CORRECTO;
    }
    if(strcmp(a->usuario,b->usuario)== 0 && strcmp(a->password,b->password) !=0){
        return INCORRECTO;
    }
    else{
        return NO_MATCH;
    }
}

int validar_user(user_t*u){
    for(int i=0;i<_MAXDB;i++){
        if(comparar_user(u,&db[i])== CORRECTO){
            printf("Usuario y contraseña aceptados \n");
            return CORRECTO;
        }
        if(comparar_user(u,&db[i])== INCORRECTO){
            printf("Contraseña Incorrecta \n");
            return INCORRECTO;
        }
    }
    printf("Usuario no registrado \n");
    return NO_MATCH;
}

void cambiar_usuario(user_t*u,char*usuario){
    if(validar_user(u) != CORRECTO){
        printf("Acceso Denegado \n");
        return;
    }
    else{
        for(int i=0;i<_MAXDB;i++){
            if(comparar_user(&db[i],u)==CORRECTO){
                strcpy(db[i].usuario,usuario);
                strcpy(u->usuario,usuario);
                printf("Se ha cambiado el usuario correctamente \n");
                u->imprimir;
                return;
            }
        }
    }
}

void cambiar_contraseña(user_t*u,char*password){
    if(validar_user(u) != CORRECTO){
        printf("Acceso Denegado \n");
        return;
    }
    else{
        for(int i=0;i<_MAXDB;i++){
            if(comparar_user(&db[i],u)==CORRECTO){
                strcpy(db[i].password,password);
                strcpy(u->password,password);
                printf("Se ha cambiado el usuario correctamente\n");
                u->imprimir;
                return;
            }
        }
    }
}