# Read from the file file.txt and output all valid phone numbers to stdout.
grep -E '^\([[:digit:]]{3}\) [[:digit:]]{3}-[[:digit:]]{4}$|^[0-9]{3}-[0-9]{3}-[0-9]{4}$' file.txt

sed -n -E '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt

awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/ {print}' file.txt