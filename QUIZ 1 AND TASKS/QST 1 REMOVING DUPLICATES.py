def remove_duplicates(nums):
    if not nums:
        return 0

    i = 0  # pointer for unique elements
    for j in range(1, len(nums)):
        if nums[i] != nums[j]:
            i += 1
            nums[i] = nums[j]

    return i + 1

# Example:
input_array = [1, 1, 2, 2, 3, 4, 4, 5]
new_length = remove_duplicates(input_array)

print("Input Array:", input_array)
print("Output Array:", input_array[:new_length])
print("New Length:", new_length)
