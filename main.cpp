#include <iostream>

using namespace std;

int findAllFactors(int num, int factorList[])
{
   int count = 0;
   for (int i = 1; i <= num; i++)
   {
      if (!(num % i))
      {
         factorList[count] = i;
         count++;
      }
   }
   return --count;
}

int largestCommonFactor(int num1, int num2)
{
   int factorList1[256] = {};
   int factorList2[256] = {};
   int index1;
   int index2;

   if ((num1 == 1)||(num2 == 1))
      return 1;
   else
   {
      index1 = findAllFactors(num1, factorList1);
      index2 = findAllFactors(num2, factorList2);
      while (!(factorList1[index1] == factorList2[index2]))
      {
         if (factorList1[index1] > factorList2[index2])
         {
            if (index1 > 1)
               index1--;
            else
               return 1;
         }
         else
         {
            if (index2 > 1)
               index2--;
            else
               return 1;
         }
      }
   }
   return factorList1[index1];

}

int main()
{
    int lcf = largestCommonFactor(36,4);
    cout << lcf;
    return 0;
}
