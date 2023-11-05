table1 = dict({
    "A X\n":4,
    "A Y\n":8,
    "A Z\n":3,
    "B X\n":1,
    "B Y\n":5,
    "B Z\n":9,
    "C X\n":7,
    "C Y\n":2,
    "C Z\n":6,
    "C X":7,  
})

table2 = dict({
    "A X\n":"A Z\n",
    "A Y\n":"A X\n",
    "A Z\n":"A Y\n",
    "B X\n":"B X\n",
    "B Y\n":"B Y\n",
    "B Z\n":"B Z\n",
    "C X\n":"C Y\n",
    "C Y\n":"C Z\n",
    "C Z\n":"C X\n",

    "C X":"C Y\n",  
})

def part2(table1, table2):

    total_score = 0

    with open('input') as f:
        for line in f:
            total_score += table1.get(table2.get(line))

    return total_score


def part1(table1):

    total_score = 0

    with open('input') as f:
        for line in f:
                total_score = total_score + table1.get(line)

    return total_score


print(f'Part 1 Answer = {part1(table1)}')
print(f'Part 2 Answer = {part2(table1, table2)}')
