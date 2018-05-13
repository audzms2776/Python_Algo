"""
input 
Company Name 
Fisr1 lastName, Man2 Middel Flaset, Main Sataic 

output
lastnamefisr1@companyname.com
flasetman2@companyname.com
sataicmain@companyname.com
"""

name_dict = dict()


def name_print(company, email_name):
    if email_name in name_dict.keys():
        name_dict[email_name] += 1
    else:
        name_dict[email_name] = 0

    email_str = ''

    if name_dict[email_name] != 0:
        email_str = name_dict[email_name]

    print('{}{}@{}.com'.format(email_name, email_str, company))


company_name = input().lower().replace(' ', '')
man_list = input().lower()

mans = man_list.split(',')

for man in mans:
    names = man.split(' ')
    name_arr = []

    for n in names:
        if n != '':
            name_arr.append(n)

    if len(name_arr):
        name_print(company_name, name_arr[-1] + name_arr[0])
