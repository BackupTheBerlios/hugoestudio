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
#include "interprete.h"
#include "traduccion2.h"
//Variables globales
FILE *archivoDatos=NULL;
FILE *archivoDebug=NULL;
FILE *archivoRes=NULL;
uli factores;
//usi i,j=0;
char factores2[10];
polinomio pol,pol2;
NumeroReal rea,/**/real,real2;
NumeroComp com,/**/comp,comp2;
bool interprete::interprete1(wxString linea)
{
    lenguajea2();
    bool si=false;
    int tempo=0,tempo2=0;
    polinomio respuestaAn;
    archivoDatos=fopen("TempInterprete.hs","w");
    archivoDebug=fopen("TempDebug.hs","w");
    fprintf(archivoDebug,L_Ev_Ope);
    if(linea.GetChar(0)=='+'||linea.GetChar(0)=='*')
    {
        return SINTAXIS_PRIMER;
    }
    if(linea.GetChar(0)=='/'||linea.GetChar(0)=='-'||linea.GetChar(0)=='?')
    {
        return SINTAXIS_PRIMER;
    }
    wxString subCadena,subCadena2;
    if(linea.IsNumber())
    {
        fprintf(archivoDebug,L_S_o);
        polinomio temp1[3],temp2;
        usi i=0,nums=0, nums2=0, nums3=0;
        subCadena=linea;
        nums=ObtenerNumDeOperacion(subCadena);
        nums2=ObtenerNumCharsOperacion(subCadena);
        for(i=0;i<nums;i++)
        {
            nums3=ObtenerNumCharsOperacion(subCadena,nums);
            temp1[i]=StringAPoli(subCadena);
        }
        si=true;
    }
    subCadena=linea.Mid(0,1);
    if(subCadena=='{')
    {
        fprintf(archivoDebug,L_S_o);
        pol=StringAPoli(linea.Mid(1,linea.length()));
	polinomio pm;
	if(linea.Find('+')!=-1)
	{
	    pm=pol.simplificar();
	}
	else if(linea.Find('-')!=-1)
	{
	    pm=pol.simplificar();
	}
	else if(linea.Find('*')!=-1)
	{
	    pm=pol.multiplicar();
	}
        //polinomio pm=pol.simplificar();
        wxString a=PoliAString(pm);
        fprintf(archivoDebug,a);
        si=true;
    }
    if(subCadena=="e"&&linea.GetChar(1)!='x')
    {
        factores=EXPONENCI;
        fprintf(archivoDebug,L_S_oe);
        subCadena2=linea.Mid(1,linea.length()-2);
        wxString exponTemp=ObtenerPolinomioParen(subCadena2);
        if(exponTemp=="error")
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        else
        {
            if(exponTemp.Contains('+')||exponTemp.Contains('-'))
            {
                fprintf(archivoDebug,L_Poli_De);
                fprintf(archivoDebug,"Interprete: Transformando de texto a polinomio\n");
                pol=StringAPoli(exponTemp);
                fprintf(archivoDebug,"Interprete: Transformando de polinomio a numero compuesto\n");
                com=PoliAComp(pol);
                fprintf(archivoDebug,"Interprete: Transformando de numero compuesto a numero real\n");
                rea=CompAReal(com);
            }
            else
            {
                fprintf(archivoDebug,"Interprete: Detectado Numero real o compuesto\n");
                fprintf(archivoDebug,"Interprete: haciendo tareas pertinentes\n");
                if(exponTemp.Contains('x')||exponTemp.Contains('y')||exponTemp.Contains('z'))
                {
                    com=StringAComp(exponTemp);
                }
                else
                {
                    rea=CompAReal(com);
                    double dou=UtilitariosBasicos::NumeroRealADouble(rea);
                    archivoRes=fopen("TempInterpreteRes.hs","w");
                    fprintf(archivoRes,"%f",exp(dou));
                    fclose(archivoRes);
                }
            }
            si=true;
        }
    }
    subCadena=linea.Mid(0,2);
    if(subCadena=="ln")
    {
        factores=LOGANATU;
        fprintf(archivoDebug,"Interprete: Operacion Logaritmo natural\n");
        subCadena2=linea.Mid(2,linea.length());
        wxString exponTemp=ObtenerPolinomioParen(subCadena2);
        if(exponTemp=="error")
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        else
        {
            if(exponTemp.Contains('+')||exponTemp.Contains('-'))
            {
                fprintf(archivoDebug,L_Poli_De);
                fprintf(archivoDebug,"Interprete: Transformando de texto a polinomio\n");
                pol=StringAPoli(exponTemp);
                fprintf(archivoDebug,"Interprete: Transformando de polinomio a numero compuesto\n");
                com=PoliAComp(pol);
                fprintf(archivoDebug,"Interprete: Transformando de numero compuesto a numero real\n");
                rea=CompAReal(com);
            }
            else
            {
                fprintf(archivoDebug,"Interprete: Detectado Numero real o compuesto\n");
                fprintf(archivoDebug,"Interprete: haciendo tareas pertinentes\n");
                if(exponTemp.Contains('x')||exponTemp.Contains('y')||exponTemp.Contains('z'))
                {
                    com=StringAComp(exponTemp);
                }
                else
                {
                    rea=CompAReal(com);
                    double dou=UtilitariosBasicos::NumeroRealADouble(rea);
                    archivoRes=fopen("TempInterpreteRes.hs","w");
                    fprintf(archivoRes,"%f",log(dou));
                    fclose(archivoRes);
                }
            }
            si=true;
        }
    }
    subCadena=linea.Mid(0,3);
    if(subCadena=="log")
    {
        factores=LOGARITMO;
        fprintf(archivoDebug,"Interprete: Operacion Logaritmo\n");
        subCadena2=linea.Mid(3,linea.length());
        usi exponTemp=ParenNumCarac(subCadena2);
        if(exponTemp==0)
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
            return si;
        }
        wxString exponTemp2=ObtenerPolinomioAntesComa(subCadena2);
        if(exponTemp2=="error")
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        wxString exponTemp3=ObtenerPolinomioDesComa(subCadena2,exponTemp);
        if(exponTemp3=="error")
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        else
        {
            if(exponTemp2.Contains('+')||exponTemp2.Contains('-')&&exponTemp3.Contains('+'))
            {
                fprintf(archivoDebug,L_Poli_De);
                fprintf(archivoDebug,"Interprete: Transformando de texto a polinomio\n");
                pol=StringAPoli(exponTemp2);
                pol2=StringAPoli(exponTemp3);
                fprintf(archivoDebug,"Interprete: Transformando de polinomio a numero compuesto\n");
                comp=PoliAComp(pol);
                comp2=PoliAComp(pol2);
                fprintf(archivoDebug,"Interprete: Transformando de numero compuesto a numero real\n");
                real=CompAReal(comp);
                real2=CompAReal(comp2);
                tempo=UtilitariosBasicos::NumRealAInt(real);
                tempo2=UtilitariosBasicos::NumRealAInt(real2);
                fprintf(archivoDebug,"Interprete: Enviando datos para operar en HugoMat\n");
            }
            else
            {
                fprintf(archivoDebug,"Interprete: Detectado Numero real o compuesto\n");
                fprintf(archivoDebug,"Interprete: haciendo tareas pertinentes\n");
                if(exponTemp2.Contains('x')||exponTemp2.Contains('y')||exponTemp2.Contains('z'))
                {
                    comp=StringAComp(exponTemp2);
                    comp2=StringAComp(exponTemp3);
                }
                else
                {
                    comp=StringAComp(exponTemp2);
                    comp2=StringAComp(exponTemp3);
                    real=CompAReal(comp);
                    real2=CompAReal(comp2);
                    tempo=UtilitariosBasicos::NumRealAInt(real);
                    tempo2=UtilitariosBasicos::NumRealAInt(real2);
                    fprintf(archivoDebug,"Interprete: Enviando datos para operar en HugoMat\n");
                    fprintf(archivoDebug, "%f", UtilitariosOperaciones::log(tempo,tempo2));
                    archivoRes=fopen("TempInterpreteRes.hs","w");
                    fprintf(archivoRes,"%f",UtilitariosOperaciones::log(tempo,tempo2));
                    fprintf(archivoRes, "\n");
                    fclose(archivoRes);
                }
            }
            cout<<UtilitariosOperaciones::log(tempo,tempo2)<<endl;
            si=true;
        }
        //si= true;
    }
    subCadena=linea.Mid(0,4);
    if(subCadena=="raiz")
    {
        factores=RAIZ;
        fprintf(archivoDebug,"Interprete: Operacion raiz\n");
        subCadena2=linea.Mid(4,linea.length());
        usi exponTemp=ParenNumCarac(subCadena2);
        if(exponTemp==0)
        {
            si=false;
        }
        wxString exponTemp2=ObtenerPolinomioAntesComa(subCadena2);
        if(exponTemp2=="error")
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        wxString exponTemp3=ObtenerPolinomioDesComa(subCadena2,exponTemp);
        if(exponTemp3=="error")
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        else
        {
            if(exponTemp2.Contains('+')||exponTemp2.Contains('-')&&exponTemp3.Contains('+'))
            {
                fprintf(archivoDebug,L_Poli_De);
                fprintf(archivoDebug,"Interprete: Transformando de texto a polinomio\n");
                pol=StringAPoli(exponTemp2);
                pol2=StringAPoli(exponTemp3);
                fprintf(archivoDebug,"Interprete: Transformando de polinomio a numero compuesto\n");
                comp=PoliAComp(pol);
                comp2=PoliAComp(pol2);
                fprintf(archivoDebug,"Interprete: Transformando de numero compuesto a numero real\n");
                real=CompAReal(comp);
                real2=CompAReal(comp2);
                tempo=UtilitariosBasicos::NumRealAInt(real);
                tempo2=UtilitariosBasicos::NumRealAInt(real2);
                fprintf(archivoDebug,"Interprete: Enviando datos para operar en HugoMat\n");
            }
            else
            {
                fprintf(archivoDebug,"Interprete: Detectado Numero real o compuesto\n");
                fprintf(archivoDebug,"Interprete: haciendo tareas pertinentes\n");
                if(exponTemp2.Contains('x')||exponTemp2.Contains('y')||exponTemp2.Contains('z'))
                {
                    comp=StringAComp(exponTemp2);
                    comp2=StringAComp(exponTemp3);
                }
                else
                {
                    comp=StringAComp(exponTemp2);
                    comp2=StringAComp(exponTemp3);
                    real=CompAReal(comp);
                    real2=CompAReal(comp2);
                    tempo=UtilitariosBasicos::NumRealAInt(real);
                    tempo2=UtilitariosBasicos::NumRealAInt(real2);
                    fprintf(archivoDebug,"Interprete: Enviando datos para operar en HugoMat\n");
                    fprintf(archivoDebug, "%f", UtilitariosOperaciones::rad(tempo,tempo2));
                    archivoRes=fopen("TempInterpreteRes.hs","w");
                    fprintf(archivoRes,"%f",UtilitariosOperaciones::rad(tempo,tempo2));
                    fprintf(archivoRes, "\n");
                    fclose(archivoRes);
                }
            }
            si=true;
        }
    }
    subCadena=linea.Mid(0,5);
    if(subCadena=="expon")
    {
        factores=POTENCIA;
        fprintf(archivoDebug,"Interprete: Operacion exponencial general\n");
        subCadena2=linea.Mid(5,linea.length());
        usi exponTemp=ParenNumCarac(subCadena2);
        if(exponTemp==0)
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        wxString exponTemp2=ObtenerPolinomioAntesComa(subCadena2);
        if(exponTemp2=="error")
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        wxString exponTemp3=ObtenerPolinomioDesComa(subCadena2,exponTemp);
        if(exponTemp3=="error")
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        else
        {
            if(exponTemp2.Contains('+')||exponTemp2.Contains('-')&&exponTemp3.Contains('+'))
            {
                fprintf(archivoDebug,L_Poli_De);
                fprintf(archivoDebug,"Interprete: Transformando de texto a polinomio\n");
                pol=StringAPoli(exponTemp2);
                pol2=StringAPoli(exponTemp3);
                fprintf(archivoDebug,"Interprete: Transformando de polinomio a numero compuesto\n");
                comp=PoliAComp(pol);
                comp2=PoliAComp(pol2);
                fprintf(archivoDebug,"Interprete: Transformando de numero compuesto a numero real\n");
                real=CompAReal(comp);
                real2=CompAReal(comp2);
                tempo=UtilitariosBasicos::NumRealAInt(real);
                tempo2=UtilitariosBasicos::NumRealAInt(real2);
                fprintf(archivoDebug,"Interprete: Enviando datos para operar en HugoMat\n");
            }
            else
            {
                fprintf(archivoDebug,"Interprete: Detectado Numero real o compuesto\n");
                fprintf(archivoDebug,"Interprete: haciendo tareas pertinentes\n");
                if(exponTemp2.Contains('x')||exponTemp2.Contains('y')||exponTemp2.Contains('z'))
                {
                    comp=StringAComp(exponTemp2);
                    comp2=StringAComp(exponTemp3);
                }
                else
                {
                    comp=StringAComp(exponTemp2);
                    comp2=StringAComp(exponTemp3);
                    real=CompAReal(comp);
                    real2=CompAReal(comp2);
                    tempo=UtilitariosBasicos::NumRealAInt(real);
                    tempo2=UtilitariosBasicos::NumRealAInt(real2);
                    fprintf(archivoDebug,"Interprete: Enviando datos para operar en HugoMat\n");
                    fprintf(archivoDebug, "%f", UtilitariosOperaciones::expon(tempo,tempo2));
                    archivoRes=fopen("TempInterpreteRes.hs","w");
                    fprintf(archivoRes,"%f",UtilitariosOperaciones::expon(tempo,tempo2));
                    fprintf(archivoRes, "\n");
                    fclose(archivoRes);
                }
            }
            si=true;
        }
    }
    subCadena=linea.Mid(0,8);
    if(subCadena=="integral")
    {
        factores=INTEGRAL;
        fprintf(archivoDebug,"Interprete: Operacion integral\n");
        subCadena2=linea.Mid(8,linea.length());//En integral no aplica FIXME
        usi exponTemp=ParenNumCarac(subCadena2);//Numero de chars antes de ','
        if(exponTemp==0)
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        wxString exponTemp2=ObtenerPolinomioAntesComa(subCadena2);//RegresaElString desde 1parentesis hasta coma
        if(exponTemp2=="error")
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        wxString exponTemp3=ObtenerPolinomioDesComa(subCadena2,exponTemp);//RegresaStringDesdeComaAParentesis
        if(exponTemp3=="error")
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        usi exponTemp4=ObtenerNumChars(linea);//regresa el numero de chars desde inicio hasta '{'
	subCadena2=linea.Mid(exponTemp4,linea.length());
        subCadena2=ObtenerPolinomioParen(subCadena2);//Selec�SupuestamenteDesdeLa{
        if(exponTemp4==0/*||exponTemp5=="error"*/)
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        else
        {
            if(subCadena2.Contains('+')||subCadena2.Contains('-'))
            {
                fprintf(archivoDebug,L_Poli_De);
                fprintf(archivoDebug,"Interprete: Transformando de texto a polinomio\n");
                pol=StringAPoli(subCadena2);
		polinomio poliT;
		NumeroComp NumResultado;
		if(exponTemp2.IsNumber()&&exponTemp3.IsNumber())
		{
		    double ba,bb;
		    double *a=&ba,*b=&bb;
		    exponTemp2.ToDouble(a);
		    exponTemp3.ToDouble(b);
		    NumResultado.CambiarNumero(UtilitariosOperaciones::integralD(NumeroReal((int)ba,1),NumeroReal((int)bb,1),pol));
		    CompAString(NumResultado);
		}
		else
		{
		    poliT=UtilitariosOperaciones::integral(pol);
		    PoliAString(poliT);
		}
		
            }
            else
            {
                fprintf(archivoDebug,"Interprete: Detectado Numero real o compuesto\n");
                fprintf(archivoDebug,"Interprete: haciendo tareas pertinentes\n");
                if(subCadena2.Contains('x')||subCadena2.Contains('y')||subCadena2.Contains('z'))
                {
                    com=StringAComp(subCadena2);
                    fprintf(archivoDebug,"Interprete: Enviando datos para operar en HugoMat\n");
		    NumeroComp te;
		    fprintf(archivoDebug,exponTemp2);
		    fprintf(archivoDebug,exponTemp3);
		    if(exponTemp3.Find('(')||exponTemp3.Find('{'))
		    {
			exponTemp3.RemoveLast();
			exponTemp3.RemoveLast();
		    }
		    fprintf(archivoDebug,exponTemp2);
		    fprintf(archivoDebug,exponTemp3);
		    if(exponTemp2.IsNumber()&&exponTemp3.IsNumber())
		    {
			double ba,bb;
			double *a=&ba,*b=&bb;
			exponTemp2.ToDouble(a);
			exponTemp3.ToDouble(b);
			te.CambiarNumero(UtilitariosOperaciones::integralD(NumeroReal((int)ba,1),NumeroReal((int)bb,1),pol));
			//NumeroComp te=intermediario.integralD(com);			
		    }
		    else
		    {
			NumeroComp te=UtilitariosOperaciones::integral(com);
		    }
		    CompAString(te);
                }
                si=true;
            }
        }
    }
    else if(subCadena=="derivada")
    {
        factores=DERIVADA;
        fprintf(archivoDebug,"Interprete: Operacion derivada\n");
        subCadena2=linea.Mid(8,linea.length());
        wxString exponTemp=ObtenerPolinomioParen(subCadena2);
        if(exponTemp=="error")
        {
            fprintf(archivoDebug,L_NoArg);
            si=false;
        }
        else
        {
            if(exponTemp.Contains('+')||exponTemp.Contains('-'))
            {
                fprintf(archivoDebug,L_Poli_De);
                fprintf(archivoDebug,"Interprete: Transformando de texto a polinomio\n");
                pol=StringAPoli(exponTemp);
                polinomio poliT=UtilitariosOperaciones::derivada(pol);
		PoliAString(poliT);
            }
            else
            {
                fprintf(archivoDebug,"Interprete: Detectado Numero real o compuesto\n");
                fprintf(archivoDebug,"Interprete: haciendo tareas pertinentes\n");
                if(exponTemp.Contains('x')||exponTemp.Contains('y')||exponTemp.Contains('z'))
                {
		    
                    com=StringAComp(exponTemp);
                    fprintf(archivoDebug,"Interprete: Enviando datos para operar en HugoMat\n");
                    NumeroComp te=UtilitariosOperaciones::derivada(com);
		    CompAString(te);
                }
                else
                {
		    com.CambiarNumerador(0);
		    CompAString(com);
                }
            }
            si=true;
        }
    }
    fclose(archivoDatos);
    fclose(archivoDebug);
    return si;
}
wxString interprete::ObtenerPolinomioParen(wxString parentesis)
{
    wxString obpa;
    char a=parentesis.GetChar(0);
    if(a=='('||a=='{')
    {
        obpa=parentesis.Mid(1,(parentesis.length()-1));
    }
    else
    {
        return "error";
        //for(i=0;i<parentesis.length();i++){}
    }
    return obpa;
}
usi interprete::ParenNumCarac(wxString parentesis)
{
    usi i=0;
    char a=parentesis.GetChar(0);
    if(a=='('||a=='{')
    {
        for(i=0;i<parentesis.length();i++)
        {
            if(parentesis.GetChar(i)==',')
                break;
        }
    }
    return i;
}
wxString interprete::ObtenerPolinomioAntesComa(wxString antesComa)
{
    usi i;
    wxString obpa="error";
    char a=antesComa.GetChar(0);
    if(a=='('||a=='{')
    {
        for(i=0;i<antesComa.length();i++)
        {
            if(antesComa.GetChar(i)==',')
                break;
            else
            {
                obpa=antesComa.Mid(1,i);
                continue;
            }
        }
    }
    return obpa;
}
wxString interprete::ObtenerPolinomioDesComa(wxString DespuesComa, usi it)
{
    wxString obpa="error";
    usi DondeComa=DespuesComa.Find(',');
    usi DondeP=DespuesComa.Find(')');
    DondeComa++;
    DondeP--;
    obpa=DespuesComa.Mid(DondeComa,DondeP);
    return obpa;
}
usi interprete::ObtenerNumChars(wxString parentesis)
{
    usi i;
    for(i=0;i<parentesis.length();i++)
    {
        if(parentesis.GetChar(i)=='{')
            break;
    }
    return i;
}
polinomio interprete::StringAPoli(wxString poli)//Pasar a hugomat?
{
    NumeroComp parteN1, parteN2;
    polinomio resultado;
    wxString parte1;
    //Mire a ver donde esta el + o el -
    int cantidad=ObtenerNumDeOperacion(poli),temporal;
    int numChar=ObtenerNumCharsOperacion(poli);//FIXME!!!!!!
    //Hasta ese punto seleccione
    parte1=poli.SubString(0,numChar);
    //Lo envie a StringAComp
    parteN1=StringAComp(parte1);
    resultado.CambiarFactorA(parteN1);
    //Asi con todas las partes del polinomio
    if(cantidad>1)
    {
        temporal=numChar;
        int signo=1;
        usi otroChar=ObtenerNumCharsOperacion(poli,poli.length());
        if(poli.GetChar(numChar+1)=='-')
        {
            resultado.CambiarSignoB(false);
            parteN2.CambiarSigno(false);
            signo=0;
        }
        wxString parte2=poli.SubString(numChar+2,otroChar);
        parteN2=StringAComp(parte2);
        if(signo==0)
        {
            parteN2.CambiarSigno(false);
        }
        resultado.CambiarFactorB(parteN2);
    }
    return resultado;
}
NumeroReal interprete::CompAReal(NumeroComp poli)//Pasar a hugomat
{
    NumeroReal resul;
    resul.CambiarNumerador(poli/*.ObtenerNumero()*/.ObtenerNumerador());
    resul.CambiarDenominador(poli/*.ObtenerNumero()*/.ObtenerDenominador());
    return resul;
}
NumeroComp interprete::StringAComp(wxString poli)//Pasar a hugomat?
{
    usi primera=0,segunda=0,tercera=0;
    double resulVariable1=1,resulVariable2=1,resulVariable3=1,resulNum=1;
    double *resulNumero=&resulNum,*exponente1=&resulVariable1,*exponente2=&resulVariable2;
    double *exponente3=&resulVariable3;
    char variables[3]={'a','a','a'};
    NumeroReal resulPar,tempo,tempo1,tempo2,tempo3;
    NumeroComp resulPar2,numeroExpoVarC;
    NumeroComp resultado;
    wxString Numero,ex1,ex2,ex3;
    if(poli.Find('x')!=-1||poli.Find('X')!=-1)
    {
        variables[0]='x';
        //		variablesP++;
    }
    if(poli.Find('y')!=-1||poli.Find('Y')!=-1)
    {
        variables[1]='y';
        //variablesP++;
    }
    if(poli.Find('z')!=-1||poli.Find('Z')!=-1)
    {
        variables[2]='z';
        //variablesP++;
    }
    if(variables[0]=='a'&&variables[1]=='a'&&variables[2]=='a')
    {
        poli.ToDouble(resulNumero);
    }
    else
    {
        if(variables[0]!='a')
        {
            primera=poli.Find('x');
            Numero=poli.Mid(0,primera);
            if(Numero.IsNumber())
            {
                Numero.ToDouble(resulNumero);
            }
        }
        primera=primera+1;
        if(variables[1]=='a'||variables[2]=='a')
        {
            ex1=poli.Mid(primera,poli.length());
	    if(ex1.Find(')')!=-1)
	    {
		ex1=ex1.BeforeFirst(')');
	    }
	    else if(ex1.Find('}')!=-1)
	    {
		ex1=ex1.BeforeFirst('}');
	    }
            if(ex1.IsNumber())
            {
                ex1.ToDouble(exponente1);
            }
        }
        if(variables[1]!='a')
        {
            segunda=poli.Find('y');
            ex1=poli.Mid(primera,segunda);
            ex1=ex1.BeforeFirst('y');
            if(ex1.IsNumber())
            {
                ex1.ToDouble(exponente1);
            }
        }
        segunda++;
        if(variables[2]!='a')
        {
            tercera=poli.Find('z');
            ex2=poli.Mid(segunda,tercera);
            ex2=ex2.BeforeFirst('z');
            //ex2=poli.Mid(segunda,tercera-6);
            if(ex2.IsNumber())
            {
                ex2.ToDouble(exponente2);
            }
            ex3=poli.AfterLast('z');
        }
        if(ex3.IsNumber())
        {
            ex3.ToDouble(exponente3);
        }
        if(resulVariable1!=0)
        {
            tempo1.CambiarNumerador((int)resulVariable1);
        }
        if(resulVariable2!=0)
        {
            tempo2.CambiarNumerador((int)resulVariable2);
        }
        if(resulVariable3!=0)
        {
            tempo3.CambiarNumerador((int)resulVariable3);
        }
    }
    /////////////////////
    resulPar.CambiarNumerador((int)resulNum);
    resulPar2.CambiarNumero(resulPar);
    resulPar2.CambiarVariable1(variables[0]);
    resulPar2.CambiarVariable2(variables[1]);
    resulPar2.CambiarVariable3(variables[2]);
    resulPar2.CambiarExponenteVariable1(tempo1);
    resulPar2.CambiarExponenteVariable2(tempo2);
    resulPar2.CambiarExponenteVariable3(tempo3);
    resultado=resulPar2;
    return resultado;
}
NumeroComp interprete::PoliAComp(polinomio poli)//Pasar a hugomat
{
    NumeroComp resultado;
    resultado=poli.ObtenerA();
    return resultado;
}
wxString interprete::ObtenerLinea(wxString string,int numeroLinea)
{
    wxString resul,stringTemp;
    int len=string.Length();
    int i=0,LineaTemp=0,NuCaracteres=0,NuCaracteresMenor=0;
    do
    {
        if(string.GetChar(i)=='\n')
        {
            LineaTemp++;//++?
            if(LineaTemp==numeroLinea)
                break;
        }
        i++;
        NuCaracteres++;
        if(i==numeroLinea-1)
        {
            stringTemp=string.Mid(0,NuCaracteres);
            NuCaracteresMenor=stringTemp.Len();
        }
    }
    while(i<len);
    resul=string.Mid(NuCaracteresMenor,NuCaracteres);
    cout<<"Valor de NuCaracteresMenor: "<<NuCaracteresMenor<<endl;
    cout<<"Valor de NuCaracteres: "<<NuCaracteres<<endl;
    return resul;
}
usi interprete::ObtenerNumCharsOperacion(wxString parentesis)
{
    usi i=0,resul=0;
    for(i=0;i<parentesis.length();i++)
    {
        if(parentesis.GetChar(i)=='+'||parentesis.GetChar(i)=='-'||parentesis.GetChar(i)=='*')
            break;
    }
    resul=i-1;
    return resul;
}
usi interprete::ObtenerNumDeOperacion(wxString parentesis)
{
    usi i=0,resul=0;
    for(i=0;i<parentesis.length();i++)
    {
        if(parentesis.GetChar(i)=='+'||parentesis.GetChar(i)=='-'||parentesis.GetChar(i)=='*')
            resul++;
    }
    return resul+1;
}
usi interprete::ObtenerNumCharsOperacion(wxString parentesis, usi longitudMa)
{
    int i=0,resul=0;
    while(parentesis.GetChar(i)!='+'||parentesis.GetChar(i)!='-'||parentesis.GetChar(i)=='*')
    {
        resul++;
        i++;
        if(i==longitudMa)
            break;
    }
    return resul;
}
wxString interprete::PoliAString(polinomio poli)//??????????????
{
    wxString resultado;
    archivoRes=fopen("TempInterpreteRes.hs","w");
    fprintf(archivoRes,"%i",poli.ObtenerA().ObtenerSigno());
    fprintf(archivoRes,"   ");
    fprintf(archivoRes,"%i",poli.ObtenerA().ObtenerNumero().ObtenerNumerador());
    fprintf(archivoRes,"/");
    fprintf(archivoRes,"%i",poli.ObtenerA().ObtenerNumero().ObtenerDenominador());
    fprintf(archivoRes,"%c",poli.ObtenerA().ObtenerVariable1());
    fprintf(archivoRes,"%i",poli.ObtenerA().ObtenerExponenteVariable1().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerA().ObtenerVariable2());
    fprintf(archivoRes,"%i",poli.ObtenerA().ObtenerExponenteVariable2().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerA().ObtenerVariable3());
    fprintf(archivoRes,"%i",poli.ObtenerA().ObtenerExponenteVariable3().ObtenerNumerador());
    fprintf(archivoRes,"   ");
    fprintf(archivoRes,"%i",poli.ObtenerB().ObtenerSigno());
    fprintf(archivoRes,"   ");
    fprintf(archivoRes,"%i",poli.ObtenerB().ObtenerNumero().ObtenerNumerador());
    fprintf(archivoRes,"/");
    fprintf(archivoRes,"%i",poli.ObtenerB().ObtenerNumero().ObtenerDenominador());
    fprintf(archivoRes,"%c",poli.ObtenerB().ObtenerVariable1());
    fprintf(archivoRes,"%i",poli.ObtenerB().ObtenerExponenteVariable1().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerB().ObtenerVariable2());
    fprintf(archivoRes,"%i",poli.ObtenerB().ObtenerExponenteVariable2().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerB().ObtenerVariable3());
    fprintf(archivoRes,"%i",poli.ObtenerB().ObtenerExponenteVariable3().ObtenerNumerador());
    fprintf(archivoRes,"   ");
    fprintf(archivoRes,"%i",poli.ObtenerC().ObtenerSigno());
    fprintf(archivoRes,"   ");
    fprintf(archivoRes,"%i",poli.ObtenerC().ObtenerNumero().ObtenerNumerador());
    fprintf(archivoRes,"/");
    fprintf(archivoRes,"%i",poli.ObtenerC().ObtenerNumero().ObtenerDenominador());
    fprintf(archivoRes,"%c",poli.ObtenerC().ObtenerVariable1());
    fprintf(archivoRes,"%i",poli.ObtenerC().ObtenerExponenteVariable1().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerC().ObtenerVariable2());
    fprintf(archivoRes,"%i",poli.ObtenerC().ObtenerExponenteVariable2().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerC().ObtenerVariable3());
    fprintf(archivoRes,"%i",poli.ObtenerC().ObtenerExponenteVariable3().ObtenerNumerador());
    fprintf(archivoRes,"   ");
    fprintf(archivoRes,"%i",poli.ObtenerD().ObtenerSigno());
    fprintf(archivoRes,"   ");
    fprintf(archivoRes,"%i",poli.ObtenerD().ObtenerNumero().ObtenerNumerador());
    fprintf(archivoRes,"/");
    fprintf(archivoRes,"%i",poli.ObtenerD().ObtenerNumero().ObtenerDenominador());
    fprintf(archivoRes,"%c",poli.ObtenerD().ObtenerVariable1());
    fprintf(archivoRes,"%i",poli.ObtenerD().ObtenerExponenteVariable1().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerD().ObtenerVariable2());
    fprintf(archivoRes,"%i",poli.ObtenerD().ObtenerExponenteVariable2().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerD().ObtenerVariable3());
    fprintf(archivoRes,"%i",poli.ObtenerD().ObtenerExponenteVariable3().ObtenerNumerador());
    fprintf(archivoRes,"   ");
    fprintf(archivoRes,"%i",poli.ObtenerE().ObtenerSigno());
    fprintf(archivoRes,"   ");
    fprintf(archivoRes,"%i",poli.ObtenerE().ObtenerNumero().ObtenerNumerador());
    fprintf(archivoRes,"/");
    fprintf(archivoRes,"%i",poli.ObtenerE().ObtenerNumero().ObtenerDenominador());
    fprintf(archivoRes,"%c",poli.ObtenerE().ObtenerVariable1());
    fprintf(archivoRes,"%i",poli.ObtenerE().ObtenerExponenteVariable1().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerE().ObtenerVariable2());
    fprintf(archivoRes,"%i",poli.ObtenerE().ObtenerExponenteVariable2().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerE().ObtenerVariable3());
    fprintf(archivoRes,"%i",poli.ObtenerE().ObtenerExponenteVariable3().ObtenerNumerador());
    fprintf(archivoRes,"\n");
    /*resultado<<poli.ObtenerA().ObtenerNumero().ObtenerNumerador();
       resultado+=poli.ObtenerA().ObtenerVariable();
       resultado<<poli.ObtenerExponentePolinomio().ObtenerNumerador();*/
    fclose(archivoRes);
    return resultado;
}
wxString interprete::CompAString(NumeroComp poli)
{
    wxString resultado;
    archivoRes=fopen("TempInterpreteRes.hs","w");
    fprintf(archivoRes,"%i",poli.ObtenerSigno());
    fprintf(archivoRes,"   ");
    fprintf(archivoRes,"%i",poli.ObtenerNumerador());
    fprintf(archivoRes,"/");
    fprintf(archivoRes,"%i",poli.ObtenerDenominador());
    fprintf(archivoRes,"%c",poli.ObtenerVariable1());
    fprintf(archivoRes,"%i",poli.ObtenerExponenteVariable1().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerVariable2());
    fprintf(archivoRes,"%i",poli.ObtenerExponenteVariable2().ObtenerNumerador());
    fprintf(archivoRes,"%c",poli.ObtenerVariable3());
    fprintf(archivoRes,"%i",poli.ObtenerExponenteVariable3().ObtenerNumerador());
    fprintf(archivoRes,"\n");
    fclose(archivoRes);
    return resultado;
}
