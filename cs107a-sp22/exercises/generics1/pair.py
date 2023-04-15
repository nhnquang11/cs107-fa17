class Pair(object):
    """
    A generic Pair struct holding two items (which are meant to be of the same
    type).
    """
    def __init__(self, first, second):
        """
        Constructs a Pair of the given two items.
        """
        self.items = [first, second]

    def getFirst(self):
        """
        Returns the first item.
        """
        return self.items[0]

    def getSecond(self):
        """
        Returns the second item.
        """
        return self.items[1]

    def setFirst(self, first):
        """
        Sets the first item to the given value.
        """
        self.items[0] = first

    def setSecond(self, second):
        """
        Sets the second item to the given value.
        """
        self.items[1] = second

    def swap(self):
        """
        Swaps the two items' value in-place.
        """
        temp = self.items[0]
        self.items[0] = self.items[1]
        self.items[1] = temp

if __name__ == "__main__":
    score = Pair(0, 0)

    print(f"Current football score is {score.getFirst()} against {score.getSecond()}!")
    score.setFirst(7)
    print(f"Current football score is {score.getFirst()} against {score.getSecond()}!")
    score.setSecond(6)
    print(f"Current football score is {score.getFirst()} against {score.getSecond()}!")
    score.swap()
    print(f"Current football score is {score.getFirst()} against {score.getSecond()}!")

    instructor = Pair("Nick", "Parlante")
    print(f"This instructor's name is {instructor.getFirst()} {instructor.getSecond()}!");
    instructor.setFirst("Troccoli")
    print(f"This instructor's name is {instructor.getFirst()} {instructor.getSecond()}!");
    instructor.setSecond("Nicholas")
    print(f"This instructor's name is {instructor.getFirst()} {instructor.getSecond()}!");
    instructor.swap()
    print(f"This instructor's name is {instructor.getFirst()} {instructor.getSecond()}!");
