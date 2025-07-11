# <h1><img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Travel%20and%20places/Parachute.png" alt="Parachute" width="80" height="80"/> Forest Scene - 2D OpenGL Graphics Project </h1>

<img width="1920" height="1040" alt="Image" src="https://github.com/kazihabiba201/forest-scene/blob/main/assets/forest_scene.png" />
A beautiful and interactive computer graphics application built with **OpenGL** and **GLUT**, simulating a **2D forest environment**. This project visually represents various forest elements using geometric transformations and creative rendering.

---

## Objectives

- ✅ Create a visually appealing 2D forest scene.
- ✅ Use OpenGL and GLUT libraries for rendering and display.
- ✅ Optimize for performance across different systems.
- ✅ Include well-documented and commented code.

---

## Tools & Technologies

-  **Language**: [C++](https://isocpp.org/)
-  **IDE**: [Code::Blocks](http://www.codeblocks.org/)
-  **Libraries**:
  - [OpenGL](https://www.opengl.org/)
  - [GLUT (OpenGL Utility Toolkit)](https://freeglut.sourceforge.net/)


---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Activities/Video%20Game.png" alt="Video Game" width="40" height="40" /> Controls and Key Bindings 


| Key / Mouse Button         | Action                                | Description                                                     |
|---------------------------|-------------------------------------|-----------------------------------------------------------------|
| **Left Arrow** / `'l'`     | Rotate pinwheel clockwise            | Increments rotation by 45°, spins pinwheel left.               |
| **Right Arrow** / `'r'`    | Rotate pinwheel counterclockwise    | Decrements rotation by 45°, spins pinwheel right.              |
| **'s' key**                | Stop pinwheel rotation               | Stops any ongoing pinwheel rotation.                            |
| **Up Arrow (GLUT_KEY_UP)** | Move cartoon & parachute upward     | Moves cartoon and parachute upward along the y-axis.           |
| **Down Arrow (GLUT_KEY_DOWN)** | Move cartoon & parachute downward | Moves cartoon and parachute downward along the y-axis.         |
| **Right Arrow (GLUT_KEY_RIGHT)** | Move cartoon right & land          | Moves cartoon right on x-axis; parachute lands on road (y=0).  |
| **Left Arrow (GLUT_KEY_LEFT)** | Move cartoon left & land           | Moves cartoon left on x-axis; parachute lands on road (y=0).   |
| **Left Mouse Button**      | Rotate pinwheel once                 | Triggers a single pinwheel rotation.                            |
| **Middle Mouse Button**    | Continuous pinwheel rotation right  | Starts continuous clockwise pinwheel rotation.                 |
| **Right Mouse Button**     | Continuous pinwheel rotation right  | Same as middle button; continuous clockwise rotation.          |


## Implementation Notes
![Forest_Scene_Grid](https://github.com/kazihabiba201/forest-scene/blob/main/assets/forest_scene_grid.png)
1. The initial design of the scene was drafted on **graph paper**.
2. Using C++ with OpenGL and GLUT, the objects were programmed with:
   - **Translation and rotation** functions
   - **Looping animations**
   - **Color and shape blending** for a natural forest look
3. Movement and interaction are triggered by animation logic built into the render loop.

---


## Features

The forest scene features a combination of static, moving, and rotating graphical objects, providing an engaging animation.

| Type            | Objects                                                                 |
|-----------------|-------------------------------------------------------------------------|
| **Static**      | Sun, Trees, Road, Basic Shapes                                           |
| **Moving**      | Clouds, Cartoon Character, Animal, Parachute (Hot Air Balloon)          |
| **Rotating**    | Pinwheel                                                                 |

Each element is created using **custom geometric shapes** and transformations. The animation is brought to life with movement effects like **floating**, **walking**, and **spinning**.

---

## Visual Demo - gif
![Forest Scene Animation](https://github.com/kazihabiba201/forest-scene/blob/main/assets/forestScene.gif)
