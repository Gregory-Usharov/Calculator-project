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

/*class AddTextControls()
{
    //creazione font
    wxFont Expression(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT, false, "Lato");
    wxFont Main(30, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT, false, "Lato");

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    ExpText = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxNO_BORDER);
    ExpText->SetFont(Expression);
    ExpText->SetForegroundColour(wxColour(125, 125, 125));
    sizer->Add(ExpText, 1, wxEXPAND);

    MainText = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxNO_BORDER);
    MainText->SetFont(Main);
    MainText->SetForegroundColour(wxColour(55, 55, 55));
    MainText->Bind(wxEVT_TEXT, &Main::OnTextChange, this);
    sizer->Add(MainText, 2, wxEXPAND);

    MainSizer->Add(sizer, 4, wxEXPAND);
}
*/
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
            nums[i]->SetFont(
                wxFontInfo(wxSize(0, nums[i]->GetSize().y / 1.3))
                    .Family(wxFONTFAMILY_SWISS)
                    .FaceName("Lato")
                    .Bold()
            );
        }
        
    }
    wxTextCtrl* outputStr = new wxTextCtrl(this,wxID_ANY, " ",wxPoint(30, 21), wxSize(540, 150));
    outputStr->Disable();
    //wxButton* lbracButton = new wxButton(this, wxID_ANY, "(", wxPoint(300, 300), wxSize(100, 100));
    //wxButton* rbracButton = new wxButton(this, wxID_ANY, ")", wxPoint(400, 300), wxSize(100, 100));
    wxButton* mulButton = new wxButton(this, wxID_ANY, "x", wxPoint(360, 185), wxSize(100, 100));
    wxButton* divButton = new wxButton(this, wxID_ANY, "/", wxPoint(470, 185), wxSize(100, 100));
    wxButton* subButton = new wxButton(this, wxID_ANY, "-", wxPoint(470, 295), wxSize(100, 100));
    wxButton* addButton = new wxButton(this, wxID_ANY, "+", wxPoint(360, 295), wxSize(100, 100));

    
    wxButton* zerButton = new wxButton(this, wxID_ANY, "0", wxPoint(360, 405), wxSize(100, 100));
    wxButton* equButton = new wxButton(this, wxID_ANY, "=", wxPoint(470, 405), wxSize(100, 100));
    wxFont* font = new wxFont();
    //mulButton->SetFont()
    mulButton->SetFont(
        wxFontInfo(wxSize(0, mulButton->GetSize().y / 1.3))
            .Family(wxFONTFAMILY_SWISS)
            .FaceName("Lato")
            .Bold()
        );
    divButton->SetFont(
        wxFontInfo(wxSize(0, divButton->GetSize().y / 1.3))
            .Family(wxFONTFAMILY_SWISS)
            .FaceName("Lato")
            .Bold()
    );
    subButton->SetFont(
        wxFontInfo(wxSize(0, subButton->GetSize().y / 1.3))
            .Family(wxFONTFAMILY_SWISS)
            .FaceName("Lato")
            .Bold()
    );
    addButton->SetFont(
        wxFontInfo(wxSize(0, addButton->GetSize().y / 1.3))
            .Family(wxFONTFAMILY_SWISS)
            .FaceName("Lato")
            .Bold()
    );
    zerButton->SetFont(
        wxFontInfo(wxSize(0, zerButton->GetSize().y / 1.3))
            .Family(wxFONTFAMILY_SWISS)
            .FaceName("Lato")
            .Bold()
    );
    equButton->SetFont(
        wxFontInfo(wxSize(0, equButton->GetSize().y / 1.3))
            .Family(wxFONTFAMILY_SWISS)
            .FaceName("Lato")
            .Bold()
    );
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello... \t Ctrl-H", "Help string shown RaAHHHHHHHHHHHHHHHHHHHH");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    wxMenu *menuTest = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile,"&File");
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
