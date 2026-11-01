
#!/bin/bash

FILE="address.txt"
TEMP="temp.txt"

while true
do
    echo ""
    echo "========== ADDRESS BOOK =========="
    echo "1. Create"
    echo "2. View"
    echo "3. Insert"
    echo "4. Delete"
    echo "5. Modify"
    echo "6. Exit"
    echo "=================================="

    read -p "Enter choice: " ch

    case $ch in

    1)
        > "$FILE"
        echo "Address book created successfully."
        ;;

    2)
        if [ -f "$FILE" ]; then
            if [ -s "$FILE" ]; then
                echo "----- Address Book Records -----"
                cat "$FILE"
            else
                echo "Address book is empty."
            fi
        else
            echo "Address book does not exist. Please create it first."
        fi
        ;;

    3)
        touch "$FILE"
        read -p "Enter name: " name
        read -p "Enter phone: " phone

        echo "$name $phone" >> "$FILE"
        echo "Record inserted successfully."
        ;;

    4)
        if [ ! -f "$FILE" ]; then
            echo "Address book does not exist."
            break
        fi

        read -p "Enter name to delete: " name

        if grep -q "^$name " "$FILE"; then
            grep -v "^$name " "$FILE" > "$TEMP"
            mv "$TEMP" "$FILE"
            echo "Record deleted successfully."
        else
            echo "Record not found."
        fi
        ;;

    5)
        if [ ! -f "$FILE" ]; then
            echo "Address book does not exist."
            break
        fi

        read -p "Enter name to modify: " name

        if grep -q "^$name " "$FILE"; then
            read -p "Enter new name: " newname
            read -p "Enter new phone: " phone

            grep -v "^$name " "$FILE" > "$TEMP"
            echo "$newname $phone" >> "$TEMP"

            mv "$TEMP" "$FILE"
            echo "Record modified successfully."
        else
            echo "Record not found."
        fi
        ;;

    6)
        echo "Exiting Address Book..."
        exit 0
        ;;

    *)
        echo "Invalid choice. Please try again."
        ;;

    esac
done
