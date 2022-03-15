#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fps, *fpd;
    void *buf;
    int rcount, wcount;

    if (argc != 3)
    {
        printf("Usage: %s src_file dst_file\n", argv[0]);
        exit(1);
    }

    fps = fopen(argv[1], "r");
    if (fps == NULL)
    {
        perror(argv[1]);
        exit(1);
    }

    fpd = fopen(argv[2], "w");
    if (fpd == NULL)
    {
        perror(argv[2]);
        fclose(fps);
        exit(1);
    }

#if 0
        buf = malloc(BUFSIZ);
        if (buf == NULL) {
                perror("malloc");
                fclose(fpd);
                fclose(fps);
                exit(1);
        }
#endif

    while (!feof(fps))
    {
        rcount = fread(buf, 1, BUFSIZ, fps);
        if (ferror(fps))
        {
            perror("fread");
            fclose(fpd);
            fclose(fps);
            exit(1);
        }

        wcount = fwrite(buf, 1, rcount, fpd);
        if (ferror(fpd))
        {
            perror("fwrite");
            fprintf(stderr, "tried to write %d bytes, "
                            "but only %d bytes were written.\n",
                    rcount, wcount);
            fclose(fpd);
            fclose(fps);
            exit(1);
        }
    }

    fclose(fpd);
    fclose(fps);

    return 0;
}
