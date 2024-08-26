// libraries from the c++ standard library
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

const char *colorArr[] = {"\u001b[31;1m", "\u001b[33;1m", "\u001b[93;1m", "\u001b[32;1m", "\u001b[36;1m", "\u001b[34;1m", "\u001b[35;1m"}; //colors and shit
const int MAX_LENGTH = 10000;
void start(char inputString[MAX_LENGTH]) //do shit
{
  char rainbowString[MAX_LENGTH] = "";
  int count = 0;
  int index = -1;
  while(count < MAX_LENGTH && inputString[count] != '\0'){
    count++;
  }
  for (int i = 0; i < count; ++i) {
    if(index >= 6) {
    index = 0;
    } else {
    index++;
  }
    strcat(rainbowString, colorArr[index]);
    rainbowString[strlen(rainbowString)] = inputString[i];
  }
  cout << "Your rainbow string: ";
  cout << rainbowString << endl;
  cout << "\u001b[37m"; // i set a 300 while making this
}
int main()
{
  char input[MAX_LENGTH] = "";
  cout << "This program takes your text and turns it rainbow!" << endl;
  cout << "Enter your string: ";
  cin.get(input, MAX_LENGTH);
  start(input);
}
