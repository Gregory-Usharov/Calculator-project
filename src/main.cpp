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
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit(){
    MyFrame *frame = new MyFrame( "Calculator", wxPoint(50, 50), wxSize(600, 600));
    frame->Show(true);
    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size): wxFrame(NULL, wxID_ANY, title, pos, size){
    std::vector<wxButton*> nums (10);
    wxButton* test = new wxButton(this, wxID_ANY, std::to_string(9), wxPoint(100, 50), wxSize(100, 35));
    for(int i = 0; i < 10; i++){
        nums[i] = new wxButton(this, wxID_ANY, std::to_string(i), wxPoint(150 + i*10, 50), wxSize(100, 35));
    }
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
