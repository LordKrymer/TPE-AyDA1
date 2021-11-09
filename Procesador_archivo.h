#ifndef PROCESADOR_ARCHIVO_H_INCLUDED
#define PROCESADOR_ARCHIVO_H_INCLUDED


void procesar_archivo_entrada(Libreria &L,string origen)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_libros = atoi(linea.c_str());
        cout << "Se cargarán " << cantidad_libros << " libros." << endl;

        //Leemos de una linea completa por vez (getline).
        int nroLibro = 1;
        while (getline(archivo, linea)) {
            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(';');

            //Informacion entre pos_inicial y pos_final
            string isbn = linea.substr(pos_inicial, pos_final);

            //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string titulo = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string autor = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            int fechaPublicacion = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

             //Quinta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string paisOrigen = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Sexta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            float precio = atof(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            pos_inicial = pos_final + 2;
            pos_final = linea.size()-1;
            string idiomas = linea.substr(pos_inicial, pos_final - pos_inicial);
            //cout << "   IDIOMAS: " << idiomas<<endl;


            nroLibro++;
            libro* libroNuevo = new libro(isbn, titulo, autor, fechaPublicacion, paisOrigen, idiomas, precio);
            L.agregarLista(libroNuevo);

        }
    }

}
#endif // PROCESADOR_ARCHIVO_H_INCLUDED
