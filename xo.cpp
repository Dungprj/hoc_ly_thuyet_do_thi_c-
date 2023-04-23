#include <iostream>

using namespace std;

int main()
{
char tictactoe[3][3] = {{'x', 'o', 'x'}, {'o', 'x', 'o'}, {'x', 'o', 'x'}};

for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
cout << tictactoe[i][j] << " ";
}
cout << endl;
}

return 0;
}
