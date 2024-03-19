"""
Copyright: Weiqi Wang, WANW7D1903
           Fraser International College
           Instructor: Koopa H.
"""


def binary_system_calculator(decimalism):
    """
    Input a decimalism number, the calculator returns a number in binary system.
    :param decimalism: Int. The decimalism number to be translated.
    :return: Dictionary. {"binary_number": binary_number}.
    """
    binary_number = ""
    while decimalism != 0:
        if decimalism % 2 == 0:
            binary_number += "0"
        else:
            binary_number += "1"
        decimalism = decimalism // 2
    return {"binary_number": binary_number[::-1]}


def coin_calculator(value):
    """
    Input a value, this coin calculator will return how many coins are equal to that value.
    :param value: Int or Float. The value to be calculated.
    :return: Dictionary. The numbers of each coin that the sum of them are equal to the value.
    """
    value = value * 100
    coins = {"penny": 1,  "nickel": 5, "dime": 10, "quarter": 25, "loonie": 100, "toonie": 200}
    result = {"penny": 0,  "nickel": 0, "dime": 0, "quarter": 0, "loonie": 0, "toonie": 0}
    for coin in reversed(coins):
        result[coin] = value // coins[coin]
        result[coin] = int(result[coin])
        value = value - result[coin] * coins[coin]
    return result


def distance_translator(feet, inches):
    """
    A distance translator, input feet and inches, return meters and centimetres.
    :param feet: Int or Float. The feet to be translated.
    :param inches: Int or Float.
    :return: Dictionary. {"meters": meters, "centimetres": centimetres}
    """
    return {"meters": feet/3.2808, "centimetres": inches / 0.3937}


def interest_calculator(amount, rate, years):
    """
    Giving the amount, interest rate and the years to save the money, this calculator will return the interest.
    :param amount: Int or Float. The amount to save in the bank.
    :param rate: Int or Float. The interest rate that the bank provides.
    :param years: Int or Float. The period of saving.
    :return: Dictionary. {"interest": interest}
    """
    return {"interest": amount*rate*years}


def quadratic_discriminant_calculator(a, b, c):
    """
    A quadratic is like a * x ** 2 + b * x + c.
    Input the a, b and c, the calculator will return the discriminant, which is b ** 2 - 4 * a * c.
    :param a: Int or Float.
    :param b: Int or Float.
    :param c: Int or Float.
    :return: Dictionary. {"discriminant": discriminant}
    """
    return {"discriminant": b**2-4*a*c}


def sphere_volume_calculator(radius):
    """
    A calculator, input the radius of the sphere, it returns it colume.
    :param radius: Int or Float. The redius of the sphere.
    :return: Dictionary. {"volume": volume}
    """
    return {"volume": 4*3.14*radius**2/3}


def temperature_translator(celsius):
    """

    :param celsius: Int or Float. The celsius temperature to be translated.
    :return: Dictionary. {fahrenheit: fahrenheit}
    """
    return {"fahrenheit": celsius*1.8+32}


def triangle_area_calculator(height, base):
    """
    A triangle area calculator, input height and base, return the area.
    :param height: Int or Float. The height of the triangle.
    :param base: Int or Float. The base of the triangle.
    :return: Dictionary. {"area": area, "base": base}
    """
    return {"area": height*base/2}


if __name__ == "__main__":
    # height_input = None
    # base_input = None
    # while height_input and base_input:
    #     try:
    #         height_input = eval(input("Enter height:"))
    #         base_input = eval(input("Enter base:"))
    #     except TypeError:
    #         print("Please enter a number. Try again:")
    #
    # print(triangle_area_calculator(height=height_input, base=base_input))
    # print(coin_calculator(25.94))
    print(binary_system_calculator(147))

