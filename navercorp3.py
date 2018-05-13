"""

"""


def solution(n: int):
    import itertools

    my_str = str(n)
    q_list = list(itertools.permutations(my_str))
    nums = []

    for ii in q_list:
        nums.append(''.join(ii))

    npp = list(set(nums))
    new_n = []

    for h in npp:
        temp_h = str(int(h))

        if len(temp_h) == len(h):
            new_n.append(h)

    # print(new_n)
    return len(new_n)


if __name__ == '__main__':
    solution(1000000000)
