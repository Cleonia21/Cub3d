# Cub3d

## PRESENTATION

The goal of ``cub3d`` is to make *something* using raycasting (like [Wolfenstein 3D](https://fr.wikipedia.org/wiki/Wolfenstein_3D)).

## WANNA PLAY? 💥
### Installation

first, copy paste the following code on your terminal:

```shell
cd ~ && cd Downloads && git clone https://github.com/Cleonia21/Cub3d.git cub3d && cd cub3d && make bonus && ./cub3d_bonus maps/map.cub
```
this should open a new window:
![Image of Cub3D](https://github.com/Cleonia21/Cub3d/blob/88f066af53fabc5c04cb5a5ecb832e778909fc74/preview.png)

### Commands

| KEY           | Action        |
| ------------- |:-------------:|
| `ESC`         | exit game     |
| `A`           | move left     |
| `D`           | move right    |
| `W`           | move forward  |
| `S`           | move backward |
| `MOUSE`       | turn right    |
| `MOUSE`       | turn left     |
| `ENTER`       | fog           |
| `SPACE`       | lamp control  |

### Rules

It's just a game template. You can simply walk around the map, control on/off lamp and break barrels with your body.

### Modifications 👨‍🎨
You can now create your own map by following this norm:
| Object         | Code          |
| -------------  |:-------------:|
| `NO`           | path to xpm texture file|
| `SO`           | path to xpm texture file|
| `WE`           | path to xpm texture file|
| `EA`           | path to xpm texture file|
| `F`            | numeric encoding in the format R,G,B for floor|
| `C`            | numeric encoding in the format R,G,B for ceiling|
| `1`            | wall          |
| `0`            | empty         |
| `N`/`E`/`W`/`S`| player initial position + orientation|
