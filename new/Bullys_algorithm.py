import time

class BullyAlgorithm:
    def __init__(self, process_id, processes):
        self.process_id = process_id
        self.processes = processes
        self.coordinator = None

    def start_election(self):
        print(f"Process {self.process_id} initiates election.")
        for process in self.processes:
            if process > self.process_id:
                try:
                    response = self.send_message(process, "ELECTION")
                    if response == "OK":
                        print(f"Process {process} responded to election message.")
                        return
                except ConnectionError:
                    print(f"Process {process} did not respond to election message.")
        self.become_coordinator()

    def send_message(self, process, message):
        time.sleep(1)  # Simulating network delay
        if process == self.coordinator:
            return "OK"
        else:
            raise ConnectionError("Process is not reachable.")

    def become_coordinator(self):
        self.coordinator = self.process_id
        print(f"Process {self.process_id} becomes the coordinator.")

    def handle_message(self, sender, message):
        if message == "ELECTION":
            print(f"Process {self.process_id} received election message from {sender}.")
            self.send_message(sender, "OK")
            self.start_election()
        elif message == "COORDINATOR":
            print(f"Process {self.process_id} received coordinator message from {sender}.")
            self.coordinator = sender

# Example usage
processes = [1, 2, 3, 4, 5]
bully = BullyAlgorithm(3, processes)
bully.start_election()