/***************************************************************************
*   Copyright (C) 2005 by Hugo Armando                                    *
*   hugo@localhost.localdomain                                            *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/
#ifndef _interprete_H
#define _interprete_H
//#include "Hugoqui.h"
#include <wx/string.h>
#include <iostream>
#include <math.h>
#include "Hugomat.h"
//#include "traduccion.h"
using namespace std;
#define SINTAXIS_PRIMER 1
#define XYZ  2
#define MAS       999999900
#define MENOS     999999901
#define POR       999999902
#define SOBRE     999999903
#define EXPONENCI 999999904
#define INTEGRAL  999999990
#define DERIVADA  999999991
#define RAIZ      999999992
#define LOGARITMO 999999993
#define LOGANATU  999999994
#define POTENCIA  999999995
#define X         999999996
#define Y         999999997
#define Z         999999998

//Funciones
class interprete
{
    //friend void HugoTab::OnCalcularM(wxMouseEvent& event);
public:
    bool interprete1(wxString linea);//principal, se encarga de manejar la interpretacion de datos
    bool interpretar(uli operacion,polinomio poli);//Interpreta polinomio
    bool interpretar(uli operacion,NumeroReal real);//Interpreta numero real
    bool interpretar(uli operacion,NumeroComp comp);//Interpreta numero compuesto
    bool interpretar(uli operacion,wxString poli);//Interpreta texto
    bool interpretarIntegral(uli operacion,wxString poli,wxString limites);//Interpreta integrales
    int hastaParen(wxString a);//Determina longitud de la cadena hasta el signo ')'
    wxString ObtenerPolinomioParen(wxString parentesis);//Devuelve el polinomio dentro del parentesis
    usi ParenNumCarac(wxString parentesis);//Debe retornar el numero de caracteres
    wxString ObtenerPolinomioAntesComa(wxString antesComa);//Regresa el string desde 1 parentesis hasta coma
    wxString ObtenerPolinomioDesComa(wxString DespuesComa,usi it);//RegresaElstring desde , hasta 2 parentesis
    wxString ObtenerLinea(wxString string,int numeroLinea);
    usi ObtenerNumChars(wxString parentesis);//regresa numero chars desde inicio hasta '{'(solo para integral)
    usi ObtenerNumCharsOperacion(wxString parentesis);//regresa numero chars desde inicio hasta + -
    usi ObtenerNumCharsOperacion(wxString parentesis, usi longitudMa);//regresaNumeroCharDeOA+-
    usi ObtenerNumDeOperacion(wxString parentesis);//regresa numero de + y -
    polinomio StringAPoli(wxString poli);//Convierte de String a polinomio
    NumeroComp StringAComp(wxString poli);//Convierte de String a NumeroComp
    NumeroComp PoliAComp(polinomio poli);//Convierte de polinomio a NumeroComp
    NumeroReal CompAReal(NumeroComp poli);//Convierte de NumeroComp a NumeroReal
    wxString PoliAString(polinomio poli);//Convierte de polinomio a wxString
    wxString CompAString(NumeroComp poli);//Convierte de NumeroComp a wxString
private:
    wxString subCadena;
};
#endif
