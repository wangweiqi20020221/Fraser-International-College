# Write the python code as the way of Java
class Time:
    __time = {"Year": 0, "Month": 0, "Day": 0}

    def getYear(self):
        return self.__time["Year"]

    def setYear(self, year):
        self.__time["Year"] = year

    def getMonth(self):
        return self.__time["Month"]

    def setMonth(self, month):
        self.__time["Month"] = month

    def getDay(self):
       return self.__time["Day"]

    def setDay(self, day):
        self.__time["Day"] = day

    def format(self, date):
        """
        format the date, from '23-2-2023' to "2023-2-23"
        
        :param date: Str().
        :return: Str().
        """
        # transfer date to list
        l = [""]
        i = 0
        for character in date:
            if character == "-":
                i += 1
                l.append("")
            else:
                l[i] += character
        self.setYear(int(l[2]))
        self.setMonth(int(l[1]))
        self.setDay(int(l[0]))
        return str(self.getYear()) + "-" + str(self.getDay()) + "-" + str(self.getMonth())

t = Time()
print(t.format("23-2-2023"))
