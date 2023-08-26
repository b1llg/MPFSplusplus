# MPFS++

MPFS++ is an attempt at creating a modular, easy to use, multyphyics finite element code.

## Project Objectives
MPFS++ uses a custom input format to assign property, assign material and define multiple domains for solid mechanics, heat transfer and fluid mechanics.

## Current Capabilities
Able to solve steady state solid mechanics problem for truss element (E1TR2). The solver is able to read an input file with a custom format

```
?==================================================
?   GRID DEFINITION
?==================================================
*NODES
?	ID	X	Y	Z
	1	0.0	0.0	0.0
	2	1.0	0.0	0.0
	3	2.0	0.0	0.0
	4	3.0	0.0	0.0
*ELEMENTS
?	TYPE ID	PROP MAT	NODES
	E1TR2	1	1	1	1	2
	E1TR2	2	1	1	2	3
	E1TR2	3	1	1	3	4
?==================================================
?   PROPERTIES
?==================================================
*MAT_SLD_ELAS
?	ID	E	nu
	1	200e3	0.3
*PROP_SLD_TRUSS
?	ID	A
	1	3.1416
?==================================================
?   BOUNDARY CONDITIONS
?==================================================
*LOAD_FORCE_STD
?	X	Y	Z	NODE
	1000	0	0	4
*BOUNDARY_DISP_STD
?	X	Y	Z	NODE
	0	0	0	1
?==================================================
?   SOLVER PARAMETERS
?==================================================
*END
```
