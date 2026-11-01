#!/bin/bash
while true
do
echo "1.Create"
echo "2.View"
echo "3.Insert"
echo "4.Delete"
echo "5.Modify"
echo "6.Exit"
read -p "Enter choice: " ch
case $ch in
1)
> address.txt
echo "Address book created"
;;
2)
cat address.txt
;;
3)
read -p "Enter name: " name
read -p "Enter phone: " phone
echo "$name $phone" >> address.txt
;;
4)
read -p "Enter name to delete: " name
grep -v "^$name " address.txt > temp.txt
mv temp.txt address.txt
echo "Record deleted"
;;
5)
read -p "Enter name to modify: " name
if grep -q "^$name " address.txt
then
read -p "Enter new name: " newname
read -p "Enter new phone: " phone
grep -v "^$name " address.txt > temp.txt
echo "$newname $phone" >> temp.txt
mv temp.txt address.txt
echo "Record modified"
else
echo "Record not found"
fi
;;
6)
exit
;;
*)
echo "Invalid choice"
;;
esac
