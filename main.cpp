#include <iostream>
#include <fstream>
#include <clocale>
#include "ListaBook.h"
#include "Procesador_archivo.h"
using namespace std;

void Interfaz_usuario(Libreria &L);

int main()
{
    Libreria L = *(new Libreria);
    string continuar = "si";

    setlocale(LC_ALL, "");
   procesar_archivo_entrada(L,"libros.csv");

    while (continuar == "si"){

    Interfaz_usuario(L);
    cout<<"Desea Continuar con la ejecucion? (si/no)"<<endl;
    cin>> continuar;

    while ((continuar != "si") && (continuar != "no")){
        cout<<"Opcion invalida, intentelo de nuevo (si/no)"<<endl;
        cin>>continuar;
        }
    system("cls");
    }

    return 0;
}


void Interfaz_usuario(Libreria &L){
    int opcion;
    cout<<"Ingrese el numero de servicio a utilizar"<<endl;
    cout<<"1:Verificar si se encuentra un libro por su nombre (uso de comodines habilitado, * para una palabra y ? para una letra)"<<endl;
    cout<<"2:Mostrar todos los libros que hayan sido publicados en un intervalo de años"<<endl;
    cout<<"3:Mostrar los libros mas baratos disponibles en el idioma seleccionado(Maximo 10)"<<endl;
    cin>> opcion;
    string aux;
    getline (cin, aux);
    system("cls");
    switch(opcion){
        case 1:{
             string aBuscar;
             cout<<"Titulo: ";
             string busqueda;
             getline (cin, aBuscar);
             if (L.buscarPorTitulo(aBuscar)){
                cout<<"El libro se encuentra en la Libreria"<<endl;
             }
             else {
                cout<<"El libro no se encuentra en la Libreria"<<endl;
             }
        break;
    }
        case 2:{
            int fechaInicio;
            int fechaFinal;
            cout<<"Introduzca desde que año quiere buscar"<<endl;
            cin>> fechaInicio;
            cout<<"Introduzca hasta que año quiere buscar"<<endl;
            cin>> fechaFinal;
            if (fechaInicio <= fechaFinal){
                L.imprimirEntreFechas(fechaInicio,fechaFinal);
            }
            else{
                cout<<"Hubo un error al introducir los años...  volviendo al menu"<<endl;
            }
            break;
        }
        case 3:{

                string buscarIdioma;
                string aux;
                cout<<"Ingrese el idioma que desea consultar"<<endl;
                getline(cin, aux);
                buscarIdioma = aux;
                cout<<aux<<endl;
                if (!L.imprimirEconomicos(buscarIdioma)){
                    cout<<"El idioma no esta disponible"<<endl;
                };
                break;
            }
            default: {cin>>opcion;}
        }
}
