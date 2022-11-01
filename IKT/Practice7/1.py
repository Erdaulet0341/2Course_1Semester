import csv
list1 = []
list2 = []
with open(r'D:\Educational materials\2Course_1Semester\2Course_1Semester\IKT\Practice7\list_symbols_euronext.csv', 'r') as file1:
    csv1_reader = csv.reader(file1)
    list1 = list(csv1_reader)
    
with open(r'D:\Educational materials\2Course_1Semester\2Course_1Semester\IKT\Practice7\list_symbols_US.csv', 'r') as file2:
    csv2_reader = csv.reader(file2)
    list2 = list(csv2_reader)
    
finalList = list1+list2 
for i in finalList[0:10]:
    print(i[1])