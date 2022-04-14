#include "filter.h"


Bitmap make_gray(const Bitmap& input_bitmap)
{
    Bitmap output_bitmap;
    copy_bitmap(input_bitmap, output_bitmap);

    for(int i = 0; i < input_bitmap.height; ++i)
    {
        for(int j = 0; j < input_bitmap.width; ++j)
        {
           Color pixel_color = get_pixel(input_bitmap,i,j);
           int grey_value = (pixel_color.red + pixel_color.green + pixel_color.blue) / 3;
           pixel_color.blue = grey_value;
           pixel_color.red = grey_value;
           pixel_color.green = grey_value;
           set_pixel(output_bitmap, i, j, pixel_color);
        }
    }

    return output_bitmap;
}

Bitmap horizontal_flip(const Bitmap& input_bitmap)
{
    Bitmap output_bitmap;
    copy_bitmap(input_bitmap, output_bitmap);

    for(int i = 0; i < input_bitmap.height; ++i)
    {
        for(int j = 0; j < input_bitmap.width; ++j)
        {
            Color pixel_color = get_pixel(input_bitmap, i, j);
            set_pixel(output_bitmap, i, input_bitmap.width - 1 - j, pixel_color);
        }
    }

    return output_bitmap;
}
