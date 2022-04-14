#include "bitmap.h"
#include "filter.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    Bitmap input = read_bitmap_from_stdin();
    Bitmap output;

    if(argv[1][0] == '1')
        output = make_gray(input);
    else if(argv[1][0]=='2')
        output = horizontal_flip(input);

    write_bitmap_to_stdout(output);

    return 0;
}