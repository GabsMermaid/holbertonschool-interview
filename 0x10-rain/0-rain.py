#!/usr/bin/python3
""" Given a list of non-negative integers representing the heights of
walls with unit width 1, as if viewing the cross-section of a relief map,
calculate how many square units of water will be retained after it rains """


def rain(walls):
    """
    Args: walls - is a list of non-negative integers.
    Return: If the list is empty return 0.
    """
    n = len(walls)
    total_water = 0

    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]

        for j in range(i + 1, n):
            right = max(right, walls[j])

        total_water = total_water + (min(left, right) - walls[i])
    return total_water
