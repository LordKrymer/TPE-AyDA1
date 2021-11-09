#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED
#include <string.h>
#include "Naccent.h"
using namespace std;

class libro
{
    private:
        string isbn;
        string titulo;
        string autor;
        int fecha;
        string pais;
        float precio;
        string idiomas;
        string convertirAString(char a[], int lenght){
            int i;
            string s = "";
            for (i = 0; i < lenght; i++) {
            s = s + a[i];
            }

            return s;
        }

    public:
        libro(string isbn, string titulo, string autor, int fecha, string pais, string &idiomas, float precio){
            this->isbn = isbn;
            this->titulo = titulo;
            this->autor = autor;
            this->fecha = fecha;
            this->pais = pais;
            int n = idiomas.length();
            char idioms[n];
            strcpy(idioms, idiomas.c_str());
            for (int i = 0; i < n; i++){
                idioms[i] = removeAccent(idioms[i]);
            }
            idiomas = convertirAString(idioms, n);
            this->idiomas = idiomas;
            this->precio = precio;
        }

        string getTitle(){return this->titulo;} //Observadora
        int getDate(){return this->fecha;} //Observadora
        string getIdiomas() const {return this-> idiomas;} //Observadora
        string getIsbn() {return this-> isbn;} //Observadora
        string getAuthor() {return this-> autor;} //Observadora
        string getPais() {return this-> pais;} //Observadora
        float getPrice() {return this ->precio;} //Observadora

        int imprimirLibro()const{          //Observadora
           cout<<"ISBN: "<<this->isbn<<endl;
           cout<<"titulo: "<<this->titulo<<endl;
           cout<<"autor: "<<this->autor<<endl;
           cout<<"Año de publicacion: "<<this->fecha<<endl;
           cout<<"Pais de origen: "<<this->pais<<endl;
           cout<<"Idiomas Disponibles: "<<this->idiomas<<endl;
           cout<<"Precio: "<<this->precio << "\n" <<endl;
           return 0;
        }

        libro& operator=( libro otro){   //Modificadora
            this->pais= otro.getPais();
            this->isbn= otro.getIsbn();
            this->titulo= otro.getTitle();
            this->autor= otro.getAuthor();
            this->fecha= otro.getDate();
            this->pais= otro.getPais();
            this->idiomas= otro.getIdiomas();
            this->precio= otro.getPrice();
            return *this;
        }


};


#endif // LIBRO_H_INCLUDED
