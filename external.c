#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.1416
#define abs(x) (x > 0 ? x : -x)

// Module
double m = 3;

// Number of teeth External
double ze = 16;

// Number of teeth Internal
double zi = 24;

// Pressure Angle
double a = 20 * PI / 180;

// Coefficient of Profile Shift
double xe = 0;
double xi = 0.5;

double fnd(double iv, double f, double t, double step)
{
	double i;
	if (iv == (tan(f) - f))
	{
		return f + step;
	}
	for (i = f; i < t; i += step)
	{
		if ((iv - (tan(i) - i)) * (iv - (tan(i - step) - i + step)) < 0)
		{
			return fnd(iv, i - step, i, step / 2);
		}
	}
	return f;
}

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
		else if (strcmp(argv[i], "-ze") == 0)
		{
			ze = strtod(argv[i + 1], &eptr);
			if (ze < 0)
			{
				printf("arg ze must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-zi") == 0)
		{
			zi = strtod(argv[i + 1], &eptr);
			if (zi < 0)
			{
				printf("arg zi must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-xe") == 0)
		{
			xe = strtod(argv[i + 1], &eptr);
			if (xe < 0)
			{
				printf("arg xe must be a positive number.\n");
			}
		}

		else if (strcmp(argv[i], "-xi") == 0)
		{
			xi = strtod(argv[i + 1], &eptr);
			if (xi < 0)
			{
				printf("arg xi must be a positive number.\n");
			}
		}
	}

	printf("Usage: ./external -m %f -a %f -ze %f -zi %f -xe %f -xi %f\n", m, a, ze, zi, xe, xi);
	printf("\t-m \tModule\n");
	printf("\t-a \tPressure Angle\n");
	printf("\t-ze \tNumber of teeth-External\n");
	printf("\t-zi \tNumber of teeth-Internal\n");
	printf("\t-xe \tCoefficient of Profile Shift-External\n");
	printf("\t-xi \tCoefficient of Profile Shift-Internal\n\n");

	printf("\n--------------------------\t\t External \t Internal \n");
	printf("Module: \t\t\t\t%f\n", m);
	printf("Number of teeth: \t\t\t%f\t%f\n", ze, zi);
	printf("Pressure Angle: \t\t\t%f\n", a * 180 / PI);
	printf("Coefficient of Profile Shift: \t\t%f\t%f\n", xe, xi);

	// Involute function
	double invaw = 2 * tan(a) * ((xe + xi) / (ze + zi)) + tan(a) - a;

	printf("Involute function: \t\t\t%f\n", invaw);

	// Working Pressure Angle
	double aw = fnd(invaw, PI / 180, PI, PI / 180);

	printf("Working Pressure Angle: \t\t%f\n", aw * 180 / PI);

	// Center Distance Increment Factor
	double y = ((zi + ze) / 2) * ((cos(a) / cos(aw)) - 1);

	printf("Center Distance Increment Factor: \t%f\n", y);

	// Center Distance
	double ax = (((zi + ze) / 2) + y) * m;

	printf("Center Distance: \t\t\t%f\n", ax);

	// Pitch Diameter
	double de = ze * m;
	double di = zi * m;

	printf("Pitch Diameter: \t\t\t%f\t%f\n", de, di);

	// Base Diameter
	double dbe = de * cos(a);
	double dbi = di * cos(a);

	printf("Base Diameter: \t\t\t\t%f\t%f\n", dbe, dbi);

	// Working Pitch Diameter
	double dwe = dbe / cos(aw);
	double dwi = dbi / cos(aw);

	printf("Working Pitch Diameter: \t\t%f\t%f\n", dwe, dwi);

	// Addendum
	double hae = (1 + y - xe) * m;
	double hai = (1 + y - xi) * m;

	printf("Addendum: \t\t\t\t%f\t%f\n", hae, hai);

	// Whole Depth
	double h = (2.25 + y - (xe + xi)) * m;

	printf("Whole Depth: \t\t\t\t%f\n", h);

	// Dedendum
	double hde = h - hae;
	double hdi = h - hai;

	printf("Dedendum: \t\t\t\t%f\t%f\n", hde, hdi);

	// Working Depth
	double hw = 2 * m;

	printf("Working Depth: \t\t\t\t%f\n", hw);

	// Outside Diameter
	double dte = de + 2 * hae;
	double dti = di - 2 * hai;

	printf("Outside Diameter: \t\t\t%f\t%f\n", dte, dti);

	// Root Diameter
	double dre = dte - 2 * h;
	double dri = dti + 2 * h;

	printf("Root Diameter: \t\t\t\t%f\t%f\n", dre, dri);

	// Top Clearance
	double c = 0.25 * m;

	printf("Top Clearance: \t\t\t\t%f\n", c);

	// Circular Pitch
	double p = m * PI;

	printf("Circular Pitch: \t\t\t%f\n", p);

	// Pitch Prependicular to Tooth
	double pn = p * cos(aw);

	printf("Pitch Prependicular to Tooth: \t\t%f\n", pn);

	// Base Pitch
	double pb = m * PI * cos(aw);

	printf("Base Pitch: \t\t\t\t%f\n", pb);

	// Tooth Thickness at Standard pitch Diameter
	double Tsid = (PI / 2) * m;

	printf("Tooth Thickness at Standard pitch Diameter: \t%f\n", Tsid);

	// Contact Ratio

	// Backlash

	//Min No of Teeth for Undercutting
	double zc = 4 / (1 - cos(2 * aw));

	printf("Min No of Teeth for Undercutting: \t%f\n", zc);
}
