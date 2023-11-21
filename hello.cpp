// g++ -o hello hello.cpp `pkg-config --cflags --libs gtk+-3.0`
#include <gtk/gtk.h>

static void tray_icon_on_click(GtkStatusIcon *status_icon, gpointer user_data)
{
    g_print("You clicked the tray icon!\n");
}

static GtkStatusIcon *create_tray_icon()
{
    GtkStatusIcon *tray_icon;

    tray_icon = gtk_status_icon_new();
    g_signal_connect(G_OBJECT(tray_icon), "activate", G_CALLBACK(tray_icon_on_click), NULL);
    gtk_status_icon_set_from_file(tray_icon, "icon.png"); // 你需要一个icon.png文件
    gtk_status_icon_set_tooltip_text(tray_icon, "Hello, GTK Tray!");
    gtk_status_icon_set_visible(tray_icon, TRUE);

    return tray_icon;
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *label;
    GtkStatusIcon *tray_icon;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello, GTK!");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    label = gtk_label_new("Hello, world!");
    gtk_container_add(GTK_CONTAINER(window), label);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    tray_icon = create_tray_icon();

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