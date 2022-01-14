#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.1416

double m = 3;
double a = 20 * PI / 180;
double z = 12;
double x = 0.6;
double H = 32;
double aw = 20 * PI / 180;

int main(int argc, char *argv[])
{
	char *eptr;
	int i;
	for (i = 1; i < argc; i += 2)
	{
		if (strcmp(argv[i], "-m") == 0)
		{
			m = strtod(argv[i + 1], &eptr);
			if (m < 0)
			{
				printf("arg m must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-a") == 0)
		{
			a = strtod(argv[i + 1], &eptr) * PI / 180;
			if (a < 0)
			{
				printf("arg a must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-z") == 0)
		{
			z = strtod(argv[i + 1], &eptr);
			if (z < 0)
			{
				printf("arg z must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-x") == 0)
		{
			x = strtod(argv[i + 1], &eptr);
			if (x < 0)
			{
				printf("arg x must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-H") == 0)
		{
			H = strtod(argv[i + 1], &eptr);
			if (H < 0)
			{
				printf("arg H must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-aw") == 0)
		{
			aw = strtod(argv[i + 1], &eptr) * PI / 180;
			if (aw < 0)
			{
				printf("arg aw must be a positive number.\n");
			}
		}
	}

	printf("Usage: ./rack -m %f -a %f -z %f -x %f -H %f -aw %f \n", m, a, z, x, H, aw);
	printf("\t-m \tModule\n");
	printf("\t-a \tPressure Angle\n");
	printf("\t-z \tNumber of teeth\n");
	printf("\t-H \tHeight of Pitch Line\n");
	printf("\t-x \tCoefficient of Profile Shift\n");
	printf("\t-aw \tWorking Pressure Angle\n\n");

	double ax = (z * m / 2) + H + x * m;
	double d = z * m;
	double db = d * cos(a);
	double dw = db / cos(aw);
	double hag = m * (1 + x);
	double har = m;
	double h = 2.25 * m;
	double da = d + 2 * hag;
	double df = da - 2 * h;

	printf("\n--------------------- \t\t\tSpur Gear\tRack\n");
	printf("Module: \t\t\t\t%f\n", m);
	printf("Pressure Angle: \t\t\t%f\n", a);
	printf("Number of Teeth: \t\t\t%f\n", z);
	printf("Coefficient of Profile Shift: \t\t%f\n", x);
	printf("Height of Pitch Line: \t\t\t%f\n", H);
	printf("Working Pressure Angle: \t\t%f\n", aw);
	printf("Center Distance: \t\t\t%f\n", ax);
	printf("Pitch Diameter: \t\t\t%f\n", d);
	printf("Base Diameter: \t\t\t\t%f\n", db);
	printf("Working Pitch Diameter: \t\t%f\n", dw);
	printf("Addendum: \t\t\t\t%f\t%f\n", hag, har);
	printf("Whole Depth: \t\t\t\t%f\n", h);
	printf("Outside Diameter: \t\t\t%f\n", da);
	printf("Root Diameter: \t\t\t\t%f\n", df);
}
