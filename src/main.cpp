// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <mmsyscom.h>

class MyApp: public wxApp{
public:
    virtual bool OnInit();
};

class MyFrame: public wxFrame{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    wxButton *HelloWorld;

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};
enum{
    ID_Hello = 1
    
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    //EVT_MENU(wxID_ABOUT, MyFrame::OnButton)
    
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit(){
    MyFrame *frame = new MyFrame( "Calculator", wxPoint(50, 50), wxSize(600, 600));
    frame->Show(true);
    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size): wxFrame(NULL, wxID_ANY, title, pos, size){
    std::vector<wxButton*> nums (9);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            nums[i] = new wxButton(this, wxID_ANY, std::to_string(j + i*3 + 1), wxPoint(30 + j*110, 185 + i * 110), wxSize(100, 100));
        }
        
    }
    wxButton* mulButton = new wxButton(this, wxID_ANY, "*", wxPoint(300, 185), wxSize(100, 100));
    wxButton* divButton = new wxButton(this, wxID_ANY, "/", wxPoint(300, 100), wxSize(100, 100));
    wxButton* subButton = new wxButton(this, wxID_ANY, "-", wxPoint(300, 300), wxSize(100, 100));
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello... \t Ctrl-H", "Help string shown RaAHHHHHHHHHHHHHHHHHHHH");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    wxMenu *menuTest = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );
}
void MyFrame::OnExit(wxCommandEvent& event){
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event){
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event){
    wxLogMessage("Hello world from wxWidgets!");
}
//void MyFrame::OnButtonlClick(wxCommandEvent& event){

//}
