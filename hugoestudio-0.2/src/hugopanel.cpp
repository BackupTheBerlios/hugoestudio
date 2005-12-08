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
#include "hugopanel.h"
#include "interprete.h"
#include "traduccion3.h"
FILE *archivoDatos2=NULL;
BEGIN_EVENT_TABLE(HugoTab, wxPanel)
EVT_SIZE      (                         HugoTab::OnSize)
EVT_BUTTON    (ID_BUTTON_M,  HugoTab::OnCalcularM)
EVT_BUTTON    (ID_BUTTON_Q,  HugoTab::OnCalcularQ)
EVT_BUTTON    (ID_BUTTON_F,  HugoTab::OnCalcularF)
EVT_BUTTON    (ID_BUTTON_L,  HugoTab::OnLimpiar)
END_EVENT_TABLE()

HugoTab::HugoTab(wxFrame *frame, int x, int y, int w, int h):wxPanel(frame,-1,wxPoint(x,y),wxSize(w,h))
{
    frame->GetClientSize( &x, &y );
    lenguajea3();
    //Posisiciones
    posiMatText=wxPoint(0,0);
    posiMatRes=wxPoint(x/2,0);
    posiBotCal=wxPoint(x/2,550);
    posiLabel=wxPoint(x/2,y/2);
    //Tamaños
    tamMatText=wxSize(x/2,y-100);
    tamMatRes=wxSize((x/2)-15,y/3);
    tamBot=wxSize(100,30);
    tamLabel=wxSize(100,100);
    tamSaber=wxSize(x-15,y-200);
    //Inicializacion
    m_notebook = NULL;
    mate_text=NULL;
    mate_res=NULL;
    fis_text=NULL;
    fis_res=NULL;
    qui_text=NULL;
    qui_res=NULL;
    hacer_calM=NULL;
    hacer_calF=NULL;
    hacer_calQ=NULL;
    label=NULL;
    labelF=NULL;
    labelQ=NULL;
    saberjdebug=NULL;
    Limp_saber=NULL;
    m_notebook = new wxNotebook(this, ID_NOTEBOOK);
    wxPanel *panel = new wxPanel(m_notebook);
    /*******************
    *Area de matematica*
    *******************/
    panel=new wxPanel(m_notebook);
    m_notebook->AddPage(panel,L_Tab_M,FALSE,-1);
    mate_text=new wxTextCtrl(panel,-1,"",posiMatText,tamMatText,wxTE_MULTILINE);
    mate_res=new wxTextCtrl(panel,-1,"",posiMatRes,tamMatRes,wxTE_MULTILINE);
    hacer_calM=new wxButton(panel,ID_BUTTON_M,L_Calcular,posiBotCal,tamBot,wxBU_EXACTFIT,wxDefaultValidator,"");
    label=new wxStaticText(panel,-1,"",posiLabel,tamLabel,wxALIGN_CENTRE,"prueba");
    /************
    *Area fisica*
    ************/
    panel=new wxPanel(m_notebook);
    m_notebook->AddPage(panel,L_Tab_F,FALSE,-1);
    fis_text=new wxTextCtrl(panel,-1,"",posiMatText,tamMatText,wxTE_MULTILINE);
    hacer_calF=new wxButton(panel,ID_BUTTON_F,L_Calcular,posiBotCal,tamBot,wxBU_EXACTFIT,wxDefaultValidator,"");
    fis_res=new wxTextCtrl(panel,-1,"",posiMatRes,tamMatRes,wxTE_MULTILINE);
    labelF=new wxStaticText(panel,-1,"",posiLabel,tamLabel,wxALIGN_CENTRE,"prueba");
    /*************
    *Area quimica*
    *************/
    panel=new wxPanel(m_notebook);
    m_notebook->AddPage(panel,L_Tab_Q,FALSE,-1);
    qui_text=new wxTextCtrl(panel,-1,"",posiMatText,tamMatText,wxTE_MULTILINE);
    qui_res=new wxTextCtrl(panel,-1,"",posiMatRes,tamMatRes,wxTE_MULTILINE);
    hacer_calQ=new wxButton(panel,ID_BUTTON_Q,L_Calcular,posiBotCal,tamBot,wxBU_EXACTFIT,wxDefaultValidator,"");
    labelQ=new wxStaticText(panel,-1,"",posiLabel,tamLabel,wxALIGN_CENTRE,"prueba");
    //area saber
    panel=new wxPanel(m_notebook);
    m_notebook->AddPage(panel,"Tareas",FALSE,-1);
    saberjdebug=new wxTextCtrl(panel,-1,"",posiMatText,tamSaber,wxTE_MULTILINE);
    Limp_saber=new wxButton(panel,ID_BUTTON_L,L_Limpiar,posiBotCal,tamBot,wxBU_EXACTFIT,wxDefaultValidator,"");
}

void HugoTab::OnSize( wxSizeEvent& WXUNUSED(event) )
{
    int x = 0;
    int y = 0;
    GetClientSize( &x, &y );

    if (m_notebook)
    {
        m_notebook->SetSize( 2, 2, x-4, y-10);
        tamMatText=wxSize(x/2,y-100);
    }
    if(1)
    {
        tamMatText=wxSize(x/2,y-100);
    }
    //if (m_text) m_text->SetSize( 2, y*2/3+2, x-4, y/3-4 );
}

void HugoTab::OnCalcularM(wxCommandEvent& WXUNUSED(event))
{
    saberjdebug->AppendText("Haciendo calculos de matematica...\n");
    interprete a;
    wxString pruLinea,falloStringSuport;
    long noLines,i;
    bool compro=false, fallo=false;
    noLines=mate_text->GetNumberOfLines();
    for(i=0;i<noLines;i++)
    {
        saberjdebug->AppendText("Enviando datos a interprete...\n");
        if(mate_text->GetLineLength(i)==-1)
            saberjdebug->AppendText("ERROR!!!, numero de linea invalido, esto no deberia pasar");
        pruLinea=mate_text->GetLineText(i);
        //cout<<"Longitud linea: "<<pruLinea.GetData()<<endl;
        saberjdebug->AppendText(pruLinea);
        saberjdebug->AppendText("\n");
        if(pruLinea.IsEmpty()==true)
        {
            saberjdebug->AppendText("ADVERTENCIA, la linea no contiene datos\n");
            fallo=true;
            archivoDatos2=fopen("Temp.hs","a+t");
            falloStringSuport=ObtenerCadena();
            saberjdebug->AppendText("Usando soporte con archivos (plan b), ¿Esto es GTK2?\n");
            if(i<0)
            {
                saberjdebug->AppendText("Mostrando contenido de archivo:\n");
                saberjdebug->AppendText(falloStringSuport);
                saberjdebug->AppendText("\n");
            }
            if(falloStringSuport.IsEmpty()==true)
                saberjdebug->AppendText("¡Tambien esta vacio!, hay problemas aqui!\n");
            saberjdebug->AppendText("Linea obtenida de archivo\n");
            saberjdebug->AppendText(a.ObtenerLinea(falloStringSuport,i));//FIXME soloparalinea 1
            compro=a.interprete1(a.ObtenerLinea(falloStringSuport,i));
            fclose(archivoDatos2);
        }
        else if(fallo==false)
        {
            compro=a.interprete1(mate_text->GetLineText(i));
        }
        if(compro==false)
        {
            saberjdebug->AppendText("ERROR!!!, fallo en el interprete\n");
        }
        if(compro==true)
        {
            wxTextFile archivoT,archivoT2;
            if(archivoT.Open("TempDebug.hs",wxConvUTF8))
            {
                wxString temp;
                saberjdebug->AppendText("\n");
                for(usi i=0;i<archivoT.GetLineCount();i++)
                {
                    saberjdebug->AppendText(archivoT.GetLine(i));
                    saberjdebug->AppendText("\n");
                }
            }
            if(archivoT2.Open("TempInterpreteRes.hs",wxConvUTF8))
            {
                wxString temp;
                for(usi i=0;i<archivoT2.GetLineCount();i++)
                {
                    mate_res->AppendText(archivoT2.GetLine(i));
                    mate_res->AppendText("\n");
                }
            }
        }
    }
    mate_text->SetSelection(0,mate_text->GetLastPosition());
    //mate_res->AppendText(mate_text->GetStringSelection());
    label->SetLabel(ObtenerCadena());
}

void HugoTab::OnLimpiar(wxCommandEvent& WXUNUSED(event))
{
    saberjdebug->Clear();
}

wxString HugoTab::ObtenerCadena()
{
    mate_text->SetSelection(0,mate_text->GetLastPosition());
    return mate_text->GetStringSelection();
}
void HugoTab::OnCalcularF(wxCommandEvent& WXUNUSED(event))
{
    saberjdebug->AppendText("Haciendo calculos de fisica...\n");
    interprete a;
    wxString pruLinea,falloStringSuport;
    long noLines,i;
    bool compro=false, fallo=false;
    noLines=fis_text->GetNumberOfLines();
    for(i=0;i<noLines;i++)
    {
        saberjdebug->AppendText("Enviando datos a interprete...\n");
        if(mate_text->GetLineLength(i)==-1)
            saberjdebug->AppendText("ERROR!!!, numero de linea invalido, esto no deberia pasar");
        pruLinea=fis_text->GetLineText(i);
        //cout<<"Longitud linea: "<<pruLinea.GetData()<<endl;
        saberjdebug->AppendText(pruLinea);
        saberjdebug->AppendText("\n");
        if(pruLinea.IsEmpty()==true)
        {
            saberjdebug->AppendText("ADVERTENCIA, la linea no contiene datos\n");
            fallo=true;
            archivoDatos2=fopen("Temp.hs","a+t");
            falloStringSuport=ObtenerCadena();
            saberjdebug->AppendText("Usando soporte con archivos (plan b), ¿Esto es GTK2?\n");
            if(i<0)
            {
                saberjdebug->AppendText("Mostrando contenido de archivo:\n");
                saberjdebug->AppendText(falloStringSuport);
                saberjdebug->AppendText("\n");
            }
            if(falloStringSuport.IsEmpty()==true)
                saberjdebug->AppendText("¡Tambien esta vacio!, hay problemas aqui!\n");
            saberjdebug->AppendText("Linea obtenida de archivo\n");
            saberjdebug->AppendText(a.ObtenerLinea(falloStringSuport,i));//FIXME soloparalinea 1
            compro=a.interprete1(a.ObtenerLinea(falloStringSuport,i));
            fclose(archivoDatos2);
        }
        else if(fallo==false)
        {
            compro=a.interprete1(fis_text->GetLineText(i));
        }
        if(compro==false)
        {
            saberjdebug->AppendText("ERROR!!!, fallo en el interprete\n");
        }
        if(compro==true)
        {
            wxTextFile archivoT,archivoT2;
            if(archivoT.Open("TempDebug.hs",wxConvUTF8))
            {
                wxString temp;
                saberjdebug->AppendText("\n");
                for(usi i=0;i<archivoT.GetLineCount();i++)
                {
                    saberjdebug->AppendText(archivoT.GetLine(i));
                    saberjdebug->AppendText("\n");
                }
            }
            if(archivoT2.Open("TempInterpreteRes.hs",wxConvUTF8))
            {
                wxString temp;
                for(usi i=0;i<archivoT2.GetLineCount();i++)
                {
                    fis_res->AppendText(archivoT2.GetLine(i));
                    fis_res->AppendText("\n");
                }
            }
        }
    }
    fis_text->SetSelection(0,fis_text->GetLastPosition());
    //mate_res->AppendText(mate_text->GetStringSelection());
    labelF->SetLabel(ObtenerCadena());
}
void HugoTab::OnCalcularQ(wxCommandEvent& WXUNUSED(event))
{
    saberjdebug->AppendText("Haciendo calculos de quimica...\n");
    interprete a;
    wxString pruLinea,falloStringSuport;
    long noLines,i;
    bool compro=false, fallo=false;
    noLines=mate_text->GetNumberOfLines();
    for(i=0;i<noLines;i++)
    {
        saberjdebug->AppendText("Enviando datos a interprete...\n");
        if(mate_text->GetLineLength(i)==-1)
            saberjdebug->AppendText("ERROR!!!, numero de linea invalido, esto no deberia pasar");
        pruLinea=qui_text->GetLineText(i);
        //cout<<"Longitud linea: "<<pruLinea.GetData()<<endl;
        saberjdebug->AppendText(pruLinea);
        saberjdebug->AppendText("\n");
        if(pruLinea.IsEmpty()==true)
        {
            saberjdebug->AppendText("ADVERTENCIA, la linea no contiene datos\n");
            fallo=true;
            archivoDatos2=fopen("Temp.hs","a+t");
            falloStringSuport=ObtenerCadena();
            saberjdebug->AppendText("Usando soporte con archivos (plan b), ¿Esto es GTK2?\n");
            if(i<0)
            {
                saberjdebug->AppendText("Mostrando contenido de archivo:\n");
                saberjdebug->AppendText(falloStringSuport);
                saberjdebug->AppendText("\n");
            }
            if(falloStringSuport.IsEmpty()==true)
                saberjdebug->AppendText("¡Tambien esta vacio!, hay problemas aqui!\n");
            saberjdebug->AppendText("Linea obtenida de archivo\n");
            saberjdebug->AppendText(a.ObtenerLinea(falloStringSuport,i));//FIXME soloparalinea 1
            compro=a.interprete1(a.ObtenerLinea(falloStringSuport,i));
            fclose(archivoDatos2);
        }
        else if(fallo==false)
        {
            compro=a.interprete1(qui_text->GetLineText(i));
        }
        if(compro==false)
        {
            saberjdebug->AppendText("ERROR!!!, fallo en el interprete\n");
        }
        if(compro==true)
        {
            wxTextFile archivoT,archivoT2;
            if(archivoT.Open("TempDebug.hs",wxConvUTF8))
            {
                wxString temp;
                saberjdebug->AppendText("\n");
                for(usi i=0;i<archivoT.GetLineCount();i++)
                {
                    saberjdebug->AppendText(archivoT.GetLine(i));
                    saberjdebug->AppendText("\n");
                }
            }
            if(archivoT2.Open("TempInterpreteRes.hs",wxConvUTF8))
            {
                wxString temp;
                for(usi i=0;i<archivoT2.GetLineCount();i++)
                {
                    qui_res->AppendText(archivoT2.GetLine(i));
                    qui_res->AppendText("\n");
                }
            }
        }
    }
    qui_text->SetSelection(0,qui_text->GetLastPosition());
    //mate_res->AppendText(mate_text->GetStringSelection());
    labelQ->SetLabel(ObtenerCadena());
}
