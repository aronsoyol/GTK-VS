// Win32Project4.cpp : Defines the entry point for the application.
//
#include <gtk/gtk.h> 
//#include <windows.h>

// C RunTime Header Files
//#include <stdlib.h>
//#include <malloc.h>
//#include <memory.h>
//#include <tchar.h>
//#include <string>

//int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPTSTR    lpCmdLine,
//	_In_ int       nCmdShow)
int main()
{

	gtk_init(0, 0);

	/* メインウィンドウの作成 */
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 300, 200);
	GtkWidget *view;
	GtkTextBuffer *buffer;
	PangoFontDescription *font_desc;
	view = gtk_text_view_new();

	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));

	
	font_desc = pango_font_description_from_string("Mongolian baiti");
	gtk_text_buffer_set_text(buffer, "ᠠᠰᠳᠠᠰᠳᠹ", -1);
	gtk_widget_modify_font(view, font_desc);
	pango_font_description_free(font_desc);
	// 「ウィンドウを閉じる」コールバック 
	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_container_add(GTK_CONTAINER(window), view);
	/* ウィジェットの表示 */
	gtk_widget_show_all(window);
	
	/* コールバックの受付開始 */
	gtk_main();
}
