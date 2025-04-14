#include "Usuarios.h"

int main(void){
    user_t u;
    u = inicializar_usario("Micros&Control","22.57");
    u.imprimir(u.usuario,u.password);
    validar_user(&u);
    cambiar_contraseña(&u,"22.58");
    u.imprimir(u.usuario,u.password);
    validar_user(&u);
    return 0;
}