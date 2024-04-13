#include <iostream>
#include <stdlib.h>
#include <fstream> // libreria para el manejo de archivos

using namespace std;

void escribir(); // funcion a crear mas adelante
void modificar(const string& nombre_archivo); // función para modificar los textos en el archivo

//cuerpo del programa
int main ()
{
    escribir();
    system("PAUSE");
    return 0;
}

//funcion para crear el archivo
void escribir()
{
    ofstream miarchivo; //variable tipo archivo
    string nombre_archivo; //variable tipo cadena de caracteres para el nombre del archivo
    string texto_archivo; //variable tipo cadena de caracteres para capturar el texto del usuario
    char respuesta; //variable para capturar la respuesta del usuario

    cout << "\n Escribe el nombre para el archivo:"; //texto en pantalla
    getline(cin, nombre_archivo); //captura el nombre del archivo que el usuario escriba
    miarchivo.open(nombre_archivo.c_str(), ios::out); //manipular la cadena de caracteres y darle ese nombre

    if (miarchivo.fail())
    {
        cout<< "Error al abrir el archivo";
        exit(1);
    }

    for (int i = 0; i < 3; ++i) { // Bucle para solicitar tres textos
        cout << "\n Escribe el texto " << i + 1 << " a guardar en el archivo:"; //mensaje en pantalla
        getline(cin, texto_archivo); //capturamos el texto que escriba el usuario para escribirlo en el txt

        miarchivo << texto_archivo << endl; //se escribe en el archivo el texto que el usuario ingrese seguido de un salto de línea
    }

    miarchivo.close(); //cerrar archivo

    cout << "\n¿Desea modificar alguno de los textos? (S/N): ";
    cin >> respuesta;
    cin.ignore(); // Limpiar el buffer de entrada

    if (respuesta == 'S' || respuesta == 's') {
        modificar(nombre_archivo);
    }
}

void modificar(const string& nombre_archivo) {
    ofstream miarchivo; //variable tipo archivo
    miarchivo.open(nombre_archivo.c_str(), ios::out | ios::app); //abrir archivo en modo append (para añadir al final)

    if (miarchivo.fail())
    {
        cout<< "Error al abrir el archivo";
        exit(1);
    }

    int numero_texto;
    string nuevo_texto;

    cout << "\n Que numero de texto desea modificar? (1, 2 o 3): ";
    cin >> numero_texto;
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "\nIngrese el nuevo texto: ";
    getline(cin, nuevo_texto);

    // Mover el puntero al principio del texto seleccionado
    miarchivo.seekp((numero_texto - 1) * 80, ios::beg);
    miarchivo << nuevo_texto; // Sobrescribir el texto en el archivo
    miarchivo.close();
}