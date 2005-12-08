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
FILE *lenguaje2=NULL;
wxString L_Ev_Ope,L_S_o,L_S_oe,L_NoArg,L_Poli_De;
void lenguajea2()
{
    int lenguajeV;
    lenguaje2=fopen("lang.len","a+t");
    fscanf(lenguaje2,"%i",&lenguajeV);
    if(lenguajeV==INGLES)
    {
	L_Ev_Ope="Interpeter: Evaluating operation\n";
	L_S_o="Interpeter: polinomic operation\n";
	L_S_oe="Interpeter: exponencial operation\n";
	L_NoArg="Interpeter: ERROR!, it seems like there are no arguments\n";
	L_Poli_De="Interpeter: polinomic function detected\n";
    }
    else if (lenguajeV==ESPANOL)
    {
	L_Ev_Ope="Interprete: Evaluando operacion...\n";
	L_S_o="Interprete: Operacion polinomio\n";
	L_S_oe="Interprete: Operacion exponencial\n";
	L_NoArg="Interprete: ERROR!, parece ser que no hay argumentos\n";
	L_Poli_De="Interprete: Detectado polinomio\n";
    }
    fclose(lenguaje2);
}
