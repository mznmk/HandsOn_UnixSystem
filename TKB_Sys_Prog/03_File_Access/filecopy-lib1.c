#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c;
    FILE *fps, *fpd;

    fps = fopen("src", "r");
    if (fps == NULL)
    {
        perror("fopen: src: ");
        exit(1);
    }

    fpd = fopen("dst", "w");
    if (fpd == NULL)
    {
        perror("fopen: dst: ");
        fclose(fps);
        exit(1);
    }

    while ((c = fgetc(fps)) != EOF)
    {
        fputc(c, fpd);
    }

    fclose(fpd);
    fclose(fps);

    return 0;
}
