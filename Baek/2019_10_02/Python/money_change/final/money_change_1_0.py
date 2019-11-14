# Developed by "DoKyu Lee"
# Date: 2019.10.02
# Version: 1.0


def main():
   money = [500, 100, 50, 10, 5, 1]
   get = 1000- int(input())
   idx=0
   answer=0
   while get > 0:
       if get >= money[idx]:
           coef = int(get/money[idx])
           get-=coef*money[idx]
           answer+=coef
       idx+=1

   print(answer)

if __name__ == "__main__":
    main()

