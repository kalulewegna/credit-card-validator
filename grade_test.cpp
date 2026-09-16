#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> key = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    vector<vector<char>> answers = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
    };

    cout << "Student\tCorrect Answers\n";
    cout << "-------\t---------------\n";

    for (int student = 0; student < (int)answers.size(); student++)
    {
        int correct = 0;
        for (int question = 0; question < (int)answers[student].size(); question++)
        {
            if (answers[student][question] == key[question])
            {
                correct++;
            }
        }
        cout << "Student " << student << "\t" << correct << "\n";
    }

    return 0;
}
