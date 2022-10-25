/**
@program Spinning donut!
@version 1.0
@author Emiliano Vivas Rodríguez
@email a01424732@tec.mx
@since 28/06/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

int main(void) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitleA("Spinning donut!");
    SMALL_RECT windowSize = { 0, 0, 80, 25 };
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 1;
    cursor.bVisible = FALSE;
    SetConsoleWindowInfo(handle, TRUE, &windowSize);
    SetConsoleCursorInfo(handle, &cursor);
    float A = 0.0f, B = 0.0f, i, j, c, d, e, f, g, h, D, l, m, n, t;
    int k, x, y, o, N;
    float z[1760];
    char b[1760];
    printf("\x1b[2J");
    for (;;) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (j = 0; j < 6.28; j += 0.07f) {
            for (i = 0; i < 6.28; i += 0.02f) {
                c = (float)sin(i);
                d = (float)cos(j);
                e = (float)sin(A);
                f = (float)sin(j);
                g = (float)cos(A);
                h = d + 2;
                D = 1 / (c * h * e + f * g + 5);
                l = (float)cos(i);
                m = (float)cos(B);
                n = (float)sin(B);
                t = c * h * g - f * e;
                x = (int)(40 + 30 * D * (l * h * m - t * n));
                y = (int)(12 + 15 * D * (l * h * n + t * m));
                o = x + 80 * y;
                N = (int)(8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n));
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H");
        for (k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);
            A += 0.00004f;
            B += 0.00002f;
        }
    }
    return EXIT_SUCCESS;
}