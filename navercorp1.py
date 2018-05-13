def solution(a, b, c, d, e, f):
    def time_check(s):
        t = ''

        if len(s) == 0:
            t = '00'
        elif len(s) == 1:
            t = '0' + int(s)
        else:
            if s[0] < s[1]:
                t = s[0] + s[1]
            else:
                t = s[1] + s[0]

        return t

    can_first = []
    dont_first = []
    nums = [a, b, c, d, e, f]

    # main code
    for n in nums:
        if n >= 6:
            dont_first.append(n)
        else:
            can_first.append(n)

    hour_str = ''
    min_str = ''
    sec_str = ''

    if len(dont_first) >= 4:
        print('NOT POSSIBLE')
        return

    can_first.sort()
    dont_first.sort()

    dont_first.reverse()

    for idx, df in enumerate(dont_first):
        if idx == 0:
            sec_str = str(df)
        elif idx == 1:
            min_str = str(df)
        else:
            hour_str = str(df)

    for idx, cf in enumerate(can_first):
        if len(hour_str) != 2:
            hour_str = str(cf) + hour_str
        elif len(min_str) != 2:
            min_str = str(cf) + min_str
        else:
            sec_str = str(cf) + sec_str

    hour_str = time_check(hour_str)
    min_str = time_check(min_str)
    sec_str = time_check(sec_str)

    if int(hour_str) >=  24:
        print('NOT POSSIBLE')
        return

    print('{}:{}:{}'.format(hour_str, min_str, sec_str)) 


if __name__ == '__main__':
    solution(2,9,9,3,2,9)
