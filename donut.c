#include <stdio.h>
#include <string.h>
#include <math.h>

#ifdef _WIN32
    #include <Windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep((ms)*1000)
#endif

#define _USE_MATH_DEFINES
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

int main() {
    float A = 0, B = 0;       // Rotation parameters
    float i, j;               // Angles for donut surface
    int k;                    // Loop counter for final printing
    float z[1760];            // Z-buffer (depth)
    char b[1760];             // ASCII buffer

#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif

    // Clear screen once before entering main loop:
    // \x1b[2J = ANSI escape to clear screen
    // \x1b[H  = ANSI escape to move cursor to top-left
    printf("\x1b[2J");

    // Main animation loop (runs forever)
    for (;;) {
        // Fill both buffers: 'b' with spaces, 'z' with 0
        memset(b, 32, sizeof(b));
        memset(z, 0,  sizeof(z));

        // Double loop over j, i to step around the donut
        for (j = 0; j < 2 * M_PI; j += 0.07f) {
            for (i = 0; i < 2 * M_PI; i += 0.02f) {
                float c = sinf(i), d = cosf(j), e = sinf(A), f = sinf(j), g = cosf(A);
                float h = d + 2.0f;          // Offset in x-direction
                float D = 1.0f / (c * h * g + f * e + 5.0f);  // Perspective depth
                float l = cosf(i), m = cosf(B), n = sinf(B);
                float t = c * h * e - f * g; // Used for shading

                // Project 3D -> 2D (x,y) onto a 80x22 "screen"
                int x = (int)(40.0f + 30.0f * D * (l * h * m - t * n));
                int y = (int)(12.0f + 15.0f * D * (l * h * n + t * m));

                // Convert (x,y) into a 1D index for b[] and z[]
                int o = x + 80 * y;

                // Shading from surface normal
                // N is used as an index into the ASCII gradient string
                int N = (int)(8.0f * ((f * g - c * d * e) * m - c * d * g - f * e - l * d * n));

                // If we’re within screen bounds and this pixel is closer than what we had
                if (y > 0 && y < 22 && x > 0 && x < 80 && D > z[o]) {
                    z[o] = D;
                    // The string ".,-~:;=!*#$@" maps N to a character; clamp to [0..11]
                    b[o] = ".,-~:;=!*#$@"[ (N > 0) ? N : 0 ];
                }
            }
        }

        // Reset cursor to top-left each frame
        printf("\x1b[H");

        // Print the 80x22 characters, plus newline at each row
        for (k = 0; k < 1760; k++) {
            putchar((k % 80) ? b[k] : '\n');
        }

        // Slightly change A, B each frame to rotate donut
        A += 0.04f;
        B += 0.02f;

        // Small pause to control animation speed
        SLEEP_MS(30);
    }

    return 0;
}
