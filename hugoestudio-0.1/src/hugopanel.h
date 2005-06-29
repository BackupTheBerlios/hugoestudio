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
#ifndef _HUGOPANEL_H_
#define _HUGOPANEL_H_
#include "includes.h"
class HugoTab:public wxPanel
{
public:
    HugoTab(wxFrame *frame, int x, int y, int w, int h);
    
    void OnSize( wxSizeEvent& event );
    void OnCalcularM(wxCommandEvent& event);
    void OnLimpiar(wxCommandEvent& event);
    wxString ObtenerCadena();
    //Pestañas
    wxNotebook *m_notebook;
    //Cajas de texto
    wxTextCtrl *mate_text;
    wxTextCtrl *mate_res;
    wxTextCtrl *fis_text;
    wxTextCtrl *qui_text;
    wxTextCtrl *saberjdebug;
    //Botones
    wxButton *hacer_calM;    
    wxButton *hacer_calF;
    wxButton *hacer_calQ;
    wxButton *Limp_saber;
    //Posisiciones
    wxPoint posiMatText;
    wxPoint posiMatRes;
    wxPoint posiBotCal;
    wxPoint posiLabel;
    //Tamaños
    wxSize tamMatText;
    wxSize tamMatRes;
    wxSize tamBot;
    wxSize tamLabel;
    wxSize tamSaber;
    //Texto estatico
    wxStaticText *label;
protected:
    DECLARE_EVENT_TABLE()
};
//---------------------------------------------------------------------- 
// MyPanel 
//---------------------------------------------------------------------- 
 
enum
{
    ID_NOTEBOOK=200,
    ID_BUTTON_M,
    ID_BUTTON_F,
    ID_BUTTON_Q,
    ID_BUTTON_L
};

#endif // _HUGOPANEL_H_
