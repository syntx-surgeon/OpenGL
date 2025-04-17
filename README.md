# OpenGL Animation Programs

This repository contains a collection of simple OpenGL animation programs written in C. Each program demonstrates different animation techniques and concepts using the OpenGL and GLUT libraries.

## Programs

### 1. Growing Moon Animation
- File: `GrowingMoon_Animation.c`
- Description: Simulates the phases of the moon using OpenGL
- Features:
  - Animates the moon's phases by drawing a circle with a moving shadow
  - Uses a timer function for smooth animation
  - White moon against a black background for better visibility
  - Demonstrates use of circular geometry and shadow effects

### 2. Ball Bouncing Animation
- File: `BallBouncing_Animation.c`
- Description: Simulates a ball bouncing on steps
- Features:
  - Red ball bouncing on gray steps
  - Implements simple physics with gravity
  - Multiple steps with collision detection
  - Smooth animation using timer functions

### 3. Moving Cloud Animation
- File: `MovementOfCloud_Animation.c`
- Description: Creates a simple cloud movement animation
- Features:
  - Cloud moves smoothly across the screen
  - Light blue background simulating sky
  - Continuous animation loop
  - Simple shape rendering using triangle fans

## Requirements

To run these programs, you'll need:
- OpenGL
- GLUT (OpenGL Utility Toolkit)
- C compiler
- Windows operating system

## Compilation and Running

To compile any of the programs, use a C compiler with OpenGL and GLUT libraries linked. For example:

```bash
gcc -o program_name program_name.c -lopengl32 -lglu32 -lfreeglut
```

Replace `program_name` with the name of the specific program you want to compile.

## Controls

All programs run automatically once started and will continue until the window is closed.

## Features Common to All Programs

- Window size: 500x500 or 600x600 pixels
- Smooth animations using GLUT timer functions
- Double or single buffering for display
- Clean initialization and window setup
- Proper cleanup and program termination

## Contributing

Feel free to contribute to this project by:
1. Adding new animations
2. Improving existing animations
3. Adding more features
4. Optimizing the code

## License

This project is open for educational purposes.
