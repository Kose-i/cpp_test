#include <gtk/gtk.h>

int main(int argc, char** argv)
{
  GtkWidget *window;
  
  gtk_init(&argc,&argv);
  
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  
  gtk_widget_set_size_request(window, 300, 200);
  {
    //子ウィジェットにbuttonを指定
    GtkWidget *button;
    
    //ボタンのラベル名を指定して作成
    button = gtk_button_new_with_label("Button");
    
    //ボタンをウィンドウに配置
    gtk_container_add(GTK_CONTAINER(window), button);
  }
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  
  //ウィンドウ上の全てのウィジェットを表示
  gtk_widget_show_all(window);
  
  gtk_main();
  
  return 0;
}
