#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.1416
#define abs(x) (x > 0 ? x : -x)

// Module
double m = 3;

// Number of teeth Pinion
double zp = 12;

// Number of teeth Pinion
double zg = 24;

// Pressure Angle
double a = 20 * PI / 180;

// Coefficient of Profile Shift
double xp = 0.6;
double xg = 0.36;

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
		else if (strcmp(argv[i], "-zp") == 0)
		{
			zp = strtod(argv[i + 1], &eptr);
			if (zp < 0)
			{
				printf("arg zp must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-zg") == 0)
		{
			zg = strtod(argv[i + 1], &eptr);
			if (zg < 0)
			{
				printf("arg zg must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-xp") == 0)
		{
			xp = strtod(argv[i + 1], &eptr);
			if (xp < 0)
			{
				printf("arg xp must be a positive number.\n");
			}
		}

		else if (strcmp(argv[i], "-xg") == 0)
		{
			xg = strtod(argv[i + 1], &eptr);
			if (xg < 0)
			{
				printf("arg xg must be a positive number.\n");
			}
		}
	}

	printf("Usage: ./internal -m %f -a %f -zp %f -zg %f -xp %f -xg %f\n", m, a, zp, zg, xp, xg);
	printf("\t-m \tModule\n");
	printf("\t-a \tPressure Angle\n");
	printf("\t-zp \tNumber of teeth-Pinion\n");
	printf("\t-zg \tNumber of teeth-Gear\n");
	printf("\t-xp \tCoefficient of Profile Shift-Pinion\n");
	printf("\t-xg \tCoefficient of Profile Shift-Gear\n\n");

	printf("\t\t\t\t\t PINION \t GEAR \n--------------------------\n");
	printf("Module: \t\t\t\t%f\n", m);
	printf("Number of teeth: \t\t\t%f\t%f\n", zp, zg);
	printf("Pressure Angle: \t\t\t%f\n", a * 180 / PI);
	printf("Coefficient of Profile Shift: \t\t%f\t%f\n", xp, xg);

	// Involute function
	double invaw = 2 * tan(a) * ((xp + xg) / (zp + zg)) + tan(a) - a;

	printf("Involute function: \t\t\t%f\n", invaw);

	// Working Pressure Angle
	double aw = fnd(invaw, PI / 180, PI, PI / 180);

	printf("Working Pressure Angle: \t\t%f\n", aw * 180 / PI);

	// Center Distance Increment Factor
	double y = ((zg + zp) / 2) * ((cos(a) / cos(aw)) - 1);

	printf("Center Distance Increment Factor: \t%f\n", y);

	// Center Distance
	double ax = (((zg + zp) / 2) + y) * m;

	printf("Center Distance: \t\t\t%f\n", ax);

	// Pitch Diameter
	double dp = zp * m;
	double dg = zg * m;

	printf("Pitch Diameter: \t\t\t%f\t%f\n", dp, dg);

	// Base Diameter
	double dbp = dp * cos(a);
	double dbg = dg * cos(a);

	printf("Base Diameter: \t\t\t\t%f\t%f\n", dbp, dbg);

	// Working Pitch Diameter
	double dwp = dbp / cos(aw);
	double dwg = dbg / cos(aw);

	printf("Working Pitch Diameter: \t\t%f\t%f\n", dwp, dwg);

	// Addendum
	double hap = (1 + y - xp) * m;
	double hag = (1 + y - xg) * m;

	printf("Addendum: \t\t\t\t%f\t%f\n", hap, hag);

	// Whole Depth
	double h = (2.25 + y - (xp + xg)) * m;

	printf("Whole Depth: \t\t\t\t%f\n", h);

	// Dedendum
	double hdp = h - hap;
	double hdg = h - hag;

	printf("Dedendum: \t\t\t\t%f\t%f\n", hdp, hdg);

	// Working Depth
	double hw = 2 * m;

	printf("Working Depth: \t\t\t\t%f\n", hw);

	// Outside Diameter
	double dtp = dp + 2 * hap;
	double dtg = dg + 2 * hag;

	printf("Outside Diameter: \t\t\t%f\t%f\n", dtp, dtg);

	// Root Diameter
	double drp = dp - 2 * hap;
	double drg = dg - 2 * hag;

	printf("Outside Diameter: \t\t\t%f\t%f\n", drp, drg);

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
	double mp = (sqrt(abs((dtg / 2) - (dbg / 2))) + sqrt(abs((dtp / 2) - (dbp / 2))) - ax * sin(aw)) / (m * PI * cos(aw));

	printf("Contact Ratio: \t\t\t\t%f\n", mp);

	// Backlash

	//Min No of Teeth for Undercutting
	double zc = 4 / (1 - cos(2 * aw));

	printf("Min No of Teeth for Undercutting: \t%f\n", zc);
}
