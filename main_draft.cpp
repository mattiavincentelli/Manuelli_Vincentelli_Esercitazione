#include <iostream>
#include <cmath>

#include "shape.h"
#include "rectangle.h"
#include "rhombus.h"
#include "right_triangle.h"

using namespace std;

#define MAX_shapeS 10

int main()
{
    shape* shapes[MAX_shapeS];
    int nshapes = 0;

    cout << "===== TEST GERARCHIA shape =====" << endl;

    // 1. Creazione figure
    shapes[nshapes++] = new rectangle(0, 0, 10, 5);
    shapes[nshapes++] = new rhombus(2, 2, 10, 6);
    shapes[nshapes++] = new right_triangle(2, 2, 6, 7);


    // 2. Impostazione testo
    shapes[0]->SetText("rettangolo");
    shapes[1]->SetText("rombo");
    shapes[1]->SetText("triangolo rettangolo");


    // 3. Dump polimorfico
    cout << endl << "===== DUMP POLIMORFICO =====" << endl;

    for (int i = 0; i < nshapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }
   
    float scale;
    cout << "inserisci scalamento" << endl;
    cin >> scale;
    

    for (int i = 0; i < nshapes; i++) {
        shapes[i]->Scale(scale);
    }

    

    for (int i = 0; i < nshapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }
    

    // 4. distruttori 
    for(int i = 0; i < nshapes; i++) {
        delete shapes[i];
    }
   

    cout << endl << "===== FINE TEST =====" << endl;

    return 0;
}