#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <gtkmm.h>

class MainWindow : public Gtk::Window
{
    private:
        void buildAppUI();

    public:
        MainWindow();
        virtual ~MainWindow();
};

#endif