#pragma once
typedef unsigned short ushort;
struct Color
{
	unsigned short red;
	unsigned short green;
	unsigned short blue;
	unsigned short alpha;

	Color(unsigned short r, ushort g, ushort b, ushort a)
	{
		red = r;
		green = g;
		blue = b;
		alpha = a;
	}
};