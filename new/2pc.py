import random

class Node:
    def __init__(self, name):
        self.name = name
        self.voted = False
        self.committed = False
    
    def receive_prepare_msg(self):
        print(f"{self.name} received Prepare message")
    
    def respond_with_yes(self):
        self.voted = random.random() < 0.8
        return self.voted
    
    def receive_global_commit_msg(self):
        print(f"{self.name} received Global Commit message")
    
    def receive_global_abort_msg(self):
        print(f"{self.name} received Global Abort message")
    
    def send_ack(self):
        print(f"{self.name} sent acknowledgment")

class Coordinator:
    def __init__(self, nodes):
        self.nodes = nodes
    def start_transaction(self):
        self.send_prepare()
        all_votes_yes = self.collect_reply()
        if all_votes_yes:
            self.send_global_commit_msg()
            self.recieve_ack()
            print("Transaction commited")
        else:
            self.send_global_abort_msg()
            self.recieve_ack()
            print("Transaction aborted")

    def send_prepare(self):
        for node in self.nodes:
            node.receive_prepare_msg()
    
    def collect_reply(self):
        for node in self.nodes:
            print(f"Asking {node.name} to prepare")
            if node.respond_with_yes():
                print(f"{node.name} votes YES.")
            else:
                print(f"{node.name} votes NO.")
            print(f"----------------------")
        all_votes_yes = all(node.voted for node in self.nodes)
        return all_votes_yes
    
    def send_global_commit_msg(self):
        for node in self.nodes:
            node.receive_global_commit_msg()
    
    def send_global_abort_msg(self):
        for node in self.nodes:
            node.receive_global_abort_msg()
    
    def recieve_ack(self):
        for node in self.nodes:
            node.send_ack()

# Create nodes
node1 = Node("Node 1")
node2 = Node("Node 2")
node3 = Node("Node 3")
# Create coordinator with nodes
coordinator = Coordinator([node1, node2, node3])
# Start transaction
coordinator.start_transaction()