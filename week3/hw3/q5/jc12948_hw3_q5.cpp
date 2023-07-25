/*
Body mass index (BMI) is a number calculated from a person’s weight and height using the following formula: 𝑤𝑒𝑖𝑔h𝑡/h𝑒𝑖𝑔h𝑡!. Where 𝑤𝑒𝑖𝑔h𝑡 is in kilograms and h𝑒𝑖𝑔h𝑡 is in meters.
According to the Centers for Disease Control and Prevention, the BMI is a fairly reliable indicator of body fatness for most people. BMI does not measure body fat directly, but research has shown that BMI correlates to direct measures of body fat, such as underwater weighing and dual-energy X-ray absorptiometry.
The following table gives the weight status in respect to the BMI value:
  const int FLOOR_ROUND = 1;
 const int CEILING_ROUND = 2;
 const int ROUND = 3;
    BMI Range
Below 18.5 [18.5, 25) [25, 30)
30 and above
Weight Status
Underweight Normal Overweight Obese
          Write a program that prompts for weight (in pounds) and height (in inches) of a person, and prints the weight status of that person.
Your program should interact with the user exactly as it shows in the following example: Please enter weight (in pounds): 135
Please enter height (in inches): 71
The weight status is: Normal
Note: 1 pound is 0.453592 kilograms and 1 inch is 0.0254 meters.
*/