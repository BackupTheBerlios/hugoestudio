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
NumeroReal::NumeroReal()
{
    numerador=1;
    denominador=1;
    signo=true;
}
NumeroReal::NumeroReal(int nume,int deno)
{
    numerador=nume;
    denominador=deno;
    if(numerador>0&&denominador>0||numerador<0&&denominador<0)
        signo=true;
    else if(numerador<0&&denominador>0||numerador>0&&denominador<0)
        signo=false;
    else
        signo=true;
}
NumeroReal::NumeroReal(int nume,int deno, bool sig)
{
    numerador=nume;
    denominador=deno;
    signo=sig;
}
NumeroReal NumeroReal::operator+(NumeroReal & numero)
{
    NumeroReal resul;
    if(denominador==numero.ObtenerDenominador())
    {
	resul.CambiarNumerador(numerador+numero.ObtenerNumerador());
	resul.CambiarDenominador(denominador);
    }
    else
    {
	resul.CambiarDenominador(denominador*numero.ObtenerDenominador());
	resul.CambiarNumerador((numerador*numero.ObtenerDenominador())+(denominador+numero.ObtenerNumerador()));
    }
    return resul;
}
NumeroReal NumeroReal::operator-(NumeroReal & numero)
{
    NumeroReal resul;
    if(denominador==numero.ObtenerDenominador())
    {
	resul.CambiarNumerador(numerador-numero.ObtenerNumerador());
	resul.CambiarDenominador(denominador);
    }
    else
    {
	resul.CambiarDenominador(denominador*numero.ObtenerDenominador());
	resul.CambiarNumerador((numerador*numero.ObtenerDenominador())-(denominador+numero.ObtenerNumerador()));
    }
    return resul;
}
NumeroReal NumeroReal::operator*(NumeroReal &numero)
{
    NumeroReal resul;
    resul.CambiarNumerador(numerador*numero.ObtenerNumerador());
    resul.CambiarDenominador(denominador*numero.ObtenerDenominador());
    return resul;
}
NumeroReal NumeroReal::operator^(NumeroReal &numero)
{
    NumeroReal resul;
    resul.CambiarNumerador(numerador);
    resul.CambiarDenominador(denominador);
    for(int i=0;i<numero.ObtenerNumerador();i++)
    {
	resul.CambiarNumerador(resul.ObtenerNumerador()*numerador);
	resul.CambiarDenominador(resul.ObtenerDenominador()*denominador);
    }
    return resul;
}
////////////////////
NumeroComp::NumeroComp()
{
    variable1='a';
    variable2='a';
    variable3='a';
    NumeroReal();
    //numero=IntANumReal(1);
    exponenteNumero=UtilitariosBasicos::IntANumReal(1);
    //variable=j;
    exponenteVariable1=UtilitariosBasicos::IntANumReal(1);
    exponenteVariable2=UtilitariosBasicos::IntANumReal(1);
    exponenteVariable3=UtilitariosBasicos::IntANumReal(1);
    signo=true;
}
NumeroComp::NumeroComp(NumeroReal num,NumeroReal num2, char var,NumeroReal num3)
{
    //numero=num;
    numerador=num.ObtenerNumerador();
    denominador=num.ObtenerDenominador();
    exponenteNumero=num2;
    variable1=var;
    exponenteVariable1=num3;
    if(numerador>0&&denominador>0||numerador<0&&denominador<0)
        signo=true;
    else if(numerador<0&&denominador>0||numerador>0&&denominador<0)
        signo=false;
    else
        signo=true;
}
NumeroComp NumeroComp::operator+(NumeroComp &num)
{
    NumeroComp resul;
    if(variable1==num.ObtenerVariable1()&&UtilitariosBasicos::SonIguales(exponenteVariable1,num.ObtenerExponenteVariable1()))
    {
	if(variable2==num.ObtenerVariable2()&&UtilitariosBasicos::SonIguales(exponenteVariable2,num.ObtenerExponenteVariable2()))
	{
	    if(variable3==num.ObtenerVariable3()&&UtilitariosBasicos::SonIguales(exponenteVariable3,num.ObtenerExponenteVariable3()))
	    {
		resul.CambiarVariables(variable1,variable2,variable3);
		resul.CambiarExponenteVariable1(num.ObtenerExponenteVariable1());
		resul.CambiarExponenteVariable2(num.ObtenerExponenteVariable2());
		resul.CambiarExponenteVariable3(num.ObtenerExponenteVariable3());
		resul.CambiarNumero(UtilitariosBasicos::sumar(ObtenerNumero(),num.ObtenerNumero()));
	    }
	}
    }
    return resul;
}
NumeroComp NumeroComp::operator*(NumeroComp &num)
{
    NumeroComp resul;
    return resul;
}
NumeroComp NumeroComp::operator-(NumeroComp &num)
{
    NumeroComp resul;
    return resul;
}
NumeroComp NumeroComp::operator/(NumeroComp &num)
{
    NumeroComp resul;
    return resul;
}
bool NumeroComp::SonIguales(NumeroComp a,NumeroComp b)
{
#define COMPAREEXPOVAR1 UtilitariosBasicos::SonIguales(a.ObtenerExponenteVariable1(),b.ObtenerExponenteVariable1())
    #define COMPAREEXPOVAR2 UtilitariosBasicos::SonIguales(a.ObtenerExponenteVariable2(),b.ObtenerExponenteVariable2())
    #define COMPAREEXPOVAR3 UtilitariosBasicos::SonIguales(a.ObtenerExponenteVariable3(),b.ObtenerExponenteVariable3())
    bool resul=false;
    if(a.ObtenerVariable1()==b.ObtenerVariable1()&&a.ObtenerVariable2()==b.ObtenerVariable2())
    {
        if(a.ObtenerVariable3()==b.ObtenerVariable3())
        {
            if(COMPAREEXPOVAR1&&COMPAREEXPOVAR2&&COMPAREEXPOVAR3)
            {
                resul=true;
            }
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
    A.CambiarNumerador(1);
    A.CambiarVariable1('a');
    A.CambiarVariable2('a');
    A.CambiarVariable3('a');
    B.CambiarNumerador(1);
    B.CambiarVariable1('a');
    B.CambiarVariable2('a');
    B.CambiarVariable3('a');
    C.CambiarNumerador(1);
    C.CambiarVariable1('a');
    C.CambiarVariable2('a');
    C.CambiarVariable3('a');
    D.CambiarNumerador(1);
    D.CambiarVariable1('a');
    D.CambiarVariable2('a');
    D.CambiarVariable3('a');
    E.CambiarNumerador(1);
    E.CambiarVariable1('a');
    E.CambiarVariable2('a');
    E.CambiarVariable3('a');
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
polinomio polinomio::simplificar()
{
#define COMPVAR1 A.ObtenerVariable1()==B.ObtenerVariable1()
    #define COMPVAR2 A.ObtenerVariable2()==B.ObtenerVariable2()
    #define COMPVAR3 A.ObtenerVariable3()==B.ObtenerVariable3()
    #define COMPEVAR1 A.ObtenerExponenteVariable1().ObtenerNumerador()
    #define COMPEVAR2 B.ObtenerExponenteVariable1().ObtenerNumerador()
    #define COMPEVAR3 A.ObtenerExponenteVariable2().ObtenerNumerador()
    #define COMPEVAR4 B.ObtenerExponenteVariable2().ObtenerNumerador()
    #define COMPEVAR5 A.ObtenerExponenteVariable3().ObtenerNumerador()
    #define COMPEVAR6 B.ObtenerExponenteVariable3().ObtenerNumerador()
    polinomio resul;
    if(COMPVAR1&&COMPVAR2&&COMPVAR3)
        //if(SonIguales(resul.A.ObtenerVariable(),resul.B.ObtenerVariable()))
    {
        if(COMPEVAR1==COMPEVAR2&&COMPEVAR3==COMPEVAR4&&COMPEVAR5==COMPEVAR6)
        {
            resul.A.CambiarNumero(UtilitariosBasicos::sumar(A.ObtenerNumero(),B.ObtenerNumero()));
            resul.A.CambiarExponenteVariable1(A.ObtenerExponenteVariable1());
            resul.A.CambiarExponenteVariable2(A.ObtenerExponenteVariable2());
            resul.A.CambiarExponenteVariable3(A.ObtenerExponenteVariable3());
            resul.A.CambiarVariable1(A.ObtenerVariable1());
            resul.A.CambiarVariable2(A.ObtenerVariable2());
            resul.A.CambiarVariable3(A.ObtenerVariable3());
        }
        else
        {
            resul.A.CambiarNumero(A.ObtenerNumero());
            resul.A.CambiarVariable1(A.ObtenerVariable1());
            resul.A.CambiarVariable2(A.ObtenerVariable2());
            resul.A.CambiarVariable3(A.ObtenerVariable3());
            resul.A.CambiarExponenteVariable1(A.ObtenerExponenteVariable1());
            resul.A.CambiarExponenteVariable2(A.ObtenerExponenteVariable2());
            resul.A.CambiarExponenteVariable3(A.ObtenerExponenteVariable3());
            resul.B.CambiarNumero(A.ObtenerNumero());
            resul.B.CambiarVariable1(A.ObtenerVariable1());
            resul.B.CambiarVariable2(A.ObtenerVariable2());
            resul.B.CambiarVariable3(A.ObtenerVariable3());
            resul.B.CambiarExponenteVariable1(A.ObtenerExponenteVariable1());
            resul.B.CambiarExponenteVariable2(A.ObtenerExponenteVariable2());
            resul.B.CambiarExponenteVariable3(A.ObtenerExponenteVariable3());
            resul.C.CambiarNumero(A.ObtenerNumero());
            resul.C.CambiarVariable1(A.ObtenerVariable1());
            resul.C.CambiarVariable2(A.ObtenerVariable2());
            resul.C.CambiarVariable3(A.ObtenerVariable3());
            resul.C.CambiarExponenteVariable1(A.ObtenerExponenteVariable1());
            resul.C.CambiarExponenteVariable2(A.ObtenerExponenteVariable2());
            resul.C.CambiarExponenteVariable3(A.ObtenerExponenteVariable3());
            resul.D.CambiarNumero(A.ObtenerNumero());
            resul.D.CambiarVariable1(A.ObtenerVariable1());
            resul.D.CambiarVariable2(A.ObtenerVariable2());
            resul.D.CambiarVariable3(A.ObtenerVariable3());
            resul.D.CambiarExponenteVariable1(A.ObtenerExponenteVariable1());
            resul.D.CambiarExponenteVariable2(A.ObtenerExponenteVariable2());
            resul.D.CambiarExponenteVariable3(A.ObtenerExponenteVariable3());
            resul.E.CambiarNumero(A.ObtenerNumero());
            resul.E.CambiarVariable1(A.ObtenerVariable1());
            resul.E.CambiarVariable2(A.ObtenerVariable2());
            resul.E.CambiarVariable3(A.ObtenerVariable3());
            resul.E.CambiarExponenteVariable1(A.ObtenerExponenteVariable1());
            resul.E.CambiarExponenteVariable2(A.ObtenerExponenteVariable2());
            resul.E.CambiarExponenteVariable3(A.ObtenerExponenteVariable3());
        }
    }
    else
    {
        resul.A.CambiarNumero(A.ObtenerNumero());
        resul.A.CambiarVariable1(A.ObtenerVariable1());
        resul.A.CambiarVariable2(A.ObtenerVariable2());
        resul.A.CambiarVariable3(A.ObtenerVariable3());
        resul.A.CambiarExponenteVariable1(A.ObtenerExponenteVariable1());
        resul.A.CambiarExponenteVariable2(A.ObtenerExponenteVariable2());
        resul.A.CambiarExponenteVariable3(A.ObtenerExponenteVariable3());
        resul.B.CambiarNumero(A.ObtenerNumero());
        resul.B.CambiarVariable1(A.ObtenerVariable1());
        resul.B.CambiarVariable2(A.ObtenerVariable2());
        resul.B.CambiarVariable3(A.ObtenerVariable3());
        resul.B.CambiarExponenteVariable1(A.ObtenerExponenteVariable1());
        resul.B.CambiarExponenteVariable2(A.ObtenerExponenteVariable2());
        resul.B.CambiarExponenteVariable3(A.ObtenerExponenteVariable3());
        resul.C.CambiarNumero(A.ObtenerNumero());
        resul.C.CambiarVariable1(A.ObtenerVariable1());
        resul.C.CambiarVariable2(A.ObtenerVariable2());
        resul.C.CambiarVariable3(A.ObtenerVariable3());
        resul.C.CambiarExponenteVariable1(A.ObtenerExponenteVariable1());
        resul.C.CambiarExponenteVariable2(A.ObtenerExponenteVariable2());
        resul.C.CambiarExponenteVariable3(A.ObtenerExponenteVariable3());
        resul.D.CambiarNumero(A.ObtenerNumero());
        resul.D.CambiarVariable1(A.ObtenerVariable1());
        resul.D.CambiarVariable2(A.ObtenerVariable2());
        resul.D.CambiarVariable3(A.ObtenerVariable3());
        resul.D.CambiarExponenteVariable1(A.ObtenerExponenteVariable1());
        resul.D.CambiarExponenteVariable2(A.ObtenerExponenteVariable2());
        resul.D.CambiarExponenteVariable3(A.ObtenerExponenteVariable3());
        resul.E.CambiarNumero(A.ObtenerNumero());
        resul.E.CambiarVariable1(A.ObtenerVariable1());
        resul.E.CambiarVariable2(A.ObtenerVariable2());
        resul.E.CambiarVariable3(A.ObtenerVariable3());
        resul.E.CambiarExponenteVariable1(A.ObtenerExponenteVariable1());
        resul.E.CambiarExponenteVariable2(A.ObtenerExponenteVariable2());
        resul.E.CambiarExponenteVariable3(A.ObtenerExponenteVariable3());
    }
    return resul;
}
polinomio polinomio::multiplicar()
{
    #define COMPVAR1 A.ObtenerVariable1()==B.ObtenerVariable1()
    #define COMPVAR2 A.ObtenerVariable2()==B.ObtenerVariable2()
    #define COMPVAR3 A.ObtenerVariable3()==B.ObtenerVariable3()
    #define COMPEVAR1 A.ObtenerExponenteVariable1().ObtenerNumerador()
    #define COMPEVAR2 B.ObtenerExponenteVariable1().ObtenerNumerador()
    #define COMPEVAR3 A.ObtenerExponenteVariable2().ObtenerNumerador()
    #define COMPEVAR4 B.ObtenerExponenteVariable2().ObtenerNumerador()
    #define COMPEVAR5 A.ObtenerExponenteVariable3().ObtenerNumerador()
    #define COMPEVAR6 B.ObtenerExponenteVariable3().ObtenerNumerador()
    polinomio resul;
    resul.A.CambiarNumero(UtilitariosBasicos::multiplicar(A.ObtenerNumero(),B.ObtenerNumero()));
    if(A.ObtenerVariable1()=='x'||B.ObtenerVariable1()=='x')
    {
	resul.A.CambiarVariable1('x');
    }
    if(A.ObtenerVariable2()=='y'||B.ObtenerVariable2()=='y')
    {
	resul.A.CambiarVariable2('y');
    }
    if(A.ObtenerVariable3()=='z'||B.ObtenerVariable3()=='z')
    {
	resul.A.CambiarVariable3('z');
    }
    resul.A.CambiarExponenteVariable1(UtilitariosBasicos::sumar(A.ObtenerExponenteVariable1(),B.ObtenerExponenteVariable1()));
    resul.A.CambiarExponenteVariable2(UtilitariosBasicos::sumar(A.ObtenerExponenteVariable2(),B.ObtenerExponenteVariable2()));
    resul.A.CambiarExponenteVariable3(UtilitariosBasicos::sumar(A.ObtenerExponenteVariable3(),B.ObtenerExponenteVariable3()));
    resul.B=polinomio();
    return resul;
}
NumeroComp polinomio::PoliAComp(polinomio poli)
{
    NumeroComp resul;
    resul=simplificar();
    resul.CambiarNumero(poli.ObtenerNumero());
    //    resul.CambiarVariable(poli.ObtenerVariable());
    resul.CambiarExponenteVariable1(poli.ObtenerExponentePolinomio());
    return resul;
}
//////////////
/******************************
*cuerpo de las clases privadas*
*******************************/
double UtilitariosOperaciones::MaCoDi(double num1, double num2)//No esta hecho aun
{
    double mcd=0;
    return mcd;
}
double UtilitariosOperaciones::expon(double base, double expon)
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
double UtilitariosOperaciones::rad(double expo, double rad)
{
    if(expo==1)
    {
        return rad;
    }
    double a=0,rad2=0;
    for(a=0;rad2!=rad;a++)
    {
        rad2=expon(a,expo);
    }
    return a-1;
}
double UtilitariosOperaciones::log(double base, double resul)
{
    double a,b=base,base1;
    if(resul==1)
    {
        return 0;
    }
    if(base==resul)
    {
        return 1;
    }
    base1=b;
    for(a=0;b!=resul||b>resul;a++)
    {
        b=base*base1;
        base1=b;
    }
    return a+1;
}
float UtilitariosOperaciones::fradec(float nume,float deno)
{
    return nume/deno;
}
double UtilitariosOperaciones::ampfrac(double nume, double deno, double amp)//solo devuleve numerador
{
    nume=nume*amp;
    deno=nume*amp;
    return nume;
}
int UtilitariosOperaciones::bindec(int bin)//Revisar el arreglo
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
int UtilitariosOperaciones::binoct(int bin)//Revisar el arreglo
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
float UtilitariosOperaciones::ValorAbsoluto(float numero)
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
float UtilitariosGeometria::cuaarea(float base,float altura)
{
    return base*altura;
}
float UtilitariosGeometria::triarea(float base,float altura)
{
    return (base*altura)/2;
}
float UtilitariosGeometria::trapearea(float base1,float base2,float altura)
{
    return (base1+base2)*altura/2;
}
float UtilitariosGeometria::romboarea(float dia1,float dia2)
{
    return (dia1*dia2)/2;
}
double UtilitariosGeometria::circuarea(double radio)
{
    return pi*(radio*radio);
}
float UtilitariosGeometria::triaperi(float lado1,float lado2,float lado3)
{
    return lado1+lado2+lado3;
}
double UtilitariosGeometria::cirperi(float diametro,float radio)
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
double UtilitariosVolumen::cilvol(double radio,double altura)
{
    return pi*(radio*radio)*altura;
}
float UtilitariosVolumen::cubvol(float acua,float altura)
{
    return acua*altura;
}
float UtilitariosVolumen::piravol(float base,float altura)
{
    return base*altura/3;
}
double UtilitariosVolumen::conovol(double radio, double altura)
{
    double r;
    r=UtilitariosOperaciones::expon(radio,2);
    return (pi*r*altura)/3;
}
double UtilitariosVolumen::esare(double radio)
{
    radio=UtilitariosOperaciones::expon(radio,2);
    return 4*pi*radio;
}
double UtilitariosVolumen::esvol(double radio)
{
    radio=UtilitariosOperaciones::expon(radio,3);
    return 4*pi*radio/3;
}
/********************************************
*funciones de calculo diferencial e integral*
********************************************/
/*****************
*implementaciones*
*****************/
polinomio UtilitariosOperaciones::derivada(polinomio funcion)
{
    polinomio funcin;
    NumeroComp numero=funcion.ObtenerA();
    NumeroReal cero=NumeroReal(0,1);
    NumeroReal uno=NumeroReal(1,1);
    NumeroComp ceroC=NumeroComp(cero,uno,'a',uno);
    funcin.CambiarFactorA(derivada(funcion.ObtenerA()));
    funcin.CambiarFactorB(derivada(funcion.ObtenerB()));
    funcin.CambiarFactorC(derivada(funcion.ObtenerC()));
    funcin.CambiarFactorD(derivada(funcion.ObtenerD()));
    funcin.CambiarFactorE(derivada(funcion.ObtenerE()));
    return funcin;
}
NumeroComp UtilitariosOperaciones::derivada(NumeroComp funcion)
{
    #define OV1 funcion.ObtenerVariable1()
    #define OV2 funcion.ObtenerVariable2()
    #define OV3 funcion.ObtenerVariable3()
    #define OEV1 funcion.ObtenerExponenteVariable1()
    #define OEV2 funcion.ObtenerExponenteVariable2()
    #define OEV3 funcion.ObtenerExponenteVariable3()
    #define ON ObtenerNumerador()
    NumeroComp funcin;
    NumeroReal cero=NumeroReal(0,1);
    NumeroReal uno=NumeroReal(1,1);
    NumeroReal Muno=NumeroReal(1,1,false);
    NumeroComp ceroC=NumeroComp(cero,uno,'a',uno);
    if(OV1=='a'&&OV2=='a'&&OV3=='a')
    {
        funcin.CambiarNumero(cero);
    }
    else if((OV1=='x'||OV1=='y'||OV1=='z')&&(OEV1.ON==1&&OEV1.ON==1&&OEV1.ON==1))//????
    {
        funcin.CambiarNumero(funcion.ObtenerNumero());
	funcin.CambiarVariables('a','a','a');
    }
    else if(OV1=='x'||OV1=='y'||OV1=='z')
    {
	funcin.CambiarNumero(UtilitariosBasicos::multiplicar(funcion.ObtenerNumero(),OEV1));
	if(OV1=='x')
	{
	    funcin.CambiarVariable1('x');
	}
	else if(OV2=='y')
	{
	    funcin.CambiarVariable1('y');
	}
	else if(OV3=='z')
	{
	    funcin.CambiarVariable1('z');
	}
	funcin.CambiarExponenteVariable1(UtilitariosBasicos::restar(OEV1,Muno));
    }
    return funcin;
}
NumeroComp UtilitariosOperaciones::integral(NumeroComp funcion)
{
    #define OV1 funcion.ObtenerVariable1()
    #define OV2 funcion.ObtenerVariable2()
    #define OV3 funcion.ObtenerVariable3()
    #define OEV1 funcion.ObtenerExponenteVariable1()
    #define OEV2 funcion.ObtenerExponenteVariable2()
    #define OEV3 funcion.ObtenerExponenteVariable3()
    #define ON ObtenerNumerador()
    NumeroReal cero=NumeroReal(0,1);
    NumeroReal uno=NumeroReal(1,1);
    NumeroReal Muno=NumeroReal(1,1,false);
    NumeroReal temp;
    NumeroReal temp2;
    NumeroComp ceroC=NumeroComp(cero,uno,'a',uno);
    NumeroComp funcin=NumeroComp(uno,uno,'a',uno);
    if(OV1=='a'&&OV2=='a'&&OV3=='a')
    {
        funcin.CambiarNumero(funcion.ObtenerNumero());
	funcin.CambiarVariable1('x');
    }
    else if(OV1=='x'||OV1=='y'||OV1=='z')
    {
	temp.CambiarNumerador(funcion.ObtenerNumero().ObtenerNumerador());
	temp.CambiarDenominador(OEV1.ObtenerNumerador()+1);
	temp2.CambiarNumerador(OEV1.ObtenerNumerador()+1);
        funcin.CambiarNumero(temp);
	if(OV1=='x')
	{
	    funcin.CambiarVariable1('x');
	    funcin.CambiarExponenteVariable1(temp2);
	}
	else if(OV2=='y')
	{
	    funcin.CambiarVariable1('y');
	    funcin.CambiarExponenteVariable1(temp2);
	}
	else if(OV3=='z')
	{
	    funcin.CambiarVariable1('z');
	    funcin.CambiarExponenteVariable1(temp2);
	}
    }
    return funcin;
}
polinomio UtilitariosOperaciones::integral(polinomio funcion)
{
    polinomio func;
    polinomio funcin;
    NumeroComp numero=funcion.ObtenerA();
    NumeroReal cero=NumeroReal(0,1);
    NumeroReal uno=NumeroReal(1,1);
    NumeroComp ceroC=NumeroComp(cero,uno,'a',uno);
    funcin.CambiarFactorA(integral(funcion.ObtenerA()));
    funcin.CambiarFactorB(integral(funcion.ObtenerB()));
    funcin.CambiarFactorC(integral(funcion.ObtenerC()));
    funcin.CambiarFactorD(integral(funcion.ObtenerD()));
    funcin.CambiarFactorE(integral(funcion.ObtenerE()));
    return funcin;
    return func;
}
NumeroReal UtilitariosOperaciones::integralD(NumeroReal LimInferior,NumeroReal LimSuperior,polinomio funcion)
{
    polinomio funcin;
    NumeroReal resul;
    NumeroReal temp1;
    NumeroReal temp2;
    NumeroReal temp3;
    NumeroReal temp4;
    NumeroReal temp5;
    NumeroReal temp6;
    funcin=integral(funcion);//Se integra normalmente
    funcin.simplificar();//Se simplifica
    NumeroReal Numero1=funcin.ObtenerA().ObtenerNumero();
    NumeroReal Numero2=funcin.ObtenerB().ObtenerNumero();
    NumeroReal Numero3=funcin.ObtenerC().ObtenerNumero();
    NumeroReal Numero4=funcin.ObtenerD().ObtenerNumero();
    NumeroReal Numero5=funcin.ObtenerE().ObtenerNumero();
    NumeroComp Sumando1=funcin.ObtenerA();
    NumeroComp Sumando2=funcin.ObtenerB();
    NumeroComp Sumando3=funcin.ObtenerC();
    NumeroComp Sumando4=funcin.ObtenerD();
    NumeroComp Sumando5=funcin.ObtenerE();
    NumeroReal Sumando1r=funcin.ObtenerA().ObtenerExponenteVariable1();
    NumeroReal Sumando2r=funcin.ObtenerB().ObtenerExponenteVariable1();
    NumeroReal Sumando3r=funcin.ObtenerC().ObtenerExponenteVariable1();
    NumeroReal Sumando4r=funcin.ObtenerD().ObtenerExponenteVariable1();
    NumeroReal Sumando5r=funcin.ObtenerE().ObtenerExponenteVariable1();
    NumeroReal exponenteL[5];
    exponenteL[0]=LimSuperior^Sumando1r;
    exponenteL[1]=LimSuperior^Sumando1r;
    exponenteL[2]=LimSuperior^Sumando1r;
    exponenteL[3]=LimSuperior^Sumando1r;
    exponenteL[4]=LimSuperior^Sumando1r;
    if(Sumando1.ObtenerVariable1()!='a')
    {
	temp1.CambiarNumero((Numero1*exponenteL[0]));
    }
    if(Sumando2.ObtenerVariable1()!='a')
    {
	temp2.CambiarNumero(Numero2*exponenteL[1]);
    }
    if(Sumando3.ObtenerVariable1()!='a')
    {
	temp3.CambiarNumero(Numero3*exponenteL[2]);
    }
    if(Sumando4.ObtenerVariable1()!='a')
    {
	temp4.CambiarNumero(Numero4*exponenteL[3]);
    }
    if(Sumando5.ObtenerVariable1()!='a')
    {
	temp5.CambiarNumero(Numero5*exponenteL[4]);
    }
    temp6=temp1+temp2;
    temp6=temp6+temp3;
    temp6=temp6+temp4;
    temp6=temp6+temp5;
    exponenteL[0]=LimInferior^Sumando1r;
    exponenteL[1]=LimInferior^Sumando1r;
    exponenteL[2]=LimInferior^Sumando1r;
    exponenteL[3]=LimInferior^Sumando1r;
    exponenteL[4]=LimInferior^Sumando1r;
    //Limite inferior
    if(Sumando1.ObtenerVariable1()!='a')
    {
	temp1.CambiarNumero((Numero1*exponenteL[0]));
    }
    if(Sumando2.ObtenerVariable1()!='a')
    {
	temp2.CambiarNumero(Numero2*exponenteL[1]);
    }
    if(Sumando3.ObtenerVariable1()!='a')
    {
	temp3.CambiarNumero(Numero3*exponenteL[2]);
    }
    if(Sumando4.ObtenerVariable1()!='a')
    {
	temp4.CambiarNumero(Numero4*exponenteL[3]);
    }
    if(Sumando5.ObtenerVariable1()!='a')
    {
	temp5.CambiarNumero(Numero5*exponenteL[4]);
    }
    resul=temp1+temp2;
    resul=resul+temp3;
    resul=resul+temp4;
    resul=resul+temp5;
    resul=resul-temp6;
    return resul;
}
//Utilitarios basicos
int UtilitariosBasicos::NumRealAInt(NumeroReal numero)
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
double UtilitariosBasicos::NumeroRealADouble(NumeroReal numero)
{
    double num;
    num=numero.ObtenerNumerador()/numero.ObtenerDenominador();
    return num;
}
NumeroReal UtilitariosBasicos::IntANumReal(int entero)
{
    NumeroReal numR;
    numR.CambiarNumerador(entero);
    numR.CambiarDenominador(1);
    return numR;
    if(entero>=0)
        numR.CambiarSigno(true);
    else
        numR.CambiarSigno(false);
}
bool UtilitariosBasicos::SonIguales(NumeroReal a,NumeroReal b)
{
    bool resul=false;
    if(a.ObtenerNumerador()==b.ObtenerNumerador()&&a.ObtenerDenominador()==b.ObtenerDenominador())
        resul=true;
    return true;
}
NumeroReal UtilitariosBasicos::sumar(NumeroReal a, NumeroReal b)
{
    NumeroReal num;
    int c,d,e,f;
    c=a.ObtenerNumerador();
    d=a.ObtenerDenominador();
    e=b.ObtenerNumerador();
    f=b.ObtenerDenominador();
    if(d==f)
    {
        if((a.ObtenerSigno()==true&&b.ObtenerSigno()==true)||(a.ObtenerSigno()==false&&b.ObtenerSigno()==false))
        {
            num.CambiarNumerador(e+c);
            if(a.ObtenerSigno()==false&&b.ObtenerSigno()==false)
            {
                num.CambiarSigno(false);
            }
        }
        else if(a.ObtenerSigno()==true&&b.ObtenerSigno()==false)
        {
            if(a.ObtenerNumerador()>b.ObtenerNumerador())
            {
                num.CambiarNumerador(c-e);//c-e
                if(c<e)
                {
                    num.CambiarSigno(false);
                }
                else if(e<c)
                {
                    num.CambiarSigno(true);
                }
            }
            else
            {
                num.CambiarNumerador(c-e);//e-c
            }
        }
        num.CambiarDenominador(d);
    }
    else
    {
        num.CambiarDenominador(f*d);
        num.CambiarNumerador((c*d)-(e*f));
    }
    return num;
}
NumeroReal UtilitariosBasicos::restar(NumeroReal a, NumeroReal b)
{
    NumeroReal res;
    if(a.ObtenerDenominador()==b.ObtenerDenominador())
    {
	res.CambiarNumerador(a.ObtenerNumerador()-b.ObtenerNumerador());
	res.CambiarDenominador(a.ObtenerDenominador());
    }
    return res;
}
NumeroReal UtilitariosBasicos::multiplicar(NumeroReal a, NumeroReal b)
{
    NumeroReal num;
    int c,d,e,f;
    c=a.ObtenerNumerador();
    d=a.ObtenerDenominador();
    e=b.ObtenerNumerador();
    f=b.ObtenerDenominador();
    num.CambiarNumerador(c*e);
    num.CambiarDenominador(d*f);
    if(((c<0||e<0)&&(d>0||f>0))||((c>0||e>0)&&(d<0||f<0)))
    {
	num.CambiarSigno(false);
    }
    return num;
}
NumeroReal UtilitariosBasicos::potencia(NumeroReal base, NumeroReal exponente)
{
    //Por ahora el exponente solo es entero
    NumeroReal resul;
    for(int i=0;i<exponente.ObtenerNumerador();i++)
    {
	resul.CambiarNumerador(base.ObtenerNumerador()*base.ObtenerNumerador());
	resul.CambiarDenominador(base.ObtenerDenominador()*base.ObtenerDenominador());
    }
    return resul;
}
NumeroReal UtilitariosBasicos::SimplificarNumero(NumeroReal num)
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
