/*
Lego Island Xtreme Stunts decompression 0.1
by Luigi Auriemma
e-mail: aluigi@autistici.org
web:    aluigi.org
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



static unsigned char lego_ixs_dump[] = {
0x55,0x8b,0xec,0x83,0xec,0x10,0x8b,0x45,0x08,0x33,0xc9,0x8a,0x08,0x8b,0x55,0x08,
0x33,0xc0,0x8a,0x42,0x01,0xc1,0xe0,0x08,0x0b,0xc8,0x8b,0x55,0x08,0x33,0xc0,0x8a,
0x42,0x02,0xc1,0xe0,0x10,0x0b,0xc8,0x8b,0x55,0x08,0x33,0xc0,0x8a,0x42,0x03,0xc1,
0xe0,0x18,0x0b,0xc8,0x89,0x4d,0xf0,0x8b,0x4d,0x08,0x83,0xc1,0x04,0x89,0x4d,0x08,
0x66,0xc7,0x45,0xfc,0x20,0x00,0xba,0x01,0x00,0x00,0x00,0x85,0xd2,0x0f,0x84,0xb4,
0x03,0x00,0x00,0x8b,0x45,0xf0,0x83,0xe0,0x01,0x85,0xc0,0x75,0x21,0x8b,0x4d,0x0c,
0x8b,0x55,0x08,0x8a,0x02,0x88,0x01,0x8b,0x4d,0x0c,0x83,0xc1,0x01,0x89,0x4d,0x0c,
0x8b,0x55,0x08,0x83,0xc2,0x01,0x89,0x55,0x08,0xe9,0x23,0x03,0x00,0x00,0x8b,0x45,
0xf0,0xd1,0xe8,0x89,0x45,0xf0,0x66,0x8b,0x4d,0xfc,0x66,0x83,0xe9,0x01,0x66,0x89,
0x4d,0xfc,0x8b,0x55,0xfc,0x81,0xe2,0xff,0xff,0x00,0x00,0x85,0xd2,0x75,0x40,0x8b,
0x45,0x08,0x33,0xc9,0x8a,0x08,0x8b,0x55,0x08,0x33,0xc0,0x8a,0x42,0x01,0xc1,0xe0,
0x08,0x0b,0xc8,0x8b,0x55,0x08,0x33,0xc0,0x8a,0x42,0x02,0xc1,0xe0,0x10,0x0b,0xc8,
0x8b,0x55,0x08,0x33,0xc0,0x8a,0x42,0x03,0xc1,0xe0,0x18,0x0b,0xc8,0x89,0x4d,0xf0,
0x8b,0x4d,0x08,0x83,0xc1,0x04,0x89,0x4d,0x08,0x66,0xc7,0x45,0xfc,0x20,0x00,0x8b,
0x55,0xf0,0x83,0xe2,0x01,0x85,0xd2,0x0f,0x84,0x35,0x01,0x00,0x00,0x8b,0x45,0x08,
0x33,0xc9,0x8a,0x08,0x8b,0x55,0x08,0x33,0xc0,0x8a,0x42,0x01,0xc1,0xe0,0x08,0x0b,
0xc8,0x66,0x89,0x4d,0xf8,0x8b,0x4d,0x08,0x83,0xc1,0x02,0x89,0x4d,0x08,0x8b,0x55,
0xf8,0x81,0xe2,0xff,0xff,0x00,0x00,0xc1,0xfa,0x03,0x81,0xca,0x00,0xe0,0xff,0xff,
0x8b,0x45,0x0c,0x03,0xc2,0x89,0x45,0xf4,0x8b,0x4d,0xf8,0x81,0xe1,0xff,0xff,0x00,
0x00,0x83,0xe1,0x07,0x66,0x89,0x4d,0xf8,0x8b,0x55,0xf8,0x81,0xe2,0xff,0xff,0x00,
0x00,0x85,0xd2,0x74,0x11,0x66,0x8b,0x45,0xf8,0x66,0x05,0x02,0x00,0x66,0x89,0x45,
0xf8,0xe9,0x91,0x00,0x00,0x00,0x8b,0x4d,0x08,0x66,0x0f,0xb6,0x11,0x66,0x89,0x55,
0xf8,0x8b,0x45,0x08,0x83,0xc0,0x01,0x89,0x45,0x08,0x8b,0x4d,0xf8,0x81,0xe1,0xff,
0xff,0x00,0x00,0x81,0xe1,0x80,0x00,0x00,0x00,0x85,0xc9,0x74,0x0c,0x8b,0x55,0xf4,
0x81,0xea,0x00,0x20,0x00,0x00,0x89,0x55,0xf4,0x66,0x8b,0x45,0xf8,0x66,0x25,0x7f,
0x00,0x66,0x89,0x45,0xf8,0x8b,0x4d,0xf8,0x81,0xe1,0xff,0xff,0x00,0x00,0x83,0xf9,
0x01,0x75,0x08,0x8b,0x45,0x0c,0xe9,0x5c,0x02,0x00,0x00,0x8b,0x55,0xf8,0x81,0xe2,
0xff,0xff,0x00,0x00,0x85,0xd2,0x75,0x23,0x8b,0x45,0x08,0x33,0xc9,0x8a,0x08,0x8b,
0x55,0x08,0x33,0xc0,0x8a,0x42,0x01,0xc1,0xe0,0x08,0x0b,0xc8,0x66,0x89,0x4d,0xf8,
0x8b,0x4d,0x08,0x83,0xc1,0x02,0x89,0x4d,0x08,0xeb,0x0c,0x66,0x8b,0x55,0xf8,0x66,
0x83,0xc2,0x02,0x66,0x89,0x55,0xf8,0x8b,0x45,0xf8,0x25,0xff,0xff,0x00,0x00,0x66,
0x8b,0x4d,0xf8,0x66,0x83,0xe9,0x01,0x66,0x89,0x4d,0xf8,0x85,0xc0,0x74,0x1e,0x8b,
0x55,0x0c,0x8b,0x45,0xf4,0x8a,0x08,0x88,0x0a,0x8b,0x55,0x0c,0x83,0xc2,0x01,0x89,
0x55,0x0c,0x8b,0x45,0xf4,0x83,0xc0,0x01,0x89,0x45,0xf4,0xeb,0xca,0xe9,0x7f,0x01,
0x00,0x00,0x8b,0x4d,0x08,0x33,0xd2,0x8a,0x11,0x81,0xca,0x00,0xff,0xff,0xff,0x8b,
0x45,0x0c,0x03,0xc2,0x89,0x45,0xf4,0x8b,0x4d,0x08,0x83,0xc1,0x01,0x89,0x4d,0x08,
0x8b,0x55,0x0c,0x8b,0x45,0xf4,0x8a,0x08,0x88,0x0a,0x8b,0x55,0x0c,0x83,0xc2,0x01,
0x89,0x55,0x0c,0x8b,0x45,0xf4,0x83,0xc0,0x01,0x89,0x45,0xf4,0x8b,0x4d,0x0c,0x8b,
0x55,0xf4,0x8a,0x02,0x88,0x01,0x8b,0x4d,0x0c,0x83,0xc1,0x01,0x89,0x4d,0x0c,0x8b,
0x55,0xf4,0x83,0xc2,0x01,0x89,0x55,0xf4,0x8b,0x45,0xf0,0xd1,0xe8,0x89,0x45,0xf0,
0x66,0x8b,0x4d,0xfc,0x66,0x83,0xe9,0x01,0x66,0x89,0x4d,0xfc,0x8b,0x55,0xfc,0x81,
0xe2,0xff,0xff,0x00,0x00,0x85,0xd2,0x75,0x40,0x8b,0x45,0x08,0x33,0xc9,0x8a,0x08,
0x8b,0x55,0x08,0x33,0xc0,0x8a,0x42,0x01,0xc1,0xe0,0x08,0x0b,0xc8,0x8b,0x55,0x08,
0x33,0xc0,0x8a,0x42,0x02,0xc1,0xe0,0x10,0x0b,0xc8,0x8b,0x55,0x08,0x33,0xc0,0x8a,
0x42,0x03,0xc1,0xe0,0x18,0x0b,0xc8,0x89,0x4d,0xf0,0x8b,0x4d,0x08,0x83,0xc1,0x04,
0x89,0x4d,0x08,0x66,0xc7,0x45,0xfc,0x20,0x00,0x8b,0x55,0xf0,0x83,0xe2,0x01,0x85,
0xd2,0x74,0x38,0x8b,0x45,0x0c,0x8b,0x4d,0xf4,0x8a,0x11,0x88,0x10,0x8b,0x45,0x0c,
0x83,0xc0,0x01,0x89,0x45,0x0c,0x8b,0x4d,0xf4,0x83,0xc1,0x01,0x89,0x4d,0xf4,0x8b,
0x55,0x0c,0x8b,0x45,0xf4,0x8a,0x08,0x88,0x0a,0x8b,0x55,0x0c,0x83,0xc2,0x01,0x89,
0x55,0x0c,0x8b,0x45,0xf4,0x83,0xc0,0x01,0x89,0x45,0xf4,0x8b,0x4d,0xf0,0xd1,0xe9,
0x89,0x4d,0xf0,0x66,0x8b,0x55,0xfc,0x66,0x83,0xea,0x01,0x66,0x89,0x55,0xfc,0x8b,
0x45,0xfc,0x25,0xff,0xff,0x00,0x00,0x85,0xc0,0x75,0x40,0x8b,0x4d,0x08,0x33,0xd2,
0x8a,0x11,0x8b,0x45,0x08,0x33,0xc9,0x8a,0x48,0x01,0xc1,0xe1,0x08,0x0b,0xd1,0x8b,
0x45,0x08,0x33,0xc9,0x8a,0x48,0x02,0xc1,0xe1,0x10,0x0b,0xd1,0x8b,0x45,0x08,0x33,
0xc9,0x8a,0x48,0x03,0xc1,0xe1,0x18,0x0b,0xd1,0x89,0x55,0xf0,0x8b,0x55,0x08,0x83,
0xc2,0x04,0x89,0x55,0x08,0x66,0xc7,0x45,0xfc,0x20,0x00,0x8b,0x45,0xf0,0x83,0xe0,
0x01,0x85,0xc0,0x74,0x1c,0x8b,0x4d,0x0c,0x8b,0x55,0xf4,0x8a,0x02,0x88,0x01,0x8b,
0x4d,0x0c,0x83,0xc1,0x01,0x89,0x4d,0x0c,0x8b,0x55,0xf4,0x83,0xc2,0x01,0x89,0x55,
0xf4,0x8b,0x45,0xf0,0xd1,0xe8,0x89,0x45,0xf0,0x66,0x8b,0x4d,0xfc,0x66,0x83,0xe9,
0x01,0x66,0x89,0x4d,0xfc,0x8b,0x55,0xfc,0x81,0xe2,0xff,0xff,0x00,0x00,0x85,0xd2,
0x75,0x40,0x8b,0x45,0x08,0x33,0xc9,0x8a,0x08,0x8b,0x55,0x08,0x33,0xc0,0x8a,0x42,
0x01,0xc1,0xe0,0x08,0x0b,0xc8,0x8b,0x55,0x08,0x33,0xc0,0x8a,0x42,0x02,0xc1,0xe0,
0x10,0x0b,0xc8,0x8b,0x55,0x08,0x33,0xc0,0x8a,0x42,0x03,0xc1,0xe0,0x18,0x0b,0xc8,
0x89,0x4d,0xf0,0x8b,0x4d,0x08,0x83,0xc1,0x04,0x89,0x4d,0x08,0x66,0xc7,0x45,0xfc,
0x20,0x00,0xe9,0x3f,0xfc,0xff,0xff,0x8b,0xe5,0x5d,0xc3,0xcc};

unsigned char * __cdecl (*lego_ixs)(unsigned char *in, unsigned char *out) = NULL;



// anti DEP limitation! if you apply VirtualAlloc on a static char
// it will cover also the rest of the page included other variables!
void *lego_ixs_alloc(u8 *dump, int dumpsz) {
    int     pagesz;
    void    *ret;

    pagesz = (dumpsz + 4095) & (~4095); // useful for pages? mah

#ifdef WIN32
    ret = VirtualAlloc(
        NULL,
        pagesz,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE);    // write for memcpy
#else
    ret = malloc(pagesz);
    mprotect(
        ret,
        pagesz,
        PROT_EXEC | PROT_WRITE);    // write for memcpy
#endif
    memcpy(ret, dump, dumpsz);
    return(ret);
}



void lego_ixs_init(void) {
    if(lego_ixs) return;
    lego_ixs = lego_ixs_alloc(lego_ixs_dump, sizeof(lego_ixs_dump));
}

