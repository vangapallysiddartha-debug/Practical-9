INF = 9999


n = int(input("Enter number of vertices: "))


graph = []

print("Enter the adjacency matrix:")

for i in range(n):
    row = list(map(int, input().split()))

    
    for j in range(n):
        if row[j] == 0:
            row[j] = INF

    graph.append(row)


selected = [0] * n

totalCost = 0


selected[0] = 1

print("\nEdges in Minimum Spanning Tree:")


for edge in range(n - 1):

    minWeight = INF
    x = -1
    y = -1


    for i in range(n):
        if selected[i]:
            for j in range(n):
                if not selected[j] and graph[i][j] < minWeight:
                    minWeight = graph[i][j]
                    x = i
                    y = j

    selected[y] = 1

    print(x, "-", y, ":", minWeight)

    totalCost += minWeight

print("\nMinimum Cost =", totalCost)
