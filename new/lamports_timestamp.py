class LamportClock:
    def __init__(self):
        self.time = 0
    
    def increment(self):
        self.time += 1
    
    def update(self, received_time):
        self.time = max(self.time, received_time) + 1
    
    def get_time(self):
        return self.time


clock_A = LamportClock()
clock_B = LamportClock()
clock_C = LamportClock()

# Process A
clock_A.increment()
clock_A.increment()
clock_A.increment()
event_a_time = clock_A.get_time()

# Process A sends a message to Process B
message = {'time': event_a_time}
clock_A.increment()

# Process B receives the message from Process A
received_time = message['time']
clock_B.update(received_time)

# Process B performs some internal events
clock_B.increment()
clock_B.increment()
event_b_time = clock_B.get_time()

# Process B sends a message to Process C
message = {'time': event_b_time}
clock_B.increment()

# Process C receives the message from Process B
received_time = message['time']
clock_C.update(received_time)

# Process C performs some internal events
clock_C.increment()
clock_C.increment()
event_c_time = clock_C.get_time()

print(f"Process A time: {event_a_time}")
print(f"Process B time: {event_b_time}")
print(f"Process C time: {event_c_time}")