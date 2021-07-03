#include <stdlib.h>
#include "../include/cpu.h"
#include "../include/ppu.h"
#include "../include/screen.h"
#include <gtk-3.0/gtk/gtk.h>

typedef struct GB {
    CPU cpu;
    Video video;
    Screen screen;
} GB;

static gboolean on_timeout(gpointer user_data) {
    static int8_t flag = 0;
    GB *gb = (GB*) user_data;

    for (uint16_t i = 0; i < 1000; i++) {
        uint64_t prev_cycles = gb->cpu.current_state.CYCLE_COUNT;
        step_cpu(&(gb->cpu));
        step_video(&(gb->video), gb->cpu.current_state.CYCLE_COUNT - prev_cycles);
        if (*(gb->video.ly) == 144) {
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

    init_cpu(&gb.cpu);
    init_video(&gb.video, &gb.cpu);
    init_screen(&gb.screen, gb.video.buffer);
    load_program(f, &gb.cpu);

    g_timeout_add(1, on_timeout, &gb);

    show_screen(&(gb.screen));
}