#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "GL/glut.h"
#include "GL/glu.h"
#include "glui.h"

int main_window;
char COLOR[3][6]={"RED", "GREEN", "BLUE"};         // цвет нового графика

GLUI *glui;
GLUI_Listbox *color;
GLUI_EditText   *edittext;
GLUI_Spinner *k_spin;
GLUI_Spinner *b_spin;
GLUI_Spinner *a_spin;
GLUI_Spinner *bb_spin;
GLUI_Spinner *c_spin;

void gluiFunc(GLUI*);

char buf[80];

char * strrev(char s[]){
    int len = strlen(s);
    // разворот слова в обратном порядке
    for(int j = 0;j <len/2;j++) {
        char temp = s [j]; 
        s [j] = s [len-j-1]; 
        s [len-j-1] = temp;
    }
    return s;
}

char *itoa (int n, char *s) {
 char *t=s; int z=0;
 if (n<0) { z=1; n=-n; }
 do *s++=n%10+'0'; while (n/=10);
 if (z) *s++='-';
 *s='\0';
 return strrev(t);
}

void graph_name(){
    // char str = '+';
    if(k > 0){
        printf("k > 0\n");
        //itoa(k, buf);
        //strcat(&str, buf);
        //printf("\nFunction: y=%s\n", &str);
    }
    
        //if(bb >= 0) strcat(&str);
        //if(c >= 0) strcat(&str, c);
        //printf("%d(x^2)%s", a, str);
    
}

void out_in_konsole(){
    
}

void control_cb( int control ) {
    if(control == 1) {
        GLUI *glui = GLUI_Master.create_glui( "VisualGraph v1.0", 0, 400, 50 );
        gluiFunc(glui);
        glui->set_main_gfx_window( main_window );
    }
    
    if(control == 2) if(func != "") printf( "y =  %s\n", edittext->get_text() );
    //graph_name();
    
    if(check_listbox[0] == 1) { printf("11"); R=1; G=0; B=0; glutPostRedisplay(); }
    if(check_listbox[1] == 1) { printf("12"); R=0; G=1; B=0; glutPostRedisplay(); }
    
    // checkbox kx+b
    if(check[1] == 1) {
        k_spin->enable(); 
        b_spin->enable();
        graph();
    }
    if(check[1] == 0) {
        k_spin->disable();
        b_spin->disable();
    }
    
    // checkbox ax^2+bx+c
    if(check[2] == 1) {
        a_spin->enable();
        bb_spin->enable();
        c_spin->enable();
    }
    if(check[2] == 0){
        a_spin->disable();
        bb_spin->disable();
        c_spin->disable();
    }
}

void gluiFunc(GLUI *glui){
//     char* text  =  "Color: ";
//     char* res_text = new char[strlen(text) + strlen(color[0]) + 1];
//     strcat(res_text, text);
//     strcat(res_text, color[0]);
    
    //string text = "Color: ";
    //string res_text = text + color[0];
    
    
    color = glui->add_listbox("Color", NULL, 0, control_cb);
    color->add_item(check_listbox[0], "RED");
    color->add_item(check_listbox[1], "GREEN");
    glui->add_statictext("");
    
    glui->add_checkbox( "Add the graph", &check[0], 1, control_cb );
    
    glui->add_statictext("");
    glui->add_separator();
    
    glui->add_statictext("                Enter");
    
    edittext = new GLUI_EditText( glui, "y=", func, 2, control_cb );
    
    glui->add_statictext("");
    glui->add_separator();

//-----------------kx + b-----------------------------
    glui->add_statictext("               Choose");
    
    glui->add_checkbox( "kx+b", &check[1], 3, control_cb );
    
    //glui->add_column(true);
    
    k_spin = glui->add_spinner( "k:",GLUI_SPINNER_FLOAT, &a );
    k_spin->disable();
    
    b_spin = glui->add_spinner( "b:",GLUI_SPINNER_FLOAT, &b );
    b_spin->disable();
    
    glui->add_statictext("");
    //glui->add_column(false);

//-----------------ax^2+bx+c--------------------------

    glui->add_checkbox( "ax^2+bx+c", &check[2], 4, control_cb );
    
    a_spin = glui->add_spinner( "a:",GLUI_SPINNER_FLOAT, &a );
    a_spin->disable();
    
    bb_spin = glui->add_spinner( "b:",GLUI_SPINNER_FLOAT, &bb );
    bb_spin->disable();
    
    c_spin = glui->add_spinner( "c:",GLUI_SPINNER_FLOAT, &c );
    c_spin->disable();
    
    glui->add_statictext("");
    
//-----------------1/x--------------------------------

    GLUI_Panel *panel = glui->add_panel( "Panel" );


    glui->add_checkbox_to_panel(panel,  "1/x", &check[3], 5, control_cb );
    glui->add_column_to_panel(panel, true);
    glui->add_checkbox_to_panel(panel,  "1/(x^2)", &check[6], 8, control_cb );
    
//-----------------others-----------------------------

    glui->add_separator();
    glui->add_statictext("");
    
    GLUI_Panel *panel1 = glui->add_panel( "Panel 2" );
    
    glui->add_checkbox_to_panel(panel1, "sin", &check[4], 6, control_cb );
    glui->add_statictext("");
    
    glui->add_checkbox_to_panel(panel1, "cos", &check[5], 7, control_cb );
    glui->add_statictext("");
    
    glui->add_column_to_panel(panel1, true);
    
    glui->add_checkbox_to_panel(panel1, "tg", &check[7], 9, control_cb );
    glui->add_statictext("");
    
    glui->add_checkbox_to_panel(panel1, "ctg", &check[8], 10, control_cb );
    glui->add_statictext("");

//-----------------others-----------------------------
    
    
}

