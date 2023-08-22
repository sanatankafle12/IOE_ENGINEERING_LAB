import time

class Node:
    def __init__(self, node_id):
        self.node_id = node_id
        self.is_leader = False

    def start_election(self, nodes):
        higher_nodes = [node for node in nodes if node.node_id > self.node_id]
        
        print(f"Node {self.node_id} is starting an election.")
        
        higher_leader_exists = False
        for higher_node in higher_nodes:
            response = higher_node.send_election_response(self)
            
            if response == "OK":
                higher_leader_exists = True
                print(f"Node {higher_node.node_id} responded to Node {self.node_id}.")
                break
        
        if not higher_leader_exists:
            self.become_leader()
            self.announce_leader(nodes)

    def send_election_response(self, requesting_node):
        if not self.is_leader:
            print(f"Node {self.node_id} sends 'OK' response to Node {requesting_node.node_id}.")
            return "OK"
        else:
            print(f"Node {self.node_id} is the leader and sends 'BUSY' response to Node {requesting_node.node_id}.")
            return "BUSY"
        
    def announce_leader(self, nodes):
        for node in nodes:
            node.receive_leader_announcement(self)
        
    def receive_leader_announcement(self, leader_node):
        if leader_node == self:
            self.is_leader = True
            print(f"Node {self.node_id} updates to be the new leader.")
        else:
            self.is_leader = False

    def become_leader(self):
        self.is_leader = True
        print(f"Node {self.node_id} becomes the leader.")

def simulate_election_process():
    nodes = [Node(1), Node(2), Node(3), Node(4)]
    
    # Initial leader failure
    print("Leader failure")
    leader_node = nodes[3]
    leader_node.is_leader = False
    
    # Node 3 starts an election
    nodes[2].start_election(nodes)
    time.sleep(1)
    
    # Add a new node
    nodes.append(Node(5))
    
    # Trigger new election after leader failure and new node addition
    print("\nNew election after leader failure and new node addition:")
    nodes[4].start_election(nodes)
    time.sleep(1)

# Simulate the election process with verbose message logging
simulate_election_process()
