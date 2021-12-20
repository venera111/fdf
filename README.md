# 1. FdF

|   |   |
| - | - |
| Evaluated | 2021-12-10 |
| Stack | C |
| Domains | Computer Graphics, Algorithm |
| Topics | `Graphics` `Line Drawing Algorithm` `Isometic Projection` |
| English Subject | [en.subject](https://github.com/venera111/fdf/blob/master/en.subject.pdf) |

# 2. Summary
The FdF project implements a simple wireframe graphical model that projects a curved terrain by connecting various points of a three-dimensional segment.

# 3. What I learned
The knowledge necessary for the projection of three-dimensional coordinates, such as the rotation transformation matrix, the linear interpolation method, the line drawing algorithm, the isometric projection method and the transformation of coordinates on the screen based on a certain point of view, were studied. He also mastered the basics of graphics programming.

# 4. Features
* Information about the coordinates and color of the terrain that will be projected using the implemented program is saved as a file and transmitted as a program parameter.
* When projecting segment points, use an isometric projection.

* The Bresenham algorithm is used to connect the points of segments.

* For pixels (coordinates) for which color information is not specified, the corresponding color is assigned using linear interpolation.

* When an error occurs while the program is running, the perror function outputs a corresponding error message.

* fdf uses the MiniLibX graphics library created by Ecole 42.
