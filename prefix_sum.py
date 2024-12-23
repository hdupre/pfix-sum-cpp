def prefix_sum(arr):
    """
    Calculate the prefix sum of an array.
    
    Args:
        arr (list): Input array of numbers
        
    Returns:
        list: Array where each element is the sum of all previous elements
    """
    n = len(arr)
    prefix = [0] * n
    prefix[0] = arr[0]  # First element is the same
    
    # Calculate cumulative sum
    for i in range(1, n):
        prefix[i] = prefix[i-1] + arr[i]
        
    return prefix

# Example usage
arr = [1, 2, 3, 4, 5]
result = prefix_sum(arr)
print(f"Original array: {arr}")
print(f"Prefix sum:    {result}")  # Output: [1, 3, 6, 10, 15]