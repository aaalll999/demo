def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    print("\nMax Heap constructed:", arr)
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)
        print(f"Heap after placing element at index {i}: {arr[:i]} (Sorted segment: {arr[i:]})")

def main():
    global arr
    while True:
        print("\n--- Heap Sort Menu ---")
        print("1. Enter array")
        print("2. Perform Heap Sort")
        print("3. Exit")
        choice = input("Enter choice: ")

        if choice == "1":
            try:
                arr = list(map(int, input("Enter integers separated by space (e.g., 5 1 4 2 8): ").split()))
            except ValueError:
                print("Invalid input. Please enter only integers.")
                arr = []
        
        elif choice == "2":
            if not arr:
                print("Array is empty! Please enter array first.")
            else:
                temp_arr = arr[:] 
                print("\nOriginal Array:", temp_arr)
                heap_sort(temp_arr)
                print("\nSorted Array (Ascending):", temp_arr)

        elif choice == "3":
            print("Exiting program...")
            break
        
        else:
            print("Invalid choice! Please try again.")

if __name__ == "__main__":
    arr = []
    main()
