#include "hugoestudio.h"
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
EVT_MENU( Menu_Fisica_1, HugoEstudioFrame::OnAbout )
EVT_MENU( Menu_Quimica_1, HugoEstudioFrame::OnAbout )
END_EVENT_TABLE()

IMPLEMENT_APP(HugoEstudioapp)
FILE *archivo=NULL;
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
    menuArchivo->Append( Menu_File_Quit, wxT( "&Salir" ) );
    
    wxMenu *menuEdicion=new wxMenu;
    menuEdicion->Append(Menu_Edicion_copiar,wxT("&Copiar"));
    menuEdicion->Append(Menu_Edicion_cortar,wxT("Cortar"));
    menuEdicion->Append(Menu_Edicion_pegar,wxT("&Pegar"));
    menuEdicion->AppendSeparator();
    menuEdicion->Append(Menu_Edicion_seltodo,wxT("Seleccionar todo"));
    
    wxMenu *menuMatematica=new wxMenu;
    menuMatematica->Append(Menu_Matematica_suma,wxT("Suma"));
    menuMatematica->Append(Menu_Matematica_resta,wxT("Resta"));
    menuMatematica->Append(Menu_Matematica_multiplicacion,wxT("Multiplicacion"));
    menuMatematica->Append(Menu_Matematica_division,wxT("Division"));
    menuMatematica->AppendSeparator();
    menuMatematica->Append(Menu_Matematica_potencia,wxT("Potencia"));
    menuMatematica->Append(Menu_Matematica_raiz,wxT("Raiz"));
    menuMatematica->Append(Menu_Matematica_logaritmo,wxT("Logaritmo"));
    menuMatematica->Append(Menu_Matematica_logaritmoN,wxT("Logaritmo natural"));
    menuMatematica->Append(Menu_Matematica_exponencial,wxT("Exponencial"));
    menuMatematica->AppendSeparator();
    menuMatematica->Append(Menu_Matematica_derivada,wxT("Derivada"));
    menuMatematica->Append(Menu_Matematica_integral,wxT("Integral"));
    
    wxMenu *menuFisica=new wxMenu;
    menuFisica->Append(Menu_Fisica_1,wxT("Prueba"));
    
    wxMenu *menuQuimica=new wxMenu;
    menuQuimica->Append(Menu_Quimica_1,wxT("Prueba"));
    
    wxMenu *menuAyuda=new wxMenu;
    menuAyuda->Append(Menu_File_About,wxT("Acerca de..."));

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuArchivo, wxT( "&Archivo" ) );
    menuBar->Append(menuEdicion,wxT("&Edicion"));
    menuBar->Append(menuMatematica,wxT("&Matematica"));
    menuBar->Append(menuFisica,wxT("&Fisica"));
    menuBar->Append(menuQuimica,wxT("&Quimica"));
    menuBar->Append(menuAyuda,wxT("A&yuda"));
    
    m_panel = new HugoTab( this, 10, 10, 300, 100 ); 
    
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText( wxT( "Bienvenido a HugoEstudio!" ) );
}

void HugoEstudioFrame::OnQuit( wxCommandEvent& WXUNUSED( event ) )
{
    fclose(archivo);    
    Close(TRUE);
}

void HugoEstudioFrame::OnAbout( wxCommandEvent& WXUNUSED( event ) )
{
    wxMessageBox( wxT( "HugoEstudio 0.1\ncopyright 2005\nliberado bajo GNU general public license" ),
                  wxT( "Acerca de HugoEstudio" ), wxOK | wxICON_INFORMATION, this );
}

void HugoEstudioFrame::OnSuma( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("{?}+{?}\n");
}
void HugoEstudioFrame::OnResta( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("{?}-{?}\n");
}
void HugoEstudioFrame::OnMultiplicacion( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("{?}*{?}\n");
}
void HugoEstudioFrame::OnDivision( wxCommandEvent& WXUNUSED( event ) )
{
    m_panel->mate_text->WriteText("{?}/{?}\n");
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
