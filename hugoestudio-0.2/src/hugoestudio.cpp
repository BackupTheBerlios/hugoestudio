#include "hugoestudio.h"
#include "traduccion.h"
#include "huestudioicon.xpm"

BEGIN_EVENT_TABLE( HugoEstudioFrame, wxFrame )
EVT_MENU( Menu_File_Quit, HugoEstudioFrame::OnQuit )
EVT_MENU( Menu_File_About, HugoEstudioFrame::OnAbout )
EVT_MENU( Menu_Edicion_copiar,HugoEstudioFrame::OnCopiar)
EVT_MENU( Menu_Edicion_cortar,HugoEstudioFrame::OnCortar)
EVT_MENU( Menu_Edicion_pegar,HugoEstudioFrame::OnPegar)
EVT_MENU( Menu_Edicion_seltodo,HugoEstudioFrame::OnSelTodo)
EVT_MENU( Menu_Matematica_suma, HugoEstudioFrame::OnSuma )
EVT_MENU( Menu_Matematica_resta, HugoEstudioFrame::OnResta )
EVT_MENU( Menu_Matematica_multiplicacion, HugoEstudioFrame::OnMultiplicacion )
EVT_MENU( Menu_Matematica_division, HugoEstudioFrame::OnDivision )
EVT_MENU( Menu_Matematica_potencia, HugoEstudioFrame::OnPotencia )
EVT_MENU( Menu_Matematica_raiz, HugoEstudioFrame::OnRaiz )
EVT_MENU( Menu_Matematica_logaritmo, HugoEstudioFrame::OnLogaritmo )
EVT_MENU( Menu_Matematica_logaritmoN, HugoEstudioFrame::OnLogaritmoN )
EVT_MENU( Menu_Matematica_exponencial, HugoEstudioFrame::OnExponencial)
EVT_MENU( Menu_Matematica_derivada, HugoEstudioFrame::OnDerivada )
EVT_MENU( Menu_Matematica_integral, HugoEstudioFrame::OnIntegral )
EVT_MENU( Menu_Fisica_UniRec, HugoEstudioFrame::OnMovRec )
EVT_MENU( Menu_Fisica_UniAce, HugoEstudioFrame::OnMovAce )
EVT_MENU( Menu_Fisica_Parab, HugoEstudioFrame::OnParab )
EVT_MENU( Menu_Quimica_Tempe, HugoEstudioFrame::OnTempe )
EVT_MENU( Menu_Quimica_Mol, HugoEstudioFrame::OnMol )
EVT_MENU( Menu_Quimica_Vol, HugoEstudioFrame::OnVol )
END_EVENT_TABLE()

IMPLEMENT_APP(HugoEstudioapp)
FILE *archivo=NULL;
FILE *archivo2=NULL;
FILE *lang=NULL;
bool HugoEstudioapp::OnInit()
{
    wxInitAllImageHandlers();
    wxBitmap bitmap;
    if (bitmap.LoadFile("splash16.png", wxBITMAP_TYPE_PNG))
    {
        wxSplashScreen* splash = new wxSplashScreen(bitmap,
                                 wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
                                 6000, NULL, -1, wxDefaultPosition, wxDefaultSize,
                                 wxSIMPLE_BORDER|wxSTAY_ON_TOP);
    }
    wxYield();
       
    archivo=fopen("temp.hs","a+t");
    archivo2=fopen("TempInterpreteRes.hs","w");
    //lang=fopen("lang.len","rt")
    lenguajea();
    fclose(archivo2);
    wxPoint point=wxPoint(0,0);
    wxSize size=wxSize(640,480);
    HugoEstudioFrame *frame = new HugoEstudioFrame(wxT("HugoEstudio"), wxPoint(0,0), wxSize(1024,700) );
    frame->Show(TRUE);
    SetTopWindow(frame);
    return TRUE;
}

HugoEstudioFrame::HugoEstudioFrame( const wxString& title, const wxPoint& posi, const wxSize& size )
        : wxFrame((wxFrame *)NULL, -1, title, posi, size)
{
    SetIcon(wxIcon(huestudioicon_xpm));
 
    wxMenu *menuArchivo = new wxMenu;
    menuArchivo->AppendSeparator();
    menuArchivo->Append( Menu_File_Quit, wxT( L_Archivo_Salir ) );
    /////////////////
    wxMenu *menuEdicion=new wxMenu;
    menuEdicion->Append(Menu_Edicion_copiar,wxT(L_Edicion_Copiar));
    menuEdicion->Append(Menu_Edicion_cortar,wxT(L_Edicion_Cortar));
    menuEdicion->Append(Menu_Edicion_pegar,wxT(L_Edicion_Pegar));
    menuEdicion->AppendSeparator();
    menuEdicion->Append(Menu_Edicion_seltodo,wxT(L_Edicion_SelTodo));
    ////////////////
    wxMenu *menuMatematica=new wxMenu;
    menuMatematica->Append(Menu_Matematica_suma,wxT(L_MenuMatematica_Suma));
    menuMatematica->Append(Menu_Matematica_resta,wxT(L_MenuMatematica_Resta));
    menuMatematica->Append(Menu_Matematica_multiplicacion,wxT(L_MenuMatematica_Multiplicacion));
    menuMatematica->Append(Menu_Matematica_division,wxT(L_MenuMatematica_Division));
    menuMatematica->AppendSeparator();
    menuMatematica->Append(Menu_Matematica_potencia,wxT(L_MenuMatematica_Potencia));
    menuMatematica->Append(Menu_Matematica_raiz,wxT(L_MenuMatematica_Raiz));
    menuMatematica->Append(Menu_Matematica_logaritmo,wxT(L_MenuMatematica_Log));
    menuMatematica->Append(Menu_Matematica_logaritmoN,wxT(L_MenuMatematica_Ln));
    menuMatematica->Append(Menu_Matematica_exponencial,wxT(L_MenuMatematica_Exponencial));
    menuMatematica->AppendSeparator();
    menuMatematica->Append(Menu_Matematica_derivada,wxT(L_MenuMatematica_Derivada));
    menuMatematica->Append(Menu_Matematica_integral,wxT(L_MenuMatematica_Integral));
    //////////////////
    wxMenu *menuFisica=new wxMenu;
    menuFisica->Append(Menu_Fisica_UniRec,wxT(L_MenuFisica_MUR));
    menuFisica->Append(Menu_Fisica_UniAce,wxT(L_MenuFisica_MUA));
    menuFisica->Append(Menu_Fisica_Parab,wxT(L_MenuFisica_Parab));
    //////////////////
    wxMenu *menuQuimica=new wxMenu;
    menuQuimica->Append(Menu_Quimica_Tempe,wxT(L_MenuQuimica_Tempe));
    menuQuimica->Append(Menu_Quimica_Mol,wxT(L_MenuQuimica_Mol));
    menuQuimica->Append(Menu_Quimica_Vol,wxT(L_MenuQuimica_Vol));
    //////////////////
    wxMenu *menuAyuda=new wxMenu;
    menuAyuda->Append(Menu_File_About,wxT(L_Ayuda_Ace));
    //////////////////
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuArchivo, wxT( L_Archivo ) );
    menuBar->Append(menuEdicion,wxT(L_Edicion));
    menuBar->Append(menuMatematica,wxT(L_MenuMatematica));
    menuBar->Append(menuFisica,wxT(L_MenuFisica));
    menuBar->Append(menuQuimica,wxT(L_MenuQuimica));
    menuBar->Append(menuAyuda,wxT(L_Ayuda));
    
    m_panel = new HugoTab( this, 10, 10, 300, 100 ); 
    
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText( wxT( "Bienvenido a HugoEstudio!" ) );
}
////////////////////////////////////
void HugoEstudioFrame::OnQuit( wxCommandEvent& WXUNUSED( event ) )
{
    fclose(archivo);    
    Close(TRUE);
}
/////////////////////////////////
void HugoEstudioFrame::OnAbout( wxCommandEvent& WXUNUSED( event ) )
{
    wxMessageBox( wxT( "HugoEstudio 0.1\ncopyright 2005 Hugo\nliberado bajo GNU general public license" ),
                  wxT( "Acerca de HugoEstudio" ), wxOK | wxICON_INFORMATION, this );
}
/////////////////////////////////
void HugoEstudioFrame::OnSuma( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("{?+?\n");
}
void HugoEstudioFrame::OnResta( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("{?-?\n");
}
void HugoEstudioFrame::OnMultiplicacion( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("{?*?\n");
}
void HugoEstudioFrame::OnDivision( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("{?/?\n");
}
void HugoEstudioFrame::OnPotencia( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("expon(base,exponente)\n");
}
void HugoEstudioFrame::OnRaiz( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("raiz(en,de)\n");
}
void HugoEstudioFrame::OnLogaritmo( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("log(base,de)\n");
}
void HugoEstudioFrame::OnLogaritmoN( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("ln(de)\n");
}
void HugoEstudioFrame::OnExponencial(wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("e(funcion)\n");
}
void HugoEstudioFrame::OnDerivada( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("derivada(funcion)\n");
}
void HugoEstudioFrame::OnIntegral( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("integral(a,b){funcion}\n");
}

void HugoEstudioFrame::OnCopiar( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->Copy();
}
void HugoEstudioFrame::OnCortar( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->Cut();
}
void HugoEstudioFrame::OnPegar( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->Paste();
}
void HugoEstudioFrame::OnSelTodo( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->SetSelection(0,m_panel->mate_text->GetLastPosition());
}
//////////////////////////
void HugoEstudioFrame::OnTempe( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->qui_text->WriteText("{v*t");
}
void HugoEstudioFrame::OnMol( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->qui_text->WriteText("");
}
void HugoEstudioFrame::OnVol( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->qui_text->WriteText("");
}
///////////////////////////
void HugoEstudioFrame::OnMovRec( wxCommandEvent& WXUNUSED( event ) )
{}
void HugoEstudioFrame::OnMovAce( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->fis_text->WriteText("{raiz(2,2a*d)");
}
void HugoEstudioFrame::OnParab( wxCommandEvent& WXUNUSED( event ) )
{}
