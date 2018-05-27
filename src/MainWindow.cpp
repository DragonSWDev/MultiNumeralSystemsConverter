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
    windowGrid->attach(*convertButton, 0, 2, 1, 1);

    //Show all widgets
    show_all();
}