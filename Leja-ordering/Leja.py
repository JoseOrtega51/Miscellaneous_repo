# -*- coding: utf-8 -*-

import numpy as np

def ordenLeja(x):
    x=-np.sort(-x)    #Ordenamos el array de mayor a menor
    n=len(x)        #Tamaño del vector input
    y=np.zeros(n)   #Vector para guaaradar la solucion
    
    x=x[np.newaxis]
    
    e=np.ones(n)    #Vector de 1's: e=[1,1,...,1]
    e=e[np.newaxis]
    
    M=np.abs(e.T*x-x.T*e)       #Matriz que contiene los valores absolutos de las diferencias.
    
    J=list(np.arange(n))  #Indices sin asignar
    
    y[0]=x[0][0]    #Asignamos el máximo como inicio
    J.remove(0)
    productos=M[0,:]
    
    for i in range (n-1):
        aux=np.argmax(productos[J])     #En caso de igualdad, por ser x decreciente, se tomará el máximo.
        ind=J[aux]
        J.remove(ind)
        y[i+1]=x[0][ind]
        productos=productos*M[ind,:]
        
    return(y)


# x=np.array([0,1/3,2/3,1])
x=np.array([0,1/4,1/2,3/4,1])
# x=np.array([-1,-1/3,1/3,1])
# x=np.array([0,1/5,2/5,3/5,4/5,1])

print(ordenLeja(x))
