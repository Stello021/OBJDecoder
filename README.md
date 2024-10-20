# OBJDecoder

## Overview
**OBJ Decoder** is a simple C++ library toload and parse 3D model 
in the Wavefront `.obj` file. It reads vertex and face data from OBJ files,
making it easy to integrate these assets in rendering projects.

## Features
- Parsing vertex positions and face indeces from OBJ files.
- Supports basic Vector operations

## Code Overview

### Key Components
- **`Vector2` and `Vector3` Classes**: Provides 2D and 3D vector operations 
used troughout the library. These include:
     - Addition and Subtraction
     - Scalar Multiplication
     - Dot and Cross product
     - Vector normalization
- **`Model` Class**: Responsible for reading and parsing OBJ file

