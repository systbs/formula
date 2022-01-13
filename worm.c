#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char isnum(char *text)
{
	int j;
	j = strlen(text);
	while (j--)
	{
		if (text[j] >= '0' && text[j] <= '9')
			continue;

		return 0;
	}
	return 1;
}

//Input Parameters
#define PI 3.1416
#define min(a, b) (a < b ? a : b)

// number of thread of worm
double zw = 2;
// number of teeth in worm gear
double zg = 30;
// module
double mx = 3;
// normal pressure angle
double an = 20 * PI / 180;

// Diameter of Worm
double d = 44;

// Coefficient of Profile Shift
double cps = 0;

// Coefficient of Clearance
double cclr = 0.25;

int main(int argc, char *argv[])
{
	char *eptr;
	int i;
	for (i = 1; i < argc; i += 2)
	{
		if (!isnum(argv[i + 1]))
		{
			printf("%s must be a number.\n", argv[i]);
			printf("Usage: ./worm -zw %f -zg %f -mx %f -an %f -dw %f -cps %s -clr %f\n", zw, zg, mx, an, d, cps, cclr);
			printf("-zw \tNo. of Threads\n");
			printf("-zg \tNo. of Teeth\n");
			printf("-mx \tModule\n");
			printf("-an \tNormal Pressure Angle\n");
			printf("-dw \tDiameter of Worm\n");
			printf("-cps \tCoefficient of Profile Shift\n");
			printf("-clr \tCoefficient of Clearance\n");
		}

		if (strcmp(argv[i], "-zw") == 0)
		{
			zw = strtod(argv[i + 1], &eptr);
			if (zw < 0)
			{
				printf("arg zw must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-zg") == 0)
		{
			zg = strtod(argv[i + 1], &eptr);
			if (zw < 0)
			{
				printf("arg zg must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-mx") == 0)
		{
			mx = strtod(argv[i + 1], &eptr);
			if (zw < 0)
			{
				printf("arg mx must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-an") == 0)
		{
			an = strtod(argv[i + 1], &eptr) * PI / 180;
			if (zw < 0)
			{
				printf("arg an must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-dw") == 0)
		{
			d = strtod(argv[i + 1], &eptr);
			if (d < 0)
			{
				printf("arg dw must be a positive number.\n");
			}
		}
	}

	printf("Usage: ./worm -zw %f -zg %f -mx %f -an %f -dw %f\n", zw, zg, mx, an, d);
	printf("\t-zw \tNo. of Threads\n");
	printf("\t-zg \tNo. of Teeth\n");
	printf("\t-mx \tModule\n");
	printf("\t-an \tNormal Pressure Angle\n");
	printf("\t-dw \tDiameter of Worm\n");
	printf("\t-cps \tCoefficient of Profile Shift\n");
	printf("\t-clr \tCoefficient of Clearance\n\n\n");

	// Lead angle
	double g = atan(mx * zw / d);

	// Lead Worm
	double Lw = PI * mx * zw;

	// Normal Module
	double mn = mx * cos(g);

	// Radial Module
	double mt = mn / sin(g);

	// Normal Pitch
	double pn = PI * mn;

	// Axial Pitch
	double px = PI * mx;

	// Radial Pitch
	double pt = PI * mt;

	// Axial Pressure Angle
	double ax = atan(tan(an) / cos(g));

	// Radial Pressure Angle
	double at = atan(tan(an) / sin(g));

	// Pitch diameter of worm
	double dw = zw * pn / (PI * sin(g));

	// Pitch diameter of worm gear
	double dg = zg * pn / (PI * cos(g));

	//  Diameter Factor
	double Q = dw / mx;

	// The length of worm with teeth
	double b = PI * mx * (4.5 + 0.02 * zg);

	// Working blank width of worm gear
	double be = 2 * mx * sqrt(Q + 1);

	// Working Depth
	double hwx = 2 * mx;

	// Normal Working Depth
	double hwn = 2 * mn;

	// Radial Working Depth
	double hwt = 2 * mt;

	// Top Clearance
	double cx = cclr * mx;

	// Normal Clearance
	double cn = cclr * mn;

	// Radial Clearance
	double ct = cclr * mt;

	// Axial Surface

	// Center distance
	double cax = ((dw + dg) / 2) + (cps * mx);
	// Addendum Worm
	double adwx = 1 * mx;
	// Deddendum Gear
	double adgx = (1 + cps) * mx;
	// Whole Depth
	double wdx = 2.25 * mx;
	// Outside Diameter Worm
	double odwx = dw + (2 * adwx);
	// Outside Diameter Gear
	double odgx = dg + (2 * adgx) + mx;
	// Throat Diameter
	double tdx = dw + (2 * adgx);
	// Throat Surface Radius
	double trx = (dw / 2) - adwx;
	// Root Diameter Worm
	double rdwx = odwx - (2 * wdx);
	// Root Diameter Gear
	double rdgx = tdx - (2 * wdx);

	// Normal Surface
	// Center distance
	double can = ((dw + dg) / 2) + (cps * mn);
	double dgn = zg * mn / cos(g);
	double adwn = mn;
	double adgn = (1 + cps) * mn;
	double wdn = 2.25 * mn;
	double odwn = dw + (2 * adwn);
	double odgn = dg + (2 * adgn) + mn;
	double tdn = dw + (2 * adgn);
	double trn = (dw / 2) - adwn;
	double rdwn = odwn - (2 * wdn);
	double rdgn = tdn - (2 * wdn);

	// Radial Surface
	// Center distance
	double cat = ((dw + dg) / 2) + (cps * mt);
	double dgt = zg * mt * tan(g);
	double adwt = mt;
	double adgt = (1 + cps) * mt;
	double wdt = 2.25 * mt;
	double odwt = dw + (2 * adwt);
	double odgt = dg + (2 * adgt) + mt;
	double tdt = dw + (2 * adgt);
	double trt = (dw / 2) - adwt;
	double rdwt = odwt - (2 * wdt);
	double rdgt = tdt - (2 * wdt);

	printf("Diameter Factor : \t\t\t%f\n", Q);
	printf("Lead-Worm: \t\t\t\t%f\n", Lw);
	printf("Lead Angle : \t\t\t\t%f\n", g * 180 / PI);
	printf("Length of worm with teeth : \t\t%f\n", b);
	printf("Working blank width of worm gear : \t%f\n", be);
	printf("Coefficient of Clearance : \t\t%f\n", cclr);
	printf("Coefficient of Profile Shift : \t\t%f\n", cps);

	printf("\n\t\t\t\t\t Axial \t\t Normal \t Radial\n ----------------------------------------\n");

	printf("Module: \t\t\t\t %f\t%f\t%f\n", mx, mn, mt);
	printf("Pressure Angle: \t\t\t %f\t%f\t%f\n", ax * 180 / PI, an * 180 / PI, at * 180 / PI);
	printf("Pitch: \t\t\t\t\t %f\t%f\t%f\n", px, pn, pt);

	printf("Pitch Diameter-Worm : \t\t\t %f\t%f\t%f\n", dw, dw, dw);
	printf("Pitch Diameter-Gear : \t\t\t %f\t%f\t%f\n", dg, dgn, dgt);

	printf("Addendum-Worm : \t\t\t %f\t%f\t%f\n", adwx, adwn, adwt);
	printf("Addendum-Gear : \t\t\t %f\t%f\t%f\n", adgx, adgn, adgt);
	printf("Whole Depth : \t\t\t\t %f\t%f\t%f\n", wdx, wdn, wdt);
	printf("Working Depth : \t\t\t %f\t%f\t%f\n", hwx, hwn, hwt);
	printf("Top Clearance : \t\t\t %f\t%f\t%f\n", cx, cn, ct);
	printf("Outside Diameter-Worm : \t\t %f\t%f\t%f\n", odwx, odwn, odwt);
	printf("Outside Diameter-Gear : \t\t %f\t%f\t%f\n", odgx, odgn, odgt);
	printf("Throat Diameter : \t\t\t %f\t%f\t%f\n", tdx, tdn, tdt);
	printf("Throat Surface Radius : \t\t %f\t%f\n", trx, trn);
	printf("Root Diameter-Worm : \t\t\t %f\t%f\n", rdwx, rdwn);
	printf("Root Diameter-Gear : \t\t\t %f\t%f\n", rdgx, rdgn);
	printf("Center Distance: \t\t\t %f\t%f\t%f\n", cax, can, cat);
}
