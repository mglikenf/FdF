# fdf — Fil de Fer
_This project has been created by [mglikenf](https://github.com/mglikenf) as part of the 42 School curriculum._

## Description
**fdf** (French for *fil de fer*, meaning "wireframe") reads a heightmap file and renders it as a 3D isometric wireframe in a graphical window. Each point in the map corresponds to a coordinate in 3D space, where the value represents altitude. The renderer projects these points using an isometric transformation and draws the mesh using Bresenham's line algorithm.

## Features
- Isometric 3D projection
- Auto-scaling and centering of the map to fit the window
- Map validation (consistent row width, valid file extension)
- Press `Escape` or close the window to exit cleanly

## Requirements
- Linux with X11
- GCC
- Make

## Installation

Clone the repository with its submodule:

```bash
git clone https://github.com/<your-username>/fdf.git
cd fdf
git submodule update --init
```

Build & clean:

```bash
make			# Build
make clean		# Remove object files
make fclean		# Remove object files and executables
make re			# Rebuild everything
```

## Usage

```bash
./fdf <map_file.fdf>
```

Example:

```bash
./fdf test_maps/valid/42.fdf
```

## Map Format

A `.fdf` map is a grid of space-separated integers representing altitude values:

```
0  0  0  0  0
0  1  2  1  0
0  2  4  2  0
0  1  2  1  0
0  0  0  0  0
```

## Technical Notes
- The map is parsed in two passes: first to determine dimensions and validate consistency, then to allocate memory and fill the point grid.
- Projection uses a 30° isometric angle (`cos`/`sin` of π/6).
- Scaling is computed from the bounding box of projected points to fit within the window with a small margin.
- MiniLibX hooks handle keyboard input and window close events.

### Subject Limitations
- The subject allows the usage of `ft_printf`, `get_next_line`, all `libft` functions, and restricts C library functions usage to the following ones: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`, `gettimeofday`. Any function from the `math` library is allowed.
- The subject requires using the `MiniLibX` library.
