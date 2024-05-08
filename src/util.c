#include "util.h"

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *datahome = NULL; /* dwmblocks数据存放目录 */

int gcd(int a, int b) {
    int temp;
    while (b > 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void closePipe(int pipe[2]) {
    close(pipe[0]);
    close(pipe[1]);
}

void trimUTF8(char* buffer, unsigned int size) {
    int length = (size - 1) / 4;
    int count = 0, j = 0;
    char ch = buffer[j];
    while (ch != '\0' && ch != '\n' && count < length) {
        // Skip continuation bytes, if any
        int skip = 1;
        while ((ch & 0xc0) > 0x80) {
            ch <<= 1;
            skip++;
        }

        j += skip;
        ch = buffer[j];
        count++;
    }

    // Trim trailing newline and spaces
    buffer[j] = ' ';
    while (j >= 0 && buffer[j] == ' ') j--;
    buffer[j + 1] = '\0';
}

void initdatahome() {
    // 存在配置直接退出
    if (datahome != NULL) return;

    char *xdgdatahome;
    char *home;
    char *localshare = ".local/share";

    if ((home = getenv("HOME")) == NULL) return;

    xdgdatahome = getenv("XDG_DATA_HOME");
    if (xdgdatahome != NULL && *xdgdatahome != '\0') {
        datahome = calloc(1, strlen(xdgdatahome) + 1);
        if (sprintf(datahome, "%s", xdgdatahome) <= 0) {
            free(datahome);
            fprintf(stderr, "dwmblocks data home init error: the XDG_DATA_HOME environment variable is not available\n");
            return;
        }
    } else {
        datahome = calloc(1, strlen(home) + strlen(localshare) + 2);
        if (sprintf(datahome, "%s/%s", home, localshare) < 0) {
            free(datahome);
            fprintf(stderr, "dwmblocks data home init error: the HOME environment variable is not available or %s directory does not exist\n", localshare);
            return;
        }
    }

    fprintf(stderr, "datahome init success: %s\n", datahome);
}

char *concat_datahome(const char* command){
    char *cmd;
    if (datahome == NULL) {
        fprintf(stderr, "dwmblocks data home init error does not exist\n");
    }

    cmd = calloc(1, strlen(datahome) + strlen(command) + 2);
    if (sprintf(cmd, "%s/%s", datahome, command) < 0) {
        free(cmd);
        fprintf(stderr, "dwmblocks data home concat error: datahome: %s, command: %s\n", datahome, command);
        return NULL;
    }
    return cmd;
}
