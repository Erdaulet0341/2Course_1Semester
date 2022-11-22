import numpy as np
from sklearn.linear_model import LinearRegression


l1 = [6,10,2,3,4,0,7,8,9,1]
l2 = [130, 21, 43, 76, 105, 3, 167, 162]

x1 = np.array(l1).reshape((-1, 1))
y = np.array(l2).reshape((-1, 1))

x2 = []
x3 = []

for i in x1:
    x2.append(i*i)
    
for i in x1:
    x3.append(i*i*i)
