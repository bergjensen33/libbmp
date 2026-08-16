#ifndef LIB_BMP
#define LIB_BMP
#include <stdint.h>
typedef struct bmp_header
{
    uint8_t header[2]; // "BM"
    uint32_t bmp_size;
    uint8_t reserved0[2]; // Can be zeroed
    uint8_t reserved1[2]; // Can be zeroed
    uint32_t offset;      // Offset to pixel data
} bmp_header;
// For the moment, only BITMAPINFOHEADER
typedef struct bmp_dib
{
    uint32_t header_size; // 40
    int32_t bmp_width;
    int32_t bmp_height;
    uint16_t color_planes;    // 1
    uint16_t bmp_bpp;         // Powers of 2 or 24
    uint32_t bmp_compression; // Unsupported as of now, defaults to 0 (BI_RGB)
    uint32_t bmp_rawsize;     // Size of the raw bitmap data
    int32_t bmp_ppm_x;        // Horizontal pixels per metre
    int32_t bmp_ppm_y;        // Vertical ṕixels per metre
    uint32_t bmp_n_colors;    // Number of colors in the palette, or 0 for 2^n
    uint32_t bmp_imp_colors;  // Number of important colors used, or 0 when all are important. Generally ignored
} bmp_dib;
typedef uint8_t *bmp_pixels1;
typedef uint8_t *bmp_pixels2;
typedef uint8_t *bmp_pixels4;
typedef uint8_t *bmp_pixels8;
typedef uint16_t *bmp_pixels16;
typedef uint8_t *bmp_pixels24;
typedef uint32_t *bmp_pixels32;
#endif