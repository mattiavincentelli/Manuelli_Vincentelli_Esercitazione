#include <iostream>
#include <cmath>
#include <string>   

#include "shape.h"
#include "rectangle.h"
#include "rhombus.h"
#include "right_triangle.h"
#include "grid.h"

using namespace std;

#define MAX_shapeS 10

void Print_All_Pol(shape *shape[], int n);
void Modify_Pol(shape *shape[], grid *grid);
void Change_Pos(shape *shape[]);

int main()
{
    grid my_grid(100, 100);
    shape* shapes[MAX_shapeS];
    int nshapes = 0;

    int running = 1;
    while(running) {
        int choice;
        cout << "MENU: " << endl << "1 - Visualizza tutti i poligoni" << endl;
        cout << "2 - Modifica le proprietà di un poligono" << endl << "3 - Sposta un poligono sulla griglia";
        cout << "4 - Inserisci un nuovo poligono" << endl << "5 - Cancella un poligono";
        cout << "6 - Cancella tutti i poligono" << endl << "0 - Esci";
        
        if(!cin >> choice)
            cout << "inserire uno dei numeri interi indicati" << endl;
        
        if(choice < 0 || choice > 6)
            cout << "scelta non disponibile" << endl;

        switch(choice){
            case 0:
                running = 0;
                break;
            case 1:
                Print_All_Pol(&shapes[nshapes], nshapes);
                break;
            case 2:
                
                break;
            case 3:
              
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
              
                break;
        }
        


    }
   

    return 0;
}



void Print_All_Pol(shape *shape[], int n) {
    for (int i = 0; i < n; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shape[i]->Dump();
    }
}

void Modify_Pol(shape *shape[], grid *grid) {
    float new_w, new_h;
    string new_text;
    const char* text_ptr = new_text.c_str();
    int n_Pol;

    
    cout << "quale poligono vuoi modificare?";
    cin >> n_Pol;

    cout << "Come vuoi modificare l'ampiezza?" << endl; 
    cin >> new_w;


    cout << "Come vuoi modificare l'altezza?" << endl; 
    cin >> new_h;

    cout << "Come vuoi modificare il testo?" << endl; 
    getline(cin, new_text);

    if(shape[n_Pol]->GetWidth() + new_w > grid->GetWidth() || shape[n_Pol]->GetHeight() + new_h > grid->GetHeight())
        cout << "poligono fuori dalla griglia" ; 
    else{
        shape[n_Pol]->SetWidth(new_w);
        shape[n_Pol]->SetHeight(new_h);
        shape[n_Pol]->SetText(text_ptr);
    }
    
}

void Change_Pos(shape *shape[]){}