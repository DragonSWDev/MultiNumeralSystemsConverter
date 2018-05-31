#include "MainWindow.hpp"

MainWindow::MainWindow()
{
    set_default_size(300, 100);
    set_resizable(false);

    buildAppUI();
}

MainWindow::~MainWindow()
{
    //Clean all widgets
    delete inputSystem;
    delete outputSystem;
    delete headerLabel;
    delete headerBox;
    delete headerBar;
    delete convertButton;
    delete windowGrid;
    delete inputEntry;
    delete outputEntry;
    delete headerAlign;
}

void MainWindow::buildAppUI()
{
    //Input numeral system Combo Box
    inputSystem = new Gtk::ComboBoxText();
    inputSystem->append("BIN");
    inputSystem->append("OCT");
    inputSystem->append("DEC");
    inputSystem->append("HEX");
    inputSystem->set_active_text("BIN");

    //Target numeral system Combo Box
    outputSystem = new Gtk::ComboBoxText();
    outputSystem->append("BIN");
    outputSystem->append("OCT");
    outputSystem->append("DEC");
    outputSystem->append("HEX");
    outputSystem->set_active_text("DEC");

    //"to" label
    headerLabel = new Gtk::Label("to");

    //Set box container and add combo boxes to it
    headerBox = new Gtk::HBox();
    headerBox->set_spacing(15);
    headerBox->pack_start(*inputSystem);
    headerBox->pack_start(*headerLabel);
    headerBox->pack_end(*outputSystem);

    //Set GTK header bar and add box to it
    headerBar = new Gtk::HeaderBar();
    headerBar->set_show_close_button(true);
    headerBar->set_custom_title(*headerBox);
    set_titlebar(*headerBar);

    //Add alignment to header bar to ensure it's height
    headerAlign = new Gtk::Alignment();
    headerAlign->set_size_request(2, 40);
    headerBar->pack_start(*headerAlign);

    //Set window content grid
    windowGrid = new Gtk::Grid();
    windowGrid->set_row_spacing(5);
    windowGrid->set_column_spacing(5);
    add(*windowGrid);

    //Set input entry (textbox)
    inputEntry = new Gtk::Entry();
    windowGrid->attach(*inputEntry, 0, 0, 1, 1);

    //Set output entry (read only textbox)
    outputEntry = new Gtk::Entry();
    outputEntry->set_can_focus(false);
    outputEntry->set_editable(false);
    windowGrid->attach(*outputEntry, 0, 1, 1, 1);

    //Set convert button
    convertButton = new Gtk::Button("Convert");
    convertButton->set_hexpand(true);
    convertButton->set_vexpand(true);
    convertButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::convertButtonClicked));
    windowGrid->attach(*convertButton, 0, 2, 1, 1);

    //Show all widgets
    show_all();
}

void MainWindow::convertButtonClicked()
{
    std::string input = inputEntry->get_text();
    NumeralConverter::NumSystem inputSys, targetSys;

    //Get input system
    if(inputSystem->get_active_text() == "BIN")
        inputSys = NumeralConverter::NumSystem::BIN;

    if(inputSystem->get_active_text() == "OCT")
        inputSys = NumeralConverter::NumSystem::OCT;

    if(inputSystem->get_active_text() == "DEC")
        inputSys = NumeralConverter::NumSystem::DEC;

    if(inputSystem->get_active_text() == "HEX")
        inputSys = NumeralConverter::NumSystem::HEX;

    //Get output system
    if(outputSystem->get_active_text() == "BIN")
        targetSys = NumeralConverter::NumSystem::BIN;

    if(outputSystem->get_active_text() == "OCT")
        targetSys = NumeralConverter::NumSystem::OCT;

    if(outputSystem->get_active_text() == "DEC")
        targetSys = NumeralConverter::NumSystem::DEC;

    if(outputSystem->get_active_text() == "HEX")
        targetSys = NumeralConverter::NumSystem::HEX;

    NumeralConverter converter(inputSys, input);
    
    if(!converter.valueGood())
    {
        outputEntry->set_text("Input error!");
        return;
    }

    outputEntry->set_text(converter.ConvertValue(targetSys));
}
