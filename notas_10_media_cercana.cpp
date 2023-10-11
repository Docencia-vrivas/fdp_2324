/******************************************************************************
@file notas_10_media_cercana.cpp
@author Víctor Rivas <vrivas@ujaen.es>
@date 11-oct-2023
@desc Realizar un programa que pida 10 notas y calcule la nota media y la más cercana a dicha media

*******************************************************************************/
#include <iostream>
using namespace std;

// Si solo hubiera que calcular la media, NO haría falta un vector.
// Pero como luego tenemos que decir cuál es la nota más cercana a la media, tenemos que
// guardar los datos.
const int MAX_NOTAS = 10;

int main()
{
    double notas[MAX_NOTAS];
    int num_notas = 0;

    // Pedimos las notas
  
    for ( int i=0; i<MAX_NOTAS; ++i ) {
        cout << "Introduzca la nota número " << i <<": ";
        cin >> notas[i];
        ++num_notas;
    }

    // Calculamos la media
  
    double media = 0;
    for( int i=0; i<num_notas; ++i ) {
        media+=notas[i];
    }
    media/=num_notas;
    cout << "La media es " << media << endl;


    // Calculamos la nota más cercana a la media. Empezamos con la nota de la posición 0
  
    int posicion_nota_mas_cercana = 0;
    double diferencia_mas_pequena= notas[0]-media;
  
    // La diferencia siempre la consideramos en valor absoluto, o sea, en valor positivo
    // así que si ha salido negativa, le cambiamos el valor.
  
    if( diferencia_mas_pequena<0 ) {
        diferencia_mas_pequena= -diferencia_mas_pequena;
    }

    // Seguimos con las demás notas: la 1, la 2, etc.
  
    for( int i=1; i<num_notas; ++i ) {
        double diferencia_a_la_media= notas[i]-media;
      
        // Si es negativa, la convierto en positiva, como antes
      
        if( diferencia_a_la_media<0 ) {
            diferencia_a_la_media= -diferencia_a_la_media;
        }

        // Si la nueva diferencia es menor que la que ya tenía, actualizo las variables
      
        if( diferencia_a_la_media<diferencia_mas_pequena ) {
            diferencia_mas_pequena = diferencia_a_la_media;
            posicion_nota_mas_cercana = i;
        }

    }

    cout << "La nota más cerca a la media es " << notas[posicion_nota_mas_cercana]<<endl;

    return 0;
}
