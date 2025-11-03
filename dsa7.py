def merge(arr, left, mid, right):
    L = arr[left:mid+1]
    R = arr[mid+1:right+1]
    i = j = 0
    k = left
    
    while i < len(L) and j < len(R):
        if L[i][2] <= R[j][2]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
        
    while i < len(L):
        arr[k] = L[i]
        i += 1
        k += 1

    while j < len(R):
        arr[k] = R[j]
        j += 1
        k += 1
        
def merge_sort(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid+1, right)
        merge(arr, left, mid, right)
        
def display_orders(orders):
    print("\nOrders:")
    print("{:<5} {:<20} {:<15}".format("ID", "Item", "Delivery Time (min)"))
    for order in orders:
        print("{:<5} {:<20} {:<15}".format(order[0], order[1], order[2]))
        
def main():
    orders = []
    while True:
        print("\n--- Online Orders Merge Sort Menu ---")
        print("1. Add Order")
        print("2. Display Orders")
        print("3. Sort Orders by Delivery Time")
        print("4. Exit")
        choice = input("Enter choice: ")

        if choice == "1":
            order_id = input("Enter Order ID: ")
            item_name = input("Enter Item Name: ")
            try:
                delivery_time = int(input("Enter Delivery Time (in minutes): "))
                if delivery_time < 0:
                     print("Delivery time cannot be negative. Please enter a positive value.")
                else:
                    orders.append((order_id, item_name, delivery_time))
            except ValueError:
                print("Invalid input! Delivery Time must be an integer.")
                
        elif choice == "2":
            if orders:
                display_orders(orders)
            else:
                print("No orders available!")
                
        elif choice == "3":
            if orders:
                merge_sort(orders, 0, len(orders)-1)
                print("\nOrders sorted by delivery time:")
                display_orders(orders)
            else:
                print("No orders to sort!")
                
        elif choice == "4":
            print("Exiting program...")
            break
            
        else:
            print("Invalid choice! Please try again.")

if __name__ == "__main__":
    main()
