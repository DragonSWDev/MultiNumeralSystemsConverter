#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "com.github.BlackDragonDv.multinumeralsystemsconverter");
    MainWindow window;

    return app->run(window);
}