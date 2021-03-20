#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "GL/glut.h"
#include "GL/glu.h"
#include "include/glui.h"
#include "include/basic.h"
#include "include/functions.h"

using namespace std;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    mesh();         // коорд. сетка
    graph();        // график
    numbers();      // координаты 
    
    glFlush();
} 

void Keyboard(unsigned char key, int x, int y){ if(key==27) exit(0); } 

void Init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    
    glutDisplayFunc(display);
    glutKeyboardFunc(Keyboard); 
}

int main(int argc, char* argv[]){
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(800,100);
    main_window = glutCreateWindow("VisualGraph v1.0");
    
    // Инициализация GLUT функций
    Init();
     
    //***********GLUI***********//
    
    GLUI_Master.set_glutIdleFunc( NULL );
    glui = GLUI_Master.create_glui( "VisualGraph v1.0", 0, 400, 50 );
    gluiFunc(glui);
    glui->set_main_gfx_window( main_window );

    //**************************//
    glui->sync_live();
    graph_name();
    glutMainLoop();
    return 0;
}


/*

 to do list
 
 \/ 1) сетка
 \/ 2) цифры
 \/ 4) построение графика
 5) GUI
    \/ 1. split
    ? 2. y= 
    \/ 3. kx+b (checkbox, spinner)
    \/ 4. ax^2+bx+c (checkbox, spinner)
    \/ 5. 1/x
    \/ 6. trigonometry(sin, cos)
    
 6) Вывод в консоль(назв. гр-ка, коорд. массив)
 
 7) неск. графиков (цвета, отрисовка)
 
 */
