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

// ν = Poisson's Ratio, and E = Young's Modulus
double vp = 0.3;
double vg = 0.3;
double Ep = 21000;
double Eg = 21000;

// Helix Angle Factor, Zβ
double Zb = 1;

// Life Factor, KHL
double Khl = 1;

// Lubricant Factor, ZL
double Zl = 1.08;

// Surface Roughness Factor, ZR
double Zr = 1;

// Sliding Speed Factor, ZV
double Zv = 1;

// Hardness Ratio Factor, ZW
double Zw = 1;

// Dimension Factor, KHX
double Khx = 1;

// Tooth Flank Load Distribution Factor, KH β
double Khb = 1.025;

// Dynamic Load Factor, KV
double Kv = 1.4;

// Overload Factor
double Ko = 1;

// Safety Factor For Pitting
double Sh = 1.15;

// Hertz Stress
double SgmaH_Lim = 164;

double Ft = 45;

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
		else if (strcmp(argv[i], "-vp") == 0)
		{
			vp = strtod(argv[i + 1], &eptr);
			if (vp < 0)
			{
				printf("arg vp must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-vg") == 0)
		{
			vg = strtod(argv[i + 1], &eptr);
			if (vg < 0)
			{
				printf("arg vg must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-ep") == 0)
		{
			Ep = strtod(argv[i + 1], &eptr);
			if (Ep < 0)
			{
				printf("arg Ep must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-eg") == 0)
		{
			Eg = strtod(argv[i + 1], &eptr);
			if (Eg < 0)
			{
				printf("arg Eg must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-zb") == 0)
		{
			Zb = strtod(argv[i + 1], &eptr);
			if (Zb < 0)
			{
				printf("arg Zb must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-khl") == 0)
		{
			Khl = strtod(argv[i + 1], &eptr);
			if (Khl < 0)
			{
				printf("arg Khl must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-zl") == 0)
		{
			Zl = strtod(argv[i + 1], &eptr);
			if (Zl < 0)
			{
				printf("arg Zl must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-zr") == 0)
		{
			Zr = strtod(argv[i + 1], &eptr);
			if (Zr < 0)
			{
				printf("arg Zr must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-zv") == 0)
		{
			Zv = strtod(argv[i + 1], &eptr);
			if (Zv < 0)
			{
				printf("arg Zv must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-zw") == 0)
		{
			Zw = strtod(argv[i + 1], &eptr);
			if (Zw < 0)
			{
				printf("arg Zw must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-khx") == 0)
		{
			Khl = strtod(argv[i + 1], &eptr);
			if (Khl < 0)
			{
				printf("arg Khl must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-khb") == 0)
		{
			Khb = strtod(argv[i + 1], &eptr);
			if (Khb < 0)
			{
				printf("arg Khb must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-kv") == 0)
		{
			Kv = strtod(argv[i + 1], &eptr);
			if (Kv < 0)
			{
				printf("arg Kv must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-ko") == 0)
		{
			Ko = strtod(argv[i + 1], &eptr);
			if (Ko < 0)
			{
				printf("arg Ko must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-sh") == 0)
		{
			Sh = strtod(argv[i + 1], &eptr);
			if (Sh < 0)
			{
				printf("arg Sh must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-sigma") == 0)
		{
			SgmaH_Lim = strtod(argv[i + 1], &eptr);
			if (SgmaH_Lim < 0)
			{
				printf("arg sigma must be an positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-ft") == 0)
		{
			Ft = strtod(argv[i + 1], &eptr);
			if (Ft < 0)
			{
				printf("arg ft must be an positive number.\n");
			}
		}
	}

	printf("Usage: ./helix -mn %f -an %f -zp %f -zg %f -xnp %f -xng %f\n", mn, an, zp, zg, xnp, xng);
	printf("\t-mn \tModule\n");
	printf("\t-an \tPressure Angle\n");
	printf("\t-zp \tNumber of teeth-Pinion\n");
	printf("\t-zg \tNumber of teeth-Gear\n");
	printf("\t-xnp \tCoefficient of Profile Shift-Pinion\n");
	printf("\t-xng \tCoefficient of Profile Shift-Gear\n");

	printf("\t-vp \tPoisson's Ratio Pinion\n");
	printf("\t-vg \tPoisson's Ratio Gear\n");
	printf("\t-ep \tYoung's Modulus Pinion\n");
	printf("\t-eg \tYoung's Modulus Gear\n");
	printf("\t-zb \tHelix Angle Factor, Zβ\n");
	printf("\t-khl \tLife Factor, KHL\n");
	printf("\t-zl \tLubricant Factor, ZL\n");
	printf("\t-zr \tSurface Roughness Factor, ZR\n");
	printf("\t-zv \tSliding Speed Factor, ZV\n");
	printf("\t-zw \tHardness Ratio Factor, ZW\n");
	printf("\t-khx \tDimension Factor, KHX\n");
	printf("\t-khb \tTooth Flank Load Distribution Factor, KH β\n");
	printf("\t-kv \tDynamic Load Factor, KV\n");
	printf("\t-ko \tOverload Factor\n");
	printf("\t-sh \tSafety Factor For Pitting\n");
	printf("\t-sigma \tHertz Stress\n");
	printf("\t-ft \tTangential force\n\n");

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

	printf("Root Diameter: \t\t\t\t%f\t%f\n", drp, drg);

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
	double eb = (sqrt(abs(pow(dtg / 2, 2) - pow(dbg / 2, 2))) + sqrt(abs(pow(dtp / 2, 2) - pow(dbp / 2, 2))) - ax * sin(awt)) / (mn * PI * cos(at));

	printf("Contact Ratio: \t\t\t\t%f\n", eb);

	// Backlash

	//Min No of Teeth for Undercutting
	double zc = 4 / (1 - cos(2 * awt));

	printf("Min No of Teeth for Undercutting: \t%f\n", zc);

	// Thickness
	double snp = (PI / 2 + 2 * xnp * tan(an)) * mn;
	double sng = (PI / 2 + 2 * xng * tan(an)) * mn;

	double zvp = zp / ((cos(3 * b) + 3 * cos(b)) / 4);
	double zvg = zg / ((cos(3 * b) + 3 * cos(b)) / 4);

	double tvp = ((90 / zvp) + ((360 * xnp * tan(an)) / (PI * zvp))) * PI / 180;
	double tvg = ((90 / zvg) + ((360 * xng * tan(an)) / (PI * zvg))) * PI / 180;

	double sjp = zvp * mn * sin(tvp);
	double sjg = zvg * mn * sin(tvg);

	double hjp = (zvp * mn / 2) * (1 - cos(tvp)) + hap;
	double hjg = (zvg * mn / 2) * (1 - cos(tvg)) + hag;

	printf("\n----------------------- Thickness --------------------\n");
	printf("Circular Tooth Thickness : \t\t%f\t%f\n", snp, sng);
	printf("No of Teeth in an equivalent spur gear: %f\t%f\n", zvp, zvg);
	printf("Half of tooth angle at pich circle : \t%f\t%f\n", tvp * 180 / PI, tvg * 180 / PI);
	printf("Chordal Thickness : \t\t\t%f\t%f\n", sjp, sjg);
	printf("Chordal Addendum : \t\t\t%f\t%f\n", hjp, hjg);

	// Effective Tooth Width, bH (mm)
	double bH = mn * 10;
	// Zone Factor, ZH
	double bb = atan(tan(b) * cos(at));
	double Zh = (1 / cos(at)) * (sqrt((2 * cos(bb)) / tan(awt)));
	// Material Factor, ZM
	double Zm = sqrt(1 / (PI * (((1 - pow(vp, 2)) / Ep) + ((1 - pow(vg, 2)) / Eg))));
	// Contact Ratio Factor, Zε
	double ea = hag / hap;
	double Ze = 1;
	if (eb <= 1)
	{
		Ze = sqrt(1 - eb + (eb / ea));
	}
	else
	{
		Ze = sqrt(1 / ea);
	}

	// Teeth Ratio
	double u = (zg / zp);

	printf("\n----------------------- Force --------------------\n");

	double SgmaH = sqrt((Ft / dp * bH) * ((u + 1) / u)) * ((Zh * Zm * Ze * Zb) / (Khl * Zl * Zr * Zv * Zw * Khx)) * sqrt(Khb * Kv * Ko) * Sh;
	double Ft_Lim = pow(SgmaH_Lim, 2) * dp * bH * (u / (u + 1)) * pow((Khl * Zl * Zr * Zv * Zw * Khx) / (Zh * Zm * Ze * Zb), 2) * (1 / (Khb * Kv * Ko)) * (1 / pow(Sh, 2));

	printf("Hertz Stress %f\n", SgmaH);
	printf("Tangential force %f\n", Ft_Lim);
}
