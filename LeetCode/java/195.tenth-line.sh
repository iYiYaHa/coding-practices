tail -n +10 file.txt|head -n 1

awk '{NR==10 print}' file.txt

sed -n 10p file.txt