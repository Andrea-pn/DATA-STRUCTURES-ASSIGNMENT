def contains_duplicate(nums):
    seen = set()
    for num in nums:
        if num in seen:
            return True
        seen.add(num)
    return False

# Example:
input_array_with_duplicates = [1, 2, 3, 1]
input_array_without_duplicates = [4, 5, 6, 7]

contains_duplicates = contains_duplicate(input_array_with_duplicates)
contains_no_duplicates = contains_duplicate(input_array_without_duplicates)

print("Array with Duplicates:", input_array_with_duplicates)
print("Contains Duplicates:", contains_duplicates)

print("\nArray without Duplicates:", input_array_without_duplicates)
print("Contains Duplicates:", contains_no_duplicates)
