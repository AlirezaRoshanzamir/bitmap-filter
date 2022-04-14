#include "bitmap.h"
#include <iostream>
#include <cmath>


using std::cin;
using std::cout;
using std::pow;


Bitmap read_bitmap_from_stdin()
{
    Bitmap bitmap;

	char temp_char;
	while(cin.get(temp_char))
		bitmap.raw_data.push_back(temp_char);

    bitmap.width = extract_int_from_bytes(bitmap.raw_data, WIDTH_OFFSET, WIDTH_BYTE_SIZE);
    bitmap.height = extract_int_from_bytes(bitmap.raw_data, HEIGHT_OFFSET, HEIGHT_BYTE_SIZE);
    bitmap.pixels_offset = extract_int_from_bytes(bitmap.raw_data, PIXELS_OFFSET_OFFSET, PIXELS_OFFSET_BYTE_SIZE);
    bitmap.file_size = extract_int_from_bytes(bitmap.raw_data, SIZE_OFFSET, SIZE_BYTE_SIZE);

    if(bitmap.width % ROW_REMAINING == 0)
        bitmap.end_line_zeros = 0;
    else
        bitmap.end_line_zeros = ROW_REMAINING - (bitmap.width % ROW_REMAINING);

	return bitmap;
}

void write_bitmap_to_stdout(const Bitmap& bitmap)
{
    for(int i = 0; i < bitmap.raw_data.size(); ++i)
        cout.put(bitmap.raw_data[i]);
}

Color get_pixel(const Bitmap& bitmap, int row, int column)
{
    int pixel_offset = find_pixel_offset(bitmap, row, column);

    Color color;
    color.red = char2uint(bitmap.raw_data[pixel_offset]);
    color.green = char2uint(bitmap.raw_data[pixel_offset + 1]);
    color.blue = char2uint(bitmap.raw_data[pixel_offset + 2]);

    return color;
}

void set_pixel(Bitmap& bitmap, int row, int column, Color color)
{
    int pixel_offset = find_pixel_offset(bitmap, row, column);

    bitmap.raw_data[pixel_offset]   = uint2char(color.red);
    bitmap.raw_data[pixel_offset + 1] = uint2char(color.green);
    bitmap.raw_data[pixel_offset + 2] = uint2char(color.blue);
}

int find_pixel_offset(const Bitmap& bitmap, int row, int column)
{
    return bitmap.pixels_offset + (bitmap.height - row - 1) * (bitmap.width * 3 + bitmap.end_line_zeros) + 3 * column;
}

void copy_bitmap(const Bitmap& source, Bitmap& destination)
{
    destination.file_size = source.file_size;
    destination.width = source.width;
    destination.height = source.height;
    destination.pixels_offset = source.pixels_offset;
    destination.end_line_zeros = source.end_line_zeros;
    destination.raw_data = source.raw_data;
}

int extract_int_from_bytes(const Bytes& bytes, int offset, int size)
{
	int result = 0;
	for (int i = 0; i < size; ++i)
        result += char2uint(bytes[offset + i]) * (int) pow(256, i);
	return result;
}



int char2uint(char input)
{
    if (int(input) < 0)
	    return 256 + (int) input;
	else
		return (int) input;
}

char uint2char(int input)
{
    if(input <= 127)
        return (char) input;
    else
        return (char) (input - 256);
}
