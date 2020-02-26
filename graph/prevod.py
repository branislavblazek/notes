def index(letter):
    return ord(letter) - 65

#  Tuto funkci implementuj.
def convert_to_matrix(graph):
    vrcholy = list(graph.keys())
    vrcholy.sort()

    matrix = []
    for _ in vrcholy:
        row = []
        for _ in vrcholy:
            row.append(0)
        matrix.append(row)

    susedi = list(graph.items())
    for kluc, hodnoty in susedi:
        for hodnota in hodnoty:
            matrix[index(kluc)][index(hodnota)] = 1

    return matrix



# Testy:
# - je doporučeno přidat si vlastní
inputs = [
    {
        'A': ['B', 'C', 'D'],
        'B': ['A', 'C'],
        'C': ['A', 'B', 'D'],
        'D': ['A', 'C']
    },
    {
        'A': {'F', 'D', 'C'},
        'B': {'F', 'H', 'E', 'C', 'D', 'G'},
        'C': {'A', 'F', 'B', 'D', 'G'},
        'D': {'A', 'F', 'H', 'E', 'B', 'C', 'G'},
        'E': {'F', 'D', 'B', 'G'},
        'F': {'A', 'E', 'B', 'C', 'D', 'G'},
        'G': {'F', 'E', 'B', 'C', 'D'},
        'H': {'B', 'D'}
    },
    {
        'A': ['B', 'C'],
        'B': ['A', 'C'],
        'C': ['A', 'D'],
        'D': ['A', 'B', 'C']
    }
]

outputs = [
    [
        [0, 1, 1, 1],
        [1, 0, 1, 0],
        [1, 1, 0, 1],
        [1, 0, 1, 0]
    ],
    [
        [0, 0, 1, 1, 0, 1, 0, 0],
        [0, 0, 1, 1, 1, 1, 1, 1],
        [1, 1, 0, 1, 0, 1, 1, 0],
        [1, 1, 1, 0, 1, 1, 1, 1],
        [0, 1, 0, 1, 0, 1, 1, 0],
        [1, 1, 1, 1, 1, 0, 1, 0],
        [0, 1, 1, 1, 1, 1, 0, 0],
        [0, 1, 0, 1, 0, 0, 0, 0]
    ],
    [
        [0, 1, 1, 0],
        [1, 0, 1, 0],
        [1, 0, 0, 1],
        [1, 1, 1, 0]
    ]
]
# malá nápověda pro tebe:
# https://graphonline.ru/en/create_graph_by_matrix
# - tady si můžeš nechat vykreslit tvoje grafy

for i, test in enumerate(inputs):
    print(convert_to_matrix(test) == outputs[i])  # True
