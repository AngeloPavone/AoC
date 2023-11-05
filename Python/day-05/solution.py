import re


SHOW_ANSWER_FOR_PART2 = True


# TODO: add input array parsing i kinda cheated by putting it in manually
all_stacks = [
    ['r','g','j','b','t','v','z'],
    ['j','r','v','l'],
    ['s','q','f'],
    ['z','h','n','l','f','v','q','g'],
    ['r','q','t','j','c','s','m','w'],
    ['s','w','t','c','h','f'],
    ['d','z','c','v','f','n','j'],
    ['l','g','z','d','w','r','f','q'],
    ['j','b','w','v','p']
]



test_stacks = [
    ['z','n'],
    ['m','c','d'],
    ['p']
]


if SHOW_ANSWER_FOR_PART2 == True:
    def move_containers(instructions):
        try:
            for instruction in instructions:
                num_of_crates = instruction[0]
                start = all_stacks[instruction[1]-1]
                end = all_stacks[instruction[2]-1]

                count = 0
                buffer = []
                while count < num_of_crates:
                    current_crate = start.pop()
                    buffer.insert(0, current_crate)
                    count += 1
                end.extend(buffer)
        except Exception as e: print(e)

        return all_stacks


elif SHOW_ANSWER_FOR_PART2 == False:
    def move_containers(instructions):
        try:
            for instruction in instructions:
                num_of_crates = instruction[0]
                start = all_stacks[instruction[1]-1]
                end = all_stacks[instruction[2]-1]

                count = 0
                buffer = []
                while count < num_of_crates:
                    current_crate = start.pop()
                    end.append(current_crate)
                    count += 1
        except Exception as e: print(e)

        return all_stacks


def parse_input():
    with open('input', 'r') as f:
        lines = f.readlines()

    # parse input to remove all none numbers and conver the numbers to int
    instructions = []
    for instruction in lines:
        instruction = re.split('move | from | to |\n', instruction)
        while '' in instruction:
            instruction.remove('')
        instructions.append([eval(i) for i in instruction])

    return instructions

if __name__ == '__main__':
    stacks = move_containers(parse_input())
    try:
        for entry in stacks:
            print(entry[-1], end='')
    except:
        pass
