# Python3 script to reverse the array


def rev(ls):
    return ls[::-1]


num = int(input("Enter the length of your array:\t"))
arr = list(map(int, input().strip().split()))

print("Your original array is: ", arr)
print("The reversed array is: ", rev(arr))

print("Sorted Array is: ", sorted(arr))
print("Sorted Array in descending order is: ", rev(sorted(arr)))
