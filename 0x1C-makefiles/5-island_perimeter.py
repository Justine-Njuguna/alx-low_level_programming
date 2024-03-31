#!/usr/bin/python3
"""
5-island_perimeter

This module defines a function that calculates the perimeter of an island
represented by a grid of integers.

Args:
    grid: A list of lists of integers, where 0 represents water and 1
         represents land.

Returns:
    The perimeter of the island in the grid.
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island in the given grid.

    Args:
        grid: A list of lists of integers, where 0 represents water and 1
             represents land.

    Returns:
        The perimeter of the island in the grid.

    Raises:
        TypeError: If the grid is not a list of lists of integers.
    """

    if not isinstance(grid, list):
        raise TypeError("grid must be a list of lists")
    for row in grid:
        if not isinstance(row, list):
            raise TypeError("grid must be a list of lists")
        for cell in row:
            if not isinstance(cell, int):
                raise TypeError("grid must contain only integers")

    rows, cols = len(grid), len(grid[0])
    perimeter = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                # Check for neighbors (up, down, left, right)
                perimeter += 4
                # Check if not on the first row and subtract top border
                if row > 0 and grid[row - 1][col] == 1:
                    perimeter -= 2
                # Check if not on the last row and subtract bottom border
                if row < rows - 1 and grid[row + 1][col] == 1:
                    perimeter -= 2
                # Check if not on the first column and subtract left border
                if col > 0 and grid[row][col - 1] == 1:
                    perimeter -= 2
                # Check if not on the last column and subtract right border
                if col < cols - 1 and grid[row][col + 1] == 1:
                    perimeter -= 2

    return perimeter
