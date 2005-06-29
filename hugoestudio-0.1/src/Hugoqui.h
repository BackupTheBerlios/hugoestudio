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
#include "Hugomat.h"
#ifndef _Hugoqui_H
#define _Hugoqui_H
float centi,faren,ke;
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
//NumAvogadro;
extern void constantes()
{
    NumAvogadro.CambNum(6.023);
    NumAvogadro.CambExpo(23);
    ValorElectron.CambNum(1.602);
    ValorElectron.CambExpo(-19);
    k.CambNum(9);
    k.CambExpo(9);
}
float TempCenFar(float centi)//pasa de grados centigrados a farenheid
{
    float faren;
    faren=((9/5*centi)+32);
    //cout<<faren<<endl;
    return faren;
}
float TempFarCen(float faren)//Pasa de Farenheid a centigrados
{
    float centi;
    centi=((faren-32)*5/9);
    //cout<<centi<<endl;
    return centi;
}
float TempCenKe(float centi)//pasa de grados centigrados a kelvin
{
    float ke;
    ke=(centi+273);
    //cout<<ke<<endl;
    return ke;
}
float TempKeCen(float ke) //Pasa de kelvin a centigrados
{
    float centi;
    centi=(ke-273);
    //cout<<centi<<endl;
    return centi;
}
float TempFarKe(float faren) //Pasa de Farenheid a kelvin
{
    float centi,ke;
    centi=((faren-32)*5/9);
    ke=(centi+273);
    //cout<<ke<<endl;
    return ke;
}
float TempKeFar(float ke)  //Pasa de kelvin a farenheid
{
    float centi, faren;
    centi=(ke-273);
    faren=((9/5*centi)+32);
    //cout<<faren<<endl;
    return faren;
}
float GasTemp(float presion,float volumen,float masa, float pesom)//Usa datos para hallar temperatura
{
    float temperatura;
    temperatura=((presion*volumen)/(0.082+masa/pesom));
    //cout<<temperatura<<endl;
    return temperatura;
}
float GasPres(float volumen,float masa,float pesom,float temperatura)//usa datos para hallar presion
{
    float presion;
    presion=((masa/pesom*0.082*temperatura)/(volumen));
    //cout<<presion<<endl;
    return presion;
}
float GasVol(float presion,float masa,float pesom,float temperatura)//Usa datos para hallar volumen
{
    float volumen;
    volumen=((masa/pesom*0.082*temperatura)/(presion));
    return volumen;
}
float GasMas(float presion,float volumen,float pesom,float temperatura)//Usa detos para hallar masa
{
    float masa;
    masa=((presion*volumen*pesom)/(0.082*temperatura));
    //cout<<masa<<endl;
    return masa;
}

float EnePot()   //Halla energia potencial
{
    float potencial,masal,altural;
    potencial=(masal*9.8*altural);
    //cout<<potencial<<endl;
    return potencial;
}
/*Halla la energia cinetica, no da el resultado correcto,
si desea usarlo quite la forma de comentario y agrege los 
modos de acceso a clase privada 
float Ene-Cin() 
{ 
 float cineti,masas,velocidad; 
 cineti=(((1*masas)/2)*(velocidad/36)*2); 
}*/

float GasviVi(float vo,float po,float ti,float to,float pi) //Halla volumen inicial
{
    float vi;
    vi=(vo*po*ti/pi*to);
    //cout<<vi<<endl;
    return vi;
}
float GasviVf(float vi,float po,float ti,float to,float pi) //Halla volumen final
{
    float vo;
    vo=(vi*pi*to/po*ti);
    //cout<<vo<<endl;
    return vo;
}
float GasviPi(float vi,float vo,float po,float ti,float to) //Halla presión inicial
{
    float pi;
    pi=(vo*po*ti/vi*to);
    //cout<<pi<<endl;
    return pi;
}
float GasviPo(float vi,float vo,float ti,float to,float pi) //Halla presión final
{
    float po;
    po=(vi*pi*to/vo*ti);
    //cout<<po<<endl;
    return po;
}
float GasviTi(float vi,float vo,float po,float to,float pi) //Halla temperatura inicial
{
    float ti;
    ti=(vi*pi*to/vo*po);
    //cout<<ti<<endl;
    return ti;
}
float GasviTo(float vi,float vo,float po,float ti,float pi) //Halla temperatura final
{
    float to;
    to=(vo*po*ti/vi*pi);
    //cout<<to<<endl;
    return to;
}

#endif
