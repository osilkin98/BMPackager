#ifndef BINARY_BMP_WRAPPER_H
#define BINARY_BMP_WRAPPER_H


#include <stdint.h> /* uses universal definitions of fixed length variables */
#include <stdio.h> /* includes the definition of the FILE struct */



#define FOUR_BYTES uint32_t /* for 4-Byte long descriptors */
#define TWO_BYTES uint16_t  /* for 2-Byte long descriptors */
#define ONE_BYTE uint8_t    /* for 1-Byte long descriptors */


/* struct to contain the headers for the bitmap */
typedef struct {

  /* this is the only variable which will actually differ */
  FOUR_BYTES file_size;

  /* since signature is known, it can be set here  */
  const ONE_BYTE signature[2];
  /* the reservation will ALWAYS be 0 */
  const FOUR_BYTES reserved;

  /* the offset for the data will be the sum 
     of the size of both headers in bytes */
  const FOUR_BYTES data_offset;
} BMapHeader;


/* this is the meta-data header, which defines values necessary
   to be rendered correctly as a BMP file. 
*/
typedef struct  {
  /* this is the total size, in bytes, */
  const FOUR_BYTES size;

  /* we're only using one plane, I'm fairly sure that you cannot use 
     more than one, though I might be wrong. */
  const TWO_BYTES planes;

    
  FOUR_BYTES width;   /* horizontal length of bitmap image in pixels */
  FOUR_BYTES height;  /* vertical length of bitmap image in pixels */

  /* must be either 8, 16 or 24. This determines numColors */
  TWO_BYTES bits_per_pixel;

  FOUR_BYTES num_colors;

  /* this is a list of values which all appear as 4-byte long constants 
     set to 0, as they are never actually needed. Some of these may be changed,
     however when doing so, you must remove them from this list and put them 
     into their own FOUR_BYTES container. 
  */
  const FOUR_BYTES zero_constants[6];
    
    
  /* the compression is something that is assumed to be 0, 
   * however I'm unsure if compression would corrupt the executable 
   * being transported by the bitmap image
   */
} BMapInfoHeader;


/* color table is not something that will be included, as the number
   of bits per pixels will ALWAYS be greater than or equal to 8.
*/

typedef struct {
  
  BMapHeader main_header;       /* This is the main header that we'll also need to write */
  
  BMapInfoHeader header_info;   /* This is the header information about the file */
  
  FILE *binary_file;            /* This is what we want to encode */

  char *fname;                  /* The name of the file we want to be saving the "image" as */
} BitmapImage;



BitmapImage *create_bitmap_image(const char *in_fname, const char *out_fname);

int write_bitmap_image(BitmapImage *data);


/* Returns a non-zero integer as an error code */
int encode_binary_as_image(const char *input_fname, const char *output_fname);


#endif
