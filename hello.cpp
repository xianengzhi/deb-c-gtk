// g++ -o hello hello.cpp `pkg-config --cflags --libs gtk+-3.0`
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *label;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello, GTK!");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    label = gtk_label_new("Hello, world!");
    gtk_container_add(GTK_CONTAINER(window), label);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

// // g++ -o myapp myapp.cpp
// #include <iostream>
// #include <gtk/gtk.h>

// int main()
// {
//     std::cout << "HELlo,world!\n";
//     return 0;
// }