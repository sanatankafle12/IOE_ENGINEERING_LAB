import random


class PBFTNode:
    def __init__(self, node_id, total_nodes):
        self.node_id = node_id
        self.total_nodes = total_nodes
        self.state = "INIT"
        self.proposed_value = None
        self.prepare_count = 0
        self.commit_count = 0

    def send_message(self, receiver, message):
        print(
            f"Node {self.node_id} sends {message['type']} to Node {receiver}")

    def receive_message(self, sender, message):
        self.process_message(sender, message)

    def propose_value(self, value):
        if self.state == "INIT":
            self.proposed_value = value
            self.state = "PRE_PREPARE"
            print(f"Node {self.node_id} proposes value: {self.proposed_value}")
            for i in range(self.total_nodes):
                if i != self.node_id:
                    self.send_message(
                        i, {"type": "PRE_PREPARE", "value": self.proposed_value})

    def handle_pre_prepare(self, sender, message):
        self.state = "PRE_PREPARE"
        if self.state == "PRE_PREPARE":
            self.state = "PREPARE"
            print(f"Node {self.node_id} receives PRE_PREPARE from {sender}")
            for i in range(self.total_nodes):
                if i != self.node_id:
                    self.send_message(
                        i, {"type": "PREPARE", "value": message["value"]})

    def handle_prepare(self, sender, message):
        if self.state == "PREPARE":
            self.prepare_count += 1
            print(f"Node {self.node_id} receives PREPARE from {sender}")
            if self.prepare_count >= (self.total_nodes // 2) + 1:
                print(
                    f'Prepare count reached threshold for Node {self.node_id}')
                self.state = "COMMIT"
                print(f"Node {self.node_id} reaches COMMIT state")
                for i in range(self.total_nodes):
                    if i != self.node_id:
                        self.send_message(
                            i, {"type": "COMMIT", "value": message["value"]})

    def handle_commit(self, sender, message):
        if self.state == "COMMIT":
            self.commit_count += 1
            print(f"Node {self.node_id} receives COMMIT from {sender}")
            if self.commit_count >= (self.total_nodes // 2) + 1:
                print(
                    f"Node {self.node_id} decides on value: {message['value']}")

    def process_message(self, sender, message):
        message_type = message["type"]
        if message_type == "PRE_PREPARE":
            self.handle_pre_prepare(sender, message)
        elif message_type == "PREPARE":
            self.handle_prepare(sender, message)
        elif message_type == "COMMIT":
            self.handle_commit(sender, message)


def main():
    total_nodes = 4
    nodes = [PBFTNode(node_id, total_nodes) for node_id in range(total_nodes)]

    # Choose Node 0 as the primary node and choose a value to find consensus on
    primary_node = nodes[0]
    value_to_consensus = random.choice(["ATTACK", "RETREAT"])
    primary_node.propose_value(value_to_consensus)

    # Simulate receiving messages for the PRE_PREPARE phase
    for node in nodes:
        if node != primary_node:
            node.receive_message(primary_node.node_id, {
                                 "type": "PRE_PREPARE", "value": value_to_consensus})

    # Simulate receiving prepare messages from other nodes
    for node in nodes:
        for other_nodes in nodes:
            if other_nodes != node:
                node.handle_prepare(other_nodes.node_id, {
                                    "type": "PREPARE", "value": value_to_consensus})

    # Simulate sending and receiving messages for the COMMIT phase
    for node in nodes:
        if node.node_id != 0:
            node.handle_commit(primary_node.node_id, {
                               "type": "COMMIT", "value": value_to_consensus})


if __name__ == "__main__":
    main()
