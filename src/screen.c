#include <cairo/cairo.h>
#include <gtk-3.0/gtk/gtk.h>
#include <stdlib.h>
#include <stdint.h>

#include "screen.h"

#define LEFT_MARGIN 10
#define TOP_MARGIN 10
#define RIGHT_MARGIN 10
#define BOTTOM_MARGIN 10
#define SCREEN_HEIGHT 144
#define SCREEN_WIDTH 160
#define WINDOW_HEIGHT SCREEN_HEIGHT + TOP_MARGIN + BOTTOM_MARGIN
#define WINDOW_WIDTH SCREEN_WIDTH + LEFT_MARGIN + RIGHT_MARGIN

static void do_drawing(cairo_t* cr, gpointer screen);

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
  do_drawing(cr, user_data);

  return FALSE;
}

static void draw_pixel(cairo_t *cr, int x, int y, int color) {
  switch (color) {
  case 0:
    cairo_set_source_rgb(cr, 0, 0, 0); // black
    break;
  case 1:
    cairo_set_source_rgb(cr, 0.5, 0.5, 0.5); // grey
    break;
  case 2:
    cairo_set_source_rgb(cr, 1, 1, 1); // white
    break;
  case 3:
    return;
  default:
    break;
  }
  cairo_move_to(cr, x, y);
  cairo_line_to(cr, x + 1, y);
  cairo_stroke(cr);    
}

static void do_drawing(cairo_t *cr, gpointer screen) {
  screen = (Screen*) screen;
  Screen *s = (Screen*) screen;
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_set_line_width(cr, 2);

  for (int i = 0; i < SCREEN_HEIGHT; i++) {
    for (int j = 0; j < SCREEN_WIDTH; j++) {
      draw_pixel(cr, LEFT_MARGIN + j, TOP_MARGIN + i, s->data[i][j]);
    }
  }
}

void init_screen(Screen *screen, uint8_t **buffer) {
  gtk_init(0, NULL);

  screen->data = buffer;

  screen->window.wind = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  screen->window.darea = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(screen->window.wind), screen->window.darea);
 
  gtk_widget_add_events(screen->window.wind, GDK_BUTTON_PRESS_MASK);

  g_signal_connect(G_OBJECT(screen->window.darea), "draw", 
      G_CALLBACK(on_draw_event), screen); 
  g_signal_connect(screen->window.wind, "destroy",
      G_CALLBACK(gtk_main_quit), NULL);  
 
  gtk_window_set_position(GTK_WINDOW(screen->window.wind), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(screen->window.wind), WINDOW_HEIGHT, WINDOW_WIDTH); 
  gtk_window_set_title(GTK_WINDOW(screen->window.wind), "GB Emulator");
}

void show_screen(Screen *screen) {
  gtk_widget_show_all(screen->window.wind);
  gtk_main();
}

void draw_screen(Screen *screen) {
  gtk_widget_queue_draw(screen->window.wind);
}