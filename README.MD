# 42 so long

![webm](screenshots/so_long.gif)

## Description

This project is a very small 2D game. It is built to make you work with textures, sprites. And some very basic gameplay elements.

## Usage

```bash
make
./so_long maps/map.ber
make fclean
```

## Map

The map must be composed of only 5 possible characters:

- 0 for an empty space
- 1 for a wall
- C for a collectible
- E for the exit
- P for the player’s starting position (only one)

## Controls

- W, A, S, D and arrow keys to move the player
- space bar to kill enemies in bonus
- ESC to quit the game
- X to close the window

![Screenshot 1](screenshots/1.png)

## Bonus

```bash
make
./so_long_bonus maps/large_map_bonus.ber
make fclean
```
