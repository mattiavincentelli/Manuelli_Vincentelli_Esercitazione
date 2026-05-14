#include <iostream>
#include <cmath>

#include "shape.h"
#include "rectangle.h"
#include "rhombus.h"

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


    // 2. Impostazione testo
    shapes[0]->SetText("rettangolo");
    shapes[1]->SetText("rombo");


    // 3. Dump polimorfico
    cout << endl << "===== DUMP POLIMORFICO =====" << endl;

    for (int i = 0; i < nshapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }

    

    cout << endl << "===== FINE TEST =====" << endl;

    return 0;
}