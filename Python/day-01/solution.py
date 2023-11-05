# Credit to https://galaxyinferno.com/how-to-solve-advent-of-code-2022-day-1-with-python/
# for this solution "im so ashamed that i had to copy for such a simple problem but i couldnt get the strings converted to int's in a 
# way that was useable"

#   with open('calories', 'r') as f:
#       lines = f.readlines()
#       calories = [entry.strip() for entry in lines]
#   
#       elf_sums = []
#       current_sum = 0
#   
#       for entry in calories:
#           if entry != '':
#               current_sum += int(entry)
#           elif entry == '':
#               elf_sums.append(current_sum)
#               current_sum = 0
#   
#       elf_sums.append(current_sum)
#       elf_sums.sort(reverse=True)
#       elf_sums[0]+elf_sums[1]+elf_sums[2]
#   
#       print(elf_sums)

with open('input', 'r') as f:
    lines = f.readlines()
    calories = [entry.strip() for entry in lines]

    elf_sums = []
    current_sum = 0

    for entry in calories:
        if entry != '':
            current_sum += int(entry)
        elif entry == '':
            elf_sums.append(current_sum)
            current_sum = 0

    elf_sums.append(current_sum)
    elf_sums.sort(reverse=True)
    print(elf_sums[0]+elf_sums[1]+elf_sums[2])
        
    print(elf_sums)
