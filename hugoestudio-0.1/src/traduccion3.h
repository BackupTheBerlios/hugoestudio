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
FILE *lenguaje3=NULL;
wxString L_Tab_M,L_Tab_F,L_Tab_Q,L_Tab_Deb,L_Calcular,L_Limpiar;
void lenguajea3()
{
    int lenguajeV;
    lenguaje3=fopen("lang.len","a+t");
    fscanf(lenguaje3,"%i",&lenguajeV);
    if(lenguajeV==INGLES)
    {
	
	L_Tab_M="Mathematics";
	L_Tab_F="Physics";
	L_Tab_Q="Chemistry";
	L_Tab_Deb="Debug";
	L_Calcular="Calculate";
	L_Limpiar="Clear";
    }
    else if (lenguajeV==ESPANOL)
    {
	L_Tab_M="Matematica";
	L_Tab_F="Fisica";
	L_Tab_Q="Quimica";
	L_Tab_Deb="Tareas";
	L_Calcular="Calcular";
	L_Limpiar="Limpiar";
    }
    fclose(lenguaje3);
}
