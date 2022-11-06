'''
The objective of this assignment is to clean the csv file of the attendance.
The path to the csv file is "attendance_to_clean.csv"
You can find it in the instruction folder.
List of installed and authorized packages :
    - csv
    - pandas
    - datetime
    - numpy
You cannot use other packages than the listed ones (except built-in default package in python).
You can write you code after this comment :
'''

#Your code here:
import pandas as pd
import csv
import datetime
import numpy as np

with open('attendance_to_clean.csv', 'r') as file1:
    df = pd.read_csv(file1)

#print('All =', len(df))

#1rt
df['NAME_STUDENT'].replace('error', np.nan, inplace=True)

#2nd
df['NAME_STUDENT'].replace('10', np.nan, inplace=True)
df['NAME_STUDENT'].replace('Kaiyrzhan Shynggys', np.nan, inplace=True)
df['WEEK'].replace('_', np.nan, inplace=True)
df['WEEK'].replace('8', np.nan, inplace=True)
df['BEGIN_HOUR'].replace('_', np.nan, inplace=True)
df['BEGIN_HOUR'].replace('23', np.nan, inplace=True)
df['COUNT'].replace('two', np.nan, inplace=True)
df['COUNT'].replace('error', np.nan, inplace=True)
df['DATE'].replace('error', np.nan, inplace=True)

df['WEEK'] = df['WEEK'].astype(float)
df['BEGIN_HOUR'] = df['BEGIN_HOUR'].astype(float)
df['COUNT'] = df['COUNT'].astype(float)
df['DATE'] = pd.to_datetime(df['DATE'])

#3rd
q1 = df['COUNT'].quantile(0.15)
q3 = df['COUNT'].quantile(0.90)
iqr1 = q3-q1
df = df[~((df['COUNT'] < (q1 - 1.5 * iqr1)) | (df['COUNT'] > (q3 + 1.5 * iqr1)))]

#4th
df = df.dropna()
#print('After drop NaN =', len(df))


#5th
df = df.drop_duplicates()
#print('After drop duplicates = ', len(df))

#6th
df = df.sort_values(by=['NAME_STUDENT','DATE', 'BEGIN_HOUR', 'WEEK'], ignore_index=True)
print(df)