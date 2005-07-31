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
#include <wx/string.h>
#include <stdlib.h>
#define INGLES 1
#define ESPANOL 0
FILE *lenguaje=NULL;
wxString L_MenuMatematica,L_MenuMatematica_Suma,L_MenuMatematica_Resta,L_MenuMatematica_Multiplicacion;
wxString L_MenuMatematica_Division, L_MenuMatematica_Potencia, L_MenuMatematica_Raiz;
wxString L_MenuMatematica_Exponencial,L_MenuMatematica_Ln,L_MenuMatematica_Log,L_MenuMatematica_Derivada;
wxString L_MenuMatematica_Integral,L_MenuFisica,L_MenuFisica_MUR,L_MenuFisica_MUA,L_MenuFisica_Parab;
wxString L_MenuQuimica,L_MenuQuimica_Tempe,L_MenuQuimica_Mol,L_MenuQuimica_Vol,L_Archivo,L_Archivo_Salir;
wxString L_Edicion,L_Edicion_Copiar,L_Edicion_Pegar,L_Edicion_Cortar,L_Edicion_SelTodo,L_Ayuda,L_Ayuda_Ace;
void lenguajea()
{
    int lenguajeV;
    lenguaje=fopen("lang.len","a+t");
    fscanf(lenguaje,"%i",&lenguajeV);
    if(lenguajeV==INGLES)
    {
	L_MenuMatematica="&Mathematics";
	L_MenuMatematica_Suma="Sum";
	L_MenuMatematica_Resta="Remainder";
	L_MenuMatematica_Multiplicacion="";
	L_MenuMatematica_Division="Division";
	L_MenuMatematica_Potencia="Power";
	L_MenuMatematica_Raiz="Root";
	L_MenuMatematica_Exponencial="Exponencial";
	L_MenuMatematica_Ln="Natural logaritm";
	L_MenuMatematica_Log="Logaritm";
	L_MenuMatematica_Derivada="Derivative";
	L_MenuMatematica_Integral="Integral";
	L_MenuFisica="&Physics";
	L_MenuFisica_MUR="Uniform movement";
	L_MenuFisica_MUA="Accelerated movement";
	L_MenuFisica_Parab="Parabolic movement";
	L_MenuQuimica="&Chemistry";
	L_MenuQuimica_Tempe="Temperature";
	L_MenuQuimica_Mol="Mol";
	L_MenuQuimica_Vol="Volume";
	L_Archivo="&File";
	L_Archivo_Salir="Exit";
	L_Edicion="Edit";
	L_Edicion_Copiar="Copy";
	L_Edicion_Pegar="Paste";
	L_Edicion_Cortar="Cut";
	L_Edicion_SelTodo="Select all";
	L_Ayuda="&Help";
	L_Ayuda_Ace="About...";
    }
    else if (lenguajeV==ESPANOL)
    {
	L_MenuMatematica="&Matematica";
	L_MenuMatematica_Suma="Suma";
	L_MenuMatematica_Resta="Resta";
	L_MenuMatematica_Multiplicacion="Multiplicacion";
	L_MenuMatematica_Division="Division";
	L_MenuMatematica_Potencia="Potencia";
	L_MenuMatematica_Raiz="Raiz";
	L_MenuMatematica_Exponencial="Exponencial";
	L_MenuMatematica_Ln="Logaritmo natural";
	L_MenuMatematica_Log="Logaritmo";
	L_MenuMatematica_Derivada="Derivada";
	L_MenuMatematica_Integral="Integral";
	L_MenuFisica="Fisica";
	L_MenuFisica_MUR="Movimiento uniforme rectilineo";
	L_MenuFisica_MUA="Movimiento uniforme acelerado";
	L_MenuFisica_Parab="Movimiento parabolico";
	L_MenuQuimica="&Quimica";
	L_MenuQuimica_Tempe="Temperatura";
	L_MenuQuimica_Mol="Moles";
	L_MenuQuimica_Vol="Volumen";
	L_Archivo="&Archivo";
	L_Archivo_Salir="Salir";
	L_Edicion="Edición";
	L_Edicion_Copiar="Copiar";
	L_Edicion_Pegar="Pegar";
	L_Edicion_Cortar="Cortar";
	L_Edicion_SelTodo="Seleccionar todo";
	L_Ayuda="A&yuda";
	L_Ayuda_Ace="Acerca de...";
    }
    fclose(lenguaje);
}
