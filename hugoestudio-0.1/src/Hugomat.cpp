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
int NumeroReal::NumRealAInt(NumeroReal numero)
{
    int entero;
    if(numero.ObtenerNumerador()==numero.ObtenerDenominador())
        entero=1;
    else if(numero.ObtenerNumerador()==0&&numero.ObtenerDenominador()!=0)
        entero=0;
    else if(numero.ObtenerDenominador()==1)
	entero=numero.ObtenerNumerador();
    else if(numero.ObtenerNumerador()%numero.ObtenerDenominador()==0)
	entero=numero.ObtenerNumerador()/numero.ObtenerDenominador();
    return entero;
}
double NumeroReal::NumeroRealADouble(NumeroReal numero)
{
    double num;
    num=numero.ObtenerNumerador()/numero.ObtenerDenominador();
    return num;
}
NumeroReal NumeroReal::SimplificarNumero(NumeroReal num)
{
    bool par,par2;
    if(num.ObtenerNumerador()%2==0)
        par=true;
    else
        par=false;
    if(num.ObtenerDenominador()%2==0)
        par2=true;
    else
        par2=false;
    if(par==true&&par2==true)
    {
        num.CambiarNumerador(num.ObtenerNumerador()/2);
        num.CambiarDenominador(num.ObtenerDenominador()/2);
    }
    return num;
}
NumeroReal::NumeroReal()
{
    numerador=1;
    denominador=1;
}
NumeroReal::NumeroReal(int nume,int deno)
{
    numerador=nume;
    denominador=deno;
}
NumeroReal NumeroReal::IntANumReal(int entero)
{
    NumeroReal numR;
    numR.CambiarNumerador(entero);
    numR.CambiarDenominador(1);
    return numR;
}
bool NumeroReal::SonIguales(NumeroReal a,NumeroReal b)
{
    bool resul=false;
    if(a.ObtenerNumerador()==b.ObtenerNumerador()&&a.ObtenerDenominador()==b.ObtenerDenominador())
 resul=true;
    return true;
}
NumeroReal NumeroReal::sumar(NumeroReal a, NumeroReal b)
{
    NumeroReal num;
    int c,d,e,f;
    c=a.ObtenerNumerador();
    d=b.ObtenerDenominador();
    e=a.ObtenerNumerador();
    f=b.ObtenerDenominador();
    if(d==f)
    {
        num.CambiarNumerador(e+c);
        num.CambiarDenominador(d);
    }
    else
    {
        num.CambiarDenominador(f*d);
        num.CambiarNumerador((c*d)-(e*f));
    }
    return num;
}
////////////////////
NumeroComp::NumeroComp()
{
    char j[1]={'x'};
    NumeroReal();
    //numero=IntANumReal(1);
    exponenteNumero=IntANumReal(1);
    variable=j;
    exponenteVariable=IntANumReal(1);
}
NumeroComp::NumeroComp(NumeroReal num,NumeroReal num2, char *var,NumeroReal num3)
{
    //numero=num;
    numerador=num.ObtenerNumerador();
    denominador=num.ObtenerDenominador();
    exponenteNumero=num2;
    variable=var;
    exponenteVariable=num3;
}
bool NumeroComp::SonIguales(NumeroComp a,NumeroComp b)
{
    bool resul=false;
    if(a.ObtenerVariable()==b.ObtenerVariable())
    {
 if(NumeroReal::SonIguales(a.ObtenerExponenteVariable(),b.ObtenerExponenteVariable()))
 {
     resul=true;
        }
    }
    return resul;
}
NumeroReal NumeroComp::CompAReal(NumeroComp num)
{
    NumeroReal resul;
    resul.CambiarNumerador(num.ObtenerNumero().ObtenerNumerador());
    resul.CambiarDenominador(num.ObtenerNumero().ObtenerDenominador());
    return resul;
}
///////////////
polinomio::polinomio()
{
}
polinomio::polinomio(NumeroComp a,NumeroComp b,NumeroComp c,NumeroComp d,NumeroComp e,NumeroReal ep)
{
    A=a;
    B=b;
    C=c;
    D=d;
    E=e;
    exponentePolinomio=ep;
}
polinomio polinomio::simplificar(polinomio poli)
{
    polinomio resul;
    if(SonIguales(resul.A,resul.B))
    {
 resul.CambiarNumero(sumar(A.ObtenerNumero(),B.ObtenerNumero()));
    }
    return resul;
}
NumeroComp polinomio::PoliAComp(polinomio poli)
{
    NumeroComp resul;
    resul=simplificar(poli);
    resul.CambiarNumero(poli.ObtenerNumero());
//    resul.CambiarVariable(poli.ObtenerVariable());
    resul.CambiarExponenteVariable(poli.ObtenerExponentePolinomio());
    return resul;
}
//////////////
/******************************
*cuerpo de las clases privadas*
*******************************/
double operaciones::MaCoDi(double num1, double num2)//No esta hecho aun
{
    double mcd=0;
    return mcd;
}
double operaciones::expon(double base, double expon)
{
    double a,b,c;
    c=base;
    if (expon!=0 || expon !=1)
    {
        for(a=1;a<expon;a++)
        {
            b=base*c;
            base=b;
        }
    }
    if(expon == 0)
    {
        b=1;
    }
    if (expon == 1)
    {
        b=base;
    }
    return b;
}
double operaciones::rad(double expo, double rad)
{
    double a,rad2;
    for(a=0;rad!=a*a;a++)
    {
        rad2=a*a;
    }
    return a;
}
double operaciones::log(double base, double poten)//No funciona con base=potencia
{
    double a,b,c=base;
    for(a=0;b!=poten;a++)
    {
        b=base*c;
        base=b;
    }
    a++;
    return a;
}
float operaciones::fradec(float nume,float deno)
{
    return nume/deno;
}
double operaciones::ampfrac(double nume, double deno, double amp)//solo devuleve numerador
{
    nume=nume*amp;
    deno=nume*amp;
    return nume;
}
int operaciones::bindec(int bin)//Revisar el arreglo
{
    int binario[10];
    /*for (aa=0,bb=0;aa<10,bb<10;aa++,bb++)
    {
        cout<<"\nIntroduzca numero de posicion "<<bb<<" binario: ";
        cin>>binario[aa];
    }*/
    double decimal,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0;
    int a1=10;
    a=binario[0];
    b=binario[1];
    c=binario[2];
    d=binario[3];
    e=binario[4];
    f=binario[5];
    g=binario[6];
    h=binario[7];
    i=binario[8];
    j=binario[9];
    a=a*(expon(2,a1-1));
    b=b*(expon(2,a1-2));
    c=c*(expon(2,a1-3));
    d=d*(expon(2,a1-4));
    e=e*(expon(2,a1-5));
    f=f*(expon(2,a1-6));
    g=g*(expon(2,a1-7));
    h=h*(expon(2,a1-8));
    i=i*(expon(2,a1-9));
    j=j*(expon(2,a1-10));
    decimal=a+b+c+d+e+f+g+h+i+j;
    /*cout<<a<<b<<c<<d<<e<<f<<g<<h<<i<<j<<endl;
    cout<<a+b+c+d+e+f+g+h+i+j;
    cout<<"\ndecimal es : "<<decimal<<endl;*/
    return 0;
}
int operaciones::binoct(int bin)//Revisar el arreglo
{
    int binario[10];
    /*for (aa=0,bb=0;aa<10,bb<10;aa++,bb++)
    {
        cout<<"\nIntroduzca numero de posicion "<<bb<<" binario: ";
        cin>>binario[aa];
    }*/
    double decimal,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0;
    int a1=10;
    a=binario[0];
    b=binario[1];
    c=binario[2];
    d=binario[3];
    e=binario[4];
    f=binario[5];
    g=binario[6];
    h=binario[7];
    i=binario[8];
    j=binario[9];
    a=a*expon(2,a1-1);
    b=b*expon(2,a1-2);
    c=c*expon(2,a1-3);
    d=d*expon(2,a1-4);
    e=e*expon(2,a1-5);
    f=f*expon(2,a1-6);
    g=g*expon(2,a1-7);
    h=h*expon(2,a1-8);
    i=i*expon(2,a1-9);
    j=j*expon(2,a1-10);
    decimal=a+b+c+d+e+f+g+h+i+j;
    /*cout<<a+b+c+d+e+f+g+h+i+j;
    cout<<"\ndecimal es : "<<decimal;*/
    return 0;
}
float operaciones::ValorAbsoluto(float numero)
{
    if(numero<0)
    {
        numero=numero*-1;
    }
    else if(numero>0)
    {
        numero=numero*1;
    }
    else
    {
        numero=0;
    }
    return numero;
}
/***************
*implementacion*
***************/
float geometria::cuaarea(float base,float altura)
{
    return base*altura;
}
float geometria::triarea(float base,float altura)
{
    return (base*altura)/2;
}
float geometria::trapearea(float base1,float base2,float altura)
{
    return (base1+base2)*altura/2;
}
float geometria::romboarea(float dia1,float dia2)
{
    return (dia1*dia2)/2;
}
double geometria::circuarea(double radio)
{
    return pi*(radio*radio);
}
float geometria::triaperi(float lado1,float lado2,float lado3)
{
    return lado1+lado2+lado3;
}
double geometria::cirperi(float diametro,float radio)
{
    double P;
    if(diametro==-1)
        P=2*pi*radio;
    else
        P=pi*diametro;
    return P;
}
/*****************
*implementaciones*
*****************/
double volumen::cilvol(double radio,double altura)
{
    return pi*(radio*radio)*altura;
}
float volumen::cubvol(float acua,float altura)
{
    return acua*altura;
}
float volumen::piravol(float base,float altura)
{
    return base*altura/3;
}
double volumen::conovol(double radio, double altura)
{
    double r;
    r=expon(radio,2);
    return (pi*r*altura)/3;
}
double volumen::esare(double radio)
{
    radio=expon(radio,2);
    return 4*pi*radio;
}
double volumen::esvol(double radio)
{
    radio=expon(radio,3);
    return 4*pi*radio/3;
}
/********************************************
*funciones de calculo diferencial e integral*
********************************************/
polinomio derivada(polinomio funcion);
polinomio integral(polinomio funcion);
/*****************
*implementaciones*
*****************/
polinomio derivada(polinomio funcion)
{
    polinomio funcin;
    return funcin;
}
polinomio integral(polinomio funcion)
{
    polinomio funcin;
    return funcin;
}
