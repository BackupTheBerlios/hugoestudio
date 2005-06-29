#include "hugopanel.h"
//#include "interprete.h"
#ifndef _HUGOESTUDIO_H_
#define _HUGOESTUDIO_H_

/**
 * @short Application Main Window
 * @author Hugo Armando <hugo@localhost.localdomain>
 * @version 0.1
 */

class HugoEstudioapp : public wxApp
{
public:
    virtual bool OnInit();
};

class HugoEstudioFrame : public wxFrame
{
public:
    HugoEstudioFrame( const wxString& title, const wxPoint& posi, const wxSize& size );
    void OnQuit( wxCommandEvent& event );
    void OnAbout( wxCommandEvent& event );
    
    HugoTab *ObtenerPanel() const { return m_panel; }
        
    void OnSuma( wxCommandEvent& event );
    void OnResta( wxCommandEvent& event );
    void OnMultiplicacion( wxCommandEvent& event );
    void OnDivision( wxCommandEvent& event );
    void OnPotencia( wxCommandEvent& event );
    void OnRaiz( wxCommandEvent& event );
    void OnLogaritmo( wxCommandEvent& event );
    void OnLogaritmoN( wxCommandEvent& event );
    void OnExponencial(wxCommandEvent& event );
    void OnDerivada( wxCommandEvent& event );
    void OnIntegral( wxCommandEvent& event );
    
    void OnCopiar( wxCommandEvent& event );
    void OnPegar( wxCommandEvent& event );
    void OnCortar( wxCommandEvent& event );
    void OnSelTodo( wxCommandEvent& event );
private:
    HugoTab *m_panel;
protected:
    DECLARE_EVENT_TABLE()
};

enum
{
    Menu_File_Quit = 100,
    Menu_File_About,
    Menu_Edicion_copiar,
    Menu_Edicion_cortar,
    Menu_Edicion_pegar,
    Menu_Edicion_seltodo,
    Menu_Matematica_1,
    Menu_Matematica_suma,
    Menu_Matematica_resta,
    Menu_Matematica_multiplicacion,
    Menu_Matematica_division,
    Menu_Matematica_potencia,
    Menu_Matematica_raiz,
    Menu_Matematica_logaritmo,
    Menu_Matematica_logaritmoN,
    Menu_Matematica_exponencial,
    Menu_Matematica_derivada,
    Menu_Matematica_integral,
    Menu_Fisica_1,
    Menu_Quimica_1
};
#endif // _HUGOESTUDIO_H_

