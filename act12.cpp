#include <iostream>
#include <vector>
#include <stdlib.h>  // for std::rand
#include <algorithm> // for std::sort
#include "act1_2.h"
#include "busqueda.h"

using namespace std;


int main()
{
    int num,busq,tipdb;
    int count=20;
    vector<int> arr_1;
    for (size_t i = 0; i < count; i++)
    {
        arr_1.push_back((int)rand()%20+1);    
    }

    vector<int> arr_2(arr_1);
    vector<int> arr_3(arr_1);
    vector<int> arr_4(arr_1);

    cout<<"Cuantas busquedas deseas hacer"<<endl;
    cin>>busq;
    while (busq>0)
    {
        Busqueda<int> b;
        cout<<"Que numero quieres buscar"<<endl;
        cin >> num;
        cout<<"        "<<endl;
        cout << "Con Busqueda Secuencial.El número que busca se encuentra en la posición: " << b.BusquedaSecuencial(arr_1,num)<< endl;
        cout<<"Que tipo de ordenamiento quiere realizar para la Binaria: "<<endl;
        cout<<"Insertion: 1"<<endl;
        cout<<"Bubble: 2"<<endl;
        cout<<"Quick: 3"<<endl;
        cin>>tipdb;
        if (tipdb==1)
        {
            InsertionSort<int> insetion;
            insetion.sort(arr_2);
            cout << "Con Busqueda Binaria. El número que busca se encuentra en la posición: " << b.BusquedaBinaria(arr_2, 0,count,num)<< endl;
            
        }
        else if (tipdb==2)
        {
            BubbleSort<int> bubble;
            bubble.sort(arr_3);
            cout << "Con Busqueda Binaria. El número que busca se encuentra en la posición: " << b.BusquedaBinaria(arr_3, 0,count,num)<< endl;
            
        }

        else
        {
            Quicksort<int> quick;
            quick.sort(arr_4);
            cout << "Con Busqueda Binaria. El número que busca se encuentra en la posición: " << b.BusquedaBinaria(arr_4,0,count,num)<< endl;

            
        }
        cout<<"________________________"<<endl;
        cout<<" "<<endl;

        busq-=1;

        
    }
   
}

