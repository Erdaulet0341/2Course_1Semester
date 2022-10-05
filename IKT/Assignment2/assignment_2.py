
'''
The objective of this assignment is to print the dataframe showed in the instruction.
Only one test will be done.
You can write you code after this comment :
'''
#Your code here:

import pandas as pd;

# 1)Create DataFrame with LISTS
datas1 = [['Brad', 'Pitt', 58], ['Angelina', 'Jolie', 47], ['Tom', 'Cruise', 60]]
colum_names = ['Name', 'Surname', "Age"]
df1 = pd.DataFrame(datas1, columns=colum_names)
print(df1, '\n')

# 2) Create DataFrame with DICTIONARY
datas2 = {'Name':['Brad', 'Angelina', 'Tom'],
          'Surname': ['Pitt', 'Jolie', 'Cruise'],
          'Age':[58, 47, 60]}
df2 = pd.DataFrame(datas2)
print(df2, '\n')

# 3) Create DataFrame using Dictionary of Pandas Series
datas3 = {'Name': pd.Series(['Brad', 'Angelina', 'Tom']),
          'Surname': pd.Series(['Pitt', 'Jolie', 'Cruise']),
          'Age': pd.Series([58, 47, 60])}
df3 = pd.DataFrame(datas3)
print(df3, '\n')

# 4) Create DataFrame using csv file
datas4 = pd.read_csv(r"D:\Educational materials\2Course_1Semester\2Course_1Semester\IKT\Assignment2\2.csv")
print(datas4)