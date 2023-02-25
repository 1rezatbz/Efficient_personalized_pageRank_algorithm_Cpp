class Graph:
    def __init__(self, numberOfNodes: int, numberOfEdges: int):
        self.numberOfNodes = numberOfNodes
        self.numberOfEdges = numberOfEdges
        self.adjacentDict = {i: [] for i in range(self.numberOfNodes)}
        self.edges = []
        self.OutDegree = {i: 0 for i in range(self.numberOfNodes)}
        self.inDegree = {i: 0 for i in range(self.numberOfNodes)}

    def InsertNodes(self, edges_list: list):
        for i in edges_list:
            self.adjacentDict[i[0]].append(i[1])
            self.OutDegree[i[0]] += 1
            self.inDegree[i[1]] += 1
            self.edges.append(i)

    def GetNodeCount(self):
        return self.numberOfNodes

    def GetEdgeCount(self):
        return self.numberOfEdges

    def GetOrderedEdges(self):
        return self.edges

    def GetOutDegree(self, nodeId):
        return self.OutDegree.get(nodeId)

    def GetInDegree(self, nodeId):
        return self.inDegree.get(nodeId)

    def DangleNodeList(self):
        return [k for k, v in self.OutDegree.items() if v ==0]