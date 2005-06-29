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
#include "includes.h"
#ifndef _Hugocons_H
#define _Hugocons_H
//Definicion de tipos de variables

//definicion de tipos compuestos
class nnc//Numero en notacion cientifica
{
public:
    void CambNum(float num);//Cambia el numero de la notacion cientifica
    void CambExpo(int expon);//Cambia el exponente de la notacion
    float ReNumero();//Retorna el numero principal
    int ReExpo();//Retorna el exponente
private:
    float numero;
    int exponente;
};
void nnc::CambNum(float num)
{
    numero=num;
}
void nnc::CambExpo(int expon)
{
    exponente=expon;
}
float nnc::ReNumero()
{
    return numero;
}
int nnc::ReExpo()
{
    return exponente;
}
//Definicion de constantes
//NumeroAvogadro
nnc NumAvogadro;
//Valor electron
nnc ValorElectron;
//Constante k
nnc k;
#endif
