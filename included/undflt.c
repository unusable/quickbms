/*
undflt 0.1a
by Luigi Auriemma
e-mail: aluigi@autistici.org
web:    aluigi.org

original DFLT decompression function from the game Lego Lord of the Rings.
it should be related to nu2api used in the games developed by Traveller's Tales.

// Deflate_v1.0

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef WIN32
    #include <windows.h>
#endif



static const unsigned char undflt_00e01df4[] =
    "\x05\x00\x00\x00\xc0\x42\xdd\x00\xff\xff\xff\xff\x16\x00\x00\x00"
    "\x88\x00\x00\x00\x13\x00\x00\x00\x01\x00\x00\x00\x98\x00\x00\x00"
    "\x05\x00\x00\x00\xac\x42\xdd\x00\xff\xff\xff\xff\x16\x00\x00\x00"
    "\x89\x00\x00\x00\x14\x00\x00\x00\x01\x00\x00\x00\xa0\x00\x00\x00"
    "\x05\x00\x00\x00\x98\x42\xdd\x00\xff\xff\xff\xff\x16\x00\x00\x00"
    "\x8a\x00\x00\x00\x15\x00\x00\x00\x01\x00\x00\x00\xa8\x00\x00\x00"
    "\x05\x00\x00\x00\x84\x42\xdd\x00\xff\xff\xff\xff\x16\x00\x00\x00"
    "\x8b\x00\x00\x00\x16\x00\x00\x00\x01\x00\x00\x00\xb0\x00\x00\x00"
    "\x05\x00\x00\x00\x6c\x42\xdd\x00\xff\xff\xff\xff\x16\x00\x00\x00"
    "\x8c\x00\x00\x00\x17\x00\x00\x00\x01\x00\x00\x00\xb8\x00\x00\x00"
    "\x06\x00\x00\x00\x58\x42\xdd\x00\xff\xff\xff\xff\x16\x00\x00\x00"
    "\x8d\x00\x00\x00\x18\x00\x00\x00\x01\x00\x00\x00\xc0\x00\x00\x00"
    "\x06\x00\x00\x00\x40\x42\xdd\x00\xff\xff\xff\xff\x16\x00\x00\x00"
    "\x8e\x00\x00\x00\x19\x00\x00\x00\x01\x00\x00\x00\xc8\x00\x00\x00"
    "\x05\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\x3f\x00\x00\x80\x3f"
    "\x00\x01\x01\x01\x01\x01\x00\x00\x01\x00\x01\x01\xff\xff\xff\xff"
    "\xff\xff\xff\xff\x00\x00\x00\x01\x95\x00\x00\x00\xcd\xcc\x0c\x40"
    "\x2f\xba\xe8\x3e\xf0\xf8\xff\xff\xfa\xeb\xd7\xff\x00\xff\xff\xff"
    "\x7f\xff\xd4\xff\xf0\xff\xff\xff\xf5\xf5\xdc\xff\xff\xe4\xc4\xff"
    "\x00\x00\x00\xff\xff\xeb\xcd\xff\x00\x00\xff\xff\x8a\x2b\xe2\xff"
    "\x7c\x3a\x00\xff\xde\xb8\x87\xff\x5f\x9e\xa0\xff\x7f\xff\x00\xff"
    "\xd2\x69\x1e\xff\xff\x7f\x50\xff\x64\x95\xed\xff\xff\xf8\xdc\xff"
    "\xdc\x14\x3c\xff\x00\xff\xff\xff\x00\x00\x8b\xff\x00\x8b\x8b\xff"
    "\xb8\x86\x0b\xff\xa9\xa9\xa9\xff\x00\x64\x00\xff\xbd\xb7\x6b\xff"
    "\x8b\x00\x8b\xff\x55\x6b\x2f\xff\xff\x8c\x00\xff\x99\x32\xcc\xff"
    "\x8b\x00\x00\xff\xe9\x96\x7a\xff\x8f\xbc\x8b\xff\x48\x3d\x8b\xff"
    "\x2f\x4f\x4f\xff\x00\xce\xd1\xff\x94\x00\xd3\xff\xff\x14\x93\xff"
    "\x00\xbf\xff\xff\x69\x69\x69\xff\x6c\x5f\x00\xff\x1e\x90\xff\xff"
    "\xb2\x22\x22\xff\xff\xfa\xf0\xff\x22\x8b\x22\xff\xff\x00\xff\xff"
    "\xdc\xdc\xdc\xff\xf8\xf8\xff\xff\xff\xd7\x00\xff\xda\xa5\x20\xff"
    "\x80\x80\x80\xff\x00\x80\x00\xff\xad\xff\x2f\xff\xf0\xff\xf0\xff"
    "\xff\x69\xb4\xff\xcd\x5c\x5c\xff\x4b\x00\x82\xff\xff\xff\xf0\xff"
    "\xf0\xe6\x8c\xff\xe6\xe6\xfa\xff\xff\xf0\xf5\xff\x7c\xfc\x00\xff"
    "\xff\xfa\xcd\xff\xad\xd8\xe6\xff\xf0\x80\x80\xff\xe0\xff\xff\xff"
    "\xfa\xfa\xd2\xff\xd3\xd3\xd3\xff\x90\xee\x90\xff\xff\xd3\x00\xff"
    "\xff\xb6\xc1\xff\xff\x40\x40\xff\xff\xa0\x7a\xff\x20\xb2\xaa\xff"
    "\x87\xce\xfa\xff\x77\x88\x99\xff\xb0\xc4\xde\xff\xff\xff\xc0\xff"
    "\x00\xff\x00\xff\x32\xcd\x32\xff\xfa\xf0\xe6\xff\xff\x00\xff\xff"
    "\x80\x00\x00\xff\x66\xcd\xaa\xff\x00\x00\xcd\xff\xba\x55\xd3\xff"
    "\x93\x70\xdb\xff\x3c\xb3\x71\xff\x7b\x68\xee\xff\x00\xfa\x9a\xff"
    "\x48\xd1\xcc\xff\xc7\x15\x85\xff\x19\x19\x70\xff\xf5\xff\xfa\xff"
    "\xff\xe4\xe1\xff\xff\xe4\xb5\xff\xff\xde\xad\xff\x00\x00\x80\xff"
    "\xfd\xf5\xe6\xff\x80\x80\x00\xff\x6b\x8e\x23\xff\xff\xa5\x00\xff"
    "\xff\x45\x00\xff\xda\x70\xd6\xff\xee\xe8\xaa\xff\x98\xfb\x98\xff"
    "\xaf\xee\xee\xff\xdb\x70\x93\xff\xff\xef\xd5\xff\xff\xda\xb9\xff"
    "\xcd\x85\x3f\xff\xff\xc0\xcb\xff\xdd\xa0\xdd\xff\xb0\xe0\xe6\xff"
    "\x80\x00\x80\xff\xff\x00\x00\xff\xbc\x8f\x8f\xff\x41\x69\xe1\xff"
    "\x8b\x45\x13\xff\xfa\x80\x72\xff\xf4\xa4\x60\xff\x2e\x8b\x57\xff"
    "\xff\xf5\xee\xff\xa0\x52\x2d\xff\xc0\xc0\xc0\xff\x87\xce\xeb\xff"
    "\x6a\x5a\xcd\xff\x70\x80\x90\xff\xff\xfa\xfa\xff\x00\xff\x7f\xff"
    "\x46\x82\xb4\xff\xd2\xb4\x8c\xff\x00\x80\x80\xff\xd8\xbf\xd8\xff"
    "\xff\x63\x47\xff\x40\xe0\xd0\xff\xee\x82\xee\xff\xf5\xde\xb3\xff"
    "\xff\xff\xff\xff\xf5\xf5\xf5\xff\xff\xff\x00\xff\x9a\xcd\x32\xff"
    "\x44\x65\x66\x6c\x61\x74\x65\x5f\x76\x31\x2e\x30\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x40\x04\x00\x00\x00\x05\x00\x00\x00\x06\x00\x00\x00"
    "\x07\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x02\x00\x00\x00"
    "\x03\x00\x00\x00\x56\x35\x82\x47\x00\x00\x80\x3f\x21\x00\x24\x00"
    "\x25\x00\x5e\x00\x26\x00\x2a\x00\x28\x00\x29\x00\x5f\x00\x2b\x00"
    "\x2d\x00\x3d\x00\x7b\x00\x7d\x00\x5b\x00\x5d\x00\x40\x00\x7e\x00"
    "\x23\x00\x3f\x00\x3c\x00\x3e\x00\x2c\x00\x2e\x00\x20\x00\x00\x00"
    "\x33\x33\x73\x3f\x0a\xd7\x23\x3c\x00\x00\x00\x00\xff\x00\x00\x00"
    "\xff\xff\x00\x00\xff\xff\xff\x00\xff\xff\xff\xff\x10\x11\x12\x00"
    "\x08\x07\x09\x06\x0a\x05\x0b\x04\x0c\x03\x0d\x02\x0e\x01\x0f\x00"
    "\x00\x00\x00\x00\x03\x00\x00\x00\x04\x00\x00\x00\x05\x00\x00\x00"
    "\x06\x00\x00\x00\x07\x00\x00\x00\x08\x00\x00\x00\x09\x00\x00\x00"
    "\x0a\x00\x00\x00\x0b\x00\x00\x00\x0d\x00\x00\x00\x0f\x00\x00\x00"
    "\x11\x00\x00\x00\x13\x00\x00\x00\x17\x00\x00\x00\x1b\x00\x00\x00"
    "\x1f\x00\x00\x00\x23\x00\x00\x00\x2b\x00\x00\x00\x33\x00\x00\x00"
    "\x3b\x00\x00\x00\x43\x00\x00\x00\x53\x00\x00\x00\x63\x00\x00\x00"
    "\x73\x00\x00\x00\x83\x00\x00\x00\xa3\x00\x00\x00\xc3\x00\x00\x00"
    "\xe3\x00\x00\x00\x02\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00"
    "\x01\x00\x00\x00\x02\x00\x00\x00\x02\x00\x00\x00\x02\x00\x00\x00"
    "\x02\x00\x00\x00\x03\x00\x00\x00\x03\x00\x00\x00\x03\x00\x00\x00"
    "\x03\x00\x00\x00\x04\x00\x00\x00\x04\x00\x00\x00\x04\x00\x00\x00"
    "\x04\x00\x00\x00\x05\x00\x00\x00\x05\x00\x00\x00\x05\x00\x00\x00"
    "\x05\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x01\x00\x00\x00\x02\x00\x00\x00\x03\x00\x00\x00"
    "\x04\x00\x00\x00\x05\x00\x00\x00\x07\x00\x00\x00\x09\x00\x00\x00"
    "\x0d\x00\x00\x00\x11\x00\x00\x00\x19\x00\x00\x00\x21\x00\x00\x00"
    "\x31\x00\x00\x00\x41\x00\x00\x00\x61\x00\x00\x00\x81\x00\x00\x00"
    "\xc1\x00\x00\x00\x01\x01\x00\x00\x81\x01\x00\x00\x01\x02\x00\x00"
    "\x01\x03\x00\x00\x01\x04\x00\x00\x01\x06\x00\x00\x01\x08\x00\x00"
    "\x01\x0c\x00\x00\x01\x10\x00\x00\x01\x18\x00\x00\x01\x20\x00\x00"
    "\x01\x30\x00\x00\x01\x40\x00\x00\x01\x60\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
static const unsigned char undflt_01205378[]=
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x01\x00\x00\x00\x01\x00\x00\x00\x02\x00\x00\x00\x02\x00\x00\x00"
    "\x03\x00\x00\x00\x03\x00\x00\x00\x04\x00\x00\x00\x04\x00\x00\x00"
    "\x05\x00\x00\x00\x05\x00\x00\x00\x06\x00\x00\x00\x06\x00\x00\x00"
    "\x07\x00\x00\x00\x07\x00\x00\x00\x08\x00\x00\x00\x08\x00\x00\x00"
    "\x09\x00\x00\x00\x09\x00\x00\x00\x0a\x00\x00\x00\x0a\x00\x00\x00"
    "\x0b\x00\x00\x00\x0b\x00\x00\x00\x0c\x00\x00\x00\x0c\x00\x00\x00"
    "\x0d\x00\x00\x00\x0d\x00\x00\x00";
static unsigned char undflt_013a1e60[4] = "";
static unsigned char undflt_013b1f00[0x90 + 0x70] = "";
static unsigned char undflt_013b2000[0x20] = "";
static unsigned char undflt_013b2e20[0x20] = ""; 



static /*const*/ unsigned char undflt_dump[] = {
    0x81,0xec,0x94,0x00,0x00,0x00,0xa1,0x60,0x1e,0x3a,0x01,0x33,0xc4,0x89,0x84,0x24,
    0x90,0x00,0x00,0x00,0x53,0x55,0x56,0x8b,0xb4,0x24,0xa4,0x00,0x00,0x00,0x57,0x8b,
    0xbc,0x24,0xac,0x00,0x00,0x00,0x33,0xed,0x6a,0x44,0x8d,0x44,0x24,0x20,0x55,0x50,
    0x89,0x74,0x24,0x20,0x89,0x7c,0x24,0x24,0x89,0x6c,0x24,0x1c,0xe8,0x9f,0xd4,0x74,
    0x00,0x68,0x00,0x04,0x00,0x00,0x68,0xff,0x00,0x00,0x00,0x56,0xe8,0x8f,0xd4,0x74,
    0x00,0x8b,0x94,0x24,0xc8,0x00,0x00,0x00,0x83,0xc4,0x18,0x33,0xc0,0x3b,0xd5,0x7e,
    0x11,0x0f,0xb6,0x0c,0x07,0xff,0x44,0x8c,0x1c,0x8d,0x4c,0x8c,0x1c,0x40,0x3b,0xc2,
    0x7c,0xef,0x33,0xc0,0x8d,0x9e,0x24,0x04,0x00,0x00,0x8d,0x96,0x66,0x04,0x00,0x00,
    0x89,0x6c,0x24,0x1c,0x8d,0x48,0x0f,0x33,0xf6,0x8d,0xa4,0x24,0x00,0x00,0x00,0x00,
    0x66,0x8b,0x7c,0x24,0x10,0x66,0x89,0x3a,0x8b,0x7c,0x34,0x20,0x01,0x7c,0x24,0x10,
    0x66,0x89,0x42,0x9c,0x89,0x44,0x34,0x64,0x03,0xc7,0x8b,0xe8,0xd3,0xe5,0x49,0x03,
    0xc0,0x83,0xc2,0x02,0x89,0x2b,0x83,0xc6,0x04,0x83,0xc3,0x04,0x85,0xc9,0x7f,0xd0,
    0x8b,0x6c,0x24,0x14,0x33,0xc0,0xc7,0x85,0x60,0x04,0x00,0x00,0x00,0x00,0x01,0x00,
    0x89,0x44,0x24,0x10,0x39,0x84,0x24,0xb0,0x00,0x00,0x00,0x0f,0x8e,0xeb,0x00,0x00,
    0x00,0x8b,0x4c,0x24,0x18,0x0f,0xb6,0x1c,0x01,0x85,0xdb,0x0f,0x84,0xc9,0x00,0x00,
    0x00,0x0f,0xb7,0xb4,0x5d,0x64,0x04,0x00,0x00,0x0f,0xb7,0x94,0x5d,0x00,0x04,0x00,
    0x00,0x8b,0x7c,0x9c,0x60,0x8d,0x4c,0x9c,0x60,0x2b,0xf2,0x03,0xf7,0x88,0x9c,0x2e,
    0x84,0x04,0x00,0x00,0x89,0x4c,0x24,0x14,0x66,0x89,0x84,0x75,0xa4,0x05,0x00,0x00,
    0x83,0xfb,0x09,0x0f,0x8f,0x8a,0x00,0x00,0x00,0x8b,0xc7,0xd1,0xf8,0x25,0x55,0x55,
    0x00,0x00,0x8b,0xcf,0x81,0xe1,0x55,0x55,0x00,0x00,0x03,0xc9,0x0b,0xc1,0x8b,0xc8,
    0x25,0x33,0x33,0x00,0x00,0x03,0xc0,0xc1,0xf9,0x02,0x03,0xc0,0x81,0xe1,0x33,0x33,
    0x00,0x00,0x0b,0xc8,0x8b,0xc1,0xc1,0xf8,0x04,0x81,0xe1,0x0f,0x0f,0x00,0x00,0x25,
    0x0f,0x0f,0x00,0x00,0xc1,0xe1,0x04,0x0b,0xc1,0x8b,0xd0,0xc1,0xfa,0x08,0x25,0xff,
    0x00,0x00,0x00,0x81,0xe2,0xff,0x00,0x00,0x00,0xc1,0xe0,0x08,0xb9,0x10,0x00,0x00,
    0x00,0x0b,0xd0,0x2b,0xcb,0xd3,0xfa,0x81,0xfa,0x00,0x02,0x00,0x00,0x7d,0x20,0xb8,
    0x01,0x00,0x00,0x00,0x8b,0xcb,0xd3,0xe0,0xeb,0x06,0x8d,0x9b,0x00,0x00,0x00,0x00,
    0x66,0x89,0x74,0x55,0x00,0x03,0xd0,0x81,0xfa,0x00,0x02,0x00,0x00,0x7c,0xf1,0x8b,
    0x44,0x24,0x10,0x8b,0x54,0x24,0x14,0x47,0x89,0x3a,0x40,0x89,0x44,0x24,0x10,0x3b,
    0x84,0x24,0xb0,0x00,0x00,0x00,0x0f,0x8c,0x15,0xff,0xff,0xff,0x8b,0x8c,0x24,0xa0,
    0x00,0x00,0x00,0x5f,0x5e,0x5d,0x5b,0x33,0xcc,0xb8,0x01,0x00,0x00,0x00,0xe8,0x41,
    0xcb,0x74,0x00,0x81,0xc4,0x94,0x00,0x00,0x00,0xc3,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,
    0x8b,0x4a,0x08,0x53,0x8b,0x5a,0x04,0x56,0x57,0x8b,0x7a,0x0c,0x8d,0x64,0x24,0x00,
    0x8b,0x32,0x3b,0xf3,0x72,0x04,0x33,0xc0,0xeb,0x06,0x0f,0xb6,0x06,0x46,0x89,0x32,
    0xd3,0xe0,0x83,0xc1,0x08,0x89,0x4a,0x08,0x0b,0xf8,0x89,0x7a,0x0c,0x83,0xf9,0x18,
    0x7e,0xde,0x5f,0x5e,0x5b,0xc3,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,
    0x51,0x8b,0x54,0x24,0x08,0x53,0x55,0x56,0x57,0x8d,0xa4,0x24,0x00,0x00,0x00,0x00,
    0x8b,0x4a,0x08,0x83,0xf9,0x10,0x7d,0x2a,0x8b,0x42,0x04,0x8b,0x5a,0x0c,0x8b,0xff,
    0x8b,0x3a,0x3b,0xf8,0x72,0x04,0x33,0xf6,0xeb,0x06,0x0f,0xb6,0x37,0x47,0x89,0x3a,
    0xd3,0xe6,0x83,0xc1,0x08,0x89,0x4a,0x08,0x0b,0xde,0x89,0x5a,0x0c,0x83,0xf9,0x18,
    0x7e,0xde,0x8b,0x72,0x0c,0x8b,0xc6,0x25,0xff,0x01,0x00,0x00,0x0f,0xb7,0x7c,0x42,
    0x1c,0x81,0xff,0xff,0xff,0x00,0x00,0x7d,0x1b,0x0f,0xb6,0x8c,0x17,0xa0,0x04,0x00,
    0x00,0xd3,0x6a,0x0c,0x29,0x4a,0x08,0x0f,0xb7,0x9c,0x7a,0xc0,0x05,0x00,0x00,0xe9,
    0xa1,0x00,0x00,0x00,0x8b,0xce,0xd1,0xf9,0x81,0xe6,0x55,0x55,0x00,0x00,0x81,0xe1,
    0x55,0x55,0x00,0x00,0x03,0xf6,0x0b,0xce,0x8b,0xf1,0x81,0xe1,0x33,0x33,0x00,0x00,
    0xc1,0xfe,0x02,0x03,0xc9,0x03,0xc9,0x81,0xe6,0x33,0x33,0x00,0x00,0x0b,0xf1,0x8b,
    0xce,0xc1,0xf9,0x04,0x81,0xe6,0x0f,0x0f,0x00,0x00,0xc1,0xe6,0x04,0x81,0xe1,0x0f,
    0x0f,0x00,0x00,0x0b,0xce,0x8b,0xf1,0xc1,0xfe,0x08,0x81,0xe1,0xff,0x00,0x00,0x00,
    0xc1,0xe1,0x08,0x81,0xe6,0xff,0x00,0x00,0x00,0x0b,0xf1,0x8d,0x8a,0x64,0x04,0x00,
    0x00,0xbf,0x0a,0x00,0x00,0x00,0x3b,0x31,0x7c,0x0e,0x8d,0x9b,0x00,0x00,0x00,0x00,
    0x83,0xc1,0x04,0x47,0x3b,0x31,0x7d,0xf8,0x0f,0xb7,0x84,0x7a,0x80,0x04,0x00,0x00,
    0xb9,0x10,0x00,0x00,0x00,0x2b,0xcf,0xd3,0xfe,0x0f,0xb7,0x8c,0x7a,0x1c,0x04,0x00,
    0x00,0x2b,0xf1,0x8b,0xcf,0xd3,0x6a,0x0c,0x03,0xf0,0x29,0x7a,0x08,0x0f,0xb7,0x9c,
    0x72,0xc0,0x05,0x00,0x00,0x8b,0x4a,0x08,0x8b,0x6a,0x0c,0x81,0xfb,0x00,0x01,0x00,
    0x00,0x7d,0x0d,0x8b,0x4a,0x10,0x88,0x19,0xff,0x42,0x10,0xe9,0xe0,0xfe,0xff,0xff,
    0x0f,0x84,0xe5,0x01,0x00,0x00,0x8b,0x04,0x9d,0xf4,0x1d,0xe0,0x00,0x8b,0x1c,0x9d,
    0x74,0x1e,0xe0,0x00,0x89,0x44,0x24,0x10,0x85,0xdb,0x74,0x44,0x3b,0xcb,0x7d,0x25,
    0x8b,0x42,0x04,0x8b,0x3a,0x3b,0xf8,0x72,0x04,0x33,0xf6,0xeb,0x06,0x0f,0xb6,0x37,
    0x47,0x89,0x3a,0xd3,0xe6,0x83,0xc1,0x08,0x89,0x4a,0x08,0x0b,0xee,0x89,0x6a,0x0c,
    0x83,0xf9,0x18,0x7e,0xde,0x8b,0x7a,0x0c,0x29,0x5a,0x08,0x8b,0xcb,0xbe,0x01,0x00,
    0x00,0x00,0xd3,0xe6,0x4e,0x23,0xf7,0xd3,0xef,0x01,0x74,0x24,0x10,0x89,0x7a,0x0c,
    0x8b,0x4a,0x08,0x83,0xf9,0x10,0x7d,0x2a,0x8b,0x42,0x04,0x8b,0x5a,0x0c,0x8b,0xff,
    0x8b,0x3a,0x3b,0xf8,0x72,0x04,0x33,0xf6,0xeb,0x06,0x0f,0xb6,0x37,0x47,0x89,0x3a,
    0xd3,0xe6,0x83,0xc1,0x08,0x89,0x4a,0x08,0x0b,0xde,0x89,0x5a,0x0c,0x83,0xf9,0x18,
    0x7e,0xde,0x8b,0x72,0x0c,0x8b,0xce,0x81,0xe1,0xff,0x01,0x00,0x00,0x0f,0xb7,0xbc,
    0x4a,0x00,0x08,0x00,0x00,0x81,0xff,0xff,0xff,0x00,0x00,0x7d,0x1b,0x0f,0xb6,0x8c,
    0x17,0x84,0x0c,0x00,0x00,0xd3,0x6a,0x0c,0x29,0x4a,0x08,0x0f,0xb7,0xb4,0x7a,0xa4,
    0x0d,0x00,0x00,0xe9,0x9d,0x00,0x00,0x00,0x8b,0xce,0xd1,0xf9,0x81,0xe6,0x55,0x55,
    0x00,0x00,0x81,0xe1,0x55,0x55,0x00,0x00,0x03,0xf6,0x0b,0xce,0x8b,0xf1,0x81,0xe1,
    0x33,0x33,0x00,0x00,0xc1,0xfe,0x02,0x03,0xc9,0x03,0xc9,0x81,0xe6,0x33,0x33,0x00,
    0x00,0x0b,0xf1,0x8b,0xce,0xc1,0xf9,0x04,0x81,0xe6,0x0f,0x0f,0x00,0x00,0xc1,0xe6,
    0x04,0x81,0xe1,0x0f,0x0f,0x00,0x00,0x0b,0xce,0x8b,0xf1,0xc1,0xfe,0x08,0x81,0xe1,
    0xff,0x00,0x00,0x00,0xc1,0xe1,0x08,0x81,0xe6,0xff,0x00,0x00,0x00,0x0b,0xf1,0x8d,
    0x8a,0x48,0x0c,0x00,0x00,0xbf,0x0a,0x00,0x00,0x00,0x3b,0x31,0x7c,0x0a,0x8b,0xff,
    0x83,0xc1,0x04,0x47,0x3b,0x31,0x7d,0xf8,0x0f,0xb7,0x84,0x7a,0x00,0x0c,0x00,0x00,
    0xb9,0x10,0x00,0x00,0x00,0x2b,0xcf,0xd3,0xfe,0x0f,0xb7,0x8c,0x7a,0x64,0x0c,0x00,
    0x00,0x2b,0xf0,0x03,0xf1,0x8b,0xcf,0xd3,0x6a,0x0c,0x29,0x7a,0x08,0x0f,0xb7,0xb4,
    0x72,0xa4,0x0d,0x00,0x00,0x8b,0x2c,0xb5,0x78,0x53,0x20,0x01,0x8b,0x04,0xb5,0xf8,
    0x22,0xe0,0x00,0x8b,0x4a,0x08,0x8b,0x5a,0x0c,0x89,0x44,0x24,0x18,0x85,0xed,0x74,
    0x44,0x3b,0xcd,0x7d,0x25,0x8b,0x42,0x04,0x8b,0x3a,0x3b,0xf8,0x72,0x04,0x33,0xf6,
    0xeb,0x06,0x0f,0xb6,0x37,0x47,0x89,0x3a,0xd3,0xe6,0x83,0xc1,0x08,0x89,0x4a,0x08,
    0x0b,0xde,0x89,0x5a,0x0c,0x83,0xf9,0x18,0x7e,0xde,0x8b,0x7a,0x0c,0x29,0x6a,0x08,
    0x8b,0xcd,0xbe,0x01,0x00,0x00,0x00,0xd3,0xe6,0x4e,0x23,0xf7,0xd3,0xef,0x01,0x74,
    0x24,0x18,0x89,0x7a,0x0c,0x8b,0x4a,0x10,0x8b,0x74,0x24,0x10,0x2b,0x4c,0x24,0x18,
    0x85,0xf6,0x0f,0x84,0x08,0xfd,0xff,0xff,0x8a,0x19,0x8b,0x42,0x10,0x88,0x18,0xff,
    0x42,0x10,0x41,0x4e,0x75,0xf2,0xe9,0xf5,0xfc,0xff,0xff,0x5f,0x5e,0x5d,0xb8,0x01,
    0x00,0x00,0x00,0x5b,0x59,0xc3,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,
    0x81,0xec,0xf4,0x01,0x00,0x00,0xa1,0x60,0x1e,0x3a,0x01,0x33,0xc4,0x89,0x84,0x24,
    0xf0,0x01,0x00,0x00,0x53,0x55,0x56,0x8b,0xb4,0x24,0x04,0x02,0x00,0x00,0x83,0x7e,
    0x08,0x05,0x57,0x7d,0x07,0x8b,0xd6,0xe8,0x64,0xfc,0xff,0xff,0x8b,0x46,0x0c,0x8b,
    0xc8,0x83,0xe1,0x1f,0xbf,0xfb,0xff,0xff,0xff,0x01,0x7e,0x08,0xc1,0xe8,0x05,0x81,
    0xc1,0x01,0x01,0x00,0x00,0x83,0x7e,0x08,0x05,0x89,0x46,0x0c,0x89,0x4c,0x24,0x1c,
    0x7d,0x07,0x8b,0xd6,0xe8,0x37,0xfc,0xff,0xff,0x8b,0x46,0x0c,0x01,0x7e,0x08,0x8b,
    0xc8,0x83,0xe1,0x1f,0xc1,0xe8,0x05,0x41,0x83,0x7e,0x08,0x04,0x89,0x46,0x0c,0x89,
    0x4c,0x24,0x18,0x7d,0x07,0x8b,0xd6,0xe8,0x14,0xfc,0xff,0xff,0x8b,0x46,0x0c,0x83,
    0x46,0x08,0xfc,0x8b,0x56,0x08,0x8b,0xe8,0x33,0xc9,0x83,0xe5,0x0f,0xc1,0xe8,0x04,
    0x83,0xc5,0x04,0x33,0xdb,0x89,0x46,0x0c,0x89,0x4c,0x24,0x24,0x89,0x4c,0x24,0x28,
    0x89,0x4c,0x24,0x2c,0x89,0x4c,0x24,0x30,0x66,0x89,0x4c,0x24,0x34,0x88,0x4c,0x24,
    0x36,0x85,0xed,0x7e,0x51,0x8b,0xca,0x83,0xf9,0x03,0x7d,0x29,0x8b,0xd0,0x8b,0xff,
    0x8b,0x3e,0x3b,0x7e,0x04,0x72,0x04,0x33,0xc0,0xeb,0x06,0x0f,0xb6,0x07,0x47,0x89,
    0x3e,0xd3,0xe0,0x83,0xc1,0x08,0x89,0x4e,0x08,0x0b,0xd0,0x8b,0xc2,0x89,0x56,0x0c,
    0x83,0xf9,0x18,0x7e,0xdb,0x8b,0xd0,0xc1,0xe8,0x03,0x83,0xe9,0x03,0x89,0x46,0x0c,
    0x89,0x4e,0x08,0x0f,0xb6,0xbb,0xe0,0x21,0xe0,0x00,0x83,0xe2,0x07,0x43,0x88,0x54,
    0x3c,0x24,0x3b,0xdd,0x7c,0xb1,0x6a,0x13,0x8d,0x4c,0x24,0x28,0x8d,0x86,0xe4,0x0f,
    0x00,0x00,0x51,0x50,0xe8,0x87,0xf9,0xff,0xff,0x83,0xc4,0x0c,0x85,0xc0,0x75,0x07,
    0x33,0xc0,0xe9,0x98,0x02,0x00,0x00,0x8b,0x7c,0x24,0x1c,0x8b,0x44,0x24,0x18,0x03,
    0xc7,0xc7,0x44,0x24,0x10,0x00,0x00,0x00,0x00,0x89,0x44,0x24,0x20,0x85,0xc0,0x0f,
    0x8e,0x41,0x02,0x00,0x00,0x8b,0x5e,0x08,0x8b,0x7e,0x0c,0xeb,0x03,0x8d,0x49,0x00,
    0x83,0xfb,0x10,0x7d,0x2f,0x8b,0x6e,0x04,0x8b,0xcb,0x8d,0x9b,0x00,0x00,0x00,0x00,
    0x8b,0x16,0x3b,0xd5,0x72,0x04,0x33,0xc0,0xeb,0x06,0x0f,0xb6,0x02,0x42,0x89,0x16,
    0xd3,0xe0,0x83,0xc1,0x08,0x8b,0xd9,0x89,0x4e,0x08,0x0b,0xf8,0x89,0x7e,0x0c,0x83,
    0xf9,0x18,0x7e,0xdc,0x8b,0xc7,0x25,0xff,0x01,0x00,0x00,0x0f,0xb7,0x84,0x46,0xe4,
    0x0f,0x00,0x00,0x8d,0xae,0xe4,0x0f,0x00,0x00,0x3d,0xff,0xff,0x00,0x00,0x7d,0x1f,
    0x0f,0xb6,0x8c,0x28,0x84,0x04,0x00,0x00,0xd3,0xef,0x2b,0xd9,0x89,0x5e,0x08,0x89,
    0x7e,0x0c,0x0f,0xb7,0x84,0x45,0xa4,0x05,0x00,0x00,0xe9,0xa0,0x00,0x00,0x00,0x8b,
    0xc7,0xd1,0xf8,0x25,0x55,0x55,0x00,0x00,0x8b,0xcf,0x81,0xe1,0x55,0x55,0x00,0x00,
    0x03,0xc9,0x0b,0xc1,0x8b,0xc8,0x25,0x33,0x33,0x00,0x00,0x03,0xc0,0xc1,0xf9,0x02,
    0x03,0xc0,0x81,0xe1,0x33,0x33,0x00,0x00,0x0b,0xc8,0x8b,0xd1,0xc1,0xfa,0x04,0x81,
    0xe2,0x0f,0x0f,0x00,0x00,0x81,0xe1,0x0f,0x0f,0x00,0x00,0xc1,0xe1,0x04,0x0b,0xd1,
    0x8b,0xc2,0xc1,0xf8,0x08,0x81,0xe2,0xff,0x00,0x00,0x00,0xc1,0xe2,0x08,0x25,0xff,
    0x00,0x00,0x00,0x0b,0xc2,0x81,0xc5,0x48,0x04,0x00,0x00,0xba,0x0a,0x00,0x00,0x00,
    0x3b,0x45,0x00,0x7c,0x09,0x83,0xc5,0x04,0x42,0x3b,0x45,0x00,0x7d,0xf7,0xb9,0x10,
    0x00,0x00,0x00,0x2b,0xca,0xd3,0xf8,0x0f,0xb7,0x8c,0x56,0xe4,0x13,0x00,0x00,0x2b,
    0xc1,0x0f,0xb7,0x8c,0x56,0x48,0x14,0x00,0x00,0x03,0xc1,0x8b,0xca,0xd3,0xef,0x2b,
    0xda,0x89,0x5e,0x08,0x89,0x7e,0x0c,0x0f,0xb7,0x84,0x46,0x88,0x15,0x00,0x00,0x8b,
    0xcb,0x83,0xf8,0x10,0x7d,0x0e,0x8b,0x6c,0x24,0x10,0x88,0x44,0x2c,0x38,0x45,0xe9,
    0x00,0x01,0x00,0x00,0x75,0x55,0x83,0xf9,0x02,0x7d,0x29,0x8b,0x6e,0x04,0x8b,0xff,
    0x8b,0x16,0x3b,0xd5,0x72,0x04,0x33,0xc0,0xeb,0x06,0x0f,0xb6,0x02,0x42,0x89,0x16,
    0xd3,0xe0,0x83,0xc1,0x08,0x8b,0xd9,0x89,0x4e,0x08,0x0b,0xf8,0x89,0x7e,0x0c,0x83,
    0xf9,0x18,0x7e,0xdc,0x8b,0x6c,0x24,0x10,0x0f,0xb6,0x54,0x2c,0x37,0x8b,0xc7,0x83,
    0xe0,0x03,0xc1,0xef,0x02,0x83,0xeb,0x02,0x83,0xc0,0x03,0x50,0x89,0x44,0x24,0x18,
    0x52,0x8d,0x44,0x2c,0x40,0x50,0xe9,0x97,0x00,0x00,0x00,0x83,0xf8,0x11,0x75,0x48,
    0x83,0xf9,0x03,0x7d,0x27,0x8b,0x6e,0x04,0x8b,0x16,0x3b,0xd5,0x72,0x04,0x33,0xc0,
    0xeb,0x06,0x0f,0xb6,0x02,0x42,0x89,0x16,0xd3,0xe0,0x83,0xc1,0x08,0x8b,0xd9,0x89,
    0x4e,0x08,0x0b,0xf8,0x89,0x7e,0x0c,0x83,0xf9,0x18,0x7e,0xdc,0x8b,0x6c,0x24,0x10,
    0x8b,0xc7,0x83,0xe0,0x07,0xc1,0xef,0x03,0x83,0xeb,0x03,0x83,0xc0,0x03,0x50,0x6a,
    0x00,0x8d,0x4c,0x2c,0x40,0x51,0xeb,0x46,0x83,0xf9,0x07,0x7d,0x27,0x8b,0x6e,0x04,
    0x8b,0x16,0x3b,0xd5,0x72,0x04,0x33,0xc0,0xeb,0x06,0x0f,0xb6,0x02,0x42,0x89,0x16,
    0xd3,0xe0,0x83,0xc1,0x08,0x8b,0xd9,0x89,0x4e,0x08,0x0b,0xf8,0x89,0x7e,0x0c,0x83,
    0xf9,0x18,0x7e,0xdc,0x8b,0x6c,0x24,0x10,0x8b,0xc7,0x83,0xe0,0x7f,0xc1,0xef,0x07,
    0x83,0xeb,0x07,0x83,0xc0,0x0b,0x50,0x6a,0x00,0x8d,0x54,0x2c,0x40,0x52,0x89,0x44,
    0x24,0x20,0x89,0x7e,0x0c,0x89,0x5e,0x08,0xe8,0x13,0xcc,0x74,0x00,0x83,0xc4,0x0c,
    0x03,0x6c,0x24,0x14,0x89,0x6c,0x24,0x10,0x3b,0x6c,0x24,0x20,0x0f,0x8c,0xce,0xfd,
    0xff,0xff,0x8b,0x7c,0x24,0x1c,0x57,0x8d,0x44,0x24,0x3c,0x50,0x8d,0x4e,0x1c,0x51,
    0xe8,0x0b,0xf7,0xff,0xff,0x83,0xc4,0x0c,0x85,0xc0,0x0f,0x84,0x80,0xfd,0xff,0xff,
    0x8b,0x54,0x24,0x18,0x52,0x8d,0x44,0x3c,0x3c,0x50,0x81,0xc6,0x00,0x08,0x00,0x00,
    0x56,0xe8,0xea,0xf6,0xff,0xff,0x83,0xc4,0x0c,0xf7,0xd8,0x1b,0xc0,0xf7,0xd8,0x8b,
    0x8c,0x24,0x00,0x02,0x00,0x00,0x5f,0x5e,0x5d,0x5b,0x33,0xcc,0xe8,0xf3,0xc3,0x74,
    0x00,0x81,0xc4,0xf4,0x01,0x00,0x00,0xc3,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,
    0x53,0x56,0x8b,0x74,0x24,0x0c,0x8b,0x46,0x08,0x57,0x8b,0xf8,0x83,0xe7,0x07,0x74,
    0x13,0x3b,0xc7,0x7d,0x07,0x8b,0xd6,0xe8,0x94,0xf8,0xff,0xff,0x8b,0xcf,0xd3,0x6e,
    0x0c,0x29,0x7e,0x08,0x8b,0x4e,0x08,0x33,0xff,0x85,0xc9,0x7e,0x22,0x8b,0x46,0x0c,
    0x8a,0x56,0x0c,0x83,0xe9,0x08,0x88,0x54,0x3c,0x10,0xc1,0xe8,0x08,0x8b,0xd9,0x47,
    0x89,0x46,0x0c,0x85,0xdb,0x7f,0xe9,0x89,0x5e,0x08,0x83,0xff,0x02,0x7d,0x1d,0x8b,
    0x56,0x04,0x8b,0x06,0x3b,0xc2,0x72,0x04,0x33,0xc9,0xeb,0x06,0x0f,0xb6,0x08,0x40,
    0x89,0x06,0x88,0x4c,0x3c,0x10,0x47,0x83,0xff,0x02,0x7c,0xe6,0x8b,0x44,0x24,0x10,
    0x0f,0xb6,0xdc,0x0f,0xb6,0xc0,0xc1,0xe3,0x08,0x03,0xd8,0x83,0xff,0x02,0x7e,0x24,
    0x8b,0x46,0x10,0x8d,0x4f,0xfe,0x51,0x8d,0x54,0x24,0x16,0x52,0x50,0xe8,0x9e,0xc7,
    0x74,0x00,0xba,0x02,0x00,0x00,0x00,0x8d,0x4f,0xfe,0x01,0x4e,0x10,0x2b,0xd7,0x83,
    0xc4,0x0c,0x03,0xda,0x8b,0x06,0x8d,0x0c,0x18,0x3b,0x4e,0x04,0x76,0x06,0x5f,0x5e,
    0x33,0xc0,0x5b,0xc3,0x8b,0x56,0x10,0x53,0x50,0x52,0xe8,0x71,0xc7,0x74,0x00,0x01,
    0x1e,0x01,0x5e,0x10,0x83,0xc4,0x0c,0x5f,0x5e,0xb8,0x01,0x00,0x00,0x00,0x5b,0xc3,
    0x68,0x90,0x00,0x00,0x00,0x6a,0x08,0x68,0x00,0x1f,0x3b,0x01,0xe8,0xbf,0xca,0x74,
    0x00,0x6a,0x70,0x6a,0x09,0x68,0x90,0x1f,0x3b,0x01,0xe8,0xb1,0xca,0x74,0x00,0xb8,
    0x07,0x07,0x07,0x07,0xa3,0x00,0x20,0x3b,0x01,0xa3,0x04,0x20,0x3b,0x01,0xa3,0x08,
    0x20,0x3b,0x01,0xa3,0x0c,0x20,0x3b,0x01,0xa3,0x10,0x20,0x3b,0x01,0xa3,0x14,0x20,
    0x3b,0x01,0xb8,0x08,0x08,0x08,0x08,0xa3,0x18,0x20,0x3b,0x01,0xa3,0x1c,0x20,0x3b,
    0x01,0xb8,0x05,0x05,0x05,0x05,0x83,0xc4,0x18,0xa3,0x20,0x2e,0x3b,0x01,0xa3,0x24,
    0x2e,0x3b,0x01,0xa3,0x28,0x2e,0x3b,0x01,0xa3,0x2c,0x2e,0x3b,0x01,0xa3,0x30,0x2e,
    0x3b,0x01,0xa3,0x34,0x2e,0x3b,0x01,0xa3,0x38,0x2e,0x3b,0x01,0xa3,0x3c,0x2e,0x3b,
    0x01,0xc3,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,
    0x53,0x55,0x56,0x8b,0x74,0x24,0x10,0x33,0xc0,0x57,0x89,0x46,0x08,0x89,0x46,0x0c,
    0x8b,0x4e,0x08,0x83,0xf9,0x01,0x7d,0x2a,0x8b,0x5e,0x04,0x8b,0x7e,0x0c,0x8b,0xff,
    0x8b,0x16,0x3b,0xd3,0x72,0x04,0x33,0xc0,0xeb,0x06,0x0f,0xb6,0x02,0x42,0x89,0x16,
    0xd3,0xe0,0x83,0xc1,0x08,0x89,0x4e,0x08,0x0b,0xf8,0x89,0x7e,0x0c,0x83,0xf9,0x18,
    0x7e,0xde,0x8b,0x46,0x0c,0xff,0x4e,0x08,0x8b,0x4e,0x08,0x8b,0xd8,0xd1,0xe8,0x83,
    0xe3,0x01,0x89,0x46,0x0c,0x83,0xf9,0x02,0x7d,0x28,0x8b,0x6e,0x04,0x8b,0xf8,0x90,
    0x8b,0x16,0x3b,0xd5,0x72,0x04,0x33,0xc0,0xeb,0x06,0x0f,0xb6,0x02,0x42,0x89,0x16,
    0xd3,0xe0,0x83,0xc1,0x08,0x89,0x4e,0x08,0x0b,0xf8,0x89,0x7e,0x0c,0x83,0xf9,0x18,
    0x7e,0xde,0x8b,0x46,0x0c,0x83,0x46,0x08,0xfe,0x8b,0xc8,0x83,0xe1,0x03,0xc1,0xe8,
    0x02,0x89,0x46,0x0c,0x83,0xf9,0x02,0x75,0x08,0x56,0xe8,0x01,0xfe,0xff,0xff,0xeb,
    0x58,0x83,0xf9,0x01,0x75,0x40,0x80,0x3d,0x3f,0x2e,0x3b,0x01,0x00,0x75,0x05,0xe8,
    0xbc,0xfe,0xff,0xff,0x68,0x20,0x01,0x00,0x00,0x8d,0x46,0x1c,0x68,0x00,0x1f,0x3b,
    0x01,0x50,0xe8,0x99,0xf4,0xff,0xff,0x83,0xc4,0x0c,0x85,0xc0,0x74,0x44,0x6a,0x20,
    0x8d,0x8e,0x00,0x08,0x00,0x00,0x68,0x20,0x2e,0x3b,0x01,0x51,0xe8,0x7f,0xf4,0xff,
    0xff,0x83,0xc4,0x0c,0xeb,0x09,0x56,0xe8,0xd4,0xf9,0xff,0xff,0x83,0xc4,0x04,0x85,
    0xc0,0x74,0x1f,0x56,0xe8,0x97,0xf6,0xff,0xff,0x83,0xc4,0x04,0x85,0xc0,0x74,0x12,
    0x85,0xdb,0x0f,0x84,0x08,0xff,0xff,0xff,0x5f,0x5e,0x5d,0xb8,0x01,0x00,0x00,0x00,
    0x5b,0xc3,0x5f,0x5e,0x5d,0x33,0xc0,0x5b,0xc3,/*INT3*/ 0xcc };



int (__cdecl *undflt_func)(void *ctx) = NULL;



// anti DEP limitation, allocation is necessary
void *undflt_alloc(void *dump, int dumpsz) {
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



static void __cdecl *undflt_memcpy(unsigned char *ptr, unsigned char *src, int num) {
    return(memmove(ptr, src, num)); // better than memcpy
}



static void __cdecl *undflt_memset(void *ptr, int value, int num) {
    return(memset(ptr, value, num));
}



void undflt_init(void) {
    static void *undflt_func_bck = NULL;

    if(undflt_func) return;

    undflt_func = undflt_alloc(undflt_dump, sizeof(undflt_dump));
    undflt_func_bck = undflt_func;

    #define PATCHIT(X,Y) *(int *)((char *)undflt_func + X) = (int)(Y);
    PATCHIT(0x00000007, undflt_013a1e60             ) // mov eax, dword ptr [13A1E60]
    PATCHIT(0x00000369, undflt_00e01df4 + 0x00000000) // mov eax, dword ptr [ebx*4+E01DF4]
    PATCHIT(0x00000370, undflt_00e01df4 + 0x00000080) // mov ebx, dword ptr [ebx*4+E01E74]
    PATCHIT(0x000004c8, undflt_01205378             ) // mov ebp, dword ptr [esi*4+1205378]
    PATCHIT(0x000004cf, undflt_00e01df4 + 0x00000504) // mov eax, dword ptr [esi*4+E022F8]
    PATCHIT(0x00000567, undflt_013a1e60             ) // mov eax, dword ptr [13A1E60]
    PATCHIT(0x00000656, undflt_00e01df4 + 0x000003ec) // movzx edi, byte ptr [ebx+E021E0]
    PATCHIT(0x00000a18, undflt_013b1f00             ) // push 13B1F00
    PATCHIT(0x00000a26, undflt_013b1f00 + 0x90      ) // push 13B1F90
    PATCHIT(0x00000a35, undflt_013b2000 + 0x00      ) // mov dword ptr [13B2000], eax
    PATCHIT(0x00000a3a, undflt_013b2000 + 0x04      ) // mov dword ptr [13B2004], eax
    PATCHIT(0x00000a3f, undflt_013b2000 + 0x08      ) // mov dword ptr [13B2008], eax
    PATCHIT(0x00000a44, undflt_013b2000 + 0x0c      ) // mov dword ptr [13B200C], eax
    PATCHIT(0x00000a49, undflt_013b2000 + 0x10      ) // mov dword ptr [13B2010], eax
    PATCHIT(0x00000a4e, undflt_013b2000 + 0x14      ) // mov dword ptr [13B2014], eax
    PATCHIT(0x00000a58, undflt_013b2000 + 0x18      ) // mov dword ptr [13B2018], eax
    PATCHIT(0x00000a5d, undflt_013b2000 + 0x1c      ) // mov dword ptr [13B201C], eax
    PATCHIT(0x00000a6a, undflt_013b2e20 + 0x00      ) // mov dword ptr [13B2E20], eax
    PATCHIT(0x00000a6f, undflt_013b2e20 + 0x04      ) // mov dword ptr [13B2E24], eax
    PATCHIT(0x00000a74, undflt_013b2e20 + 0x08      ) // mov dword ptr [13B2E28], eax
    PATCHIT(0x00000a79, undflt_013b2e20 + 0x0c      ) // mov dword ptr [13B2E2C], eax
    PATCHIT(0x00000a7e, undflt_013b2e20 + 0x10      ) // mov dword ptr [13B2E30], eax
    PATCHIT(0x00000a83, undflt_013b2e20 + 0x14      ) // mov dword ptr [13B2E34], eax
    PATCHIT(0x00000a88, undflt_013b2e20 + 0x18      ) // mov dword ptr [13B2E38], eax
    PATCHIT(0x00000a8d, undflt_013b2e20 + 0x1c      ) // mov dword ptr [13B2E3C], eax
    PATCHIT(0x00000b48, undflt_013b2e20 + 0x1f      ) // cmp byte ptr [13B2E3F], 0
    PATCHIT(0x00000b5d, undflt_013b1f00             ) // push 13B1F00
    PATCHIT(0x00000b77, undflt_013b2e20             ) // push 13B2E20
    #undef PATCHIT

    #define PATCHIT_FUNC(X,Y)   *(int *)((char *)undflt_func + X + 1) = (void *)Y - (void *)((char *)undflt_func + X + 1 + 4);
    memset(undflt_func + 0x1de, 0x90, 5);
    memset(undflt_func + 0x92c, 0x90, 5);
    PATCHIT_FUNC(0x0000003c, undflt_memset)
    PATCHIT_FUNC(0x0000004c, undflt_memset)
    PATCHIT_FUNC(0x000008c8, undflt_memset)
    PATCHIT_FUNC(0x00000a1c, undflt_memset)
    PATCHIT_FUNC(0x00000a2a, undflt_memset)
    PATCHIT_FUNC(0x000009cd, undflt_memcpy)
    PATCHIT_FUNC(0x000009fa, undflt_memcpy)
    #undef PATCHIT_FUNC

    undflt_func = (void *)((char *)undflt_func_bck + 0xaa0);
}



int undflt(unsigned char *in, int insz, unsigned char *out, int outsz) {
    typedef struct {
        void    *input;
        void    *input_end;
        int     dummy1;
        int     dummy2;
        void    *ptr;
        void    *output;
        void    *output_end;
        char    data[0x17c8];   // 0x17ac
    } undflt_ctx_t;
    undflt_ctx_t    *ctx;
    int     ret;

    undflt_init();

    ctx = calloc(sizeof(undflt_ctx_t), 1);
    if(!ctx) return(-1);

    ctx->input      = in;
    ctx->input_end  = in + insz;
    ctx->ptr        = out;
    ctx->output     = out;
    ctx->output_end = out + outsz;

    memset(undflt_013a1e60, 0, sizeof(undflt_013a1e60));
    memset(undflt_013b1f00, 0, sizeof(undflt_013b1f00));
    memset(undflt_013b2000, 0, sizeof(undflt_013b2000));
    memset(undflt_013b2e20, 0, sizeof(undflt_013b2e20));
    
    ret = undflt_func(ctx);

    free(ctx);

    if(!ret) return(-1);
    return(outsz);
}


