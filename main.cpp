/**
  * @file imagenES.cpp
  * @brief Fichero con definiciones para la E/S de imágenes
  *
  * Permite la E/S de archivos de tipo PGM,PPM
  *
  */

#include <fstream>
#include <string>
#include <iostream>
#include <netinet/in.h>
//#include <graphics.h>

#include "imagenES.h"

using namespace std;


TipoImagen::LeerTipo(ifstream& f)
{
    char c1,c2;
    TipoImagen res= IMG_DESCONOCIDO;

    if (f) {

        /*
            The first eight bytes of a PNG file always contain the following values:
            (decimal)              137  80  78  71  13  10  26  10
            (hexadecimal)           89  50  4e  47  0d  0a  1a  0a
            (ASCII C notation)    211   P   N   G  r  n �32 n
        */
        unsigned char cas[8];
        unsigned char check[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
        bool fallo = false;
        f.read(reinterpret_cast<char>(cas), 8);
        for (int i = 0; i < 8 && !fallo; i++)
            if (check[i] != cas[i])
                fallo = true;
        //cout.setf ( ios::hex, ios::basefield );
        //cout.setf ( ios::showbase );
        //cout << (int)check[i] << " ";

        if (!fallo)
            return IMG_PNG;

        f.seekg(0L, ios::beg);

        c1=f.get();
        c2=f.get();

        if (f && c1=='P')
            switch (c2) {
                case '5': res= IMG_PGM; break;
                case '6': res= IMG_PPM; break;
                default: res= IMG_DESCONOCIDO;
            }
    }
    return res;
}

// _____________________________________________________________________________

char SaltarSeparadores (ifstream& f)
{
    char c;
    do {
        c= f.get();
    } while (isspace(c));
    f.putback(c);
    return c;
}

// _____________________________________________________________________________

bool LeerCabecera (ifstream& f, int& filas, int& columnas, bool png = false)
{
    //Si la imagen es PNG leemos algunos datos.
    if (png){
        f.seekg(16L, ios::beg);

        f.read(reinterpret_cast<char>(&columnas;), 4);
        f.read(reinterpret_cast<char>(&filas;), 4);

        columnas = ntohl(columnas);
        filas = ntohl(filas);

        return true;
    }else{
        int maxvalor;

        while (SaltarSeparadores(f)=='#')
            f.ignore(10000,'n');

        f >> columnas >> filas >> maxvalor;

        if (/*str &&*/ f && filas>0 && filas <5000 && columnas >0 && columnas<5000) {
            f.get(); // Saltamos separador
            return true;
        }
        else return false;
    }
}

// _____________________________________________________________________________

TipoImagen LeerTipoImagen(const char nombre[], int& filas, int& columnas)
{
    TipoImagen tipo;
    filas=columnas=0;
    ifstream f(nombre);

    tipo=LeerTipo(f);
    if (tipo!=IMG_DESCONOCIDO)
        if (!LeerCabecera(f,filas,columnas, tipo == IMG_PNG)) {
            tipo=IMG_DESCONOCIDO;
        }

    return tipo;
}


// _____________________________________________________________________________

bool LeerImagenPNG (const char nombre[], int& filas, int& columnas){

    bool exito = false;
    filas      = 0;
    columnas   = 0;
    ifstream f(nombre);

    if (LeerTipo(f) == IMG_PNG)
        if (LeerCabecera(f, filas, columnas, true))
            exito = true;
    //if (f.read(reinterpret_cast<char>(buffer), filas * columnas))

    return exito;
}

/* Fin Fichero: imagenES.cpp */
//if (f.read(reinterpret_cast<char>(buffer), filas * columnas))

return exito;
}

/* Fin Fichero: imagenES.cpp */

