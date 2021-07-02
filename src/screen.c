#include <cairo/cairo.h>
#include <gtk-3.0/gtk/gtk.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "screen.h"

#define SCALE 4

enum Color {
  WHITE,
  L_GRAY,
  D_GRAY,
  BLACK
};

static void do_drawing(cairo_t* cr, gpointer screen);

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
  do_drawing(cr, user_data);

  return TRUE;
}

static void draw_pixel(cairo_t *cr, int x, int y, enum Color color) {
  switch (color) {
  case BLACK:
    cairo_set_source_rgb(cr, 0, 0, 0); // black
    break;
  case D_GRAY:
    cairo_set_source_rgb(cr, 0.25, 0.25, 0.25); // dark gray
    break;
  case L_GRAY:
    cairo_set_source_rgb(cr, 0.5, 0.5, 0.5); // light gray
    break;
  case WHITE:
    cairo_set_source_rgb(cr, 1, 1, 1); // white
    break;
  default:
    return;
  }

  cairo_rectangle(cr, x, y, SCALE, SCALE);
  cairo_stroke(cr);    
}

static void do_drawing(cairo_t *cr, gpointer screen) {
  Screen *s = (Screen*) screen;
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_set_line_width(cr, SCALE);

  for (int i = 0; i < SCREEN_HEIGHT; i++) {
    for (int j = 0; j < SCREEN_WIDTH; j++) {
      draw_pixel(cr, (LEFT_MARGIN + j) * SCALE, (TOP_MARGIN + i) * SCALE, s->data[i][j]);
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
  gtk_window_set_default_size(GTK_WINDOW(screen->window.wind), WINDOW_WIDTH * SCALE, WINDOW_HEIGHT * SCALE); 
  gtk_window_set_title(GTK_WINDOW(screen->window.wind), "GB Emulator");
}

void show_screen(Screen *screen) {
  gtk_widget_show_all(screen->window.wind);
  gtk_main();
}

void draw_screen(Screen *screen) {
  gtk_widget_queue_draw(screen->window.wind);
}