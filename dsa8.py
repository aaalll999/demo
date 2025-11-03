def fractional_knapsack(weights, profits, capacity):
    ratio = []
    for i in range(len(weights)):

        if weights[i] > 0:
            r = profits[i] / weights[i]
        else:

            r = float('inf') 
        ratio.append((r, weights[i], profits[i]))
        
    ratio.sort(reverse=True, key=lambda x: x[0])
    
    total_profit = 0
    selected_items = []
    
    for r, w, p in ratio:
        if capacity <= 0:
            break
            
        if w <= capacity:
            capacity -= w
            total_profit += p
            selected_items.append((w, p, 1.0))
        else:
            fraction = capacity / w
            total_profit += p * fraction
            selected_items.append((w, p, fraction))
            capacity = 0
            
    return total_profit, selected_items

def input_data():
    n = int(input("Enter number of parcels: "))
    weights = []
    profits = []
    for i in range(n):
        w = float(input(f"Enter weight of parcel {i+1}: "))
        p = float(input(f"Enter profit of parcel {i+1}: "))
        weights.append(w)
        profits.append(p)
    capacity = float(input("Enter truck capacity: "))
    return weights, profits, capacity

def display_result(selected, max_profit):
    print("\nSelected parcels:")
    for w, p, frac in selected:
        print(f"Weight: {w}, Profit: {p}, Taken: {frac*100:.2f}%")
    print(f"\nMaximum Profit: {max_profit:.2f}\n")


while True:
    print("\n=== Fractional Knapsack Menu ===")
    print("1. Enter Data and Calculate")
    print("2. Exit")
    choice = input("Enter choice: ")
    if choice == "1":
        weights, profits, capacity = input_data()
        max_profit, selected = fractional_knapsack(weights, profits, capacity)
        display_result(selected, max_profit)
    elif choice == "2":
        print("Exiting... Goodbye!")
        break
    else:
        print("Invalid choice. Try again.")