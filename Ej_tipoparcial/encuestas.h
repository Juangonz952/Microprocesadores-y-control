// Librerias

// Macros y Defines
#define _LENGTH_MATERIA 20
#define _NA 0
#define _LENGHT_COMENTARIOS 11
#define _LENGTH_NOMBRE 20

// Tipos de Datos

typedef struct encuesta_t{
    char Materia[_LENGTH_MATERIA]; // El nombre de la materia mas largo tiene 19 caracteres
    unsigned int puntaje_materia; //Es obligatorio 1,2,3,4,5
    char nombre_docente[_LENGTH_NOMBRE];
    int puntaje_docente; // puede ser Na_123123
    char nombre_ayudante[_LENGTH_NOMBRE];
    int puntaje_ayudante;
    char comentario[_LENGHT_COMENTARIOS]
};

// Funciones Globales 
void print_encuesta(encuesta_t *p); //Imprime la encuesta en Pantalla
char* get_materia(encuesta_t *p);
// Funciones Locales
