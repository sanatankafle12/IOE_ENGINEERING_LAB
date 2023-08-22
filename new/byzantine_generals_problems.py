import random

class ByzantineGenerals:
    def __init__(self, num_generals):
        self.num_generals = num_generals
        self.generals = []

    def add_general(self, general):
        self.generals.append(general)

    def send_message(self, sender, receiver, message):
        receiver.handle_message(sender, message)

    def simulate_attack(self):
        order = random.randint(0, 1) 

        print(f"Order from commander: {'ATTACK' if order == 1 else 'RETREAT'}")

        traitor_count = self.num_generals // 3
        traitors = random.sample(self.generals, traitor_count)

        for general in self.generals:
            if general in traitors:
                message = random.randint(0, 1)
            else:
                message = order

            self.send_message(general, general, message)

    def check_consensus(self):
        votes = []
        for general in self.generals:
            votes.append(general.get_vote())

        if votes.count(votes[0]) == len(votes):
            print(f"Consensus reached: {'ATTACK' if votes[0] == 1 else 'RETREAT'}")
        else:
            print("Consensus could not be reached.")

class General:
    def __init__(self, name, commander=None):
        self.name = name
        self.commander = commander
        self.vote = None

    def handle_message(self, sender, message):
        if self.commander is not None:
            self.commander.send_message(sender, self, message)
        else:
            self.vote = message

    def get_vote(self):
        return self.vote

generals = ByzantineGenerals(7)

g1 = General("General A")
g2 = General("General B")
g3 = General("General C")
g4 = General("General D")
g5 = General("General E")
g6 = General("General F")
g7 = General("General G")

generals.add_general(g1)
generals.add_general(g2)
generals.add_general(g3)
generals.add_general(g4)
generals.add_general(g5)
generals.add_general(g6)
generals.add_general(g7)

generals.simulate_attack()
generals.check_consensus()