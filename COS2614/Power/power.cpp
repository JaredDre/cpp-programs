 #include <iostream>
 #include <cstdlib>
 using namespace std;

 float raised_to_power(float number, int power )
 {
 if (power < 0)
 {
 cout << "\nError - can't raise to a negative power\n";
 exit(1);
 }
 else if (power==0 )
 return (1);
 else
 return (number * raised_to_power(number, power - 1));
 }
 main()
 {
 float answer = raised_to_power(4.0,3);
 cout << answer;
 return 0;
 }
