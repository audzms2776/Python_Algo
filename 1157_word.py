# https://www.acmicpc.net/problem/1157
if __name__ == '__main__':
    str = input()
    str = str.upper()
    char_dict = dict()

    for i in str:
        if i in char_dict.keys():
            char_dict[i] += 1
        else:
            char_dict[i] = 1

    max_value = max([(char_dict[key], key) for key in char_dict])

    print(max_value)

    if list(char_dict.values()).count(max_value[0]) is 1:
        print(max_value[1])
    else:
        print('?')
