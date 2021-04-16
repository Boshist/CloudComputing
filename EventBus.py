class EventBus():

    def __init__(self):
        self.subscribers = dict()

    def Subscribe(self, event, callback):
        if event not in self.subscribers.keys():
            self.subscribers[event] = [callback]
        else:
            self.subscribers[event].append(callback)

    def RaiseEvent(self, event, *args):
        if event in self.subscribers.keys():
            for callback in self.subscribers[event]:
                callback(args)

    def Unsubscribe(self, event, callback):        
        if event in self.subscribers.keys():
            self.subscribers[event].remove(callback)

def receiveNumber(args):

    if len(args) > 1:
        user = str(args[0])
        number = str(args[1])
        print(user + " received " + number)

def mySum(args):

    totalSum = 0
    for num in args:
        totalSum += int(num)

    print("sum = " + str(totalSum))

bus = EventBus()

bus.Subscribe("Event1", receiveNumber)
bus.Subscribe("Event1", mySum)
bus.Subscribe("Event2", receiveNumber)

bus.RaiseEvent("Event1", 1, 2, 3, 4, 5)
bus.RaiseEvent("Event2", "Alex", 5)

bus.Unsubscribe("Event1", receiveNumber)
