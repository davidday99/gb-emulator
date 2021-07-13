#include <stdlib.h>
#include "../include/screen.h"
#include <gtk-3.0/gtk/gtk.h>

#include "../include/gb.h"

static gboolean on_timeout(gpointer user_data) {
    static int8_t flag = 0;
    GB *gb = (GB*) user_data;

    for (uint16_t i = 0; i < 1000; i++) {
        step_gb(gb);
        if (*(gb->ppu.ly) == 144) {
            if (flag == 0) {
                gtk_widget_queue_draw(GTK_WIDGET(gb->screen.window.wind));
                flag = 1;
            }
        } else {
            flag = 0;
        }
    }
    
    return G_SOURCE_CONTINUE;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./gb <GB ROM path>\n");
        exit(-1);
    }
    
    FILE *f = fopen(argv[1], "rb");

    if (f == NULL) {
        printf("Error: could not open file.\n");
        exit(-1);
    }

    GB gb;

    init_gb(&gb);
    load_gb_game(&gb, f);

    g_timeout_add(1, on_timeout, &gb);

    show_screen(&(gb.screen));
}