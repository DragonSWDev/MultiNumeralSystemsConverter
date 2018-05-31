#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <gtkmm.h>

#include "NumeralConverter.hpp"

class MainWindow : public Gtk::Window
{
    protected:
        Gtk::HBox *headerBox;
        Gtk::Grid *windowGrid;
        Gtk::HeaderBar *headerBar;
        Gtk::ComboBoxText *inputSystem;
        Gtk::ComboBoxText *outputSystem;
        Gtk::Label *headerLabel;
        Gtk::Entry *inputEntry;
        Gtk::Entry *outputEntry;
        Gtk::Button *convertButton;
        Gtk::Alignment *headerAlign;

        void convertButtonClicked();

    private:
        void buildAppUI();

    public:
        MainWindow();
        virtual ~MainWindow();
};

#endif
