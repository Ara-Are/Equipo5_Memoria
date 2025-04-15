#include "raylib.h"
#define TAM 5



void mostrarMat(int[][TAM],int,int);//mostrar la matriz y al usuario

int main()
{

    const int screenWidth = 1000;//Tamaño de la ventana
    const int screenHeight = 900;
    int x=0,y=0;//contador para el movimiento en la matriz


    int mat[TAM][TAM] = {};//declarar la matriz de TAM*TAM
    for (int i = 0; i < TAM; i++) {//llenar la matriz
        for (int j = 0; j < TAM; j++) {
            mat[i][j] = (i*TAM)+j+1;//se llena con el número que representa la casilla
        }
    }

    InitWindow(screenWidth, screenHeight, "Prueba tablero");//abrir la ventana

    while (!WindowShouldClose())    // mientras no se cierre la ventana
    {
        mostrarMat(mat, x, y);//mostrar la matriz y al usuario
        if ((IsKeyPressed(KEY_W)|| IsKeyPressed(KEY_UP)) && y>0 ) {//en caso de que suba por el tablero
            y=y-1;
            mostrarMat(mat, x, y);
        }
        else if ((IsKeyPressed(KEY_S)|| IsKeyPressed(KEY_DOWN)) && y<TAM-1) {//en caso de que baje por el tablero
            y=y+1;
            mostrarMat(mat, x, y);
        }
        if ((IsKeyPressed(KEY_A)|| IsKeyPressed(KEY_LEFT)) && x>0) {//en caso de que  valla a la izquierda
            x=x-1;
            mostrarMat(mat, x, y);
        }
        else if ((IsKeyPressed(KEY_D)|| IsKeyPressed(KEY_RIGHT)) && x<TAM-1) {//en caso de que  valla a la derecha
            x=x+1;
            mostrarMat(mat, x, y);//se muestra en cada movimiento para que se aprecie dicho movimiento
        }

    }
    CloseWindow();//cerrar la ventana

    return 0;
}
void mostrarMat(int mat[][TAM],int x,int y) {//mostrar matriz y al usuario

    BeginDrawing();//para poder activar las opciones de dibujo
    ClearBackground(RAYWHITE);//limpia la pantalla
    DrawText(TextFormat("Matriz %dx%d prueba de movimiento",TAM,TAM), 100, 50, 30, BLUE);//escribe en pantalla
    // Dibujar la matriz
    for (int i = 0; i <TAM ; i++) {
        for (int j = 0; j < TAM; j++) {

            if (i==y && j==x) {//lo que se muestra en la posición del usuario
                DrawRectangle(100+j*50, 100+i*50, 20, 20, PINK);//dibuja un rectangulo
                //DrawRectangle(100+j*50, 100+i*50, 45, 45, PINK);//cuadrado de usuario
            }
            else if (i!=y || j!=x) {//no dibujar el número en la posición de usuario
                // Convertir lo que tiene en la casilla a cadena y dibujarlo con ayuda de formato
                DrawText(TextFormat("%d", mat[i][j]), 100+j*50, 100+i*50, 20, BLACK);
                //DrawRectangle(100+j*50, 100+i*50, 45, 45, BLUE);//matriz con cuadrados
            }
        }
    }

    EndDrawing();
}