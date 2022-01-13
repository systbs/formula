# formula
Gear Formula - Gear Worm 

## Worm Gear Mesh Geometry, Elements of Metric Gear Technology (Cont.)
  [Worm Gear Mesh Geometry-Document](https://www.sdp-si.com/resources/elements-of-metric-gear-technology/page5.php)
  [Gear Types and Axial Arrangements; Details of Involute Gearing, Elements of Metric Gear Technology (Cont.)](https://www.sdp-si.com/resources/elements-of-metric-gear-technology/page2.php#Section4)


# How to use 

## Calculations of Worm Gears
```
gcc -o worm worm.c -lm 
Usage: ./worm -zw 2.000000 -zg 30.000000 -mx 3.000000 -an 0.349067 -dw 44.000000
        -zw     No. of Threads
        -zg     No. of Teeth
        -mx     Module
        -an     Normal Pressure Angle
        -dw     Diameter of Worm
        -cps    Coefficient of Profile Shift
        -clr    Coefficient of Clearance
        
Output:

Diameter Factor :                       14.666667
Lead-Worm:                              18.849600
Lead Angle :                            7.765148
Length of worm with teeth :             48.066480
Working blank width of worm gear :      23.748684
Coefficient of Clearance :              0.250000
Coefficient of Profile Shift :          0.000000

                                         Axial           Normal          Radial
 ----------------------------------------
Module:                                  3.000000       2.972491        22.000000
Pressure Angle:                          20.170236      20.000000       69.633928
Pitch:                                   9.424800       9.338376        69.115200
Pitch Diameter-Worm :                    44.000000      44.000000       44.000000
Pitch Diameter-Gear :                    90.000000      90.000000       90.000000
Addendum-Worm :                          3.000000       2.972491        22.000000
Addendum-Gear :                          3.000000       2.972491        22.000000
Whole Depth :                            6.750000       6.688104        49.500000
Working Depth :                          6.000000       5.944981        44.000000
Top Clearance :                          0.750000       0.743123        5.500000
Outside Diameter-Worm :                  50.000000      49.944981       88.000000
Outside Diameter-Gear :                  99.000000      98.917472       156.000000
Throat Diameter :                        50.000000      49.944981       88.000000
Throat Surface Radius :                  19.000000      19.027509
Root Diameter-Worm :                     36.500000      36.568774
Root Diameter-Gear :                     36.500000      36.568774
Center Distance:                         67.000000      67.000000       67.000000
```

## Calculations of Internal Gears
```
gcc -o internal internal.c -lm 
Usage: ./spur -m 3.000000 -a 0.349067 -zp 12.000000 -zg 24.000000 -xp 0.600000 -xg 0.360000
        -m      Module
        -a      Pressure Angle
        -zp     Number of teeth-Pinion
        -zg     Number of teeth-Gear
        -xp     Coefficient of Profile Shift-Pinion
        -xg     Coefficient of Profile Shift-Gear
        
 Output:
 
Usage: ./internal -m 3.000000 -a 0.349067 -zp 12.000000 -zg 24.000000 -xp 0.600000 -xg 0.360000
        -m      Module
        -a      Pressure Angle
        -zp     Number of teeth-Pinion
        -zg     Number of teeth-Gear
        -xp     Coefficient of Profile Shift-Pinion
        -xg     Coefficient of Profile Shift-Gear

                                         PINION          GEAR
--------------------------
Module:                                 3.000000
Number of teeth:                        12.000000       24.000000
Pressure Angle:                         20.000000
Coefficient of Profile Shift:           0.600000        0.360000
Involute function:                      0.034316
Working Pressure Angle:                 26.078125
Center Distance Increment Factor:       0.831615
Center Distance:                        56.494844
Pitch Diameter:                         36.000000       72.000000
Base Diameter:                          33.828924       67.657849
Working Pitch Diameter:                 37.663229       75.326458
Addendum:                               3.694844        4.414844
Whole Depth:                            6.364844
Dedendum:                               2.670000        1.950000
Working Depth:                          6.000000
Outside Diameter:                       43.389687       80.829687
Outside Diameter:                       28.610313       63.170313
Top Clearance:                          0.750000
Circular Pitch:                         9.424800
Pitch Prependicular to Tooth:           8.465308
Base Pitch:                             8.465308
Tooth Thickness at Standard pitch Diameter:     4.712400
Contact Ratio:                          -2.372302
Min No of Teeth for Undercutting:       10.349517
 ```

## Support Us
BTC    bc1qy8zfvyymhtfh7t2ykuaf3ev6h3nq3r2zn64jv7
