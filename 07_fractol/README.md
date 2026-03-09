# fract-ol

## 🗣️ About The Project
This project involves graphical 2D programming and complex mathematics to render beautiful fractal sets. 
Fractals are infinitely complex geometric structures that exhibit self-similarity across different scales. Handled primarily utilizing the dynamic MiniLibX graphical library.

## 🧮 Implemented Formulas
The underlying principle relies purely on iteratively squaring complex numbers: `Z = Z² + C`
- **Mandelbrot Set:** Explores various coordinate values of C, initializing Z at 0.
- **Julia Set:** Maintains a static custom complex parameter for C while iterating directly over the pixel coordinates as Z. 
- Custom mathematical combinations or the Burning Ship fractal variant.

## 🎮 Interactivity
- Smooth hardware pan and infinitely precise zooming mechanics mapping directly to the mouse wheel tracking cursor parameters.
- Dynamic color-shifting utilizing fluid HSL/RGB interpolation for distinct depth differentiation.
- Custom parameter tuning precisely via coordinate input combinations on execution execution.

## 🛠️ Usage
```bash
make
./fractol mandelbrot
./fractol julia -0.4 +0.6
```
