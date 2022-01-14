# formula
Gear Formula - Gear Worm 

## Elements of Metric Gear Technology (Cont.)
 - [Worm Gear Mesh Geometry-Document](https://www.sdp-si.com/resources/elements-of-metric-gear-technology/page5.php)
 - [Calculations of Internal Gears and The Fundamentals of Helical Gears, Elements of Metric Gear Technology (Cont.)](https://www.sdp-si.com/resources/elements-of-metric-gear-technology/page3.php)
 - [Gear Types and Axial Arrangements; Details of Involute Gearing, Elements of Metric Gear Technology (Cont.)](https://www.sdp-si.com/resources/elements-of-metric-gear-technology/page2.php#Section4)


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

## Calculations of Spur Gears
gcc -o spur spur.c -lm 
```
Usage: ./spur -m 3.000000 -a 0.349067 -zp 12.000000 -zg 24.000000 -xp 0.600000 -xg 0.360000
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
Contact Ratio:                          1.226579
Min No of Teeth for Undercutting:       10.349517
 ```

## Spur Gear & Rack
gcc -o rack rack.c -lm
```
Usage: ./rack -m 3.000000 -a 0.349067 -z 12.000000 -x 0.600000 -H 32.000000 -aw 0.349067
        -m      Module
        -a      Pressure Angle
        -z      Number of teeth
        -H      Height of Pitch Line
        -x      Coefficient of Profile Shift
        -aw     Working Pressure Angle


---------------------                   Spur Gear       Rack
Module:                                 3.000000
Pressure Angle:                         0.349067
Number of Teeth:                        12.000000
Coefficient of Profile Shift:           0.600000
Height of Pitch Line:                   32.000000
Working Pressure Angle:                 0.349067
Center Distance:                        51.800000
Pitch Diameter:                         36.000000
Base Diameter:                          33.828924
Working Pitch Diameter:                 36.000000
Addendum:                               4.800000        3.000000
Whole Depth:                            6.750000
Outside Diameter:                       45.600000
Root Diameter:                          32.100000
```

## Internal/External Gear Calculations
gcc -o external external.c -lm
```
Usage: ./external -m 3.000000 -a 0.349067 -ze 16.000000 -zi 24.000000 -xe 0.000000 -xi 0.500000
        -m      Module
        -a      Pressure Angle
        -ze     Number of teeth-External
        -zi     Number of teeth-Internal
        -xe     Coefficient of Profile Shift-External
        -xi     Coefficient of Profile Shift-Internal


--------------------------               External        Internal
Module:                                 3.000000
Number of teeth:                        16.000000       24.000000
Pressure Angle:                         20.000000
Coefficient of Profile Shift:           0.000000        0.500000
Involute function:                      0.060401
Working Pressure Angle:                 31.000000
Center Distance Increment Factor:       0.385109
Center Distance:                        13.155328
Pitch Diameter:                         48.000000       72.000000
Base Diameter:                          45.105232       67.657849
Working Pitch Diameter:                 52.621311       78.931966
Addendum:                               3.000000        1.500000
Whole Depth:                            6.750000
Dedendum:                               3.750000        5.250000
Working Depth:                          6.000000
Outside Diameter:                       54.000000       69.000000
Root Diameter:                          40.500000       82.500000
Top Clearance:                          0.750000
Circular Pitch:                         9.424800
Pitch Prependicular to Tooth:           8.078624
Base Pitch:                             8.078624
Tooth Thickness at Standard pitch Diameter:     4.712400
Min No of Teeth for Undercutting:       7.539621
```

## Helical Gear Calculations
gcc -o helix helix.c -lm
```
Usage: ./helix -mn 3.000000 -an 0.349067 -zp 12.000000 -zg 60.000000 -xnp 0.098090 -xng 0.000000
        -mn     Module
        -an     Pressure Angle
        -zp     Number of teeth-Pinion
        -zg     Number of teeth-Gear
        -xnp    Coefficient of Profile Shift-Pinion
        -xng    Coefficient of Profile Shift-Gear


--------------------------                       PINION          GEAR 
Normal Module:                          3.000000
Normal Pressure Angle:                  20.000000
Helix Angle:                            30.000000
Number of teeth:                        12.000000       60.000000     
Normal Coefficient of Profile Shift:    0.098090        0.000000      
Involute function:                      0.023405
Working Pressure Angle:                 23.062500
Center Distance Increment Factor:       0.081906
Center Distance:                        124.953463
Pitch Diameter:                         41.569249       207.846244    
Base Diameter:                          38.322299       191.611495    
Working Pitch Diameter:                 41.651154       208.255772    
Addendum:                               3.245717        2.951447      
Whole Depth:                            6.701447
Dedendum:                               3.455730        3.750000
Working Depth:                          6.000000
Outside Diameter:                       48.060683       213.749138
Root Diameter:                  34.657789       200.346244
Top Clearance:                          0.750000
Circular Pitch:                         9.424800
Pitch Prependicular to Tooth:           8.671548
Base Pitch:                             8.671548
Tooth Thickness at Standard pitch Diameter:     4.712400
Contact Ratio:                          1.486783
Min No of Teeth for Undercutting:       13.032967
```

## Support Us
BTC    bc1qy8zfvyymhtfh7t2ykuaf3ev6h3nq3r2zn64jv7
