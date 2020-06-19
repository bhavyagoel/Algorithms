def HornersRule(degree, coef, x):
    val = 0
    for i in range(degree, -1, -1):
        val = coef[i] + x*val

    return val


if __name__ == "__main__":

    degree = int(input("Enter the degree of polynomial you wish to have : "))

    coef = list(map(lambda x: int(x), input("Enter the coefficients of the polynomial : ").split()))


    x = int(input("Enter the value of x : "))

    val = HornersRule(degree, coef, x);
    print("The calculated value is : " ,val)
