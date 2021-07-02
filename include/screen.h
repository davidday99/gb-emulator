#ifndef
#define SCREEN_H

#include <gtk-3.0/gtk/gtk.h>
#include <stdint.h>

#define LEFT_MARGIN 10
#define TOP_MARGIN 10
#define RIGHT_MARGIN 10
#define BOTTOM_MARGIN 10
#define SCREEN_HEIGHT 144
#define SCREEN_WIDTH 160
#define WINDOW_HEIGHT SCREEN_HEIGHT + TOP_MARGIN + BOTTOM_MARGIN
#define WINDOW_WIDTH SCREEN_WIDTH + LEFT_MARGIN + RIGHT_MARGIN

typedef struct Window {
  GtkWidget *wind;
  GtkWidget *darea;
} Window;

typedef struct Screen {
  Window window;
  uint8_t **data;
  const int *line;
} Screen;

void init_screen(Screen *screen, uint8_t **buffer);
void show_screen(Screen *screen);
void draw_line(Screen *screen);
void draw_screen(Screen *screen);

#endif /* SCREEN_H */