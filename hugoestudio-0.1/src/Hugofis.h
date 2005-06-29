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
#ifndef _Hugofis_H
#define _Hugofis_H
#include "Hugoqui.h"
/*Declaracion de funciones  externas*/
/************************************************************************************
*Las siguientes son declaraciones e implementaciones de funciones de fisica mecanica*
************************************************************************************/
/*Entiendase como mur=Movimiento uniforme rectilineo, mua=Movimiento Uniforme acelerado*/
float distancia(float velocidad,float tiempo);//Regresa la distancia en un mur;
float velocidad(float distancia,float tiempo);//Regresa la velocidad en un mur;
float tiempo(float distancia,float velocidad);//Regresa el tiempo en un mur;
float distanciaA(float tiempo, float aceleracion);//Regresa la distancia en un mua;
float velocidadA(float aceleracion,float tiempo);//Regresa la velocidad en un mua;
//Impementacion
float distancia(float velocidad,float tiempo)
{
    return velocidad*tiempo;
}
float velocidad(float distancia,float tiempo)
{
    return distancia/tiempo;
}
float tiempo(float distancia,float velocidad)
{
    return distancia/velocidad;
}
float distanciaA(float tiempo, float aceleracion)
{
    return (aceleracion*expon(tiempo,2))/2;
}
float velocidadA(float aceleracion,float tiempo)
{
    return aceleracion*tiempo;
}
/********************************************************************************************
*Las siguientes son declaraciones e implementaciones de funciones de fisica electromagnetica*
********************************************************************************************/
int NumElectrones(int numAtomico, int numAtomos);//Devuelve el numero de electrones de un atomo
double NumElectrones(double carga);//Devuelve el numero de electrones de un atomo
float NumAtomos(int moles);//Devuelve el numero de atomos
double carga(int electrones);//Devuelve la carga
double FuerzaCoulomb(float carga1,float carga2, float distancia);//Devuelve la fuerza segun la ley de coulomb
double CampoElectrico(float carga1,float distancia);//Regresa el campo electrico
float moles(float masa, float masaAtomica);//Devuelve el numero de moles
//Implementacion
int NumElectrones(int numAtomico, int numAtomos)
{
    return numAtomico*numAtomos;
}
double NumElectrones(double carga)
{
    return carga/ValorAbsoluto(ValorElectron.ReNumero());
}
float NumAtomos(int moles)
{
    return moles*NumAvogadro.ReNumero();
}
double carga(int electrones)
{
    return electrones*ValorElectron.ReNumero();
}
double FuerzaCoulomb(float carga1,float carga2, float distancia)
{
    return (k.ReNumero()*ValorAbsoluto(carga1*carga2))/expon(distancia,2);//*direccion(todavia no hay direc)
}
double CampoElectrico(float carga1,float distancia)
{
    if(distancia==0)
        return 0;
    return (k.ReNumero()*ValorAbsoluto(carga1))/expon(distancia,2);
}
float moles(float masa, float masaAtomica)
{
    return masa/masaAtomica;
}
#endif
