#include <iostream>
#include <cmath>

using namespace std;

float g = 0.9; // Яркость сетки (оттенки серого)
float y[20];   // массив координат Y

float R = 1.f;
float G = 0;
float B = 0;

/* GLUI variables */

string func;
int check[9]={0,0,0,0,0,0,0,0,0};
int check_listbox[3]={0,0,0};
float k = 0;
float b = 0;  

float a = 0;
float bb = 0;
float c = 0;

/////////////////////


void calc(){
    // float k;
    char X[256];
    cout << "Enter a function: ";
    cin >> X[256];
    
    //cout << X[1] << endl;
    
    for(int i=0; i<256; ++i){
        if(X[i]=='x'){
            cout << X[i] << endl;
            //k=-1*(X[0]-X[i-1]);
        }
    }
    // cout << "k=" << k;
}

void graph(){
    glPointSize(2.5);
    glColor3f(R,G,B);                              // цвет
    glBegin(GL_POINTS);
    for(float x=-10; x<=10; x+=0.001){
        for(int j=0; j<20; j++){
            
            if(check[1] == 1) y[j]=(a*x)+b;                 // kx+b
            else if(check[2] == 1) y[j]=(a*(x*x))+(bb*x)+c;      // ax^2+bx+c
            
            else if(check[6] == 1){
                    if(check[1] == 1) y[j]=1/pow((a*x)+b, 2);                      // 1/(kx+b)^2
                    else if(check[2] == 1) y[j]=1/pow((a*(x*x))+(bb*x)+c, 2);      // 1/(ax^2+bx+c)^2
                    else if(check[4] == 1) y[j]=1/pow(sin(x), 2);                  // 1/sin^2
                    else if(check[5] == 1) y[j]=1/pow(cos(x), 2);                  // 1/cos^2
                    else y[j]=1/(x*x);     
            }
            else if(check[3] == 1){
                    if(check[1] == 1) y[j]=1/((a*x)+b);                      // 1/kx+b
                    else if(check[2] == 1) y[j]=1/((a*(x*x))+(bb*x)+c);      // 1/(ax^2+bx+c)
                    else if(check[4] == 1) y[j]=1/sin(x);                  // 1/sin
                    else if(check[5] == 1) y[j]=1/cos(x);                  // 1/cos
                    else  y[j]=1/(x);                                      // 1/x
            }
            
            else if(check[4] == 1) y[j]=sin(x);                  // sin
            else if(check[5] == 1) y[j]=cos(x);                  // cos
            else if(check[7] == 1) y[j]=tan(x);                  // tg
            else if(check[8] == 1) y[j]=1/tan(x);                // ctg
            
            else y[j] = 0;
            
            glVertex2f(x*0.1, y[j]*0.1);
        }
    }
    glEnd();
}

///////////////////////////////////////////////////

void mesh(){
    glLineWidth(1);
    glColor3f(g,g,g);
    
    for(float i=-1; i<1; i+=0.1){
        glBegin(GL_LINES);
        glVertex2f(-1, i);
        glVertex2f(1, i);
        glVertex2f(i, -1);
        glVertex2f(i, 1);
        glEnd();
    }
    
    // Оси координат
    glLineWidth(2);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    //Y
    glVertex2f(0,-1);
    glVertex2f(0,1);
    //X
    glVertex2f(-1,0);
    glVertex2f(1,0);
    glEnd();
}

void numbers(){
    glColor3f(0, 0, 0);
    char str[]=" 123456789";
    // 0
    glRasterPos2f(0,-0.05);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0');
    
    // +X
    for (int i=0;str[i]!='\0';i++) {
        glRasterPos2f(i*0.1, -0.05);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
    }
    
    // -X
    for (int i=0;str[i]!='\0';i++) {
        glRasterPos2f(i*(-0.1), -0.05);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
    }
    
    // +Y
    for (int i=0;str[i]!='\0';i++) {
        glRasterPos2f(-0.05, i*0.1);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
    }
    
    // -Y
    for (int i=0;str[i]!='\0';i++) {
        glRasterPos2f(-0.05, i*(-0.1));
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
    }
}
