def rotate_array(nums, k):
    n = len(nums)
    k = k % n  # in case k is larger than the length of the array

    # Reverse the entire array
    nums.reverse()

    # Reverse the first k elements
    nums[:k] = reversed(nums[:k])

    # Reverse the remaining elements
    nums[k:] = reversed(nums[k:])

# Example:
input_array = [1, 2, 3, 4, 5, 6, 7]
k_steps = 3
rotate_array(input_array, k_steps)

print("Input Array:", input_array)
