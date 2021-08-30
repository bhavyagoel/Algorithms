def sumBin(bin1, bin2):
    init = 1
    sumBinary = 0
    res = 0
    while (bin1 != 0 or bin2 != 0):
        sumBinary += ((bin1%10 + bin2%10 + res)%2)*init
        res = (bin1%10 + bin2%10 + res)//2
        bin1 = bin1 // 10
        bin2 = bin2 // 10
        init = init * 10
    if (res != 0):
        sumBinary += (res*init)
    return sumBinary

num1 = int(input("Enter first Element : "))
num2 = int(input("Enter second Element : "))
num1Binary = bin(num1).replace("0b", "")
num2Binary = bin(num2).replace("0b", "")
num1Binary = int(num1Binary)
num2Binary = int(num2Binary)

print("Binary of the " , num1 , "is", num1Binary, ".")
print("Binary of the " , num2 , "is", num2Binary, ".")

sumBinary = sumBin(num1Binary, num2Binary)

print("Sum in binary is ", sumBinary)
