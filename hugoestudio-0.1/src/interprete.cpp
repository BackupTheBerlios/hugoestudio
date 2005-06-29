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
//Variables globales
FILE *archivoDatos=NULL;
uli factores;
//usi i,j=0;
char factores2[10];
polinomio pol,pol2;
NumeroReal rea,/**/real,real2;
NumeroComp com,/**/comp,comp2;
operaciones intermediario;
bool interprete::interprete1(wxString linea)
{
    bool si=false;
    int tempo=0,tempo2=0;
    polinomio respuestaAn;
    archivoDatos=fopen("Temp.hs","a+t");
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
	polinomio temp1[3],temp2;
	usi i=0,nums=0, nums2=0, nums3=0;
	subCadena=linea;
	nums=ObtenerNumDeOperacion(subCadena);
	nums2=ObtenerNumCharsOperacion(subCadena);
	for(i=0;i<nums;i++)
	{
	    nums3=ObtenerNumCharsOperacion(subCadena,nums,i);
	    temp1[i]=StringAPoli(subCadena);
	}
	si=true;
    }
    subCadena=linea.Mid(0,1);
    if(subCadena=="e")
    {
        factores=EXPONENCI;
        subCadena2=linea.Mid(1,linea.length()-2);
        wxString exponTemp=ObtenerPolinomioParen(subCadena2);
        if(exponTemp=="error")
        {
            si=false;
        }
        else
        {
            pol=StringAPoli(exponTemp);
            si=true;
        }
    }
    subCadena=linea.Mid(0,2);
    if(subCadena=="ln")
    {
        factores=LOGANATU;
        subCadena2=linea.Mid(2,linea.length());
        wxString exponTemp=ObtenerPolinomioParen(subCadena2);
        if(exponTemp=="error")
        {
            si=false;
        }
        else
        {
            pol=StringAPoli(exponTemp);
            si=true;
        }
    }
    subCadena=linea.Mid(0,3);
    if(subCadena=="log")
    {
        factores=LOGARITMO;
        subCadena2=linea.Mid(3,linea.length());
        usi exponTemp=ParenNumCarac(subCadena2);
        if(exponTemp==0)
        {
            si=false;
            return si;
        }
        wxString exponTemp2=ObtenerPolinomioAntesComa(subCadena2);
        if(exponTemp2=="error")
        {
            si=false;
        }
        wxString exponTemp3=ObtenerPolinomioDesComa(subCadena2,exponTemp);
        if(exponTemp3=="error")
        {
            si=false;
        }
        else
        {
            pol=StringAPoli(exponTemp2);
            pol2=StringAPoli(exponTemp3);
            comp=PoliAComp(pol);
            comp2=PoliAComp(pol2);
            real=CompAReal(comp);
            real2=CompAReal(comp2);
            tempo=rea.NumRealAInt(real);
            tempo2=rea.NumRealAInt(real2);
            cout<<"tempo: "<<tempo<<endl;
            cout<<"tempo2: "<<tempo2<<endl;
            cout<<intermediario.log(tempo,tempo2)<<endl;
            si=true;
        }
        //si= true;
    }
    subCadena=linea.Mid(0,4);
    if(subCadena=="raiz")
    {
        factores=RAIZ;
        subCadena2=linea.Mid(4,linea.length());
        usi exponTemp=ParenNumCarac(subCadena2);
        if(exponTemp==0)
        {
            si=false;
        }
        wxString exponTemp2=ObtenerPolinomioAntesComa(subCadena2);
        if(exponTemp2=="error")
        {
            si=false;
        }
        wxString exponTemp3=ObtenerPolinomioDesComa(subCadena2,exponTemp);
        if(exponTemp3=="error")
        {
            si=false;
        }
        else
        {
            StringAPoli(exponTemp2);
            StringAPoli(exponTemp3);
            si=true;
        }
    }
    subCadena=linea.Mid(0,5);
    if(subCadena=="expon")
    {
        factores=POTENCIA;
        subCadena2=linea.Mid(5,linea.length());
        usi exponTemp=ParenNumCarac(subCadena2);
        if(exponTemp==0)
        {
            si=false;
        }
        wxString exponTemp2=ObtenerPolinomioAntesComa(subCadena2);
        if(exponTemp2=="error")
        {
            si=false;
        }
        wxString exponTemp3=ObtenerPolinomioDesComa(subCadena2,exponTemp);
        if(exponTemp3=="error")
        {
            si=false;
        }
        else
        {
            StringAPoli(exponTemp2);
            StringAPoli(exponTemp3);
            si=true;
        }
    }
    subCadena=linea.Mid(0,8);
    if(subCadena=="integral")
    {
        factores=INTEGRAL;
        //subCadena2=linea.Mid(8,linea.length());//En integral no aplica FIXME
        usi exponTemp=ParenNumCarac(subCadena2);//Numero de chars antes de ','
        if(exponTemp==0)
        {
            si=false;
        }
        wxString exponTemp2=ObtenerPolinomioAntesComa(subCadena2);//RegresaElString desde 1parentesis hasta coma
        if(exponTemp2=="error")
        {
            si=false;
        }
        wxString exponTemp3=ObtenerPolinomioDesComa(subCadena2,exponTemp);//RegresaStringDesdeComaAParentesis
        if(exponTemp3=="error")
        {
            si=false;
        }
        usi exponTemp4=ObtenerNumChars(subCadena2);//regresa el numero de chars desde inicio hasta '{'
        subCadena2=linea.Mid(ObtenerNumChars(subCadena2),linea.length());//Selec�SupuestamenteDesdeLa{
        wxString exponTemp5=ObtenerPolinomioParen(exponTemp3);
        if(exponTemp4==0||exponTemp5=="error")
        {
            si=false;
        }
        else
        {
            StringAPoli(exponTemp2);
            StringAPoli(exponTemp3);
            StringAPoli(exponTemp5);
            si=true;
        }
    }
    else if(subCadena=="derivada")
    {
        factores=DERIVADA;
        subCadena2=linea.Mid(8,linea.length());
        wxString exponTemp=ObtenerPolinomioParen(subCadena2);
        if(exponTemp=="error")
        {
            si=false;
        }
        else
        {
            StringAPoli(exponTemp);
            si=true;
        }
    }
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
    usi i=0;
    for(i=it;i<DespuesComa.length();i++)
    {
        if(DespuesComa.GetChar(i)==')')
            break;
        else
        {
            obpa=DespuesComa.Mid(1,i);
            continue;
        }
    }
    return obpa=DespuesComa.Mid(it+1,(DespuesComa.length()-1));
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
polinomio interprete::StringAPoli(wxString poli)
{
    usi i;
    int numeroT=0;
    char j[10],variables[3]={'a','a','a'},temp;
    NumeroReal resulPar;
    NumeroComp resulPar2;
    polinomio resultado;
    for(i=0;i<poli.length();i++)//Arreglar ¿cual es el problema?
    {
        temp=poli.GetChar(i);
        switch(temp)
        {
        case '0':
            j[i]='0';
            break;
        case '1':
            j[i]='1';
            break;
        case '2':
            j[i]='2';
            break;
        case '3':
            j[i]='3';
            break;
        case '4':
            j[i]='4';
            break;
        case '5':
            j[i]='5';
            break;
        case '6':
            j[i]='6';
            break;
        case '7':
            j[i]='7';
            break;
        case '8':
            j[i]='8';
            break;
        case '9':
            j[i]='9';
            break;
        case 'x':
            variables[i-i]='x';
            break;
	case 'X':
            variables[i-i]='x';
            break;
        case 'y':
            variables[i-(i-1)]='y';
            break;
	case 'Y':
            variables[i-(i-1)]='y';
            break;
        case 'z':
            variables[i-(i-2)]='z';
            break;
	case 'Z':
            variables[i-(i-2)]='z';
            break;
        default:
            break;
        }
    }
    numeroT=atoi(j);
    cout<<"Numero obtenido: "<<numeroT<<endl;    
    cout<<"Variable en x: "<<variables[0]<<endl;
    cout<<"Variable en y: "<<variables[1]<<endl;
    cout<<"Variable en z: "<<variables[2]<<endl;
    resulPar.CambiarNumerador(numeroT);
    resulPar2.CambiarNumero(resulPar);
    resulPar2.CambiarVariable(variables);
    //resultado=resulPar2;
    return resultado;
}
NumeroReal interprete::CompAReal(NumeroComp poli)
{
    NumeroReal resul;
    resul.CambiarNumerador(poli.ObtenerNumero().ObtenerNumerador());
    resul.CambiarDenominador(poli.ObtenerNumero().ObtenerDenominador());
    return resul;
}
NumeroComp interprete::PoliAComp(polinomio poli)
{
    NumeroComp resul;
    //    resul=simplificar(poli);
    resul.CambiarNumero(poli.ObtenerNumero());
    //    resul.CambiarVariable(poli.ObtenerVariable());
    resul.CambiarExponenteVariable(poli.ObtenerExponentePolinomio());
    return resul;
}
/**Polinomio interprete::StringAPoli(wxString poli)
{
    polinomio resultado;
    return resultado;
}*/
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
	/*if(LineaTemp>=1)
	{
	    NuCaracteresMenor++;
	}*/
	if(i==numeroLinea-1)
	{
	    stringTemp=string.Mid(0,NuCaracteres);
	    NuCaracteresMenor=stringTemp.Len();
	}
    }while(i<len);
    resul=string.Mid(NuCaracteresMenor,NuCaracteres);
    cout<<"Valor de NuCaracteresMenor: "<<NuCaracteresMenor<<endl;
    cout<<"Valor de NuCaracteres: "<<NuCaracteres<<endl;
    return resul;
}
usi interprete::ObtenerNumCharsOperacion(wxString parentesis)
{
    int i=0,resul=0;
    while(parentesis.GetChar(i)!='+'||parentesis.GetChar(i)!='-')
    {
	resul++;
    }
    return resul;
}
usi interprete::ObtenerNumDeOperacion(wxString parentesis)
{
    int i=0,resul=0;
    for(i=0;i<parentesis.length();i++)
    {
	if(parentesis.GetChar(i)=='+'||parentesis.GetChar(i)=='-')
	    resul++;
    }
    return resul;
}
usi interprete::ObtenerNumCharsOperacion(wxString parentesis, usi longitudMa, usi longitudMe)
{
    int i=0,resul=0,resul2=0;
    while(parentesis.GetChar(i)!='+'||parentesis.GetChar(i)!='-')
    {
	if(resul!=longitudMe)
	    resul++;
	if(resul2!=longitudMa)
	   resul2++;
    }
    return resul2-resul;
}
