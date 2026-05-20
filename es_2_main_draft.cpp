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
void Change_Pos(shape *shape[], grid *grid);
void Insert_New_Pol(shape *shape[], int *n, grid *grid);
void Delete_Pol(shape *shape[], int n);
void Delete_All_Pols(shape *shape[], int n);

int main()
{
    grid *my_grid = new grid(100, 100);
    shape* shapes[MAX_shapeS];
    int nshapes = 0;
    int *nshapes_ptr = &nshapes;

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
                Modify_Pol(&shapes[nshapes], my_grid);
                break;
            case 3:
                Change_Pos(&shapes[nshapes], my_grid);
                break;
            case 4:
                Insert_New_Pol(&shapes[nshapes], nshapes_ptr, my_grid);
                break;
            case 5:
                Delete_Pol(&shapes[nshapes], nshapes);
                break;
            case 6:
                Delete_All_Pols(&shapes[nshapes], nshapes);
                break;
            default: 
                break;
        }
        


    }
   
    for(int i = 0; i < nshapes; i++)
        delete shapes[i];

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

void Change_Pos(shape *shape[], grid *grid) {
    float new_w, new_h;
    
    int n_Pol;

    
    cout << "quale poligono vuoi modificare?";
    cin >> n_Pol;

    cout << "Come vuoi modificare l'ampiezza?" << endl; 
    cin >> new_w;


    cout << "Come vuoi modificare l'altezza?" << endl; 
    cin >> new_h;


    if(shape[n_Pol]->GetWidth() + new_w > grid->GetWidth() || shape[n_Pol]->GetHeight() + new_h > grid->GetHeight())
        cout << "poligono fuori dalla griglia" ; 
    else{
        shape[n_Pol]->SetWidth(new_w);
        shape[n_Pol]->SetHeight(new_h);
    }
}


void Insert_New_Pol(shape *shape[], int *n, grid *grid) {
    int choice;
    float x, y, height, width;

    cout << "Quale poligono vuoi inserire?" << endl;

    cout << "1. rettangolo" << endl << "2. rombo" << endl << "3. triangolo rettangolo" << endl; 
    cin >> choice;
    
    cout << "Che x ha sulla griglia?" << endl;
    cin >> x;

    cout << "Che y ha sulla griglia?" << endl;
    cin >> y;

    cout << "Che altezza ha?" << endl;
    cin >> height;

    cout << "Che larghezza ha?" << endl;
    cin >> width;


    if((choice) < 4  || choice > 0 || x + width < grid->GetWidth() || y + height < grid->GetHeight()) {
        switch(choice) {
            case 1:
                shape[*n] = new rectangle(x, y, width, height); 
                break;
            case 2:
                shape[*n] = new rhombus(x, y, width, height);
                break;  
            case 3:
                shape[*n] = new right_triangle(x, y, width, height);
                break;
            default:
                break;
        }
    }else
        cout << "Specifiche non valide" << endl;
    
    
}


void Delete_Pol(shape *shape[], int n) {
    int choice;

    cout << "Quale poligono vuoi cancellare?" << endl; 
    cin >> choice;

    if(choice < 0 || choice > n)
        cout << "Scelta non valida" << endl; 
    
    delete shape[choice];
}

void Delete_All_Pols(shape *shape[], int n) {
    for(int i =0; i < n; i++)
        delete shape[i];
}
