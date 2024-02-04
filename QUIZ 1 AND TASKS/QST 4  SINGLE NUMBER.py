def single_number(nums):
    result = 0
    for num in nums:
        result ^= num
    return result

# Example:
input_array = [4, 3, 2, 4, 3, 2, 1]

single_num = single_number(input_array)

print("Input Array:", input_array)
print("Single Number:", single_num)
