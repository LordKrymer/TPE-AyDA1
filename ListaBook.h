#ifndef LISTABOOK_H_INCLUDED
#define LISTABOOK_H_INCLUDED
#include "libro.h"
#include <sstream>
#include "Naccent.h"

typedef struct nodo {libro* book; struct nodo* sig;};

class Libreria{

    private:

        nodo* listaLibros;

        bool coincidencia (libro* libroActual,string buscar){  //Observadora
            int n = buscar.length();
            int m = libroActual->getTitle().length();
            char busqueda[n+1];
            char nombre[m+1];
            strcpy(busqueda,buscar.c_str());
            strcpy(nombre,libroActual->getTitle().c_str());

            for (int i=0; i<m; i++){
                nombre[i] = removeAccent(nombre[i]);
            }
            bool match = true;
            int cont1 = 0;
            int cont2 = 0;
            while ((cont1 < n) && (cont2 < m) && (match)){
                if (busqueda[cont1] == '*'){
                    while ((cont2 < m) && (nombre[cont2] != ' ')){
                        cont2++;
                    }
                    cont1++;
                }
                else{
                    if ((cont1 < n) && (cont2 < m)){
                        if ((busqueda[cont1] == nombre[cont2]) || (busqueda[cont1] == '?')){
                            cont1++;
                            cont2++;
                        }
                        else{
                            match = false;
                        }
                    }
                }
            }
                return ((cont1 == n) && (cont2 == m));
        }


    void insertarNodo(nodo* &cursor, nodo* aAgregar){ //Modificadora
            if (cursor == nullptr){
                cursor = aAgregar;
            }
            else{
                    aAgregar->sig = cursor;
                    cursor = aAgregar;
            }
    }

    void agregarNodo(nodo* &cursor, nodo* &aAgregar){ //Modificadora
            if ((cursor == nullptr)||(cursor->book->getPrice() > aAgregar->book->getPrice())){
                insertarNodo(cursor,aAgregar);
                }
                else{
                    agregarNodo(cursor->sig, aAgregar);
                }
            }

    bool idiomaDisponible(string idioma, nodo* libroActual){ //Observadora
            int pos = 0;
            int pos_final = 1;
            bool disponible = false;
            string idiomas = libroActual->book->getIdiomas();
             if (idiomas.find(idioma) != -1){
                disponible = true;
             };
            return disponible;
        }

    public:
        Libreria(){ //Constructor
            listaLibros = nullptr;
        }

        ~Libreria(){ //Destructor
            nodo * aEliminar = listaLibros;
            while (listaLibros != nullptr){
                aEliminar = listaLibros;
                delete aEliminar;
                aEliminar = nullptr;
                listaLibros = listaLibros->sig;
            }
        }

    void agregarLista(libro* pLibro){ //Modificadora
        nodo* nuevoNodo = new nodo;
        (*nuevoNodo).book = pLibro;
        (*nuevoNodo).sig = nullptr;
        agregarNodo(listaLibros, nuevoNodo);
        nodo* cursor = listaLibros;
        while (cursor != nullptr){
            cursor = cursor->sig;
        }
        }

    bool imprimirEconomicos(string idioma){ //Observadora
        nodo * cursor = listaLibros;
        unsigned int cont = 0;
        while ((cursor != nullptr) && (cont < 10)){
            if (idiomaDisponible(idioma, cursor)){
                cursor->book->imprimirLibro();
                cont++;
            }
            cursor = cursor->sig;
        }
        return (cont > 0);
    }

    void imprimirEntreFechas(int fechaInicial, int fechaFinal){ //Observadora
            nodo* cursor = listaLibros;
            if (cursor == nullptr){cout<<"cout null"<<endl;}
            while(cursor != nullptr){
                if ((cursor->book->getDate() >= fechaInicial) && (cursor->book->getDate() <= fechaFinal)){
                        cursor->book->imprimirLibro();
                }
                cursor = cursor->sig;
            }
            }

    bool buscarPorTitulo(string titulo){ //Observadora
        nodo* cursor = listaLibros;
        bool match = false;
        while ((cursor != nullptr) && (!coincidencia(cursor->book,titulo))){
            cursor = cursor->sig;
        }
        return (cursor != nullptr);
    }
};

#endif // LISTABOOK_H_INCLUDED
