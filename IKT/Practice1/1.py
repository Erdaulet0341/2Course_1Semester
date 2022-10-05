import csv

def print_arrays(l):
    for i in l:
        print(i)


fields = []
rows = []

path = r"D:\Educational materials\2Course_1Semester\2Course_1Semester\IKT\Practice1\IRM.csv"
with open(path, 'r') as csvFile:
    csvreader = csv.reader(csvFile)
    
    fields = next(csvreader)
    
    for row in csvreader:
        rows.append(row)

print('Field names are:' + ', '.join(field for field in fields))

date, openn, high, low, close, ajd, volume = [], [], [], [], [], [], []

for i in range(10):
    date.append(rows[i][0])
    openn.append(rows[i][1])
    high.append(rows[i][2])
    low.append(rows[i][3])
    close.append(rows[i][4])
    ajd.append(rows[i][5])
    volume.append(rows[i][6])

print_arrays(close)