#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.1416
#define abs(x) (x > 0 ? x : -x)

// Module
double mn = 3;

// Number of teeth Pinion
double zp = 12;

// Number of teeth Pinion
double zg = 60;

// Pressure Angle
double an = 20 * PI / 180;

// Helix Angle
double b = 30 * PI / 180;

// Coefficient of Profile Shift
double xnp = 0.09809;
double xng = 0;

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
		if (strcmp(argv[i], "-mn") == 0)
		{
			mn = strtod(argv[i + 1], &eptr);
			if (mn < 0)
			{
				printf("arg mn must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-an") == 0)
		{
			an = strtod(argv[i + 1], &eptr) * PI / 180;
			if (an < 0)
			{
				printf("arg an must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-zp") == 0)
		{
			zp = strtod(argv[i + 1], &eptr);
			if (zp < 0)
			{
				printf("arg zp must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-zg") == 0)
		{
			zg = strtod(argv[i + 1], &eptr);
			if (zg < 0)
			{
				printf("arg zg must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-xnp") == 0)
		{
			xnp = strtod(argv[i + 1], &eptr);
			if (xnp < 0)
			{
				printf("arg xnp must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-xng") == 0)
		{
			xng = strtod(argv[i + 1], &eptr);
			if (xng < 0)
			{
				printf("arg xng must be an positive number.\n");
			}
		}
	}

	printf("Usage: ./helix -mn %f -an %f -zp %f -zg %f -xnp %f -xng %f\n", mn, an, zp, zg, xnp, xng);
	printf("\t-mn \tModule\n");
	printf("\t-an \tPressure Angle\n");
	printf("\t-zp \tNumber of teeth-Pinion\n");
	printf("\t-zg \tNumber of teeth-Gear\n");
	printf("\t-xnp \tCoefficient of Profile Shift-Pinion\n");
	printf("\t-xng \tCoefficient of Profile Shift-Gear\n\n");

	printf("\n--------------------------\t\t\t PINION \t GEAR \n");
	printf("Normal Module: \t\t\t\t%f\n", mn);
	printf("Normal Pressure Angle: \t\t\t%f\n", an * 180 / PI);
	printf("Helix Angle: \t\t\t\t%f\n", b * 180 / PI);
	printf("Number of teeth: \t\t\t%f\t%f\n", zp, zg);
	printf("Normal Coefficient of Profile Shift: \t%f\t%f\n", xnp, xng);

	// Radial Pressure Angle
	double at = atan(tan(an) / cos(b));

	// Involute function
	double invaw = 2 * tan(an) * ((xnp + xng) / (zp + zg)) + tan(at) - at;

	printf("Involute function: \t\t\t%f\n", invaw);

	// Working Pressure Angle
	double awt = fnd(invaw, PI / 180, PI, PI / 180);

	printf("Working Pressure Angle: \t\t%f\n", awt * 180 / PI);

	// Center Distance Increment Factor
	double y = ((zg + zp) / (2 * cos(b))) * ((cos(at) / cos(awt)) - 1);

	printf("Center Distance Increment Factor: \t%f\n", y);

	// Center Distance
	double ax = (((zg + zp) / (2 * cos(b))) + y) * mn;

	printf("Center Distance: \t\t\t%f\n", ax);

	// Pitch Diameter
	double dp = zp * mn / cos(b);
	double dg = zg * mn / cos(b);

	printf("Pitch Diameter: \t\t\t%f\t%f\n", dp, dg);

	// Base Diameter
	double dbp = dp * cos(at);
	double dbg = dg * cos(at);

	printf("Base Diameter: \t\t\t\t%f\t%f\n", dbp, dbg);

	// Working Pitch Diameter
	double dwp = dbp / cos(awt);
	double dwg = dbg / cos(awt);

	printf("Working Pitch Diameter: \t\t%f\t%f\n", dwp, dwg);

	// Addendum
	double hap = (1 + y - xng) * mn;
	double hag = (1 + y - xnp) * mn;

	printf("Addendum: \t\t\t\t%f\t%f\n", hap, hag);

	// Whole Depth
	double h = (2.25 + y - (xnp + xng)) * mn;

	printf("Whole Depth: \t\t\t\t%f\n", h);

	// Dedendum
	double hdp = h - hap;
	double hdg = h - hag;

	printf("Dedendum: \t\t\t\t%f\t%f\n", hdp, hdg);

	// Working Depth
	double hw = 2 * mn;

	printf("Working Depth: \t\t\t\t%f\n", hw);

	// Outside Diameter
	double dtp = dp + 2 * hap;
	double dtg = dg + 2 * hag;

	printf("Outside Diameter: \t\t\t%f\t%f\n", dtp, dtg);

	// Root Diameter
	double drp = dtp - 2 * h;
	double drg = dtg - 2 * h;

	printf("Root Diameter: \t\t\t%f\t%f\n", drp, drg);

	// Top Clearance
	double c = 0.25 * mn;

	printf("Top Clearance: \t\t\t\t%f\n", c);

	// Circular Pitch
	double p = mn * PI;

	printf("Circular Pitch: \t\t\t%f\n", p);

	// Pitch Prependicular to Tooth
	double pn = p * cos(awt);

	printf("Pitch Prependicular to Tooth: \t\t%f\n", pn);

	// Base Pitch
	double pb = mn * PI * cos(awt);

	printf("Base Pitch: \t\t\t\t%f\n", pb);

	// Tooth Thickness at Standard pitch Diameter
	double Tsid = (PI / 2) * mn;

	printf("Tooth Thickness at Standard pitch Diameter: \t%f\n", Tsid);

	// Contact Ratio
	double mp = (sqrt(abs(pow(dtg / 2, 2) - pow(dbg / 2, 2))) + sqrt(abs(pow(dtp / 2, 2) - pow(dbp / 2, 2))) - ax * sin(awt)) / (mn * PI * cos(at));

	printf("Contact Ratio: \t\t\t\t%f\n", mp);

	// Backlash

	//Min No of Teeth for Undercutting
	double zc = 4 / (1 - cos(2 * awt));

	printf("Min No of Teeth for Undercutting: \t%f\n", zc);
}
