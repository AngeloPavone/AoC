def get_input():
    with open('input', 'r') as f:
        input = f.readlines()
        result = input[0]
    return result

def parse_input(input):
    buffer = []
    fuckme = set()

    for char in range(len(input) - 3):
        buffer.extend(input[char:char + 4])
        try:
            for char1 in buffer:
                fuckme.add(char1)
            if len(fuckme) == 4:
                return char + 4
            else:
                fuckme.clear()
        except:
            pass
        buffer.clear()

def parse_input2(input):
    buffer = []
    fuckme = set()

    for char in range(len(input) - 13):
        buffer.extend(input[char:char + 14])
        try:
            for char1 in buffer:
                fuckme.add(char1)
            if len(fuckme) == 14:
                return char + 14
            else:
                fuckme.clear()
        except:
            pass
        buffer.clear()


if __name__ == "__main__":
    print(parse_input(get_input()))
    print(parse_input2(get_input()))
