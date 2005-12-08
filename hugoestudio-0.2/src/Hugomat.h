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
//#warning "Clases NumeroReal, NumeroComp y polinomio no probadas"
//Constantes
double const pi=3.141592653;
class NumeroReal
{
protected:
    int numerador;
    int denominador;
    bool signo;//Verdadero es + negativo -
public:
    friend class operaciones;
    NumeroReal();//Constructor predeterminado
    NumeroReal(int nume,int deno);//Constructor
    NumeroReal(int nume,int deno, bool sig);//Constructor
    NumeroReal operator+( NumeroReal & numero);
    NumeroReal operator-( NumeroReal & numero);
    NumeroReal operator*(NumeroReal & numero);
    NumeroReal operator^(NumeroReal & numero);
    //bool operator==(NumeroReal & numero);
    void CambiarNumero(NumeroReal numero)
    {
	numerador=numero.ObtenerNumerador();
	denominador=numero.ObtenerDenominador();
	signo=numero.ObtenerSigno();
    }
    void CambiarNumerador(int num)
    {
        numerador=num;
    }
    void CambiarDenominador(int dem)
    {
        denominador=dem;
    }
    void CambiarSigno(bool sig)
    {
	signo=sig;
    }
    int ObtenerNumerador()
    {
        return numerador;
    }
    int ObtenerDenominador()
    {
        return denominador;
    }
    bool ObtenerSigno()
    {
	return signo;
    }
};

//////////////////////////////
class NumeroComp:public NumeroReal
{
protected:
    NumeroReal exponenteNumero;//El numero al que esta elevado numero
    //char *variable;//Variable por lo general x,y,z si es a el valor de esta es 1
    char variable1;
    char variable2;
    char variable3;
    NumeroReal exponenteVariable1;//El numero al que esta elevada la variable
    NumeroReal exponenteVariable2;
    NumeroReal exponenteVariable3;
public:
    NumeroComp();//Constructor predeterminado
    NumeroComp(NumeroReal num,NumeroReal num2, char var,NumeroReal num3);//Constructor
    NumeroReal CompAReal(NumeroComp num);
    bool SonIguales(NumeroComp a,NumeroComp b);//Comprueba si dos objetos NumeroComp son iguales
    NumeroComp operator+(NumeroComp &num);
    NumeroComp operator-(NumeroComp &num);
    NumeroComp operator*(NumeroComp &num);
    NumeroComp operator/(NumeroComp &num);
    void CambiarExponenteNumero(NumeroReal ex)
    {
        exponenteNumero=ex;
    }
    void CambiarVariable1(char var)
    {
        variable1=var;		
    }
    void CambiarVariable2(char var)
    {
        variable2=var;		
    }
    void CambiarVariable3(char var)
    {
        variable3=var;		
    }
    void CambiarExponenteVariable1(NumeroReal exVar)
    {
        exponenteVariable1=exVar;
    }
    void CambiarExponenteVariable2(NumeroReal exVar)
    {
        exponenteVariable2=exVar;
    }
    void CambiarExponenteVariable3(NumeroReal exVar)
    {
        exponenteVariable3=exVar;
    }
    void CambiarVariables(char var1,char var2,char var3)
    {
	variable1=var1;
	variable2=var2;
	variable3=var3;
    }
    NumeroReal ObtenerNumero()//Arreglar
    {
        NumeroReal resul;
	resul.CambiarNumerador(/*this.*/ObtenerNumerador());
	resul.CambiarDenominador(/*this.*/ObtenerDenominador());
	resul.CambiarSigno(ObtenerSigno());
	return resul;
    }
    NumeroReal ObtenerExponenteNumero()
    {
        return exponenteNumero;
    }
    char ObtenerVariable1()
    {
        return variable1;
    }
    char ObtenerVariable2()
    {
        return variable2;
    }
    char ObtenerVariable3()
    {
        return variable3;
    }
    NumeroReal ObtenerExponenteVariable1()
    {
        return exponenteVariable1;
    }
    NumeroReal ObtenerExponenteVariable2()
    {
        return exponenteVariable2;
    }
    NumeroReal ObtenerExponenteVariable3()
    {
        return exponenteVariable3;
    }
};
/*//////////////////////////*/
class polinomio:NumeroComp
{
private:
    NumeroComp A,B,C,D,E;
    NumeroReal exponentePolinomio;
public:
    polinomio();
    polinomio(NumeroComp a,NumeroComp b,NumeroComp c,NumeroComp d,NumeroComp e,NumeroReal ep);
    polinomio simplificar();
    polinomio multiplicar();
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
    void CambiarSignoA(bool signo)
    {
	A.CambiarSigno(signo);
    }
    void CambiarSignoB(bool signo)
    {
	B.CambiarSigno(signo);
    }
    void CambiarSignoC(bool signo)
    {
	C.CambiarSigno(signo);
    }
    void CambiarSignoD(bool signo)
    {
	D.CambiarSigno(signo);
    }
    void CambiarSignoE(bool signo)
    {
	E.CambiarSigno(signo);
    }
    NumeroComp ObtenerA()
    {
	return A;
    }
    NumeroComp ObtenerB()
    {
	return B;
    }
    NumeroComp ObtenerC()
    {
	return C;
    }
    NumeroComp ObtenerD()
    {
	return D;
    }
    NumeroComp ObtenerE()
    {
	return E;
    }
};
//#warning "Los metodos usan tipos primitivos imposible usar tipos NumeroReal, NumeroComp ni polinomio"
/*******************
*Clases utilitarias*
*******************/
/*****************************************
*Clase de metodos que reemplazan operator*
*****************************************/
class UtilitariosBasicos
{
public:
    static NumeroReal IntANumReal(int entero);//Convierte un entero a un real
    static int NumRealAInt(NumeroReal numero);//Convierte de real a entero
    static double NumeroRealADouble(NumeroReal numero);//Convierte de numero real a double
    static NumeroReal SimplificarNumero(NumeroReal num);//Simplifica un numero real
    static bool SonIguales(NumeroReal a,NumeroReal b);//Comprueba si 2 NumeroReal son iguales
    static NumeroReal sumar(NumeroReal a, NumeroReal b);//Suma dos numeros reales
    static NumeroReal restar(NumeroReal a, NumeroReal b);//resta dos numeros reales(solo para aplicar en derivada)
    static NumeroReal multiplicar(NumeroReal a, NumeroReal b);
    static NumeroReal potencia(NumeroReal base, NumeroReal exponente);
};
/************************************************************************************
*La siguiente definiciones e implementaciones de la funcion son de matematica basica*
************************************************************************************/
class UtilitariosOperaciones//Falta implementar las de numero compuesto
{
public:
    static double MaCoDi(double num1,double num2);//regresa el maximo comun divisor(no esta hecha)
    static double expon(double base,double expon);//regresa la potencia    
    static double expon(NumeroComp base,NumeroComp expon);//regresa la potencia
    static double rad(double expo, double rad);//regresa la potencia de un radical
    static double rad(NumeroComp expo, NumeroComp rad);//regresa la potencia de un radical
    static double log(double base, double poten);//regresa el logaritmo de un numero
    static double log(NumeroComp base, NumeroComp poten);//regresa el logaritmo de un numero
    static float fradec(float nume,float deno);//regresa el decimal de una fraccion
    static double ampfrac(double nume, double deno, double amp);//Amplifica un fraccionario n veces
    static int bindec(int bin);//Transforma un binario en decimal
    static int binoct(int bin);//Transforma un binario en octal
    static float ValorAbsoluto(float numero);//Devuelve el valor absoluto de un numero
    static float ValorAbsoluto(NumeroReal numero);//Devuelve el valor absoluto de un numero
    static polinomio derivada(polinomio funcion);//Devuelve la derivada
    static NumeroComp derivada(NumeroComp funcion);//Devuelve la derivada
    static polinomio integral(polinomio funcion);//Devuelve la integral indefinida
    static NumeroComp integral(NumeroComp funcion);//Devuelve la integral indefinida
    static NumeroReal integralD(NumeroReal LimInferior, NumeroReal LimSuperior, polinomio funcion);//Devuelve la integral definida
};

/*****************************
*funciones de geometria plana*
*****************************/
class UtilitariosGeometria
{
public:
    static float cuaarea(float base, float altura);//Devuelve el area de un cauadrado
    static float triarea(float base, float altura);//Devuelve el area de un triangulo
    static float trapearea(float base1,float base2,float altura);//Devuelve el area de un trapecio
    static float romboarea(float dia1,float dia2);//Devuelve el area de un rombo
    static double circuarea(double radio);//Devuelve el area de un circulo
    static float triaperi(float lado1,float lado2,float lado3);
    static double cirperi(float diametro,float radio);//Devuleve el perimetro de un circulo
};

/**********************************
*funciones de geometria de volumen*
**********************************/
class UtilitariosVolumen
{
public:
    static double cilvol(double radio,double altura);//Devuelve el volumen de un cilindro
    static float cubvol(float acua,float altura);//Devuelve el volumen de un cubo y/o de un paralelepipedo
    static float piravol(float base,float altura);//Devuelve el area de una piramide
    static double conovol(double radio, double altura);//Devuelve el area de un cono
    static double esare(double radio);//Devuleve el area de una esfera
    static double esvol(double radio);//Devuleve el volumen de una esfera
};
bool operator==(NumeroReal & numero1,NumeroReal & numero2)
{
   bool resul=false;
   if(numero1.ObtenerNumerador()==numero2.ObtenerNumerador()&&numero1.ObtenerDenominador()==numero2.ObtenerDenominador()&&numero1.ObtenerSigno()==numero2.ObtenerSigno())
   {
       resul=true;
   }
   return resul;
}
#endif
