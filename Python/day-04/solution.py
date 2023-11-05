# shamefuly solved with the help of chatGPT because im a dog shit programmer

def count_fully_contained_pairs():
    with open('input', 'r') as f:
        lines = f.readlines()

        count = 0
        for pair in lines:
            range1, range2 = pair.split(',')
            start1, end1 = range1.split('-')
            start2, end2 = range2.split('-')
            start1, end1 = int(start1), int(end1)
            start2, end2 = int(start2), int(end2)

            if start1 <= start2 and end1 >= end2 or start2 <= start1 and end2 >= end1:
                count += 1


    return count


def count_semi_contained_pairs():
    with open('input', 'r') as f:
        count = 0
        lines = f.readlines()

        for pair in lines:
            range1, range2 = pair.split(',')
            start1, end1 = range1.split('-')
            start2, end2 = range2.split('-')
            start1, end1 = int(start1), int(end1)
            start2, end2 = int(start2), int(end2)


            if start1 <= start2 and end1 >= end2 or start2 <= start1 and end2 >= end1:
                count +=1
            elif start1 <= start2 and start2 <= end1 and end1 <= end2 and start1 <= end1 or start2 <= end2 and start2 <= start1 and start1 <= end2 and end2 <= end1:
                count +=1



    return count


if __name__ == "__main__":
    print(f'answer: {count_fully_contained_pairs()}')
    print(f'answer: {count_semi_contained_pairs()}')
