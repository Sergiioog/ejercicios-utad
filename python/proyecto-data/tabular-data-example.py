import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('basic-dataset.csv')
#print(">>> Dataframe basico ", df)

dfV2 = df.sample(n=5) #Con sample se seleccionan 5 filas de forma random
# print(dfV2)

print(dfV2.sort_values(by='salary', ascending=False)) #Con sort values ordenamos en base a una feature

plt.style.use('fivethirtyeight')