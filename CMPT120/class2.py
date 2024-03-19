"""
Copyright: Weiqi Wang, WANW7D1903
           Fraser International College
           Instructor: Koopa H.
"""
import random


def accrued_account(principle_amount, years):
    """
    Q1. Calculates the accrued total amount given a principal amount and time period in years.
    :param years: Int.
    :param principle_amount: Int or Float.
    :return: {"totalAmount": total_amount}
             {"error": "Wrong principle amount"} when principle_amount < 0
    """
    if 0 <= principle_amount < 1000:
        interest_rate = 0.025
    elif 1000 <= principle_amount < 10000:
        interest_rate = 0.02
    elif 10000 <= principle_amount < 100000:
        interest_rate = 0.015
    elif 100000 <= principle_amount:
        interest_rate = 0.01
    else:
        return {"error": "Wrong principle amount"}
    return {"totalAmount": principle_amount * (1 + interest_rate * years)}


def salary_calculator(dependents, work_time):
    """
    Q3. Calculate the salary.
    :param dependents: Int.
    :param work_time: Int or Float.
    :return: {"grossPay": gross_pay, "socialSecurityTax": social_security_tax, "federalIncomeTax": federal_income_tax
              "stateIncomeTax": state_income_tax, "takeHomePay": take_home_pay, "healthInsurance": health_insurance}
    """
    initial = {"salary": 16.78, "social_security_tax": 0.06, "federal_income_Tax": 0.14, "state_income_tax": 0.05,
               "union_dues": 10, "extra_health_insurance": 35}
    gross_pay = 0
    if 0 <= work_time <= 40:
        gross_pay = initial["salary"] * work_time
    elif 40 < work_time:
        gross_pay = initial["salary"] * (work_time + (work_time - 40) * 1.5)
    social_security_tax = gross_pay * initial["social_security_tax"]
    federal_income_tax = gross_pay * initial["federal_income_Tax"]
    state_income_tax = gross_pay * initial["state_income_tax"]
    health_insurance = 0
    if dependents >= 3:
        health_insurance = initial["extra_health_insurance"]
    take_home_pay = gross_pay - social_security_tax - federal_income_tax - state_income_tax - health_insurance
    return {"grossPay": gross_pay, "socialSecurityTax": social_security_tax, "federalIncomeTax": federal_income_tax,
            "stateIncomeTax": state_income_tax, "takeHomePay": take_home_pay, "healthInsurance": health_insurance}


def integers_variables(*args):
    """
    Q4. Input 5 numbers, calculate the sum and average of them.
    :param numbers_list: A list, each term of the list should be an Int or Float number.
    :return: {"sumPositives": sum_positives, "sumNegatives": sum_negatives, "averageNegatives": average_negatives,
              "sumAll": sum_all, "averageAll": average_all}
    """
    positive_numbers = 0
    negative_numbers = 0
    sum_positives = 0
    sum_negatives = 0
    for number in args:
        if number > 0:
            positive_numbers += 1
            sum_positives += number
        elif number < 0:
            negative_numbers += 1
            sum_negatives += number
    return {"sumPositives": sum_positives, "sumNegatives": sum_negatives,
            "averageNegatives": sum_negatives/negative_numbers, "sumAll": sum_positives+sum_negatives,
            "averageAll": (sum_positives+sum_negatives)/len(args)}


def random_choice():
    """
    Q5. Random choice a word in ["Yes", "No", "Not-Sure"]
    :return: A string, maybe Yes, No or Not-Sure.
    """
    return random.choice(["Yes", "No", "Not-Sure"])


def pizza_selector(small_pizza_size, large_pizza_size, small_pizza_price, large_pizza_price):
    """
    Q6. This selector help you to buy a pizza!
    :param small_pizza_size: Int or Float.
    :param large_pizza_size: Int or Float.
    :param small_pizza_price: Int or Float.
    :param large_pizza_price: Int or Float.
    :return: {"Your choice:" "Small pizza"} or {"Your choice:" "Large pizza"} or {"Your choice:" "Whatever"}
    """
    small_pizza_area = 3.1415926 * small_pizza_size ** 2
    large_pizza_area = 3.1415926 * large_pizza_size ** 2
    if small_pizza_area / small_pizza_price < large_pizza_area / large_pizza_price:
        return {"Your choice:" "Small pizza"}
    elif small_pizza_area / small_pizza_price > large_pizza_area / large_pizza_price:
        return {"Your choice:" "Large pizza"}
    else:
        return {"Your choice:" "Whatever"}


if __name__ == "__main__":
    # The entrance of this program
    print("Hello! My name is Weiqi Wang, and this is my class 2 lab program.")
    while True:
        try:
            program = int(input("Choose the program you want to check:"))
            if 1 <= program <= 6 and program != 2:
                break
            else:
                print("Please enter a number between 1 and 6 without 2")
        except TypeError:
            print("You didn't enter a number. Try again:")
    if program == 1:
        try:
            print(accrued_account(principle_amount=eval(input("Input principle amount:")),
                                  years=eval(input("Input the year:"))))
        except TypeError:
            print("Type error exist. The program will exit.")
    elif program == 3:
        try:
            print(salary_calculator(dependents=int(input("Input dependents:")),
                                    work_time=eval(input("Input work times:"))))
        except TypeError:
            print("Type error exist. The program will exit.")
    elif program == 4:
        try:
            print(integers_variables(int(input("Input the number 1:")),
                                     int(input("Input the number 2:")),
                                     int(input("Input the number 3:")),
                                     int(input("Input the number 4:")),
                                     int(input("Input the number 5:"))))
        except TypeError:
            print("Type error exist. The program will exit.")
    elif program == 5:
        print(random_choice())
    elif program == 6:
        try:
            print(pizza_selector(small_pizza_size=int(input("Input the size of small pizza:")),
                                 large_pizza_size=int(input("Input the size of large pizza:")),
                                 small_pizza_price=eval(input("Input the price of small pizza:")),
                                 large_pizza_price=eval(input("Input the price of large pizza:"))))
        except TypeError:
            print("Type error exist. The program will exit.")
