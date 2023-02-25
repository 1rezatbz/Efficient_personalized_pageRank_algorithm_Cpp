from graph import Graph

class Pagerank:
    """
    Rank(n, t + 1) = (1 - d) / number_of_nodes
             + d *
             sum { Rank(in_neighbour_of_n, t) /out_degree(in_neighbour_of_n)}
    """

    def __init__(self, n_iteration: int, graph: Graph, damping_factor: float = 0.85):
        self.graph = graph
        self.n_iteration = n_iteration
        self.damping_factor = damping_factor
        self.node_cnt = graph.GetNodeCount()

    @staticmethod
    def normalise(rank: dict) -> dict:
        sum_rank = sum(rank.values())
        normalised_rank = {i: (j / sum_rank) for i, j in rank.items()}
        return normalised_rank

    def rankIteration(self, edges: list, old_rank: dict, personalisation: dict = None):
        new_rank = {i: 0 for i in range(self.graph.GetNodeCount())}
        for i in edges:
            fr, to = i
            new_rank[to] += old_rank[fr] / self.graph.GetOutDegree(fr)
        damp = {i: (1-self.damping_factor)* j for i,j in personalisation.items()}
        rank = {i: self.damping_factor*j for i,j in new_rank.items()}
        new = [i+j for i, j in zip(damp.values(), rank.values())]
        nn = {i: new[i] for i in range(self.node_cnt)}
        return nn

    def calculate(self, personalisation: dict = None):
        edges = self.graph.GetOrderedEdges()
        old_rank = {i: (1 / self.node_cnt) for i in range(self.node_cnt)}
        if personalisation:
              s = sum(personalisation.values())
              p = {i: (personalisation.get(i,0) / s) for i in range(self.node_cnt)}

        else:
            p = {i: (1/self.graph.GetNodeCount()) for i in range(self.graph.GetNodeCount())}
        for i in range(self.n_iteration):
            old_rank = self.rankIteration(edges, old_rank, p)
        # normalised_rank = self.normalise(old_rank)
        return old_rank


if __name__ == '__main__':
    reza = Graph(6, 10)
    reza.InsertNodes ([(0,1),(1,0),(1,2),(0,2),(2,3),(3,2),(4,3),(5,3),(4,5),(5,4)])
    # personalization = {0: 0, 1: 0, 2: 0, 3: 1, 4: 0, 5: 0}
    personalization = {3: 1}
    pr = Pagerank(100 ,reza)
    p = pr.calculate(personalization)
    print(p)