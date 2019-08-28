# Questions

## What's `stdint.h`?
For you to be able to import different sizes of integer variables

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?
Since some integer variables has its maximum value such as the rgb triplet, those three can only contain values upto 255 so it is just logical to use just unint8_t/unsigned int 8 bits.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?
a BYTE is 1 byte, a DWORD is 4 bytes, a LONG is 4 bytes, a WORD is 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."
B and M

##  What’s the difference between bfSize and biSize?
bfSize (is a member (field) of the BITMAPFILEHEADER structure (struct) which contains information about the type, size, and layout of a file that contains a DIB) represents the size, in bytes, of the bitmap file.
biSize (is a member (field) of the BITMAPINFOHEADER structure (struct) which contains information about the dimensions and color format of a DIB) represents the number of bytes required by the structure.

## What does it mean if biHeight is negative?
If biHeight is negative, it means that the bitmap is a top-down DIB and its origin is the upper-left corner.

##  What field in BITMAPINFOHEADER specifies the BMP’s color depth (i.e., bits per pixel)?
biBitCount specifies the number of bits-per-pixel. The biBitCount member of the BITMAPINFOHEADER structure 
determines the number of bits that define each pixel and the maximum number of colors in the bitmap. 

## Why might fopen return NULL in lines 24 and 32 of copy.c?
Fopen is supposed to return a file pointer for the new file. We check if it is not equal to NULL to make sure 
we get legitimate pointer back. Reasons why fopen might return NULL (not limited to):
- the file doesn't exist;
- the file is opened in a mode that doesn't allow other accesses;
- the network is down;
- the file exists, but you don't have permissions;
- fopen cannot return legitimate pointer back.

##  Why is the third argument to fread always 1 in our code?
Argument 1 in fread function means that fread will read one element from a given file, namely 
reads infile's BITMAPFILEHEADER, infile's BITMAPINFOHEADER, RGB triple from infile.

## What value does line 65 of copy.c assign to padding if bi.biWidth is 3?
 int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
 (4-(3*3(RGBTRIPLE equals 3 bytes)%4)%4=3. so int paddling is equals 3. 
 If the width is 3, padding is necessary since the scanline must be a multiple of 4.
 3 bytes are added to bring the scanline to 12 bytes. 
 (3 pixels) × (3 bytes per pixel) + (3 bytes of padding) = 12 bytes, which is indeed a multiple of 4.

## What does fseek do?
Fseek allows to remind or fast-forward within a file (changes the location of the file pointer).
In copy.c fseek skips over padding, if any, and looks for the next pixel.

## What is SEEK_CUR?
This is an integer constant which, when used as the whence argument to the fseek function, specifies that the padding provided is relative to the current file position. SEEK_CUR moves file pointer position to given location.(The value of whence must be one of the constants SEEK_SET, SEEK_CUR, or SEEK_END, to indicate whether the offset is relative to the beginning of the file, the current file position, or the end of the file, respectively.)  
(Function: int fseek (FILE *stream, long int offset, int whence).