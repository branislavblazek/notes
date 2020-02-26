# Tuto a ani nasledujucu funkciu nemente.
def contains_cycle(v, e):
    visited = {vert: False for vert in v}
    con = {vert: set() for vert in v}
    for a, b, w in e:
        con[a].add(b), con[b].add(a)
    for vert in v:
        if not visited[vert]:
            if contains(vert, con, visited):
                return True
    return False


def contains(vert, con, visited, parent=None):
    visited[vert] = True
    for neighbour in con[vert]:
        if not visited[neighbour]:
            if contains(neighbour, con, visited, vert):
                return True
        elif neighbour != parent:
            return True
    return False


# Tuto funkciu implementuj.
def optimize_network(colonies, paths):
    network, total_len = [], 0
    # Do magic
    return network, total_len

# Testy
print(optimize_network(["Umo", "Fumo", "Guro"],
                       [("Umo", "Fumo", 1),
                        ("Fumo", "Guro", 3)
                        ]))
"""
([('Umo', 'Fumo', 1),
  ('Fumo', 'Guro', 3)
  ], 4)
"""
print(optimize_network(["Umo", "Fumo", "Guro", "Lumo"],
                       [("Umo", "Fumo", 1),
                        ("Fumo", "Umo", 3)
                        ]))
"""
([], 0)
"""
print(optimize_network(["Umo", "Fumo", "Guro", "Lumo"],
                       [("Umo", "Fumo", 3),
                        ("Umo", "Guro", 2),
                        ("Guro", "Lumo", 4),
                        ("Fumo", "Lumo", 5),
                        ("Lumo", "Umo", 6)
                        ]))
"""
([('Umo', 'Guro', 2),
  ('Umo', 'Fumo', 3),
  ('Guro', 'Lumo', 4)
  ], 9)
"""
