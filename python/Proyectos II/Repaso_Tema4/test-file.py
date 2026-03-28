import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.cluster import KMeans

# 1. Cargar datos
df = pd.read_csv("dataset.csv")

# 2. Separar features y target
X = df.drop(columns=["latitude"])
y = df["longitude"]

# 3. Dividir train/test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 4. Clustering
feats = X_train[["latitude", "longitude"]].to_numpy()