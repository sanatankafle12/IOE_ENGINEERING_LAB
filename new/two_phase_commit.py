class Coordinator:
    def __init__(self, participants):
        self.participants = participants

    def start_transaction(self):
        decision = self.send_prepare()
        if decision:
            self.send_commit()
        else:
            self.send_abort()

    def send_prepare(self):
        for participant in self.participants:
            response = participant.prepare()
            if not response:
                return False
        return True

    def send_commit(self):
        for participant in self.participants:
            participant.commit()

    def send_abort(self):
        for participant in self.participants:
            participant.abort()


class Participant:
    def __init__(self, name):
        self.name = name

    def prepare(self):
        return True 

    def commit(self):
        print(f"{self.name} - Committed.")

    def abort(self):
        print(f"{self.name} - Aborted.")


participant1 = Participant("Participant 1")
participant2 = Participant("Participant 2")
participant3 = Participant("Participant 3")

participants = [participant1, participant2, participant3]

coordinator = Coordinator(participants)
coordinator.start_transaction()