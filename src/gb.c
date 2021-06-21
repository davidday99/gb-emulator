#include "../include/cpu.h"
#include "../include/video.h"

int gb() {
    CPU cpu;
    Video video;

    init_cpu(&cpu);
    init_video(&video, &cpu);

    while (1) {
        step_cpu(&cpu);
        step_video(&video);
    }
}