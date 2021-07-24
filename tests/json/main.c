#include <stdio.h>
#include <stdlib.h>

#include <colibri.h>
#include <coatl.h>

#include "testfiles.inc"

int read(Col_Word rope, Col_Word *valuePtr) {
    Col_RopeIterator begin, end;
    Col_RopeIterFirst(begin, rope);
    Col_RopeIterBegin(end, rope, SIZE_MAX);

    if (!Coatl_ReadJson(begin, end, valuePtr)) {
        return 0;
    }
    return 1;
}

Col_Word write(Col_Word value, Col_StringFormat format) {
    Col_Word strbuf = Col_NewStringBuffer(0, format);
    size_t len = Coatl_WriteJson(strbuf, value, 0);
    if (len == 0) {
        return WORD_NIL;
    }
    return Col_StringBufferFreeze(strbuf);
}

int test(const char *filename, int verbose) {
    if (verbose)
        printf("%s ... ", filename);

    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("error reading file!\n");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    size_t len = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *data = (char *)malloc(len + 1);
    memset(data, 0, len + 1);
    fread(data, 1, len, f);
    fclose(f);

    Col_Init(COL_SINGLE);
    Col_PauseGC();

    Col_Word rope = Col_NewRope(COL_UTF8, data, len);

    int result = 0;
    Col_Word value;
    if (!read(rope, &value)) {
        printf("error reading value\n");
        result = 1;
        goto cleanup;
    }

    Col_Word rope2 = write(value, COL_UCS);
    if (!rope2) {
        printf("error writing value\n");
        result = 1;
        goto cleanup;
    }

    if (!read(rope2, &value)) {
        printf("error reading written value\n");
        result = 1;
        goto cleanup;
    }

    printf("success\n");

cleanup:
    Col_ResumeGC();
    Col_Cleanup();
    free(data);
    return result;
}

int main(int argc, char *argv[]) {
    int verbose = 1;
    int result = 0;
    if (argc > 1) {
        const char *filename = argv[1];
        result += test(filename, verbose);
    } else {
        const char **p = testfiles;
        while (*p) {
            const char *filename = *p;
            result += test(filename, verbose);
            p++;
        }
    }
    return result;
}
