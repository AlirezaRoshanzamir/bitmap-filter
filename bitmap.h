#ifndef BITMAP_H
#define BITMAP_H

// Constant definitions
#define SIZE_OFFSET 2
#define PIXELS_OFFSET_OFFSET 10
#define WIDTH_OFFSET 18
#define HEIGHT_OFFSET 22
#define ROW_SIZE_OFFSET 34

#define HEADER_BYTE_SIZE 14
#define DIB_HEADER_BYTE_SIZE 40
#define WIDTH_BYTE_SIZE 4
#define HEIGHT_BYTE_SIZE 4
#define SIZE_BYTE_SIZE 4
#define PIXELS_OFFSET_BYTE_SIZE 4
#define ROW_SIZE_SIZE 4

#define ROW_REMAINING 4


// Includes
#include <vector>


// Type definitions
typedef std::vector<char> Bytes;

struct Bitmap
{
	int file_size;
	int width;
	int height;
	int pixels_offset;
    int end_line_zeros;
	Bytes raw_data;
};

struct Color
{
    int red;
    int green;
    int blue;
};


// Function declarations
Bitmap read_bitmap_from_stdin();
void write_bitmap_to_stdout(const Bitmap& bitmap);

int extract_int_from_bytes(const Bytes& bytes, int offset, int size);
Color extract_color_from_bytes(const Bytes& bytes, int offset);
void copy_bitmap(const Bitmap& source, Bitmap& destination);
void set_pixel(Bitmap& bitmap, int row, int column, Color color);
Color get_pixel(const Bitmap& bitmap, int row, int column);
int find_pixel_offset(const Bitmap& bitmap, int row, int column);

int char2uint(char input);
char uint2char(int input);


#endif
