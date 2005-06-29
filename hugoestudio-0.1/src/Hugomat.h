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
#ifndef _Hugomat_H
#define _Hugomat_H
//#include "Hugocons.h"
/***************************************************
*La siguiente definiciones de objetos en matematica*
***************************************************/
typedef unsigned short int usi;
typedef unsigned long int uli;
#warning "Clases NumeroReal, NumeroComp y polinomio no probadas"
//Constantes
double const pi=3.141592653;
class NumeroReal
{
protected:
    int numerador;
    int denominador;
public:
    NumeroReal();//Constructor predeterminado
    NumeroReal(int nume,int deno);//Constructor
    NumeroReal IntANumReal(int entero);//Convierte un entero a un real
    int NumRealAInt(NumeroReal numero);//Convierte de real a entero
    double NumeroRealADouble(NumeroReal numero);//Convierte de numero real a double
    NumeroReal SimplificarNumero(NumeroReal num);//Simplifica un numero real
    bool SonIguales(NumeroReal a,NumeroReal b);//Comprueba si 2 NumeroReal son iguales
    NumeroReal sumar(NumeroReal a, NumeroReal b);
    void CambiarNumerador(int num)
    {
        numerador=num;
    }
    void CambiarDenominador(int dem)
    {
        denominador=dem;
    }
    int ObtenerNumerador()
    {
        return numerador;
    }
    int ObtenerDenominador()
    {
        return denominador;
    }
};

//////////////////////////////
class NumeroComp:public NumeroReal
{
private:
    NumeroReal exponenteNumero;//El numero al que esta elevado numero
    char *variable;//Variable por lo general x,y,z si es a el valor de esta es 1
    NumeroReal exponenteVariable;//El numero al que esta elevada la variable
public:
    NumeroComp();//Constructor predeterminado
    NumeroComp(NumeroReal num,NumeroReal num2, char *var,NumeroReal num3);//Constructor
    NumeroReal CompAReal(NumeroComp num);
    bool SonIguales(NumeroComp a,NumeroComp b);//Comprueba si dos objetos NumeroComp son iguales
    void CambiarNumero(NumeroReal num)
    {
        numerador=num.ObtenerNumerador();
	denominador=num.ObtenerDenominador();
    }
    void CambiarExponenteNumero(NumeroReal ex)
    {
        exponenteNumero=ex;
    }
    void CambiarVariable(char *var)
    {
        variable=var;
    }
    void CambiarExponenteVariable(NumeroReal exVar)
    {
        exponenteVariable=exVar;
    }
    NumeroReal ObtenerNumero()//Arreglar
    {
        NumeroReal resul;
	/*resul.ObtenerNumerador()=this.ObtenerNumerador();
	resul.ObtenerDenominador()=this.ObtenerDenominador();*/
	return resul;
    }
    NumeroReal ObtenerExponenteNumero()
    {
        return exponenteNumero;
    }
    char* ObtenerVariable()
    {
        return variable;
    }
    NumeroReal ObtenerExponenteVariable()
    {
        return exponenteVariable;
    }
};
/*//////////////////////////*/
class polinomio:public NumeroComp
{
private:
    NumeroComp A,B,C,D,E;
    NumeroReal exponentePolinomio;
public:
    polinomio();
    polinomio(NumeroComp a,NumeroComp b,NumeroComp c,NumeroComp d,NumeroComp e,NumeroReal ep);
    polinomio simplificar(polinomio poli);
    NumeroComp ObtenerA();    
    NumeroComp ObtenerB();
    NumeroComp ObtenerC();
    NumeroComp ObtenerD();
    NumeroComp ObtenerE();
    NumeroComp PoliAComp(polinomio poli);
    NumeroReal ObtenerExponentePolinomio()
    {
        return exponentePolinomio;
    }
    void CambiarFactorA(NumeroComp a)
    {
        A=a;
    }
    void CambiarFactorB(NumeroComp b)
    {
        B=b;
    }
    void CambiarFactorC(NumeroComp c)
    {
        C=c;
    }
    void CambiarFactorD(NumeroComp d)
    {
        D=d;
    }
    void CambiarFactorE(NumeroComp e)
    {
        E=e;
    }
};
#warning "Los metodos usan tipos primitivos imposible usar tipos NumeroReal, NumeroComp ni polinomio"
/**********************************************************************************
*La siguiente definiciones e implementaciones de la funcion son de matematica basica**
***********************************************************************************/
class operaciones//Falta implementar las de numero compuesto
{
public:
    double MaCoDi(double num1,double num2);//regresa el maximo comun divisor(no esta hecha)
    double expon(double base,double expon);//regresa la potencia    
    double expon(NumeroComp base,NumeroComp expon);//regresa la potencia
    double rad(double expo, double rad);//regresa la potencia de un radical
    double rad(NumeroComp expo, NumeroComp rad);//regresa la potencia de un radical
    double log(double base, double poten);//regresa el logaritmo de un numero
    double log(NumeroComp base, NumeroComp poten);//regresa el logaritmo de un numero
    float fradec(float nume,float deno);//regresa el decimal de una fraccion
    double ampfrac(double nume, double deno, double amp);//Amplifica un fraccionario n veces
    int bindec(int bin);//Transforma un binario en decimal
    int binoct(int bin);//Transforma un binario en octal
    float ValorAbsoluto(float numero);//Devuelve el valor absoluto de un numero
    float ValorAbsoluto(NumeroReal numero);//Devuelve el valor absoluto de un numero
};

/*****************************
*funciones de geometria plana*
*****************************/
class geometria:public operaciones
{
public:
    float cuaarea(float base, float altura);//Devuelve el area de un cauadrado
    float triarea(float base, float altura);//Devuelve el area de un triangulo
    float trapearea(float base1,float base2,float altura);//Devuelve el area de un trapecio
    float romboarea(float dia1,float dia2);//Devuelve el area de un rombo
    double circuarea(double radio);//Devuelve el area de un circulo
    float triaperi(float lado1,float lado2,float lado3);
    double cirperi(float diametro,float radio);//Devuleve el perimetro de un circulo
};

/**********************************
*funciones de geometria de volumen*
**********************************/
class volumen:public geometria
{
public:
    double cilvol(double radio,double altura);//Devuelve el volumen de un cilindro
    float cubvol(float acua,float altura);//Devuelve el volumen de un cubo y/o de un paralelepipedo
    float piravol(float base,float altura);//Devuelve el area de una piramide
    double conovol(double radio, double altura);//Devuelve el area de un cono
    double esare(double radio);//Devuleve el area de una esfera
    double esvol(double radio);//Devuleve el volumen de una esfera
};
#endif
