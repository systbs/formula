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
double mx = 2.54;
// normal pressure angle
double an = 20 * PI / 180;

// Diameter of Worm
double d = 20;

// Coefficient of Profile Shift
double xg = 0;

// Coefficient of Clearance
double cclr = 0.25;

double Ft = 0.45;
double n1 = 600; //rpm
// Lubrication Factor Zm
double Zm = 1;
// Lubricant Factor, ZL
double Zl = 1;
// Surface Roughness Factor, ZR
double Zr = 1;
// Contact Factor, Kc
double Kc = 1;
// Starting Factor, Ks
double Ks = 1;
// Time Factor, Kh
double Kh = 1;
//Basic Zone Factor, Z
double bzf = 1.36;
// Allowable Stress Factor, Sc lim
double Sc_lim = 0.67;

int main(int argc, char *argv[])
{
	char *eptr;
	int i;
	for (i = 1; i < argc; i += 2)
	{
		if (!isnum(argv[i + 1]))
		{
			printf("%s must be a number.\n", argv[i]);
			printf("Usage: ./formula -zw %f -zg %f -mx %f -an %f -dw %f -xg %s -clr %f\n", zw, zg, mx, an, d, xg, cclr);
			printf("-zw \tNo. of Threads\n");
			printf("-zg \tNo. of Teeth\n");
			printf("-mx \tModule\n");
			printf("-an \tNormal Pressure Angle\n");
			printf("-dw \tDiameter of Worm\n");
			printf("-xg \tCoefficient of Profile Shift\n");
			printf("-clr \tCoefficient of Clearance\n");
			printf("-ft \tTangential force (kgf)\n");
			printf("-n \tRevolution Per Minuts (rpm)\n");
			printf("-zm \tLubrication Factor Zm\n");
			printf("-zl \tLubricant Factor, ZL\n");
			printf("-zr \tSurface Roughness Factor, ZR\n");
			printf("-kc \tContact Factor, Kc\n");
			printf("-ks \tStarting Factor, Ks\n");
			printf("-kh \tTime Factor, Kh\n");
			printf("-bzf \tBasic Zone Factor\n");
			printf("-sc \tAllowable Stress Factor, Sc lim\n");
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

		else if (strcmp(argv[i], "-ft") == 0)
		{
			Ft = strtod(argv[i + 1], &eptr);
			if (Ft < 0)
			{
				printf("arg ft must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-n") == 0)
		{
			n1 = strtod(argv[i + 1], &eptr);
			if (n1 < 0)
			{
				printf("arg n must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-zm") == 0)
		{
			Zm = strtod(argv[i + 1], &eptr);
			if (Zm < 0)
			{
				printf("arg Zm must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-Zl") == 0)
		{
			Zl = strtod(argv[i + 1], &eptr);
			if (Zl < 0)
			{
				printf("arg Zl must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-Zr") == 0)
		{
			Zr = strtod(argv[i + 1], &eptr);
			if (Zr < 0)
			{
				printf("arg zr must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-kc") == 0)
		{
			Kc = strtod(argv[i + 1], &eptr);
			if (Kc < 0)
			{
				printf("arg kc must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-ks") == 0)
		{
			Ks = strtod(argv[i + 1], &eptr);
			if (d < 0)
			{
				printf("arg ks must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-kh") == 0)
		{
			Kh = strtod(argv[i + 1], &eptr);
			if (Kh < 0)
			{
				printf("arg kh must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-bzf") == 0)
		{
			bzf = strtod(argv[i + 1], &eptr);
			if (bzf < 0)
			{
				printf("arg bzf must be a positive number.\n");
			}
		}
		else if (strcmp(argv[i], "-sc") == 0)
		{
			Sc_lim = strtod(argv[i + 1], &eptr);
			if (Sc_lim < 0)
			{
				printf("arg sc must be a positive number.\n");
			}
		}
	}

	printf("Usage: ./worm -zw %f -zg %f -mx %f -an %f -dw %f\n", zw, zg, mx, an, d);
	printf("\t-zw \tNo. of Threads\n");
	printf("\t-zg \tNo. of Teeth\n");
	printf("\t-mx \tModule\n");
	printf("\t-an \tNormal Pressure Angle\n");
	printf("\t-dw \tDiameter of Worm\n");
	printf("\t-xg \tCoefficient of Profile Shift\n");
	printf("\t-clr \tCoefficient of Clearance\n");
	printf("\t-ft \tTangential force (kgf)\n");
	printf("\t-n \tRevolution Per Minuts (rpm)\n");
	printf("\t-zm \tLubrication Factor Zm\n");
	printf("\t-zl \tLubricant Factor, ZL\n");
	printf("\t-zr \tSurface Roughness Factor, ZR\n");
	printf("\t-kc \tContact Factor, Kc\n");
	printf("\t-ks \tStarting Factor, Ks\n");
	printf("\t-kh \tTime Factor, Kh\n");
	printf("\t-bzf \tBasic Zone Factor\n");
	printf("\t-sc \tAllowable Stress Factor, Sc lim\n\n\n");

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
	double cax = ((dw + dg) / 2) + (xg * mx);
	// Addendum Worm
	double adwx = 1 * mx;
	// Deddendum Gear
	double adgx = (1 + xg) * mx;
	// Whole Depth
	double wdx = 2.25 * mx;
	// Outside Diameter Worm
	double odwx = dw + (2 * adwx);
	// Outside Diameter Gear
	double odgx = dg + (2 * adgx) + mx;
	// Throat Diameter
	double tdx = dg + (2 * adgx);
	// Throat Surface Radius
	double trx = (dw / 2) - adwx;
	// Root Diameter Worm
	double rdwx = odwx - (2 * wdx);
	// Root Diameter Gear
	double rdgx = tdx - (2 * wdx);

	// Normal Surface
	// Center distance
	double can = ((dw + dg) / 2) + (xg * mn);
	double dgn = zg * mn / cos(g);
	double adwn = mn;
	double adgn = (1 + xg) * mn;
	double wdn = 2.25 * mn;
	double odwn = dw + (2 * adwn);
	double odgn = dg + (2 * adgn) + mn;
	double tdn = dw + (2 * adgn);
	double trn = (dw / 2) - adwn;
	double rdwn = odwn - (2 * wdn);
	double rdgn = tdn - (2 * wdn);

	// Thickness
	// Axial Circular Tooth Thickness
	double sxw = PI * mx / 2;
	double sxg = (PI / 2 + 2 * xg * tan(ax)) * mx;
	// No of Teeth in an equivalent spur gear
	double zxg = zg / ((cos(3 * g) + 3 * cos(g)) / 4);
	// Half of tooth angle at pich circle
	double txg = ((90 / zxg) + ((360 * xg * tan(ax)) / (PI * zxg))) * PI / 180;
	// Chordal Thickness
	double sjwx = sxw * cos(g);
	double sjgx = zxg * mx * cos(g) * sin(txg);
	// Chordal Addendum
	double hjwx = adwx + (pow(sxw * sin(g), 2) / (4 * dw));
	double hjgx = adgx + ((zxg * mx * cos(g) / 2) * (1 - cos(txg)));

	// Radial Surface
	// Center distance
	double cat = ((dw + dg) / 2) + (xg * mt);
	double dgt = zg * mt * tan(g);
	double adwt = mt;
	double adgt = (1 + xg) * mt;
	double wdt = 2.25 * mt;
	double odwt = dw + (2 * adwt);
	double odgt = dg + (2 * adgt) + mt;
	double tdt = dw + (2 * adgt);
	double trt = (dw / 2) - adwt;
	double rdwt = odwt - (2 * wdt);
	double rdgt = tdt - (2 * wdt);

	// Thickness
	// Normal Circular Tooth Thickness
	double snw = PI * mn / 2;
	double sng = (PI / 2 + 2 * xg * tan(an)) * mn;
	// No of Teeth in an equivalent spur gear
	double zng = zg / ((cos(3 * g) + 3 * cos(g)) / 4);
	// Half of tooth angle at pich circle
	double tng = ((90 / zng) + ((360 * xg * tan(an)) / (PI * zng))) * PI / 180;
	// Chordal Thickness
	double sjwn = snw * cos(g);
	double sjgn = zng * mn * cos(g) * sin(tng);
	// Chordal Addendum
	double hjwn = adwn + (pow(snw * sin(g), 2) / (4 * dw));
	double hjgn = adgn + ((zng * mn * cos(g) / 2) * (1 - cos(tng)));

	/* Strength Of Worm Gearing
		This information is applicable for worm gear drives that are used to transmit power in general industrial machines with the following parameters:
		Axial Module: mx, 1 to 25 mm
		Pitch Diameter of Worm Gear: d2, less than 900 mm
		Sliding Speed: vs, less than 30 m/sec
		Rotating Speed, Worm Gear: n2, less than 600 rpm

		T2 = Nominal torque of worm gear (kg • m)
		T1 = Nominal torque of worm (kgf • m)
		Ft = Nominal tangential force on worm gear's pitch circle (kgf)
		d2 = Pitch diameter of worm gear (mm)
		u = Teeth number ratio = z2 /zw
		ηR = Transmission efficiency, worm driving (not including bearing loss, lubricant agitation loss, etc.)
		µ= Friction coefficient

	*/

	double u = zg / zw;
	double vs = dw * n1 / (19100 * cos(g));
	// Surface Strength of Worm Gearing Mesh
	// Sliding Speed Factor, Kv
	double Kv = 0.0252 * pow(vs, 4) - 0.2297 * pow(vs, 3) + 0.7352 * pow(vs, 2) - 0.9973 * vs + 0.9969;

	// Rotating Speed Factor, Kn
	double Kn = -0.099 * log(n1) + 0.9922;

	double Z = 1;
	if (b < 2.3 * mx * sqrt(Q + 1))
	{
		Z = bzf * b / (2 * mx * sqrt(Q + 1));
	}
	else
	{
		Z = bzf * 1.15;
	}

	printf("Kv %f Zm %f Kn %f Z %f\n", Kv, Zm, Kn, Z);

	// Basics Formulas

	double mu = 0.0397 * exp(-0.051 * vs);
	double etaR = (tan(g) * (1 - tan(g) * mu / cos(an))) / (tan(g) + (mu / cos(an)));
	double T2 = Ft * dg / 2000;
	double T1 = T2 / (u * etaR);

	double Fte = Ft * Kh * Ks;
	double T2e = T2 * Kh * Ks;

	// Calculation of Basic Load
	double Ft_lim = 3.82 * Kv * Kn * Sc_lim * Z * pow(dg, 0.8) * mx * (Zl * Zm * Zr / Kc);
	double T_lim = 0.00191 * Kv * Kn * Sc_lim * Z * pow(dg, 1.8) * mx * (Zl * Zm * Zr / Kc);

	printf("Diameter Factor : \t\t\t%f\n", Q);
	printf("Lead-Worm: \t\t\t\t%f\n", Lw);
	printf("Lead Angle : \t\t\t\t%f\n", g * 180 / PI);
	printf("Length of worm with teeth : \t\t%f\n", b);
	printf("Working blank width of worm gear : \t%f\n", be);
	printf("Coefficient of Clearance : \t\t%f\n", cclr);
	printf("Coefficient of Profile Shift : \t\t%f\n", xg);

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
	printf("\n----------------------- Thickness --------------------\n");
	printf("Circular Tooth Thickness-Worm : \t%f\t%f\n", sxw, snw);
	printf("Circular Tooth Thickness-Gear : \t%f\t%f\n", sxg, sng);

	printf("No of Teeth in an equivalent spur gear: %f\t%f\n", zxg, zng);
	printf("Half of tooth angle at pich circle : \t%f\t%f\n", txg * 180 / PI, tng * 180 / PI);

	printf("Chordal Thickness - Worm : \t\t%f\t%f\n", sjwx, sjwn);
	printf("Chordal Thickness - Gear : \t\t%f\t%f\n", sjgx, sjgn);

	printf("Chordal Addendum - Worm : \t\t%f\t%f\n", hjwx, hjwn);
	printf("Chordal Addendum - Gear : \t\t%f\t%f\n", hjgx, hjgn);

	printf("\n----------------------- Force --------------------\n");

	printf("Nominal tangential force on worm gear's pitch circle (kgf) %f < %f\n", Fte, Ft_lim);
	printf("Nominal torque of worm gear (kg * m) %f < %f\n", T2e, T_lim);
}
